#include "ros/ros.h"
#include "std_msgs/String.h"

void handle_chatter_subscription(std_msgs::String in) {
    ROS_INFO("%s", in.data.c_str());
}

int main(int argc, char *argv[]) {
    ros::init(argc, argv, "listener");
    ros::NodeHandle handle;

    ros::Subscriber sub = handle.subscribe<std_msgs::String>("chatter", 1000, handle_chatter_subscription);

    ros::Rate rate(10);

    ros::spin();
}