#!/usr/bin/python3
import rospy, time
#import RPi.GPIO as GPIO
from geometry_msgs.msg import Twist
from time import sleep

#import pigpio

#pi = pigpio.pi()

def info(data):
    print("I heard")
    rospy.loginfo(data.linear.x)
    rospy.loginfo(data.angular.z)

def listen():
    rospy.init_node('teleop_listener', anonymous=False)
    print("listening \n")
    rospy.Subscriber("turtle1/cmd_vel", Twist, info)
    rospy.spin()


if __name__ == '__main__':
    try:
        listen()
    except rospy.ROSInterruptException:
        pass