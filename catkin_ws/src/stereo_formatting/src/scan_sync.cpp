//This script sets message time of laser scan message to that of this computer, allowing non syncronized unit time on laser scan unit.
#include <ros/ros.h>
#include <iostream>
#include <sensor_msgs/LaserScan.h>

using namespace std;

ros::Time time_last;
ros::Time time_now;

bool first_frame = true;
bool new_msg = false;

sensor_msgs::LaserScan scan_copy;

void Callback(const sensor_msgs::LaserScanConstPtr &scan){
  scan_copy = *scan;

  new_msg = true;
}

//due to time not always being calibrated on Raspberry Pi 4, this script sets message time of laser scan message to that of this computer
int main(int argc, char** argv){
  ros::init(argc, argv, "stereo_transport");

  ros::NodeHandle n;

  ros::Subscriber scanSub = n.subscribe("jn0/base_scan", 1, Callback);

  ros::Publisher scanPub = n.advertise<sensor_msgs::LaserScan>("/stereo/scan", 1);

  while(n.ok()){
    //make sure a new message has been posted
    if(new_msg){
      //if statement sets correct unit ros time.
      if(!first_frame){ //time difference will be unit time plus unsynchronized time difference.
        time_now += scan_copy.header.stamp - time_last;
        time_last = scan_copy.header.stamp;
      }
      else{ //at first frame earlier frame will not exist, then time is set to current unit time.
        time_now = ros::Time::now();
        time_last = scan_copy.header.stamp;
        first_frame = false;
      }

      scan_copy.header.stamp=time_now;

      scanPub.publish(scan_copy);

      new_msg = false;
    }
    ros::spinOnce();
  }
  return 0;
}
