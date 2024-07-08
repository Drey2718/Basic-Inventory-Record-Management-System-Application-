cmake_minimum_required(VERSION 3.14)

project(COS3711_A3_UDPReceiverApplication LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

#ADDED to Find the Qt libraries needed (Widgets)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

#ADDED to use xml
find_package(Qt5 COMPONENTS Core Xml REQUIRED)

#ADDED to use networking
find_package(Qt5 COMPONENTS Network REQUIRED)

add_executable(COS3711_A3_UDPReceiverApplication
  main.cpp
  udpreceivermainwindow.h
  udpreceivermainwindow.cpp
)
target_link_libraries(COS3711_A3_UDPReceiverApplication Qt${QT_VERSION_MAJOR}::Core)

#ADDED to use Widgets
target_link_libraries(COS3711_A3_UDPReceiverApplication Qt5::Widgets)

#ADDED to use xml
target_link_libraries(COS3711_A3_UDPReceiverApplication  Qt5::Xml)

#ADDED to use networking
target_link_libraries(COS3711_A3_UDPReceiverApplication Qt5::Network)
