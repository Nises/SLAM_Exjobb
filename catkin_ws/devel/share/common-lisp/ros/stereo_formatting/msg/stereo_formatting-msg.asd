
(cl:in-package :asdf)

(defsystem "stereo_formatting-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :sensor_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "CompStereo" :depends-on ("_package_CompStereo"))
    (:file "_package_CompStereo" :depends-on ("_package"))
  ))