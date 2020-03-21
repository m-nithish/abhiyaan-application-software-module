import rospy
from std_msgs.msg import String
def receive(message):
	print message.data
	    
def hear():
 	s1= rospy.Subscriber('welcome_message', String,receive)
	rospy.init_node('subscriber1', anonymous=True)
	rospy.spin()
if __name__ == '__main__':
	try:
		hear()
	except rospy.ROSInterruptException:
		pass
