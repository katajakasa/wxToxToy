
SET(TOX_SEARCH_PATHS
    /usr/local/
    /usr
    /opt
)

FIND_PATH(TOX_INCLUDE_DIR tox/tox.h 
    HINTS ${TOX_ROOT}
    PATH_SUFFIXES include
    PATHS ${TOX_SEARCH_PATHS}
)

FIND_LIBRARY(TOX_LIBRARY toxcore
    HINTS ${TOX_ROOT}
    PATH_SUFFIXES lib64 lib bin
    PATHS ${TOX_SEARCH_PATHS}
)

IF(TOX_INCLUDE_DIR AND TOX_LIBRARY)
   SET(TOX_FOUND TRUE)
ENDIF()


IF(TOX_FOUND)
    MESSAGE(STATUS "Found libtoxcore: ${TOX_LIBRARY}")
ELSE()
    MESSAGE(WARNING "Could not find libtoxcore")
ENDIF()