#!/usr/bin/env python
import serial
import roslib, rospy
from std_msgs.msg import Int32MultiArray, Float64, Float64MultiArray, Int16
from optparse import OptionParser
import yaml
import time as time
rospy.init_node('latency_', anonymous = True)
from optparse import OptionParser
t_sent = 0
t_test = rospy.get_time()
trigger_state1 = 0
trigger_state2 =0
arduino = serial.Serial(port='/dev/ttyACM1', baudrate=19200, timeout=.1)
pub = rospy.Publisher("trigger_publisher", Int16 )
pub1 = rospy.Publisher('latency_time', Float64)
t_light  =0
def call_back_1(data):
	#print(data.data)
	if data.data==1 and trigger_state1==0:
		global t_sent
		
		arduino.writelines('a')
		t_sent =rospy.get_time()
		#print(t_sent)
		#t_new =rospy.get_time()
		#print(t_sent-t_new)
		#print(t_sent -t_test)
		#trigger_state1 =1

def call_back_2(data):
	global trigger_state2
	global t_light
	if data.data > .025 and trigger_state2==0:
		t_light =  rospy.get_time()
		lat=t_light-t_sent
		print(lat)
		#print(t_light)
		#print("t sent is" + str(t_sent))
		trigger_state2=1
	elif data.data <.010 and trigger_state2==1:
		trigger_state2=0

def listener():
	rospy.Subscriber('/trigger_publisher', Int16, call_back_1)
	rospy.Subscriber('/analog_output', Float64, call_back_2)

if __name__ == '__main__':
	#listener1()
	listener()
	rospy.spin()
#	flash_check(5, tseconds)

