//This script sets message time of laser scan message to that of this computer, allowing non syncronized unit time on laser scan unit.
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/CompressedImage.h>
#include <sensor_msgs/Image.h>

#include <iostream>
#include <stereo_formatting/CompStereo.h>

#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

using namespace std;
sensor_msgs::CameraInfo info_right;
sensor_msgs::CameraInfo info_left;

sensor_msgs::Image left_image;
sensor_msgs::Image right_image;

ros::Time time_last;
ros::Time time_now;

bool first_frame = true;
bool new_msg = false;


void Callback(const stereo_formatting::CompStereoConstPtr &stereo){
  if(stereo->left_compressed.data.empty()){
      ROS_WARN("empty compressed data input");
    }

  info_left = stereo->left_camera_info;
  info_right = stereo->right_camera_info;

  cv::Mat left = cv::imdecode(cv::Mat(stereo->left_compressed.data), cv::IMREAD_COLOR);
  cv::Mat right = cv::imdecode(cv::Mat(stereo->right_compressed.data), cv::IMREAD_COLOR);
  if(left.empty()){
    ROS_WARN("empty image");
  }
  left_image = *cv_bridge::CvImage(stereo->left_compressed.header, "bgr8", left).toImageMsg();
  right_image = *cv_bridge::CvImage(stereo->right_compressed.header, "bgr8", right).toImageMsg();

  new_msg = true;
}


int main(int argc, char** argv){
  ros::init(argc, argv, "stereo_transport");

  ros::NodeHandle n;
  image_transport::ImageTransport it(n);

  ros::Subscriber StereoCompSub = n.subscribe("stereo_image/compressed", 1, Callback);

  image_transport::Publisher leftPub = it.advertise("left/image_raw", 1);
  image_transport::Publisher rightPub = it.advertise("right/image_raw", 1);

  ros::Publisher leftInfoPub = n.advertise<sensor_msgs::CameraInfo>("left/camera_info", 1);
  ros::Publisher rightInfoPub = n.advertise<sensor_msgs::CameraInfo>("right/camera_info", 1);

  while(n.ok()){
    //make sure a new message has been posted
    if(new_msg){
      //if statement sets correct unit ros time.
      if(!first_frame){ //time difference will be unit time plus unsynchronized time difference.
        time_now += info_left.header.stamp - time_last;
        time_last = info_left.header.stamp;
      }
      else{ //at first frame earlier frame will not exist, then time is set to current unit time.
        time_now = ros::Time::now();
        time_last = info_left.header.stamp;
        first_frame = false;
      }

      info_right.header.stamp=time_now;
      info_left.header.stamp=time_now;
      right_image.header.stamp=time_now;
      left_image.header.stamp=time_now;

      leftPub.publish(left_image);
      leftInfoPub.publish(info_left);

      rightPub.publish(right_image);
      rightInfoPub.publish(info_right);

      new_msg = false;
    }
    ros::spinOnce();
    //r.spin();
    //ros::spin();
  }
  return 0;
}
