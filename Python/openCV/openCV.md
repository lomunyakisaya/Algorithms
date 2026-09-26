# OpenCV Notes

## 1. What is OpenCV?
OpenCV (Open Source Computer Vision Library) is a Python library used for image and video processing.

It is widely used in:
- image processing
- computer vision
- face detection
- object detection
- video analysis
- robotics
- AI vision systems

OpenCV helps us read, modify, analyze, and save images and videos.

---

## 2. Why use OpenCV?
OpenCV is popular because it is:
- open source
- fast
- easy to use with Python
- useful for real-world vision tasks

It is used in many projects such as:
- camera apps
- license plate detection
- QR code scanning
- motion detection
- security systems

---

## 3. Installing OpenCV
To install OpenCV in Python:

```bash
pip install opencv-python
```

You can also install the extra contrib package:

```bash
pip install opencv-python-headless
```

or

```bash
pip install opencv-contrib-python
```

---

## 4. Importing OpenCV
```python
import cv2
```

This is the main library used to access OpenCV features.

---

## 5. Reading an image
```python
import cv2

img = cv2.imread("image.jpg")
cv2.imshow("My Image", img)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

### Explanation
- `cv2.imread()` reads an image from a file.
- `cv2.imshow()` displays the image in a window.
- `cv2.waitKey(0)` waits for a key press.
- `cv2.destroyAllWindows()` closes the window.

---

## 6. Checking if image loaded successfully
```python
import cv2

img = cv2.imread("image.jpg")

if img is None:
    print("Image not found")
else:
    print("Image loaded successfully")
```

---

## 7. Image properties
Every image in OpenCV is a NumPy array.

```python
import cv2

img = cv2.imread("image.jpg")
print(img.shape)
print(img.dtype)
```

### Image shape
For a colored image, shape is:
```python
(height, width, channels)
```

Example:
```python
(480, 640, 3)
```

This means:
- height = 480
- width = 640
- channels = 3 (B, G, R)

---

## 8. Color spaces
OpenCV supports different color formats.

### BGR format
OpenCV reads images in BGR color format instead of RGB.

```python
import cv2

img = cv2.imread("image.jpg")

# convert BGR to RGB
rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
```

### Common conversions
- `COLOR_BGR2RGB`
- `COLOR_BGR2GRAY`
- `COLOR_BGR2HSV`

Example:
```python
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
```

---

## 9. Converting to grayscale
```python
import cv2

img = cv2.imread("image.jpg")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

cv2.imshow("Gray Image", gray)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

Grayscale is useful because it simplifies image processing.

---

## 10. Resizing an image
```python
import cv2

img = cv2.imread("image.jpg")
resized = cv2.resize(img, (500, 300))

cv2.imshow("Resized", resized)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

---

## 11. Rotating an image
```python
import cv2

img = cv2.imread("image.jpg")
(h, w) = img.shape[:2]
center = (w // 2, h // 2)
rotated = cv2.rotate(img, cv2.ROTATE_90_CLOCKWISE)

cv2.imshow("Rotated", rotated)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

---

## 12. Drawing shapes
OpenCV can draw lines, rectangles, circles, and text.

### Drawing a line
```python
import cv2
import numpy as np

img = np.zeros((400, 400, 3), dtype="uint8")
cv2.line(img, (0, 0), (400, 400), (0, 255, 0), 3)
cv2.imshow("Line", img)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

### Drawing a rectangle
```python
cv2.rectangle(img, (50, 50), (250, 250), (255, 0, 0), 2)
```

### Drawing a circle
```python
cv2.circle(img, (200, 200), 50, (0, 0, 255), -1)
```

### Writing text
```python
cv2.putText(img, "OpenCV", (50, 350), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
```

---

## 13. Blurring an image
```python
import cv2

img = cv2.imread("image.jpg")
blur = cv2.GaussianBlur(img, (15, 15), 0)

cv2.imshow("Blurred", blur)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

Blur is used to reduce noise and smooth images.

---

## 14. Edge detection
```python
import cv2

img = cv2.imread("image.jpg", cv2.IMREAD_GRAYSCALE)
edges = cv2.Canny(img, 100, 200)

cv2.imshow("Edges", edges)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

Canny edge detection is commonly used to detect outlines in images.

---

## 15. Video capture
OpenCV can also work with videos using a webcam or a video file.

```python
import cv2

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    cv2.imshow("Webcam", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
```

### Explanation
- `cv2.VideoCapture(0)` opens the default webcam.
- `cap.read()` reads one frame.
- `q` quits the video stream.

---

## 16. Saving an image
```python
import cv2

img = cv2.imread("image.jpg")
cv2.imwrite("output.jpg", img)
```

This saves the image to a new file.

---

## 17. Basic OpenCV functions
Some common functions are:

- `cv2.imread()` - read image
- `cv2.imshow()` - show image
- `cv2.imwrite()` - save image
- `cv2.cvtColor()` - convert color
- `cv2.resize()` - resize image
- `cv2.rotate()` - rotate image
- `cv2.GaussianBlur()` - blur image
- `cv2.Canny()` - detect edges
- `cv2.VideoCapture()` - capture video

---

## 18. Main uses of OpenCV
OpenCV is used in:
- face detection
- hand tracking
- object detection
- movement tracking
- medical imaging
- self-driving cars
- barcode recognition

---

## 19. Summary
OpenCV is a Python library used for processing images and videos.
It allows us to:
- read and display images
- process colors and grayscale
- draw shapes
- detect edges
- resize and rotate
- capture webcam video

It is one of the most important tools in computer vision.

---

## 20. Quick revision questions
1. What does OpenCV stand for?
2. What function is used to read an image?
3. What is the default color format in OpenCV?
4. What function converts an image to grayscale?
5. What function is used to capture video from a webcam?

---

## 21. Final note
OpenCV is very useful for learning computer vision and image processing. Start with simple tasks like reading images, converting colors, and drawing shapes before moving to advanced topics like detection and tracking.
