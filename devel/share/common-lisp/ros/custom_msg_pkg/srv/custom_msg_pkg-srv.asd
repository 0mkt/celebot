
(cl:in-package :asdf)

(defsystem "custom_msg_pkg-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ChangeNodeStateServiceMsg" :depends-on ("_package_ChangeNodeStateServiceMsg"))
    (:file "_package_ChangeNodeStateServiceMsg" :depends-on ("_package"))
  ))