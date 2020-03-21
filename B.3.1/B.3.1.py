"""
THIS PROGRAM TAKES THE INPUT IMAGE AND USES OPEN CV TO MARK THE LANE.
IT FIRST CREATES A GRAY SCALE VERSION OF THE IMAGE FOLLOWED BY A CANNY EDGE DETECTOR TO MARK JUST THE EDGES.
IT THEN USES THE PROBABILISTUC HOUGH LINE TRANSORM TO MARK THE LANES
THE PARAMETERS OF HOUGHLINEP HAVE BEEN ADJUSTED BASED ON HIT AND TRIAL TO IMPROVE THE ACCURACY OF THE OUTPUT
"""
import cv2
import numpy as np
import matplotlib.pylab as plt

image=cv2.imread('lane.jpeg')    
gray_image=cv2.cvtColor(image,cv2.COLOR_RGB2GRAY)
canny_image=cv2.Canny(gray_image,100,200)
lines=cv2.HoughLinesP(canny_image,1,np.pi/180,115,minLineLength=110,maxLineGap=5)
for line in lines:
    x1,y1,x2,y2=line[0]
    cv2.line(image,(x1,y1),(x2,y2),(0,0,255),2)
    
cv2.imshow('images',image)
k=cv2.waitKey(0)
cv2.destroyAllWindows()
