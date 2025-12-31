import cv2
import os
from datetime import datetime

SAVE_DIR = "faces/pending"
os.makedirs(SAVE_DIR, exist_ok=True)

def capture_face():
    cam = cv2.VideoCapture(0, cv2.CAP_DSHOW)

    if not cam.isOpened():
        return None

    while True:
        ret, frame = cam.read()
        if not ret:
            continue

        cv2.imshow("Capture Face - Press SPACE", frame)
        key = cv2.waitKey(1)

        if key == 32:  # SPACE
            filename = datetime.now().strftime("%Y%m%d_%H%M%S") + ".jpg"
            path = os.path.join(SAVE_DIR, filename)
            cv2.imwrite(path, frame)
            cam.release()
            cv2.destroyAllWindows()
            return filename

        elif key == ord('q'):
            cam.release()
            cv2.destroyAllWindows()
            return None