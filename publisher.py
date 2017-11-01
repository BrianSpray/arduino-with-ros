#!/usr/bin/env python
import rospy
from std_msgs.msg import String

def toggleLed():
    pub = rospy.Publisher('toggle_led', String, queue_size=10)
    rospy.init_node('toggle_led', anonymous=True)
    rate = rospy.Rate(1)
    random_string = ''
    while not rospy.is_shutdown():
        user_choice = raw_input("Please enter a value [ledoff/ledon]\n")
        if user_choice == 'ledoff':
            random_string = 'ledoff'
            pub.publish(random_string)
        elif user_choice == 'ledon':
            random_string = 'ledon'
            pub.publish(random_string)
        rate.sleep()

if __name__ == '__main__':
    try:
        toggleLed()
    except rospy.ROSInterruptException:
        pass