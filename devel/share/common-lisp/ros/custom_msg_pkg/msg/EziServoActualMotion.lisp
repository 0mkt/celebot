; Auto-generated. Do not edit!


(cl:in-package custom_msg_pkg-msg)


;//! \htmlinclude EziServoActualMotion.msg.html

(cl:defclass <EziServoActualMotion> (roslisp-msg-protocol:ros-message)
  ((position
    :reader position
    :initarg :position
    :type cl:integer
    :initform 0)
   (velocity
    :reader velocity
    :initarg :velocity
    :type cl:integer
    :initform 0)
   (direction
    :reader direction
    :initarg :direction
    :type cl:fixnum
    :initform 0)
   (positionError
    :reader positionError
    :initarg :positionError
    :type cl:integer
    :initform 0))
)

(cl:defclass EziServoActualMotion (<EziServoActualMotion>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EziServoActualMotion>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EziServoActualMotion)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msg_pkg-msg:<EziServoActualMotion> is deprecated: use custom_msg_pkg-msg:EziServoActualMotion instead.")))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <EziServoActualMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-msg:position-val is deprecated.  Use custom_msg_pkg-msg:position instead.")
  (position m))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <EziServoActualMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-msg:velocity-val is deprecated.  Use custom_msg_pkg-msg:velocity instead.")
  (velocity m))

(cl:ensure-generic-function 'direction-val :lambda-list '(m))
(cl:defmethod direction-val ((m <EziServoActualMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-msg:direction-val is deprecated.  Use custom_msg_pkg-msg:direction instead.")
  (direction m))

(cl:ensure-generic-function 'positionError-val :lambda-list '(m))
(cl:defmethod positionError-val ((m <EziServoActualMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-msg:positionError-val is deprecated.  Use custom_msg_pkg-msg:positionError instead.")
  (positionError m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EziServoActualMotion>) ostream)
  "Serializes a message object of type '<EziServoActualMotion>"
  (cl:let* ((signed (cl:slot-value msg 'position)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'velocity)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'direction)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'positionError)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EziServoActualMotion>) istream)
  "Deserializes a message object of type '<EziServoActualMotion>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'position) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'velocity) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'direction) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'positionError) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EziServoActualMotion>)))
  "Returns string type for a message object of type '<EziServoActualMotion>"
  "custom_msg_pkg/EziServoActualMotion")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EziServoActualMotion)))
  "Returns string type for a message object of type 'EziServoActualMotion"
  "custom_msg_pkg/EziServoActualMotion")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EziServoActualMotion>)))
  "Returns md5sum for a message object of type '<EziServoActualMotion>"
  "daeaf4d99ce00a9fa73523e8fd77742c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EziServoActualMotion)))
  "Returns md5sum for a message object of type 'EziServoActualMotion"
  "daeaf4d99ce00a9fa73523e8fd77742c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EziServoActualMotion>)))
  "Returns full string definition for message of type '<EziServoActualMotion>"
  (cl:format cl:nil "int32 position~%int32 velocity~%int8 direction~%int32 positionError~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EziServoActualMotion)))
  "Returns full string definition for message of type 'EziServoActualMotion"
  (cl:format cl:nil "int32 position~%int32 velocity~%int8 direction~%int32 positionError~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EziServoActualMotion>))
  (cl:+ 0
     4
     4
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EziServoActualMotion>))
  "Converts a ROS message object to a list"
  (cl:list 'EziServoActualMotion
    (cl:cons ':position (position msg))
    (cl:cons ':velocity (velocity msg))
    (cl:cons ':direction (direction msg))
    (cl:cons ':positionError (positionError msg))
))
