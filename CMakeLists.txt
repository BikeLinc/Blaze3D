# Build Script For Blaze3D
# 
# This is a altered/modified version of Juliette Focaut and Doug Binks'
# GLFW-CMake-starter found at https://github.com/juliettef/GLFW-CMake-starter;

cmake_minimum_required( VERSION 3.1 )

project( BlazeEngine2D )

find_package( OpenGL REQUIRED )

include_directories( ${OPENGL_INCLUDE_DIRS} )

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_subdirectory( glfw )
add_subdirectory( glew/build/cmake )

if( MSVC )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup" )
endif()

include_directories(glew/include)

file(GLOB GLM_SRC
    "src/glm/*.hpp"
    "src/glm/ext/*.hpp"
    "src/glm/gtc/*.hpp"
    "src/glm/gtc/*.hpp"
)

file(GLOB SOIL2_SRC
     "src/SOIL2/*.h"
     "src/SOIL2/*.c"
)

file(GLOB CORE_SRC
    "src/*.cpp"
    "src/*.h"
    "src/*.c"
)
     
add_executable( ${PROJECT_NAME} WIN32 ${GLEW_INC} ${CORE_SRC} ${SOIL2_SRC} ${SHADER_RES} ${IMAGE_RES})
target_link_libraries( ${PROJECT_NAME} ${OPENGL_LIBRARIES} glew glfw )
if( MSVC )
    if(${CMAKE_VERSION} VERSION_LESS "3.1.0") 
        message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.1.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'BlazeEngine' as StartUp Project in Visual Studio.\n" )
    else()
        set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME} )
    endif()
endif()
