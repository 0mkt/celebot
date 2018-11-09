; Auto-generated. Do not edit!


(cl:in-package custom_msg_pkg-msg)


;//! \htmlinclude EziServoStatus.msg.html

(cl:defclass <EziServoStatus> (roslisp-msg-protocol:ros-message)
  ((connected
    :reader connected
    :initarg :connected
    :type cl:boolean
    :initform cl:nil)
   (enabled
    :reader enabled
    :initarg :enabled
    :type cl:boolean
    :initform cl:nil)
   (alarm
    :reader alarm
    :initarg :alarm
    :type cl:boolean
    :initform cl:nil)
   (emergency
    :reader emergency
    :initarg :emergency
    :type cl:boolean
    :initform cl:nil)
   (stopping
    :reader stopping
    :initarg :stopping
    :type cl:boolean
    :initform cl:nil)
   (moving
    :reader moving
    :initarg :moving
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass EziServoStatus (<EziServoStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EziServoStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EziServoStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msg_pkg-msg:<EziServoStatus> is deprecated: use custom_msg_pkg-msg:EziServoStatus instead.")))

(cl:ensure-generic-function 'connected-val :lambda-list '(m))
(cl:defmethod connected-val ((m <EziServoStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-msg:connected-val is deprecated.  Use custom_msg_pkg-msg:connected instead.")
  (connected m))

(cl:ensure-generic-function 'enabled-val :lambda-list '(m))
(cl:defmethod enabled-val ((m <EziServoStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-msg:enabled-val is deprecated.  Use custom_msg_pkg-msg:enabled instead.")
  (enabled m))

(cl:ensure-generic-function 'alarm-val :lambda-list '(m))
(cl:defmethod alarm-val ((m <EziServoStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-msg:alarm-val is deprecated.  Use custom_msg_pkg-msg:alarm instead.")
  (alarm m))

(cl:ensure-generic-function 'emergency-val :lambda-list '(m))
(cl:defmethod emergency-val ((m <EziServoStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-msg:emergency-val is deprecated.  Use custom_msg_pkg-msg:emergency instead.")
  (emergency m))

(cl:ensure-generic-function 'stopping-val :lambda-list '(m))
(cl:defmethod stopping-val ((m <EziServoStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-msg:stopping-val is deprecated.  Use custom_msg_pkg-msg:stopping instead.")
  (stopping m))

(cl:ensure-generic-function 'moving-val :lambda-list '(m))
(cl:defmethod moving-val ((m <EziServoStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-msg:moving-val is deprecated.  Use custom_msg_pkg-msg:moving instead.")
  (moving m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EziServoStatus>) ostream)
  "Serializes a message object of type '<EziServoStatus>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'connected) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'enabled) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'alarm) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'emergency) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'stopping) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'moving) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EziServoStatus>) istream)
  "Deserializes a message object of type '<EziServoStatus>"
    (cl:setf (cl:slot-value msg 'connected) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'enabled) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'alarm) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'emergency) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'stopping) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'moving) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EziServoStatus>)))
  "Returns string type for a message object of type '<EziServoStatus>"
  "custom_msg_pkg/EziServoStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EziServoStatus)))
  "Returns string type for a message object of type 'EziServoStatus"
  "custom_msg_pkg/EziServoStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EziServoStatus>)))
  "Returns md5sum for a message object of type '<EziServoStatus>"
  "f22805727de3ca4b7981acde30ca7355")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EziServoStatus)))
  "Returns md5sum for a message object of type 'EziServoStatus"
  "f22805727de3ca4b7981acde30ca7355")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EziServoStatus>)))
  "Returns full string definition for message of type '<EziServoStatus>"
  (cl:format cl:nil "bool connected~%bool enabled~%bool alarm~%bool emergency~%bool stopping ~%bool moving~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EziServoStatus)))
  "Returns full string definition for message of type 'EziServoStatus"
  (cl:format cl:nil "bool connected~%bool enabled~%bool alarm~%bool emergency~%bool stopping ~%bool moving~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EziServoStatus>))
  (cl:+ 0
     1
     1
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EziServoStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'EziServoStatus
    (cl:cons ':connected (connected msg))
    (cl:cons ':enabled (enabled msg))
    (cl:cons ':alarm (alarm msg))
    (cl:cons ':emergency (emergency msg))
    (cl:cons ':stopping (stopping msg))
    (cl:cons ':moving (moving msg))
))
