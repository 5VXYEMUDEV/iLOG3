CMAKE_MINIMUM_REQUIRED (VERSION 3.8)
PROJECT (iLog3-Solution C)

# Using C99
# Reference: https://stackoverflow.com/questions/24840030/forcing-c99-in-cmake-to-use-for-loop-initial-declaration
SET (CMAKE_C_STANDARD 99)

MESSAGE (STATUS "Solution: " ${CMAKE_PROJECT_NAME})
MESSAGE (STATUS "Dev-Root BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE (STATUS "Dev-Root SOURCE dir " ${PROJECT_SOURCE_DIR})

# Check Operating System type
MESSAGE(STATUS "CMAKE_SYSTEM_NAME : ${CMAKE_SYSTEM_NAME}")
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "Detecting OS platform: Linux")
    # ADD_DEFINITIONS( -D _LINUX )
    # ADD_DEFINITIONS( -D -fPIC )
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "Detecting OS platform: Windows")
    ADD_DEFINITIONS( -D _WIN32 )
ELSE ()
    MESSAGE(STATUS "Detecting OS platform : (other) : ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

INCLUDE_DIRECTORIES(
    ../../Code
    ../../src
    /usr/local/lib/iLog3
)

LINK_DIRECTORIES(
        # glib-2.0, gio and mxml
        /usr/local/lib/iLog3
    )

MESSAGE(STATUS "")
MESSAGE(STATUS "=========================================================")
MESSAGE(STATUS "| Target iLog3 Dynamic Library       (SHARED LIB) BEGIN |")
MESSAGE(STATUS "=========================================================")
MESSAGE(STATUS "")

SET ( SRC_LIST_iLog3_LIB

    ../../src/LOG.c
    ../../src/LOGC.c
    ../../src/LOGS.c

)

MESSAGE(STATUS "Compile ...")
add_library( iLog3 SHARED ${SRC_LIST_iLog3_LIB} )

MESSAGE(STATUS "")
MESSAGE(STATUS "=========================================================")
MESSAGE(STATUS "| Target iLog3 Dynamic Library       (SHARED LIB) END   |")
MESSAGE(STATUS "=========================================================")
MESSAGE(STATUS "")

MESSAGE(STATUS "")
MESSAGE(STATUS "=========================================================")
MESSAGE(STATUS "| Target iLog3-Verification          (EXECUTABLE) BEGIN |")
MESSAGE(STATUS "=========================================================")
MESSAGE(STATUS "")

SET ( SRC_LIST_iLog3_Verification

    ../../Code/Utilities/iLog3-Verification/iLog3-Verification.c
    ../../Code/Utilities/iLog3-Verification/TEST_hello.c
    ../../Code/Utilities/iLog3-Verification/TEST_hello2.c
    ../../Code/Utilities/iLog3-Verification/TEST_logs.c

)

MESSAGE(STATUS "Compile ...")
ADD_EXECUTABLE( iLog3-Verification ${SRC_LIST_iLog3_Verification} )

MESSAGE(STATUS "Link ...")
TARGET_LINK_LIBRARIES( iLog3-Verification iLog3)


MESSAGE(STATUS "")
MESSAGE(STATUS "=========================================================")
MESSAGE(STATUS "| Target iLog3-Verification          (EXECUTABLE) END   |")
MESSAGE(STATUS "=========================================================")
MESSAGE(STATUS "")