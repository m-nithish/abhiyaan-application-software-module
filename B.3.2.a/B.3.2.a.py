"""
THIS PROGRAM ATTEMPTS TO CLASSIFY SIGNALS. FIRST WE READ THE IMAGES AND CONVERT THEM TO HSV.THEN WE APPLY A MASK TO IDENTIFY 
REGIONS OF EACH IMAGE IN THE SAME HSV RANGE OF REG,YELLOW AND GREEN. THEN USING THE BITWISE AND FUNCTION WE RESTORE THE ORIGINAL COLOR .
SO AFTER APPLYING THE THREE MASKS ON THE THREE IMAGES WE CAN IDENTIFY THE SIGNAL BASED ON THE OUTPUT AS ONLY COMMON OVERLAP REGIONS
ARE SHOWN IN COLOR.
"""
import cv2
import numpy as np

image1 = cv2.imread('1.png')
image2 = cv2.imread('2.png')
image3 = cv2.imread('3.png')

hsv1 = cv2.cvtColor(image1, cv2.COLOR_BGR2HSV)
hsv2 = cv2.cvtColor(image2, cv2.COLOR_BGR2HSV)
hsv3 = cv2.cvtColor(image3, cv2.COLOR_BGR2HSV)

#red mask
lower_range_red = np.array([0,100,100])
upper_range_red = np.array([5,255,255])

mask_red_1= cv2.inRange(hsv1, lower_range_red, upper_range_red)
mask_red_2= cv2.inRange(hsv2, lower_range_red, upper_range_red)
mask_red_3= cv2.inRange(hsv3, lower_range_red, upper_range_red)

red_mask_1=cv2.bitwise_and(image1,image1,mask=mask_red_1)
red_mask_2=cv2.bitwise_and(image2,image2,mask=mask_red_2)
red_mask_3=cv2.bitwise_and(image3,image3,mask=mask_red_3)

cv2.imshow('red mask 1',red_mask_1)
cv2.imshow('red mask 2',red_mask_2)
cv2.imshow('red mask 3',red_mask_3)

#green mask
lower_range_green = np.array([55,100,100])
upper_range_green = np.array([65,255,255])

mask_green_1= cv2.inRange(hsv1, lower_range_green, upper_range_green)
mask_green_2= cv2.inRange(hsv2, lower_range_green, upper_range_green)
mask_green_3= cv2.inRange(hsv3, lower_range_green, upper_range_green)

green_mask_1=cv2.bitwise_and(image1,image1,mask=mask_green_1)
green_mask_2=cv2.bitwise_and(image2,image2,mask=mask_green_2)
green_mask_3=cv2.bitwise_and(image3,image3,mask=mask_green_3)

cv2.imshow('green mask 1',green_mask_1)
cv2.imshow('green mask 2',green_mask_2)
cv2.imshow('green mask 3',green_mask_3)

#yellow mask
lower_range_yellow = np.array([30,100,100])
upper_range_yellow = np.array([35,255,255])

mask_yellow_1= cv2.inRange(hsv1, lower_range_yellow, upper_range_yellow)
mask_yellow_2= cv2.inRange(hsv2, lower_range_yellow, upper_range_yellow)
mask_yellow_3= cv2.inRange(hsv3, lower_range_yellow, upper_range_yellow)

yellow_mask_1=cv2.bitwise_and(image1,image1,mask=mask_yellow_1)
yellow_mask_2=cv2.bitwise_and(image2,image2,mask=mask_yellow_2)
yellow_mask_3=cv2.bitwise_and(image3,image3,mask=mask_yellow_3)

cv2.imshow('yellow mask 1',yellow_mask_1)
cv2.imshow('yellow mask 2',yellow_mask_2)
cv2.imshow('yellow mask 3',yellow_mask_3)

cv2.waitKey(0)
cv2.destroyAllWindows()