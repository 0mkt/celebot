;; Auto-generated. Do not edit!


(when (boundp 'custom_msg_pkg::EziServosData)
  (if (not (find-package "CUSTOM_MSG_PKG"))
    (make-package "CUSTOM_MSG_PKG"))
  (shadow 'EziServosData (find-package "CUSTOM_MSG_PKG")))
(unless (find-package "CUSTOM_MSG_PKG::EZISERVOSDATA")
  (make-package "CUSTOM_MSG_PKG::EZISERVOSDATA"))

(in-package "ROS")
;;//! \htmlinclude EziServosData.msg.html


(defclass custom_msg_pkg::EziServosData
  :super ros::object
  :slots (_eziServoData ))

(defmethod custom_msg_pkg::EziServosData
  (:init
   (&key
    ((:eziServoData __eziServoData) (let (r) (dotimes (i 0) (push (instance custom_msg_pkg::EziServoData :init) r)) r))
    )
   (send-super :init)
   (setq _eziServoData __eziServoData)
   self)
  (:eziServoData
   (&rest __eziServoData)
   (if (keywordp (car __eziServoData))
       (send* _eziServoData __eziServoData)
     (progn
       (if __eziServoData (setq _eziServoData (car __eziServoData)))
       _eziServoData)))
  (:serialization-length
   ()
   (+
    ;; custom_msg_pkg/EziServoData[] _eziServoData
    (apply #'+ (send-all _eziServoData :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; custom_msg_pkg/EziServoData[] _eziServoData
     (write-long (length _eziServoData) s)
     (dolist (elem _eziServoData)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; custom_msg_pkg/EziServoData[] _eziServoData
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _eziServoData (let (r) (dotimes (i n) (push (instance custom_msg_pkg::EziServoData :init) r)) r))
     (dolist (elem- _eziServoData)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get custom_msg_pkg::EziServosData :md5sum-) "a1386091f448a56ae9b0d394c1619d91")
(setf (get custom_msg_pkg::EziServosData :datatype-) "custom_msg_pkg/EziServosData")
(setf (get custom_msg_pkg::EziServosData :definition-)
      "EziServoData[] eziServoData

================================================================================
MSG: custom_msg_pkg/EziServoData
string ipAddress
EziServoStatus status
EziServoActualMotion actualMotion


================================================================================
MSG: custom_msg_pkg/EziServoStatus
bool connected
bool enabled
bool alarm
bool emergency
bool stopping 
bool moving



================================================================================
MSG: custom_msg_pkg/EziServoActualMotion
int32 position
int32 velocity
int8 direction
int32 positionError


")



(provide :custom_msg_pkg/EziServosData "a1386091f448a56ae9b0d394c1619d91")


