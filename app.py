from flask import Flask, render_template, request, redirect
import cv2
import os
import sqlite3
from datetime import datetime

app = Flask(__name__)

# ---------- Paths ----------
FACE_DIR = "faces/captured"
os.makedirs(FACE_DIR, exist_ok=True)

# ---------- Database ----------
def get_db():
    cur = sqlite3.connect("attendance.db")
    cur.execute("""
        CREATE TABLE IF NOT EXISTS students (
            reg_no TEXT PRIMARY KEY,
            name TEXT,
            image_path TEXT
        )
    """)
    return cur

# ---------- Routes ----------
@app.route("/")
def student():
    return render_template("student.html")

@app.route("/capture", methods=["POST"])
def capture():
    name = request.form["name"]
    reg_no = request.form["reg_no"]

    cam = cv2.VideoCapture(0)

    if not cam.isOpened():
        return "Camera not accessible"

    print("Press SPACE to capture, Q to quit")

    while True:
        ret, frame = cam.read()
        if not ret:
            break

        cv2.imshow("Capture Face", frame)
        key = cv2.waitKey(1)

        # SPACE = capture
        if key == 32:
            filename = f"{reg_no}.jpg"
            path = os.path.join(FACE_DIR, filename)
            cv2.imwrite(path, frame)
            break

        # Q = quit
        elif key == ord('q'):
            cam.release()
            cv2.destroyAllWindows()
            return redirect("/")

    cam.release()
    cv2.destroyAllWindows()

    # Save to DB
    conn = get_db()
    conn.execute(
        "INSERT OR REPLACE INTO students VALUES (?,?,?,?)",
        (reg_no, name, path, datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
    )
    conn.commit()
    conn.close()

    return "✅ Face captured and data stored successfully!"

# ---------- Run ----------
if __name__ == "__main__":
    app.run(debug=True)