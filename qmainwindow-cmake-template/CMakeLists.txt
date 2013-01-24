project(qtapp)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake/ ${CMAKE_MODULE_PATH})

message(STATUS ${CMAKE_MODULE_PATH})

# try Qt5 first, and prefer that if found
find_package(Qt5Core QUIET)
if (Qt5Core_FOUND)
  find_package(Qt5Gui REQUIRED)
  find_package(Qt5Widgets REQUIRED)
  find_package(Qt5Test REQUIRED)

  include(ECMQt4To5Porting)
  include_directories(${QT_INCLUDES}) # TODO: Port away from this.

  if (Qt5_POSITION_INDEPENDENT_CODE)
    if (CMAKE_VERSION VERSION_LESS 2.8.9) # TODO remove once we increase the cmake requirement
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    else()
      set(CMAKE_POSITION_INDEPENDENT_CODE ON)
    endif()
  endif()

# Qt4
else()
  find_package(Qt4 ${QT_MIN_VERSION} REQUIRED QtCore QtGui)

  include_directories(${QT_INCLUDES})
  set(HAVE_QT_SVG true)
  set(HAVE_QT_DESIGNER true)
  set(HAVE_QT_PRINTSUPPORT true)
endif()

set(LIB_SUFFIX "" CACHE STRING "Define suffix of directory name (32/64)")
set(LIB_INSTALL_DIR "lib${LIB_SUFFIX}")
set(PLUGIN_INSTALL_DIR "${LIB_INSTALL_DIR}/qt4/plugins")

set(
  INSTALL_TARGETS_DEFAULT_ARGS
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION ${LIB_INSTALL_DIR}
  ARCHIVE DESTINATION ${LIB_INSTALL_DIR} COMPONENT Devel
)

add_subdirectory(src)
