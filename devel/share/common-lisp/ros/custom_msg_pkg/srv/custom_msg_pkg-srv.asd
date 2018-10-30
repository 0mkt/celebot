
(cl:in-package :asdf)

(defsystem "custom_msg_pkg-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "SCNChangeStateServiceMsg" :depends-on ("_package_SCNChangeStateServiceMsg"))
    (:file "_package_SCNChangeStateServiceMsg" :depends-on ("_package"))
  ))