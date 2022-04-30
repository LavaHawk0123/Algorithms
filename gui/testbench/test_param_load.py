#!/usr/bin/env python3
import rospy

rospy.init_node('load_param_testbench')
i= 1.123311
while True:
	rospy.set_param("/colorpal/lambda/r",i)
	rospy.set_param("/colorpal/lambda/g",i)
	rospy.set_param("/colorpal/lambda/b",i)
	rospy.set_param("/colorpal/r",i)
	rospy.set_param("/colorpal/g",i)
	rospy.set_param("/colorpal/b",i)
	rospy.set_param("/CCS811/CO2",i)
	rospy.set_param("/CCS811/tVOC",i)
	rospy.set_param('/aero/O3',i)
	rospy.set_param('spectral','0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5.877471754111438e-39,5.877471754111438e-39,5.877471754111438e-39,5.877471754111438e-39,5.877471754111438e-39,5.877471754111438e-39,5.877471754111438e-39,5.877471754111438e-39,5.877471754111438e-39,5.877471754111438e-39,5.877471754111438e-39,5.877471754111438e-39,5.877471754111438e-39,5.877471754111438e-39,5.877471754111438e-39,5.877471754111438e-39,5.877471754111438e-39,5.877471754111438e-39,0.1')
