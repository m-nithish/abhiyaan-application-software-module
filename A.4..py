import rospy
import time
import math
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose

x=0.0
y=0.0
orient=0.0
x0=0.0
y0=0.0
flag=0

def getpos(current_pos):
	global x
	global y
	global flag
	global orient
	x=current_pos.x
	y=current_pos.y
	orient=current_pos.theta

def pos():	
	rospy.Subscriber("/turtle1/pose",Pose,getpos)
	
	
def getgoalpos(cur_pos):
	global x0
	global y0
	x0=cur_pos.x
	y0=cur_pos.y

def goalpos():
	rospy.Subscriber("/abhiyaan/pose",Pose,getgoalpos)
	print "Finding the Location of Abhiyaan"


def find():
	global x
	global y
	global x0
	global y0
	global orient
	message=Twist()
	bot=rospy.Publisher("/turtle1/cmd_vel",Twist,queue_size=10)
	k1=0.5
	k2=0.75
	print "Moving towards Abhiyaan...\n Coordinates:"
	while(True):
		angle=math.atan2(y0-y,x0-x)
		dist=abs(math.sqrt((x-x0)**2+(y-y0)**2))

		linear_speed=dist*k1
		angular_speed=(angle-orient)*k2

		message.linear.x=linear_speed
		message.angular.z=angular_speed
		
		bot.publish(message)
		print "x=",x,"y=",y,"Distance: ",dist
		if(dist<=2):
			print "FOUND!!!!!"
			break
	
	

if __name__=="__main__":
	rospy.init_node("t1",anonymous=True)
	goalpos()
	time.sleep(1)
	print "Location of Abhiyaan:\n x: %f \n y: %f " %(x0,y0)
	pos()
	time.sleep(2)
	print "Current location of turtle1(x) : %f" %x
	print "Current location of turtle1(y) : %f" %y
	print "Current location of turtle1(orientation) : %f" %orient
	find()
	print "Final location of turtle1:\n x: %f \ny: %f \norientation: %f" %(x,y,orient)
