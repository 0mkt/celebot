;; Auto-generated. Do not edit!


(when (boundp 'custom_msg_pkg::EziServoData)
  (if (not (find-package "CUSTOM_MSG_PKG"))
    (make-package "CUSTOM_MSG_PKG"))
  (shadow 'EziServoData (find-package "CUSTOM_MSG_PKG")))
(unless (find-package "CUSTOM_MSG_PKG::EZISERVODATA")
  (make-package "CUSTOM_MSG_PKG::EZISERVODATA"))

(in-package "ROS")
;;//! \htmlinclude EziServoData.msg.html


(defclass custom_msg_pkg::EziServoData
  :super ros::object
  :slots (_ipAddress _status _actualMotion ))

(defmethod custom_msg_pkg::EziServoData
  (:init
   (&key
    ((:ipAddress __ipAddress) "")
    ((:status __status) (instance custom_msg_pkg::EziServoStatus :init))
    ((:actualMotion __actualMotion) (instance custom_msg_pkg::EziServoActualMotion :init))
    )
   (send-super :init)
   (setq _ipAddress (string __ipAddress))
   (setq _status __status)
   (setq _actualMotion __actualMotion)
   self)
  (:ipAddress
   (&optional __ipAddress)
   (if __ipAddress (setq _ipAddress __ipAddress)) _ipAddress)
  (:status
   (&rest __status)
   (if (keywordp (car __status))
       (send* _status __status)
     (progn
       (if __status (setq _status (car __status)))
       _status)))
  (:actualMotion
   (&rest __actualMotion)
   (if (keywordp (car __actualMotion))
       (send* _actualMotion __actualMotion)
     (progn
       (if __actualMotion (setq _actualMotion (car __actualMotion)))
       _actualMotion)))
  (:serialization-length
   ()
   (+
    ;; string _ipAddress
    4 (length _ipAddress)
    ;; custom_msg_pkg/EziServoStatus _status
    (send _status :serialization-length)
    ;; custom_msg_pkg/EziServoActualMotion _actualMotion
    (send _actualMotion :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _ipAddress
       (write-long (length _ipAddress) s) (princ _ipAddress s)
     ;; custom_msg_pkg/EziServoStatus _status
       (send _status :serialize s)
     ;; custom_msg_pkg/EziServoActualMotion _actualMotion
       (send _actualMotion :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _ipAddress
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _ipAddress (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; custom_msg_pkg/EziServoStatus _status
     (send _status :deserialize buf ptr-) (incf ptr- (send _status :serialization-length))
   ;; custom_msg_pkg/EziServoActualMotion _actualMotion
     (send _actualMotion :deserialize buf ptr-) (incf ptr- (send _actualMotion :serialization-length))
   ;;
   self)
  )

(setf (get custom_msg_pkg::EziServoData :md5sum-) "70843f32172de7329088dc42b06b7545")
(setf (get custom_msg_pkg::EziServoData :datatype-) "custom_msg_pkg/EziServoData")
(setf (get custom_msg_pkg::EziServoData :definition-)
      "string ipAddress
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



(provide :custom_msg_pkg/EziServoData "70843f32172de7329088dc42b06b7545")


