// Generated by gencpp from file custom_msg_pkg/SCNChangeStateServiceMsgResponse.msg
// DO NOT EDIT!


#ifndef CUSTOM_MSG_PKG_MESSAGE_SCNCHANGESTATESERVICEMSGRESPONSE_H
#define CUSTOM_MSG_PKG_MESSAGE_SCNCHANGESTATESERVICEMSGRESPONSE_H


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
struct SCNChangeStateServiceMsgResponse_
{
  typedef SCNChangeStateServiceMsgResponse_<ContainerAllocator> Type;

  SCNChangeStateServiceMsgResponse_()
    : result(0)
    , errorDesc()  {
    }
  SCNChangeStateServiceMsgResponse_(const ContainerAllocator& _alloc)
    : result(0)
    , errorDesc(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _result_type;
  _result_type result;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _errorDesc_type;
  _errorDesc_type errorDesc;





  typedef boost::shared_ptr< ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SCNChangeStateServiceMsgResponse_

typedef ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<std::allocator<void> > SCNChangeStateServiceMsgResponse;

typedef boost::shared_ptr< ::custom_msg_pkg::SCNChangeStateServiceMsgResponse > SCNChangeStateServiceMsgResponsePtr;
typedef boost::shared_ptr< ::custom_msg_pkg::SCNChangeStateServiceMsgResponse const> SCNChangeStateServiceMsgResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace custom_msg_pkg

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "97ca5a82af8b07afaf006f10bd1c483d";
  }

  static const char* value(const ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x97ca5a82af8b07afULL;
  static const uint64_t static_value2 = 0xaf006f10bd1c483dULL;
};

template<class ContainerAllocator>
struct DataType< ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "custom_msg_pkg/SCNChangeStateServiceMsgResponse";
  }

  static const char* value(const ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 result\n\
string errorDesc\n\
\n\
";
  }

  static const char* value(const ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
      stream.next(m.errorDesc);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SCNChangeStateServiceMsgResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::custom_msg_pkg::SCNChangeStateServiceMsgResponse_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<int32_t>::stream(s, indent + "  ", v.result);
    s << indent << "errorDesc: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.errorDesc);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CUSTOM_MSG_PKG_MESSAGE_SCNCHANGESTATESERVICEMSGRESPONSE_H