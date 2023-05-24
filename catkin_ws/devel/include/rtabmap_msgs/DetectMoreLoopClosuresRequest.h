// Generated by gencpp from file rtabmap_msgs/DetectMoreLoopClosuresRequest.msg
// DO NOT EDIT!


#ifndef RTABMAP_MSGS_MESSAGE_DETECTMORELOOPCLOSURESREQUEST_H
#define RTABMAP_MSGS_MESSAGE_DETECTMORELOOPCLOSURESREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rtabmap_msgs
{
template <class ContainerAllocator>
struct DetectMoreLoopClosuresRequest_
{
  typedef DetectMoreLoopClosuresRequest_<ContainerAllocator> Type;

  DetectMoreLoopClosuresRequest_()
    : cluster_radius_max(0.0)
    , cluster_radius_min(0.0)
    , cluster_angle(0.0)
    , iterations(0)
    , intra_only(false)
    , inter_only(false)  {
    }
  DetectMoreLoopClosuresRequest_(const ContainerAllocator& _alloc)
    : cluster_radius_max(0.0)
    , cluster_radius_min(0.0)
    , cluster_angle(0.0)
    , iterations(0)
    , intra_only(false)
    , inter_only(false)  {
  (void)_alloc;
    }



   typedef float _cluster_radius_max_type;
  _cluster_radius_max_type cluster_radius_max;

   typedef float _cluster_radius_min_type;
  _cluster_radius_min_type cluster_radius_min;

   typedef float _cluster_angle_type;
  _cluster_angle_type cluster_angle;

   typedef int32_t _iterations_type;
  _iterations_type iterations;

   typedef uint8_t _intra_only_type;
  _intra_only_type intra_only;

   typedef uint8_t _inter_only_type;
  _inter_only_type inter_only;





  typedef boost::shared_ptr< ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator> const> ConstPtr;

}; // struct DetectMoreLoopClosuresRequest_

typedef ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<std::allocator<void> > DetectMoreLoopClosuresRequest;

typedef boost::shared_ptr< ::rtabmap_msgs::DetectMoreLoopClosuresRequest > DetectMoreLoopClosuresRequestPtr;
typedef boost::shared_ptr< ::rtabmap_msgs::DetectMoreLoopClosuresRequest const> DetectMoreLoopClosuresRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator1> & lhs, const ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator2> & rhs)
{
  return lhs.cluster_radius_max == rhs.cluster_radius_max &&
    lhs.cluster_radius_min == rhs.cluster_radius_min &&
    lhs.cluster_angle == rhs.cluster_angle &&
    lhs.iterations == rhs.iterations &&
    lhs.intra_only == rhs.intra_only &&
    lhs.inter_only == rhs.inter_only;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator1> & lhs, const ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace rtabmap_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "df5cfe58cb7487b0d93ed1614efab4a3";
  }

  static const char* value(const ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xdf5cfe58cb7487b0ULL;
  static const uint64_t static_value2 = 0xd93ed1614efab4a3ULL;
};

template<class ContainerAllocator>
struct DataType< ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rtabmap_msgs/DetectMoreLoopClosuresRequest";
  }

  static const char* value(const ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Detect more loop closures service\n"
"#\n"
"#     Based on the current optimized graph, \n"
"#     this process will try to find more nodes corresponding with each \n"
"#     other, and thus finding more loop closures to add to graph.\n"
"# \n"
"\n"
"# Cluster radius (m),     default 1 m if not set\n"
"float32 cluster_radius_max\n"
"\n"
"# Cluster radius min (m), default 0 m if not set\n"
"float32 cluster_radius_min\n"
"\n"
"# Cluster angle (deg),    default 0 deg if not set\n"
"float32 cluster_angle\n"
"\n"
"# Iterations,             default 1 if not set\n"
"int32 iterations\n"
"\n"
"# Add only intra session loop closures\n"
"bool intra_only\n"
"\n"
"# Add only inter session loop closures\n"
"bool inter_only\n"
;
  }

  static const char* value(const ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.cluster_radius_max);
      stream.next(m.cluster_radius_min);
      stream.next(m.cluster_angle);
      stream.next(m.iterations);
      stream.next(m.intra_only);
      stream.next(m.inter_only);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DetectMoreLoopClosuresRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rtabmap_msgs::DetectMoreLoopClosuresRequest_<ContainerAllocator>& v)
  {
    s << indent << "cluster_radius_max: ";
    Printer<float>::stream(s, indent + "  ", v.cluster_radius_max);
    s << indent << "cluster_radius_min: ";
    Printer<float>::stream(s, indent + "  ", v.cluster_radius_min);
    s << indent << "cluster_angle: ";
    Printer<float>::stream(s, indent + "  ", v.cluster_angle);
    s << indent << "iterations: ";
    Printer<int32_t>::stream(s, indent + "  ", v.iterations);
    s << indent << "intra_only: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.intra_only);
    s << indent << "inter_only: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.inter_only);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RTABMAP_MSGS_MESSAGE_DETECTMORELOOPCLOSURESREQUEST_H
