cmake_minimum_required(VERSION 3.9)
set(TARGET_NAME BankSystem)

set(CMAKE_CXX_STANDARD 11)
include_directories(.)


set(CMAKE_AUTOMOC  ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC  ON)

file(GLOB_RECURSE   SOURCES "*.cpp")
file(GLOB_RECURSE   HEADER  "*.h")
file(GLOB_RECURSE   FORMS   "*.ui")
file(GLOB_RECURSE   RESOURCES   "*.qrc")


set(QTPKG Core  Gui Widgets Sql)
find_package(Qt5 REQUIRED   ${QTPKG})

set(CMAKE_PREFIX_PATH "/home/tender/Qt5.9.6/5.9.6/gcc_64")

add_executable(${TARGET_NAME} ${SOURCES} ${HEADERS} ${FORMS}    ${RESOURCES} DIalogChangePasswd.cpp DIalogChangePasswd.h)

qt5_use_modules(${TARGET_NAME}  ${QTPKG})
