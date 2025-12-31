import cv2
import os

# Folder to save faces
SAVE_DIR = "faces/pending"
if not os.path.exists(SAVE_DIR):
    os.makedirs(SAVE_DIR, exist_ok=True)

# Try camera index 0 with DirectShow (Windows fix)
cam = cv2.VideoCapture(0, cv2.CAP_DSHOW)

if not cam.isOpened():
    print("❌ Camera not accessible")
    exit()

count = 0
print("📸 Press SPACE to capture face")
print("❌ Press q to quit")

while True:
    ret, frame = cam.read()
    if not ret:
        print("❌ Failed to grab frame")
        break

    cv2.imshow("Face Capture", frame)

    key = cv2.waitKey(1)

    # SPACE key → capture
    if key == 32:
        img_path = f"{SAVE_DIR}/face_{count}.jpg"
        cv2.imwrite(img_path, frame)
        print(f"✅ Saved: {img_path}")
        count += 1

    # Q key → quit
    elif key == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()
print("👋 Done")
