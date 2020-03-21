import rospy
from std_msgs.msg import String

def send():
    p1 = rospy.Publisher('welcome_message', String, queue_size=10)
    rospy.init_node('publisher1', anonymous=True)
    rate = rospy.Rate(5) 
    while not rospy.is_shutdown():
        str = "Welcome to Abhiyaan"
        rospy.loginfo(str)
        p1.publish(str)
        rate.sleep()
 
if __name__ == '__main__':
    try:
        send()
    except rospy.ROSInterruptException:
        pass