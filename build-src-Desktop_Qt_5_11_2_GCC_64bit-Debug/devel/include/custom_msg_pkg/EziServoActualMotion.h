// Generated by gencpp from file custom_msg_pkg/EziServoActualMotion.msg
// DO NOT EDIT!


#ifndef CUSTOM_MSG_PKG_MESSAGE_EZISERVOACTUALMOTION_H
#define CUSTOM_MSG_PKG_MESSAGE_EZISERVOACTUALMOTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace custom_msg_pkg
{
template <class ContainerAllocator>
struct EziServoActualMotion_
{
  typedef EziServoActualMotion_<ContainerAllocator> Type;

  EziServoActualMotion_()
    : position(0)
    , velocity(0)
    , direction(0)
    , positionError(0)  {
    }
  EziServoActualMotion_(const ContainerAllocator& _alloc)
    : position(0)
    , velocity(0)
    , direction(0)
    , positionError(0)  {
  (void)_alloc;
    }



   typedef int32_t _position_type;
  _position_type position;

   typedef int32_t _velocity_type;
  _velocity_type velocity;

   typedef int8_t _direction_type;
  _direction_type direction;

   typedef int32_t _positionError_type;
  _positionError_type positionError;





  typedef boost::shared_ptr< ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator> const> ConstPtr;

}; // struct EziServoActualMotion_

typedef ::custom_msg_pkg::EziServoActualMotion_<std::allocator<void> > EziServoActualMotion;

typedef boost::shared_ptr< ::custom_msg_pkg::EziServoActualMotion > EziServoActualMotionPtr;
typedef boost::shared_ptr< ::custom_msg_pkg::EziServoActualMotion const> EziServoActualMotionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace custom_msg_pkg

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'custom_msg_pkg': ['/home/michal/catkin_ws/src/custom_msg_pkg/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator> >
{
  static const char* value()
  {
    return "daeaf4d99ce00a9fa73523e8fd77742c";
  }

  static const char* value(const ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xdaeaf4d99ce00a9fULL;
  static const uint64_t static_value2 = 0xa73523e8fd77742cULL;
};

template<class ContainerAllocator>
struct DataType< ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator> >
{
  static const char* value()
  {
    return "custom_msg_pkg/EziServoActualMotion";
  }

  static const char* value(const ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 position\n\
int32 velocity\n\
int8 direction\n\
int32 positionError\n\
\n\
";
  }

  static const char* value(const ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.position);
      stream.next(m.velocity);
      stream.next(m.direction);
      stream.next(m.positionError);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct EziServoActualMotion_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::custom_msg_pkg::EziServoActualMotion_<ContainerAllocator>& v)
  {
    s << indent << "position: ";
    Printer<int32_t>::stream(s, indent + "  ", v.position);
    s << indent << "velocity: ";
    Printer<int32_t>::stream(s, indent + "  ", v.velocity);
    s << indent << "direction: ";
    Printer<int8_t>::stream(s, indent + "  ", v.direction);
    s << indent << "positionError: ";
    Printer<int32_t>::stream(s, indent + "  ", v.positionError);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CUSTOM_MSG_PKG_MESSAGE_EZISERVOACTUALMOTION_H
