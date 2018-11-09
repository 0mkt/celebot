
(cl:in-package :asdf)

(defsystem "custom_msg_pkg-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ChangeNodeStateSrv" :depends-on ("_package_ChangeNodeStateSrv"))
    (:file "_package_ChangeNodeStateSrv" :depends-on ("_package"))
  ))