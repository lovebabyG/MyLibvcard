CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)



################################################################################
# Qt5
################################################################################
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

################################################################################



################################################################################
# libvcard
################################################################################
file(GLOB vcard_cpp libvcard/*.cpp)
file(GLOB vcard_h include/vcard/*.h)

include_directories(AFTER SYSTEM include/vcard ${CMAKE_BINARY_DIR})
add_library(vcard ${vcard_cpp} ${vcard_h})

add_executable(myLibvcardApp main.cpp ${vcard_cpp})

target_link_libraries(vcard Qt5::Core)
################################################################################

qt5_use_modules( myLibvcardApp Core Widgets)
