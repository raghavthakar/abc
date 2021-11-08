cmake_minimum_required(VERSION 3.0.2)
project(abc_control)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    rospy
	message_generation
	std_msgs
	geometry_msgs
	tf
	nav_msgs
	sensor_msgs
    actionlib_msgs
)

## Generate actions in the 'action' folder
add_action_files(
FILES
MoveDistance.action
# Action2.action
)

generate_messages(
	DEPENDENCIES
	std_msgs
	geometry_msgs
	nav_msgs
	sensor_msgs
    actionlib_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES abc_control
#  CATKIN_DEPENDS roscpp rospy
#  DEPENDS system_lib
    CATKIN_DEPENDS actionlib_msgs
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
