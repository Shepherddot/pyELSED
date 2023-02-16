import sys
sys.path.append('../lib/')

from pyelsed import detect_line_use_elsed
import cv2

img = cv2.imread("../images/banner.jpg")
lines = detect_line_use_elsed(img)

for one_line in lines:
    start_x = int(one_line[0])
    start_y = int(one_line[1])

    end_x = int(one_line[2])
    end_y = int(one_line[3])

    cv2.line(img, (start_x, start_y), (end_x, end_y), color=(0, 255, 0), thickness=2)

cv2.imshow('line_img', img)
cv2.waitKey()

print()