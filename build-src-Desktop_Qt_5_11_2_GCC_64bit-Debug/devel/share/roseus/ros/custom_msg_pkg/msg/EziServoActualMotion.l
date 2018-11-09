;; Auto-generated. Do not edit!


(when (boundp 'custom_msg_pkg::EziServoActualMotion)
  (if (not (find-package "CUSTOM_MSG_PKG"))
    (make-package "CUSTOM_MSG_PKG"))
  (shadow 'EziServoActualMotion (find-package "CUSTOM_MSG_PKG")))
(unless (find-package "CUSTOM_MSG_PKG::EZISERVOACTUALMOTION")
  (make-package "CUSTOM_MSG_PKG::EZISERVOACTUALMOTION"))

(in-package "ROS")
;;//! \htmlinclude EziServoActualMotion.msg.html


(defclass custom_msg_pkg::EziServoActualMotion
  :super ros::object
  :slots (_position _velocity _direction _positionError ))

(defmethod custom_msg_pkg::EziServoActualMotion
  (:init
   (&key
    ((:position __position) 0)
    ((:velocity __velocity) 0)
    ((:direction __direction) 0)
    ((:positionError __positionError) 0)
    )
   (send-super :init)
   (setq _position (round __position))
   (setq _velocity (round __velocity))
   (setq _direction (round __direction))
   (setq _positionError (round __positionError))
   self)
  (:position
   (&optional __position)
   (if __position (setq _position __position)) _position)
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:direction
   (&optional __direction)
   (if __direction (setq _direction __direction)) _direction)
  (:positionError
   (&optional __positionError)
   (if __positionError (setq _positionError __positionError)) _positionError)
  (:serialization-length
   ()
   (+
    ;; int32 _position
    4
    ;; int32 _velocity
    4
    ;; int8 _direction
    1
    ;; int32 _positionError
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _position
       (write-long _position s)
     ;; int32 _velocity
       (write-long _velocity s)
     ;; int8 _direction
       (write-byte _direction s)
     ;; int32 _positionError
       (write-long _positionError s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _position
     (setq _position (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _velocity
     (setq _velocity (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int8 _direction
     (setq _direction (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _direction 127) (setq _direction (- _direction 256)))
   ;; int32 _positionError
     (setq _positionError (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get custom_msg_pkg::EziServoActualMotion :md5sum-) "daeaf4d99ce00a9fa73523e8fd77742c")
(setf (get custom_msg_pkg::EziServoActualMotion :datatype-) "custom_msg_pkg/EziServoActualMotion")
(setf (get custom_msg_pkg::EziServoActualMotion :definition-)
      "int32 position
int32 velocity
int8 direction
int32 positionError


")



(provide :custom_msg_pkg/EziServoActualMotion "daeaf4d99ce00a9fa73523e8fd77742c")


