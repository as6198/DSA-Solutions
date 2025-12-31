from flask import Flask
import cv2

app = Flask(__name__)

@app.route("/")
def home():
    return """
    <h2>Smart Attendance</h2>
    <a href='/capture'><button>Open Camera</button></a>
    """

@app.route("/capture")
def capture():
    cam = cv2.VideoCapture(0)

    if not cam.isOpened():
        return "❌ Camera not opening"

    while True:
        ret, frame = cam.read()
        if not ret:
            break

        cv2.imshow("Camera", frame)
        if cv2.waitKey(1) == 32:   # SPACE
            break

    cam.release()
    cv2.destroyAllWindows()
    return "✅ Image captured. Close this tab."

if __name__ == "__main__":
    app.run(debug=True)