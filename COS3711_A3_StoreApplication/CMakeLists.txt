cmake_minimum_required(VERSION 3.14)

project(COS3711_A3_StoreApplication LANGUAGES CXX)

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

add_executable(COS3711_A3_StoreApplication
  main.cpp
  customer.h
  customer.cpp
  customerform.h
  customerform.cpp
  transaction.h
  transaction.cpp
  book.h
  book.cpp
  magazine.h
  magazine.cpp
  transactionfactory.h
  transactionfactory.cpp
  checkdataform.h
  checkdataform.cpp
  shopmainwindow.h
  shopmainwindow.cpp
  shoptreemodelview.h
  shoptreemodelview.cpp
  transactionlisttoxml.h
  transactionlisttoxml.cpp
  itemlistmemento.h
  itemlistmemento.cpp
  shoptransactionserializer.h
  shoptransactionserializer.cpp
)
target_link_libraries(COS3711_A3_StoreApplication Qt${QT_VERSION_MAJOR}::Core)


#ADDED to use Widgets
target_link_libraries(COS3711_A3_StoreApplication Qt5::Widgets)

#ADDED to use xml
target_link_libraries(COS3711_A3_StoreApplication  Qt5::Xml)

#ADDED to use networking
target_link_libraries(COS3711_A3_StoreApplication Qt5::Network)
