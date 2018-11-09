; Auto-generated. Do not edit!


(cl:in-package custom_msg_pkg-msg)


;//! \htmlinclude EziServosData.msg.html

(cl:defclass <EziServosData> (roslisp-msg-protocol:ros-message)
  ((eziServoData
    :reader eziServoData
    :initarg :eziServoData
    :type (cl:vector custom_msg_pkg-msg:EziServoData)
   :initform (cl:make-array 0 :element-type 'custom_msg_pkg-msg:EziServoData :initial-element (cl:make-instance 'custom_msg_pkg-msg:EziServoData))))
)

(cl:defclass EziServosData (<EziServosData>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EziServosData>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EziServosData)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msg_pkg-msg:<EziServosData> is deprecated: use custom_msg_pkg-msg:EziServosData instead.")))

(cl:ensure-generic-function 'eziServoData-val :lambda-list '(m))
(cl:defmethod eziServoData-val ((m <EziServosData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-msg:eziServoData-val is deprecated.  Use custom_msg_pkg-msg:eziServoData instead.")
  (eziServoData m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EziServosData>) ostream)
  "Serializes a message object of type '<EziServosData>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'eziServoData))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'eziServoData))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EziServosData>) istream)
  "Deserializes a message object of type '<EziServosData>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'eziServoData) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'eziServoData)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'custom_msg_pkg-msg:EziServoData))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EziServosData>)))
  "Returns string type for a message object of type '<EziServosData>"
  "custom_msg_pkg/EziServosData")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EziServosData)))
  "Returns string type for a message object of type 'EziServosData"
  "custom_msg_pkg/EziServosData")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EziServosData>)))
  "Returns md5sum for a message object of type '<EziServosData>"
  "a1386091f448a56ae9b0d394c1619d91")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EziServosData)))
  "Returns md5sum for a message object of type 'EziServosData"
  "a1386091f448a56ae9b0d394c1619d91")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EziServosData>)))
  "Returns full string definition for message of type '<EziServosData>"
  (cl:format cl:nil "EziServoData[] eziServoData~%~%================================================================================~%MSG: custom_msg_pkg/EziServoData~%string ipAddress~%EziServoStatus status~%EziServoActualMotion actualMotion~%~%~%================================================================================~%MSG: custom_msg_pkg/EziServoStatus~%bool connected~%bool enabled~%bool alarm~%bool emergency~%bool stopping ~%bool moving~%~%~%~%================================================================================~%MSG: custom_msg_pkg/EziServoActualMotion~%int32 position~%int32 velocity~%int8 direction~%int32 positionError~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EziServosData)))
  "Returns full string definition for message of type 'EziServosData"
  (cl:format cl:nil "EziServoData[] eziServoData~%~%================================================================================~%MSG: custom_msg_pkg/EziServoData~%string ipAddress~%EziServoStatus status~%EziServoActualMotion actualMotion~%~%~%================================================================================~%MSG: custom_msg_pkg/EziServoStatus~%bool connected~%bool enabled~%bool alarm~%bool emergency~%bool stopping ~%bool moving~%~%~%~%================================================================================~%MSG: custom_msg_pkg/EziServoActualMotion~%int32 position~%int32 velocity~%int8 direction~%int32 positionError~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EziServosData>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'eziServoData) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EziServosData>))
  "Converts a ROS message object to a list"
  (cl:list 'EziServosData
    (cl:cons ':eziServoData (eziServoData msg))
))
