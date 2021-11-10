#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <abc_control/MoveDistanceAction.h>
#include <abc_control/MoveDistanceGoal.h>
#include <abc_control/MoveDistanceResult.h>
#include <abc_control/MoveDistanceFeedback.h>

typedef actionlib::SimpleActionServer<abc_control::MoveDistanceAction> Server;

ros::NodeHandle node_handle;

class Mover
{

};

void execute(const abc_control::MoveDistanceGoalConstPtr& goal, Server* as)
{
  // Do lots of awesome groundbreaking robot stuff here
  for(int i=0; i<100; i++)
    ROS_INFO_STREAM("IN THE LOOP!");
  as->setSucceeded();
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "move_distance_server");
  Server server(node_handle, "move_distance", boost::bind(&execute, _1, &server), false);
  server.start();
  ros::spin();
  return 0;
}
