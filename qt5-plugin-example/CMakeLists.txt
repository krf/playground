# suppose you have created a ui file called configwin.ui
cmake_minimum_required (VERSION 2.8)

project(echoplugin)

find_package(Qt5Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(echowindow)

set(echoplugin_SRCS plugin/echoplugin.cpp)

#FIXME: Potential feature in Qt5
#qt5_wrap_cpp(echoplugin_SRCS plugin/echoplugin.h DEPENDS plugin/echoplugin.json) # force re-evaluating JSON file on changes
#set_source_files_properties(plugin/echoplugin.cpp PROPERTIES SKIP_AUTOMOC TRUE) # fix conflict with automoc

add_library(echoplugin MODULE ${echoplugin_SRCS})
target_link_libraries(echoplugin Qt5::Widgets)
add_executable(app echowindow/echowindow.cpp echowindow/main.cpp)
target_link_libraries(app Qt5::Widgets)
