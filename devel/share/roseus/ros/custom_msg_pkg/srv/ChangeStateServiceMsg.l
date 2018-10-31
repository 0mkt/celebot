;; Auto-generated. Do not edit!


(when (boundp 'custom_msg_pkg::ChangeStateServiceMsg)
  (if (not (find-package "CUSTOM_MSG_PKG"))
    (make-package "CUSTOM_MSG_PKG"))
  (shadow 'ChangeStateServiceMsg (find-package "CUSTOM_MSG_PKG")))
(unless (find-package "CUSTOM_MSG_PKG::CHANGESTATESERVICEMSG")
  (make-package "CUSTOM_MSG_PKG::CHANGESTATESERVICEMSG"))
(unless (find-package "CUSTOM_MSG_PKG::CHANGESTATESERVICEMSGREQUEST")
  (make-package "CUSTOM_MSG_PKG::CHANGESTATESERVICEMSGREQUEST"))
(unless (find-package "CUSTOM_MSG_PKG::CHANGESTATESERVICEMSGRESPONSE")
  (make-package "CUSTOM_MSG_PKG::CHANGESTATESERVICEMSGRESPONSE"))

(in-package "ROS")





(defclass custom_msg_pkg::ChangeStateServiceMsgRequest
  :super ros::object
  :slots (_targetState _callerId ))

(defmethod custom_msg_pkg::ChangeStateServiceMsgRequest
  (:init
   (&key
    ((:targetState __targetState) 0)
    ((:callerId __callerId) 0)
    )
   (send-super :init)
   (setq _targetState (round __targetState))
   (setq _callerId (round __callerId))
   self)
  (:targetState
   (&optional __targetState)
   (if __targetState (setq _targetState __targetState)) _targetState)
  (:callerId
   (&optional __callerId)
   (if __callerId (setq _callerId __callerId)) _callerId)
  (:serialization-length
   ()
   (+
    ;; int32 _targetState
    4
    ;; int32 _callerId
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _targetState
       (write-long _targetState s)
     ;; int32 _callerId
       (write-long _callerId s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _targetState
     (setq _targetState (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _callerId
     (setq _callerId (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass custom_msg_pkg::ChangeStateServiceMsgResponse
  :super ros::object
  :slots (_result _errorDesc ))

(defmethod custom_msg_pkg::ChangeStateServiceMsgResponse
  (:init
   (&key
    ((:result __result) 0)
    ((:errorDesc __errorDesc) "")
    )
   (send-super :init)
   (setq _result (round __result))
   (setq _errorDesc (string __errorDesc))
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:errorDesc
   (&optional __errorDesc)
   (if __errorDesc (setq _errorDesc __errorDesc)) _errorDesc)
  (:serialization-length
   ()
   (+
    ;; int32 _result
    4
    ;; string _errorDesc
    4 (length _errorDesc)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _result
       (write-long _result s)
     ;; string _errorDesc
       (write-long (length _errorDesc) s) (princ _errorDesc s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _result
     (setq _result (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _errorDesc
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _errorDesc (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass custom_msg_pkg::ChangeStateServiceMsg
  :super ros::object
  :slots ())

(setf (get custom_msg_pkg::ChangeStateServiceMsg :md5sum-) "e7cf3a237ea1ba28a266b276ffbdbbae")
(setf (get custom_msg_pkg::ChangeStateServiceMsg :datatype-) "custom_msg_pkg/ChangeStateServiceMsg")
(setf (get custom_msg_pkg::ChangeStateServiceMsg :request) custom_msg_pkg::ChangeStateServiceMsgRequest)
(setf (get custom_msg_pkg::ChangeStateServiceMsg :response) custom_msg_pkg::ChangeStateServiceMsgResponse)

(defmethod custom_msg_pkg::ChangeStateServiceMsgRequest
  (:response () (instance custom_msg_pkg::ChangeStateServiceMsgResponse :init)))

(setf (get custom_msg_pkg::ChangeStateServiceMsgRequest :md5sum-) "e7cf3a237ea1ba28a266b276ffbdbbae")
(setf (get custom_msg_pkg::ChangeStateServiceMsgRequest :datatype-) "custom_msg_pkg/ChangeStateServiceMsgRequest")
(setf (get custom_msg_pkg::ChangeStateServiceMsgRequest :definition-)
      "int32 targetState
int32 callerId
---
int32 result
string errorDesc

")

(setf (get custom_msg_pkg::ChangeStateServiceMsgResponse :md5sum-) "e7cf3a237ea1ba28a266b276ffbdbbae")
(setf (get custom_msg_pkg::ChangeStateServiceMsgResponse :datatype-) "custom_msg_pkg/ChangeStateServiceMsgResponse")
(setf (get custom_msg_pkg::ChangeStateServiceMsgResponse :definition-)
      "int32 targetState
int32 callerId
---
int32 result
string errorDesc

")



(provide :custom_msg_pkg/ChangeStateServiceMsg "e7cf3a237ea1ba28a266b276ffbdbbae")


