# Smart Attendance System (Face Capture Based)

Smart Attendance System is a web-based application developed using Python (Flask), OpenCV, and SQLite. The system captures student facial images through a webcam and allows students to verify their identity before marking attendance. Captured faces are temporarily stored and later approved by an administrator with student details such as name and registration number. This project demonstrates the integration of computer vision with web technologies to automate and simplify the attendance process securely and efficiently.

---

##  Features

- Webcam-based face capture using OpenCV
- Web interface using Flask
- Student verification page (Name & Register Number)
- Face images stored locally
- Attendance data stored in SQLite database
- Simple and beginner-friendly project structure
- Suitable for academic mini-projects

---

##  Technologies Used

- Python 3
- Flask (Web Framework)
- OpenCV (Camera & Image Capture)
- SQLite (Database)
- HTML & CSS (Frontend)

---

## Project Structure
```
SmartAttendance/
│
├── app.py
├── camera.py
├── attendance.db
│
├── faces/
│   ├── pending/
│   └── approved/
│       └── <reg_no>/
│           └── face.jpg
│
├── templates/
│   ├── student.html
│   ├── verify.html
│   ├── admin.html
│   ├── pending.html
│   ├── manage_students.html
│   └── student_table.html
│
├── static/
│   └── style.css
│
└── README.md
```
---

##  Required Libraries
```
Make sure Python is installed (Python 3.9 or above recommended).
Install required libraries using:
  pip install flask opencv-python
```
---  
## How to Run the Application

### Step 1: Run the Flask app
```
  python app.py
You should see:
Running on http://127.0.0.1:5000
```
### Step 2: Open browser
```
Go to:
  http://127.0.0.1:5000
 ``` 
### Step 3: Capture Face
```
-Click Capture Face
-Webcam opens
-Press SPACE to capture image
-Camera closes automatically
-Website redirects to verification page
```
### Step 4: Enter Student Details
```
-Enter Name
-Enter Register Number
-Click Save
  ✔ Face image is saved
  ✔ Student data stored in SQLite
  ✔ Attendance recorded
```
---
## Data Storage
```
Face images are stored in:
  faces/approved_<regno>/
Database file:
  attendance.db
```
---
## Notes
```
-Ensure webcam is not used by other apps
-Use Python 3.8+
-Works offline (no internet required)
```
---
## Future Enhancements
```
  -Face recognition (automatic attendance)
  -Admin approval panel
  -Attendance reports
  -CSV export
  -Login system
```
 --- 
## Author
```
Amirtha S S
CSE AIML
2nd year undergraduate 
Developed as an academic project for learning purposes.
```
