cmake_minimum_required(VERSION 3.16)
project(pro2team LANGUAGES CXX)

# Compiler and standard settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build configurations
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

# Collect source and header files
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/source/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/header/*.hpp ${CMAKE_SOURCE_DIR}/dxlib_for_visual_studio/*.h)
file(GLOB RESOURCE_FILES ${CMAKE_SOURCE_DIR}/image/*.{png,jpg})

# Add executable
# Add executable and specify a GUI application
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES} ${HEADER_FILES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/header
    ${CMAKE_SOURCE_DIR}/dxlib_for_visual_studio
)

# Link directories
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/dxlib_for_visual_studio)

# Compiler options for different compilers
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4        # Enable most warnings (MSVC equivalent to -Wall)
        /permissive-  # Enforce standards-compliant C++
        /utf-8     # Ensure UTF-8 encoding
    )
else()
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall       # Enable all warnings
        -Wextra     # Enable additional warnings
        -Wpedantic  # Strict standard compliance
    )
endif()

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)
    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Release>:/OPT:REF /OPT:ICF>
    )
endif()

# Resource handling
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/image
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/image
)

# Output directories
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release
)
