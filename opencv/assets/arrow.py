from wsgiref.util import shift_path_info
import cv2
import numpy as np


def nothing(_):
    pass


if __name__ == '__main__':

    cv2.namedWindow("img")
    cv2.createTrackbar("x1", "img", 0, 800, nothing)
    cv2.createTrackbar("y1", "img", 0, 800, nothing)
    cv2.createTrackbar("x2", "img", 0, 800, nothing)
    cv2.createTrackbar("y2", "img", 0, 800, nothing)
    cv2.createTrackbar("thickness", "img", 0, 10, nothing)
    cv2.createTrackbar("tipLength", "img", 0, 20, nothing)

    while True:
        x1 = cv2.getTrackbarPos("x1", "img")
        y1 = cv2.getTrackbarPos("y1", "img")
        x2 = cv2.getTrackbarPos("x2", "img")
        y2 = cv2.getTrackbarPos("y2", "img")
        thickness = cv2.getTrackbarPos("thickness", "img")
        tipLength = cv2.getTrackbarPos("tipLength", "img")
        print(x1, y1, x2, y2)
        # img = np.zeros((250, 250, 3, 0))
        img = np.ones((800, 800, 4)) * (255, 255, 255, 0)
        cv2.arrowedLine(img, (x1, y1), (x2, y2), color=(0, 0, 0), thickness=thickness+1, line_type=8, shift=0, tipLength=1/(tipLength+1))

        cv2.imshow("img", img)
        key_pressed = cv2.waitKey(1)
        if key_pressed == ord('q'):
            b, g, r, a = cv2.split(img)
            for i in range(img.shape[0]):
                for j in range(img.shape[1]):
                    if not (b[i][j] > 0 and g[i][j] > 0 and r[i][j] > 0):
                        a[i][j] = 255
            img = cv2.merge((b, g, r, a))
            cv2.imwrite("arrow.png", img)
            break
