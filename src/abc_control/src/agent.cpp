#include "ros/ros.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include "std_msgs/Float64.h"
#include <string>
#include <cmath>
#include <actionlib/client/simple_action_client.h>
#include <abc_control/MoveDistanceAction.h>
#include <abc_control/MoveDistanceGoal.h>
#include <abc_control/MoveDistanceResult.h>
#include <abc_control/MoveDistanceFeedback.h>

int main(int argc, char**argv)
{
    ros::init(argc, argv, "agent");
    // iniitalise the action client
    actionlib::SimpleActionClient<abc_control::MoveDistanceAction> client("move_distance", true);

    // wait for the server to start
    client.waitForServer();

    // declare a goal to send the robot to
    abc_control::MoveDistanceGoal goal;
    // initialise the goal
    goal.target.x=10;

    // send the goal
    client.sendGoal(goal);

    //wait for the action to return
    bool finished_before_timeout = client.waitForResult();

    if(finished_before_timeout)
    {
        actionlib::SimpleClientGoalState state = client.getState();
        ROS_INFO("Action finished: %s",state.toString().c_str());
    }
    else
        ROS_INFO("Action did not finish before the time out.");
}
