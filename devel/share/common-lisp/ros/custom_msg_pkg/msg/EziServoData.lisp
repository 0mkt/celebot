; Auto-generated. Do not edit!


(cl:in-package custom_msg_pkg-msg)


;//! \htmlinclude EziServoData.msg.html

(cl:defclass <EziServoData> (roslisp-msg-protocol:ros-message)
  ((ipAddress
    :reader ipAddress
    :initarg :ipAddress
    :type cl:string
    :initform "")
   (status
    :reader status
    :initarg :status
    :type custom_msg_pkg-msg:EziServoStatus
    :initform (cl:make-instance 'custom_msg_pkg-msg:EziServoStatus))
   (actualMotion
    :reader actualMotion
    :initarg :actualMotion
    :type custom_msg_pkg-msg:EziServoActualMotion
    :initform (cl:make-instance 'custom_msg_pkg-msg:EziServoActualMotion)))
)

(cl:defclass EziServoData (<EziServoData>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EziServoData>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EziServoData)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msg_pkg-msg:<EziServoData> is deprecated: use custom_msg_pkg-msg:EziServoData instead.")))

(cl:ensure-generic-function 'ipAddress-val :lambda-list '(m))
(cl:defmethod ipAddress-val ((m <EziServoData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-msg:ipAddress-val is deprecated.  Use custom_msg_pkg-msg:ipAddress instead.")
  (ipAddress m))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <EziServoData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-msg:status-val is deprecated.  Use custom_msg_pkg-msg:status instead.")
  (status m))

(cl:ensure-generic-function 'actualMotion-val :lambda-list '(m))
(cl:defmethod actualMotion-val ((m <EziServoData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-msg:actualMotion-val is deprecated.  Use custom_msg_pkg-msg:actualMotion instead.")
  (actualMotion m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EziServoData>) ostream)
  "Serializes a message object of type '<EziServoData>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'ipAddress))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'ipAddress))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'status) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'actualMotion) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EziServoData>) istream)
  "Deserializes a message object of type '<EziServoData>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ipAddress) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'ipAddress) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'status) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'actualMotion) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EziServoData>)))
  "Returns string type for a message object of type '<EziServoData>"
  "custom_msg_pkg/EziServoData")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EziServoData)))
  "Returns string type for a message object of type 'EziServoData"
  "custom_msg_pkg/EziServoData")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EziServoData>)))
  "Returns md5sum for a message object of type '<EziServoData>"
  "70843f32172de7329088dc42b06b7545")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EziServoData)))
  "Returns md5sum for a message object of type 'EziServoData"
  "70843f32172de7329088dc42b06b7545")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EziServoData>)))
  "Returns full string definition for message of type '<EziServoData>"
  (cl:format cl:nil "string ipAddress~%EziServoStatus status~%EziServoActualMotion actualMotion~%~%~%================================================================================~%MSG: custom_msg_pkg/EziServoStatus~%bool connected~%bool enabled~%bool alarm~%bool emergency~%bool stopping ~%bool moving~%~%~%~%================================================================================~%MSG: custom_msg_pkg/EziServoActualMotion~%int32 position~%int32 velocity~%int8 direction~%int32 positionError~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EziServoData)))
  "Returns full string definition for message of type 'EziServoData"
  (cl:format cl:nil "string ipAddress~%EziServoStatus status~%EziServoActualMotion actualMotion~%~%~%================================================================================~%MSG: custom_msg_pkg/EziServoStatus~%bool connected~%bool enabled~%bool alarm~%bool emergency~%bool stopping ~%bool moving~%~%~%~%================================================================================~%MSG: custom_msg_pkg/EziServoActualMotion~%int32 position~%int32 velocity~%int8 direction~%int32 positionError~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EziServoData>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'ipAddress))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'status))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'actualMotion))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EziServoData>))
  "Converts a ROS message object to a list"
  (cl:list 'EziServoData
    (cl:cons ':ipAddress (ipAddress msg))
    (cl:cons ':status (status msg))
    (cl:cons ':actualMotion (actualMotion msg))
))
