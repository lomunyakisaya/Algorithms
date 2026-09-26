import cv2
image = cv2.imread("giraffe.jpg")
cv2.imshow("Image", image)
cv2.waitKey(9000)
cv2.destroyAllWindows()