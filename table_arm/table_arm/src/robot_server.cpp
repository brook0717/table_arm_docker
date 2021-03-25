#include "ros/ros.h"
#include "table_arm/robot.h"

bool add(table_arm::robot::Request  &req,
         table_arm::robot::Response &res)
{
  //res.sum = req.a + req.b;
  ROS_INFO("request: joint_1=%f,
					 joint_2=%f,
					 joint_3=%f,
					 joint_4=%f,
					 joint_5=%f,
					 joint_6=%f,
                    ,(long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "robot_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("HI", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}