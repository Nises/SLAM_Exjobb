//Subscribes to left and right compressed image message, camera info, packages them together and publishes that message.
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/CompressedImage.h>
#include <iostream>
#include <stereo_formatting/CompStereo.h>

#include <image_transport/image_transport.h>
#include <image_transport/subscriber_filter.h>

using namespace std;
stereo_formatting::CompStereo stereo;


void rightCallback(const sensor_msgs::CompressedImageConstPtr &right){
  stereo.right_compressed= *right;
}

void leftCallback(const sensor_msgs::CompressedImageConstPtr &left){
  stereo.left_compressed = *left;
}

void rightInfoCallback(const sensor_msgs::CameraInfoConstPtr &info){
  stereo.right_camera_info = *info;
}

void leftInfoCallback(const sensor_msgs::CameraInfoConstPtr &info){
  stereo.left_camera_info = *info;
}

int main(int argc, char** argv){
  ros::init(argc, argv, "stereo_transport");

  ros::NodeHandle n;
  ros::Rate r(10);

  ros::Subscriber right_sub = n.subscribe("raspicam_right/image/compressed", 1, rightCallback);
  ros::Subscriber left_sub = n.subscribe("raspicam_left/image/compressed", 1, leftCallback);

  ros::Subscriber rightInfo_sub = n.subscribe("raspicam_right/camera_info", 1, rightInfoCallback);
  ros::Subscriber leftInfo_sub = n.subscribe("raspicam_left/camera_info", 1, leftInfoCallback);

  ros::Publisher StereoCompPub = n.advertise<stereo_formatting::CompStereo>("stereo_image/compressed", 1);
  while(n.ok()){
    stereo.right_camera_info.header.stamp=stereo.left_camera_info.header.stamp;
    stereo.right_compressed.header.stamp=stereo.left_camera_info.header.stamp;
    stereo.left_compressed.header.stamp=stereo.left_camera_info.header.stamp;
    StereoCompPub.publish(stereo);

    ros::spinOnce();
    r.sleep();
  }
}
