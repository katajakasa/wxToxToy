cmake_minimum_required(VERSION 2.6)
project(wxTox CXX)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake-scripts)
find_package(wxwidgets3)
find_package(tox)
find_package(sodium)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -static-libstdc++ -static-libgcc ${WX_OPTS}")
set(CMAKE_CXX_FLAGS_DEBUG "-ggdb -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

IF(MINGW)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wl,--subsystem,windows")
ENDIF()

add_executable(wxtox
    src/wxtoxgui.cpp
    src/app.cpp
    src/wxtoxframe.cpp
    src/wxtoxtick.cpp
    src/addfrienddialog.cpp
    src/settingsdialog.cpp
    src/convframe.cpp
    src/utils.cpp
    src/toxfriend.cpp
    src/log.cpp
)

set(COREINCS
    ${WXWIDGETS_INCLUDE_DIR}
    ${TOX_INCLUDE_DIR}
    ${SODIUM_INCLUDE_DIR}
)

set(CORELIBS
    ${WXWIDGETS_LIBRARY}
    ${TOX_LIBRARY}
    ${SODIUM_LIBRARY}
)

IF(MINGW)
    set(CORELIBS mingw32 ${CORELIBS} comctl32 ws2_32 iphlpapi)
ENDIF()

include_directories(${COREINCS})
target_link_libraries(wxtox ${CORELIBS})
