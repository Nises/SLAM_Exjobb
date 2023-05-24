#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/tf.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <boost/array.hpp>
#include <iostream>
#include <ros/console.h>
#include <std_msgs/String.h>

using namespace std;


double x = 0.0;
double y = 0.0;
double th = 0.0;

double x_old = 0.0;
double y_old = 0.0;
double th_old = 0.0;

double vx = 0;
double vy = 0;
double vth = 0;

typedef boost::array<double, 36> array36_t;
array36_t cov;

double current_time, last_time;

void chatterCallback(const geometry_msgs::PoseWithCovarianceStamped &pose_cov){
  //Access information from pose_cov and calculates velocity and turn
  current_time = pose_cov.header.stamp.toSec();

  //save old values for velocity calculations
  x_old = x;
  y_old = y;
  th_old = th;
  //Access information
  x = pose_cov.pose.pose.position.x;
  y = pose_cov.pose.pose.position.y;
  cov = pose_cov.pose.covariance;

  //use quartenion to calculate yaw th
  tf::Quaternion q(
    pose_cov.pose.pose.orientation.x,
    pose_cov.pose.pose.orientation.y,
    pose_cov.pose.pose.orientation.z,
    pose_cov.pose.pose.orientation.w);
  tf::Matrix3x3 m(q);
  double roll, pitch;
  m.getRPY(roll, pitch, th);

  double dt = (current_time - last_time);
  vx = (x-x_old)/dt;
  vy = (y-y_old)/dt;
  vth = (th-th_old)/dt;

  last_time = current_time;
}

int main(int argc, char** argv){
  ros::init(argc, argv, "odometry_node");
  
  ros::NodeHandle n;
  ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);
  ros::Subscriber odom_sub = n.subscribe("poseupdate", 1, chatterCallback);

  tf::TransformBroadcaster odom_broadcaster;

  ros::Rate r(10);

  while(n.ok()){
    //Broadcasts information calculated in chatterCallback as Odometry Topic
    ros::Time time_now = ros::Time::now(); //
    
    //since all odometry is 6DOF we'll need a quaternion created from yaw
    geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);

    //first, we'll publish the transform over tf
    geometry_msgs::TransformStamped odom_trans;
    odom_trans.header.stamp = time_now;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_link";

    odom_trans.transform.translation.x = x;
    odom_trans.transform.translation.y = y;
    odom_trans.transform.translation.z = 0.0;
    odom_trans.transform.rotation = odom_quat;

    //send the transform
    odom_broadcaster.sendTransform(odom_trans);

    //next, we'll publish the odometry message over ROS
    nav_msgs::Odometry odom;
    odom.header.stamp = time_now;
    odom.header.frame_id = "odom";

    //set the position
    odom.pose.pose.position.x = x;
    odom.pose.pose.position.y = y;
    odom.pose.pose.position.z = 0.0;
    odom.pose.pose.orientation = odom_quat;

    odom.pose.covariance = cov;

    //set the velocity
    odom.child_frame_id = "base_link";
    odom.twist.twist.linear.x = vx;
    odom.twist.twist.linear.y = vy;
    odom.twist.twist.angular.z = vth;

    //publish the message
    odom_pub.publish(odom);

    last_time = current_time;
    ros::spinOnce(); //check for incoming messages
  }
}
