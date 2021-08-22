cmake_minimum_required(VERSION 3.9)
include(CMakeDependentOption)
cmake_policy(SET CMP0048 NEW)
project("sdl_game" LANGUAGES CXX)

# General compiler settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
  add_compile_options(/W3 /WX)
endif()

set(SOURCE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

# Directory output files single config generators
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/game/lib 
  CACHE PATH "Output directory for static libraries.")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/game/lib
  CACHE PATH "Output directory for shared libraries.")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/game/bin
  CACHE PATH "Output directory for executables and DLL's.")


if(CMAKE_CONFIGURATION_TYPES)
  # Directory output files for multi config generators
  foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    #string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_BINARY_DIR}/game/bin" CACHE PATH "" FORCE)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_BINARY_DIR}/game/lib" CACHE PATH "" FORCE)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_BINARY_DIR}/game/lib" CACHE PATH "" FORCE)
  endforeach()
else()
  # Directory output files for single config generators
  #string(TOUPPER ${CMAKE_BUILD_TYPE} OUTPUTCONFIG)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/game/bin" CACHE PATH "" FORCE)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/game/lib" CACHE PATH "" FORCE)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/game/lib" CACHE PATH "" FORCE)
endif()

#
# game.exe: Editor / Game Launcher
#
add_executable(game WIN32 
${SOURCE_PATH}/main.cpp
${SOURCE_PATH}/Engine.cpp
${SOURCE_PATH}/Time.cpp
${SOURCE_PATH}/Animation.cpp
${SOURCE_PATH}/GameObject.cpp
${SOURCE_PATH}/InputHandler.cpp
${SOURCE_PATH}/PlayerCharacter.cpp
${SOURCE_PATH}/TextureManager.cpp
${SOURCE_PATH}/TileLayer.cpp
${SOURCE_PATH}/Vector2.cpp
${SOURCE_PATH}/GameMap.cpp
)
target_include_directories(game INTERFACE ${SOURCE_PATH}/include)
target_include_directories(game INTERFACE ${SOURCE_PATH}/SDL2/include)
target_link_libraries(game PRIVATE 
${SOURCE_PATH}/SDL2/lib/x86/SDL2.lib 
${SOURCE_PATH}/SDL2/lib/x86/SDL2main.lib
${SOURCE_PATH}/SDL2/lib/x86/SDL2_image.lib)

add_custom_command(TARGET game POST_BUILD 
 # COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/smolSDK/include
  COMMAND ${CMAKE_COMMAND} -E copy ${SOURCE_PATH}/SDL2/lib/x86/SDL2.dll ${CMAKE_BINARY_DIR}/game/bin
  COMMAND ${CMAKE_COMMAND} -E copy ${SOURCE_PATH}/SDL2/lib/x86/SDL2_image.dll ${CMAKE_BINARY_DIR}/game/bin)

# Make windows Debug builds to have a console subsystem
#if(CMAKE_CONFIGURATION_TYPES)
set_property(TARGET game PROPERTY LINK_OPTIONS $<$<CXX_COMPILER_ID:MSVC>:$<IF:$<CONFIG:Release>,/SUBSYSTEM:WINDOWS,/SUBSYSTEM:CONSOLE>>)

if (CMAKE_BUILD_TYPE STREQUAL "Release" )
  if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set_property(TARGET game PROPERTY LINK_OPTIONS /SUBSYSTEM:WINDOWS)
  endif()
endif()

install(DIRECTORY "${CMAKE_BINARY_DIR}/game" DESTINATION .)