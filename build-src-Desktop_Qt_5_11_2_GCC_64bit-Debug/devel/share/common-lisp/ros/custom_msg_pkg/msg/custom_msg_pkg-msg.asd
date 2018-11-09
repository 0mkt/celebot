
(cl:in-package :asdf)

(defsystem "custom_msg_pkg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "EziServoActualMotion" :depends-on ("_package_EziServoActualMotion"))
    (:file "_package_EziServoActualMotion" :depends-on ("_package"))
    (:file "EziServoData" :depends-on ("_package_EziServoData"))
    (:file "_package_EziServoData" :depends-on ("_package"))
    (:file "EziServoStatus" :depends-on ("_package_EziServoStatus"))
    (:file "_package_EziServoStatus" :depends-on ("_package"))
    (:file "EziServosData" :depends-on ("_package_EziServosData"))
    (:file "_package_EziServosData" :depends-on ("_package"))
  ))