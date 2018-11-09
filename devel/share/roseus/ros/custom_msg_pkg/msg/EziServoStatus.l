;; Auto-generated. Do not edit!


(when (boundp 'custom_msg_pkg::EziServoStatus)
  (if (not (find-package "CUSTOM_MSG_PKG"))
    (make-package "CUSTOM_MSG_PKG"))
  (shadow 'EziServoStatus (find-package "CUSTOM_MSG_PKG")))
(unless (find-package "CUSTOM_MSG_PKG::EZISERVOSTATUS")
  (make-package "CUSTOM_MSG_PKG::EZISERVOSTATUS"))

(in-package "ROS")
;;//! \htmlinclude EziServoStatus.msg.html


(defclass custom_msg_pkg::EziServoStatus
  :super ros::object
  :slots (_connected _enabled _alarm _emergency _stopping _moving ))

(defmethod custom_msg_pkg::EziServoStatus
  (:init
   (&key
    ((:connected __connected) nil)
    ((:enabled __enabled) nil)
    ((:alarm __alarm) nil)
    ((:emergency __emergency) nil)
    ((:stopping __stopping) nil)
    ((:moving __moving) nil)
    )
   (send-super :init)
   (setq _connected __connected)
   (setq _enabled __enabled)
   (setq _alarm __alarm)
   (setq _emergency __emergency)
   (setq _stopping __stopping)
   (setq _moving __moving)
   self)
  (:connected
   (&optional __connected)
   (if __connected (setq _connected __connected)) _connected)
  (:enabled
   (&optional __enabled)
   (if __enabled (setq _enabled __enabled)) _enabled)
  (:alarm
   (&optional __alarm)
   (if __alarm (setq _alarm __alarm)) _alarm)
  (:emergency
   (&optional __emergency)
   (if __emergency (setq _emergency __emergency)) _emergency)
  (:stopping
   (&optional __stopping)
   (if __stopping (setq _stopping __stopping)) _stopping)
  (:moving
   (&optional __moving)
   (if __moving (setq _moving __moving)) _moving)
  (:serialization-length
   ()
   (+
    ;; bool _connected
    1
    ;; bool _enabled
    1
    ;; bool _alarm
    1
    ;; bool _emergency
    1
    ;; bool _stopping
    1
    ;; bool _moving
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _connected
       (if _connected (write-byte -1 s) (write-byte 0 s))
     ;; bool _enabled
       (if _enabled (write-byte -1 s) (write-byte 0 s))
     ;; bool _alarm
       (if _alarm (write-byte -1 s) (write-byte 0 s))
     ;; bool _emergency
       (if _emergency (write-byte -1 s) (write-byte 0 s))
     ;; bool _stopping
       (if _stopping (write-byte -1 s) (write-byte 0 s))
     ;; bool _moving
       (if _moving (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _connected
     (setq _connected (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _enabled
     (setq _enabled (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _alarm
     (setq _alarm (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _emergency
     (setq _emergency (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _stopping
     (setq _stopping (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _moving
     (setq _moving (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get custom_msg_pkg::EziServoStatus :md5sum-) "f22805727de3ca4b7981acde30ca7355")
(setf (get custom_msg_pkg::EziServoStatus :datatype-) "custom_msg_pkg/EziServoStatus")
(setf (get custom_msg_pkg::EziServoStatus :definition-)
      "bool connected
bool enabled
bool alarm
bool emergency
bool stopping 
bool moving



")



(provide :custom_msg_pkg/EziServoStatus "f22805727de3ca4b7981acde30ca7355")


