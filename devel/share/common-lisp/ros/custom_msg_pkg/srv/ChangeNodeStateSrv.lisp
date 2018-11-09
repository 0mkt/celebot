; Auto-generated. Do not edit!


(cl:in-package custom_msg_pkg-srv)


;//! \htmlinclude ChangeNodeStateSrv-request.msg.html

(cl:defclass <ChangeNodeStateSrv-request> (roslisp-msg-protocol:ros-message)
  ((targetState
    :reader targetState
    :initarg :targetState
    :type cl:integer
    :initform 0)
   (callerId
    :reader callerId
    :initarg :callerId
    :type cl:integer
    :initform 0))
)

(cl:defclass ChangeNodeStateSrv-request (<ChangeNodeStateSrv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ChangeNodeStateSrv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ChangeNodeStateSrv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msg_pkg-srv:<ChangeNodeStateSrv-request> is deprecated: use custom_msg_pkg-srv:ChangeNodeStateSrv-request instead.")))

(cl:ensure-generic-function 'targetState-val :lambda-list '(m))
(cl:defmethod targetState-val ((m <ChangeNodeStateSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-srv:targetState-val is deprecated.  Use custom_msg_pkg-srv:targetState instead.")
  (targetState m))

(cl:ensure-generic-function 'callerId-val :lambda-list '(m))
(cl:defmethod callerId-val ((m <ChangeNodeStateSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-srv:callerId-val is deprecated.  Use custom_msg_pkg-srv:callerId instead.")
  (callerId m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ChangeNodeStateSrv-request>) ostream)
  "Serializes a message object of type '<ChangeNodeStateSrv-request>"
  (cl:let* ((signed (cl:slot-value msg 'targetState)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'callerId)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ChangeNodeStateSrv-request>) istream)
  "Deserializes a message object of type '<ChangeNodeStateSrv-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'targetState) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'callerId) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ChangeNodeStateSrv-request>)))
  "Returns string type for a service object of type '<ChangeNodeStateSrv-request>"
  "custom_msg_pkg/ChangeNodeStateSrvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ChangeNodeStateSrv-request)))
  "Returns string type for a service object of type 'ChangeNodeStateSrv-request"
  "custom_msg_pkg/ChangeNodeStateSrvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ChangeNodeStateSrv-request>)))
  "Returns md5sum for a message object of type '<ChangeNodeStateSrv-request>"
  "e7cf3a237ea1ba28a266b276ffbdbbae")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ChangeNodeStateSrv-request)))
  "Returns md5sum for a message object of type 'ChangeNodeStateSrv-request"
  "e7cf3a237ea1ba28a266b276ffbdbbae")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ChangeNodeStateSrv-request>)))
  "Returns full string definition for message of type '<ChangeNodeStateSrv-request>"
  (cl:format cl:nil "int32 targetState~%int32 callerId~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ChangeNodeStateSrv-request)))
  "Returns full string definition for message of type 'ChangeNodeStateSrv-request"
  (cl:format cl:nil "int32 targetState~%int32 callerId~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ChangeNodeStateSrv-request>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ChangeNodeStateSrv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ChangeNodeStateSrv-request
    (cl:cons ':targetState (targetState msg))
    (cl:cons ':callerId (callerId msg))
))
;//! \htmlinclude ChangeNodeStateSrv-response.msg.html

(cl:defclass <ChangeNodeStateSrv-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:integer
    :initform 0)
   (errorDesc
    :reader errorDesc
    :initarg :errorDesc
    :type cl:string
    :initform ""))
)

(cl:defclass ChangeNodeStateSrv-response (<ChangeNodeStateSrv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ChangeNodeStateSrv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ChangeNodeStateSrv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msg_pkg-srv:<ChangeNodeStateSrv-response> is deprecated: use custom_msg_pkg-srv:ChangeNodeStateSrv-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <ChangeNodeStateSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-srv:result-val is deprecated.  Use custom_msg_pkg-srv:result instead.")
  (result m))

(cl:ensure-generic-function 'errorDesc-val :lambda-list '(m))
(cl:defmethod errorDesc-val ((m <ChangeNodeStateSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg_pkg-srv:errorDesc-val is deprecated.  Use custom_msg_pkg-srv:errorDesc instead.")
  (errorDesc m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ChangeNodeStateSrv-response>) ostream)
  "Serializes a message object of type '<ChangeNodeStateSrv-response>"
  (cl:let* ((signed (cl:slot-value msg 'result)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'errorDesc))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'errorDesc))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ChangeNodeStateSrv-response>) istream)
  "Deserializes a message object of type '<ChangeNodeStateSrv-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'result) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'errorDesc) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'errorDesc) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ChangeNodeStateSrv-response>)))
  "Returns string type for a service object of type '<ChangeNodeStateSrv-response>"
  "custom_msg_pkg/ChangeNodeStateSrvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ChangeNodeStateSrv-response)))
  "Returns string type for a service object of type 'ChangeNodeStateSrv-response"
  "custom_msg_pkg/ChangeNodeStateSrvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ChangeNodeStateSrv-response>)))
  "Returns md5sum for a message object of type '<ChangeNodeStateSrv-response>"
  "e7cf3a237ea1ba28a266b276ffbdbbae")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ChangeNodeStateSrv-response)))
  "Returns md5sum for a message object of type 'ChangeNodeStateSrv-response"
  "e7cf3a237ea1ba28a266b276ffbdbbae")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ChangeNodeStateSrv-response>)))
  "Returns full string definition for message of type '<ChangeNodeStateSrv-response>"
  (cl:format cl:nil "int32 result~%string errorDesc~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ChangeNodeStateSrv-response)))
  "Returns full string definition for message of type 'ChangeNodeStateSrv-response"
  (cl:format cl:nil "int32 result~%string errorDesc~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ChangeNodeStateSrv-response>))
  (cl:+ 0
     4
     4 (cl:length (cl:slot-value msg 'errorDesc))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ChangeNodeStateSrv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ChangeNodeStateSrv-response
    (cl:cons ':result (result msg))
    (cl:cons ':errorDesc (errorDesc msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ChangeNodeStateSrv)))
  'ChangeNodeStateSrv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ChangeNodeStateSrv)))
  'ChangeNodeStateSrv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ChangeNodeStateSrv)))
  "Returns string type for a service object of type '<ChangeNodeStateSrv>"
  "custom_msg_pkg/ChangeNodeStateSrv")