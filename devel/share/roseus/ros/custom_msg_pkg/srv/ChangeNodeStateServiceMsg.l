;; Auto-generated. Do not edit!


(when (boundp 'custom_msg_pkg::ChangeNodeStateServiceMsg)
  (if (not (find-package "CUSTOM_MSG_PKG"))
    (make-package "CUSTOM_MSG_PKG"))
  (shadow 'ChangeNodeStateServiceMsg (find-package "CUSTOM_MSG_PKG")))
(unless (find-package "CUSTOM_MSG_PKG::CHANGENODESTATESERVICEMSG")
  (make-package "CUSTOM_MSG_PKG::CHANGENODESTATESERVICEMSG"))
(unless (find-package "CUSTOM_MSG_PKG::CHANGENODESTATESERVICEMSGREQUEST")
  (make-package "CUSTOM_MSG_PKG::CHANGENODESTATESERVICEMSGREQUEST"))
(unless (find-package "CUSTOM_MSG_PKG::CHANGENODESTATESERVICEMSGRESPONSE")
  (make-package "CUSTOM_MSG_PKG::CHANGENODESTATESERVICEMSGRESPONSE"))

(in-package "ROS")





(defclass custom_msg_pkg::ChangeNodeStateServiceMsgRequest
  :super ros::object
  :slots (_targetState _callerId ))

(defmethod custom_msg_pkg::ChangeNodeStateServiceMsgRequest
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

(defclass custom_msg_pkg::ChangeNodeStateServiceMsgResponse
  :super ros::object
  :slots (_result _errorDesc ))

(defmethod custom_msg_pkg::ChangeNodeStateServiceMsgResponse
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

(defclass custom_msg_pkg::ChangeNodeStateServiceMsg
  :super ros::object
  :slots ())

(setf (get custom_msg_pkg::ChangeNodeStateServiceMsg :md5sum-) "e7cf3a237ea1ba28a266b276ffbdbbae")
(setf (get custom_msg_pkg::ChangeNodeStateServiceMsg :datatype-) "custom_msg_pkg/ChangeNodeStateServiceMsg")
(setf (get custom_msg_pkg::ChangeNodeStateServiceMsg :request) custom_msg_pkg::ChangeNodeStateServiceMsgRequest)
(setf (get custom_msg_pkg::ChangeNodeStateServiceMsg :response) custom_msg_pkg::ChangeNodeStateServiceMsgResponse)

(defmethod custom_msg_pkg::ChangeNodeStateServiceMsgRequest
  (:response () (instance custom_msg_pkg::ChangeNodeStateServiceMsgResponse :init)))

(setf (get custom_msg_pkg::ChangeNodeStateServiceMsgRequest :md5sum-) "e7cf3a237ea1ba28a266b276ffbdbbae")
(setf (get custom_msg_pkg::ChangeNodeStateServiceMsgRequest :datatype-) "custom_msg_pkg/ChangeNodeStateServiceMsgRequest")
(setf (get custom_msg_pkg::ChangeNodeStateServiceMsgRequest :definition-)
      "int32 targetState
int32 callerId
---
int32 result
string errorDesc

")

(setf (get custom_msg_pkg::ChangeNodeStateServiceMsgResponse :md5sum-) "e7cf3a237ea1ba28a266b276ffbdbbae")
(setf (get custom_msg_pkg::ChangeNodeStateServiceMsgResponse :datatype-) "custom_msg_pkg/ChangeNodeStateServiceMsgResponse")
(setf (get custom_msg_pkg::ChangeNodeStateServiceMsgResponse :definition-)
      "int32 targetState
int32 callerId
---
int32 result
string errorDesc

")



(provide :custom_msg_pkg/ChangeNodeStateServiceMsg "e7cf3a237ea1ba28a266b276ffbdbbae")


