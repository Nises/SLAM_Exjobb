# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "stereo_formatting: 1 messages, 0 services")

set(MSG_I_FLAGS "-Istereo_formatting:/home/marcusn/catkin_ws/src/stereo_formatting/msg;-Isensor_msgs:/opt/ros/noetic/share/sensor_msgs/cmake/../msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/noetic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(stereo_formatting_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/marcusn/catkin_ws/src/stereo_formatting/msg/CompStereo.msg" NAME_WE)
add_custom_target(_stereo_formatting_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "stereo_formatting" "/home/marcusn/catkin_ws/src/stereo_formatting/msg/CompStereo.msg" "std_msgs/Header:sensor_msgs/CameraInfo:sensor_msgs/RegionOfInterest:sensor_msgs/CompressedImage"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(stereo_formatting
  "/home/marcusn/catkin_ws/src/stereo_formatting/msg/CompStereo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/CompressedImage.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/stereo_formatting
)

### Generating Services

### Generating Module File
_generate_module_cpp(stereo_formatting
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/stereo_formatting
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(stereo_formatting_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(stereo_formatting_generate_messages stereo_formatting_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/marcusn/catkin_ws/src/stereo_formatting/msg/CompStereo.msg" NAME_WE)
add_dependencies(stereo_formatting_generate_messages_cpp _stereo_formatting_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(stereo_formatting_gencpp)
add_dependencies(stereo_formatting_gencpp stereo_formatting_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS stereo_formatting_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(stereo_formatting
  "/home/marcusn/catkin_ws/src/stereo_formatting/msg/CompStereo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/CompressedImage.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/stereo_formatting
)

### Generating Services

### Generating Module File
_generate_module_eus(stereo_formatting
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/stereo_formatting
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(stereo_formatting_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(stereo_formatting_generate_messages stereo_formatting_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/marcusn/catkin_ws/src/stereo_formatting/msg/CompStereo.msg" NAME_WE)
add_dependencies(stereo_formatting_generate_messages_eus _stereo_formatting_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(stereo_formatting_geneus)
add_dependencies(stereo_formatting_geneus stereo_formatting_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS stereo_formatting_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(stereo_formatting
  "/home/marcusn/catkin_ws/src/stereo_formatting/msg/CompStereo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/CompressedImage.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/stereo_formatting
)

### Generating Services

### Generating Module File
_generate_module_lisp(stereo_formatting
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/stereo_formatting
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(stereo_formatting_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(stereo_formatting_generate_messages stereo_formatting_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/marcusn/catkin_ws/src/stereo_formatting/msg/CompStereo.msg" NAME_WE)
add_dependencies(stereo_formatting_generate_messages_lisp _stereo_formatting_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(stereo_formatting_genlisp)
add_dependencies(stereo_formatting_genlisp stereo_formatting_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS stereo_formatting_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(stereo_formatting
  "/home/marcusn/catkin_ws/src/stereo_formatting/msg/CompStereo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/CompressedImage.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/stereo_formatting
)

### Generating Services

### Generating Module File
_generate_module_nodejs(stereo_formatting
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/stereo_formatting
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(stereo_formatting_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(stereo_formatting_generate_messages stereo_formatting_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/marcusn/catkin_ws/src/stereo_formatting/msg/CompStereo.msg" NAME_WE)
add_dependencies(stereo_formatting_generate_messages_nodejs _stereo_formatting_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(stereo_formatting_gennodejs)
add_dependencies(stereo_formatting_gennodejs stereo_formatting_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS stereo_formatting_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(stereo_formatting
  "/home/marcusn/catkin_ws/src/stereo_formatting/msg/CompStereo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/CompressedImage.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/stereo_formatting
)

### Generating Services

### Generating Module File
_generate_module_py(stereo_formatting
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/stereo_formatting
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(stereo_formatting_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(stereo_formatting_generate_messages stereo_formatting_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/marcusn/catkin_ws/src/stereo_formatting/msg/CompStereo.msg" NAME_WE)
add_dependencies(stereo_formatting_generate_messages_py _stereo_formatting_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(stereo_formatting_genpy)
add_dependencies(stereo_formatting_genpy stereo_formatting_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS stereo_formatting_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/stereo_formatting)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/stereo_formatting
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(stereo_formatting_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(stereo_formatting_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/stereo_formatting)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/stereo_formatting
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(stereo_formatting_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(stereo_formatting_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/stereo_formatting)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/stereo_formatting
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(stereo_formatting_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(stereo_formatting_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/stereo_formatting)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/stereo_formatting
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(stereo_formatting_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(stereo_formatting_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/stereo_formatting)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/stereo_formatting\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/stereo_formatting
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(stereo_formatting_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(stereo_formatting_generate_messages_py std_msgs_generate_messages_py)
endif()
