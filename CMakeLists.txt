cmake_minimum_required(VERSION 3.15)
project(evolution)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Make it a debug config
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Set the path to SFML
set(SFML_DIR "${CMAKE_SOURCE_DIR}/lib/SFML-3.0.0/lib/cmake/SFML")

# Find the SFML package
find_package(SFML 3.0 REQUIRED COMPONENTS Graphics Window System Audio)

# Collect all .cpp files in the 'view' folder
file(GLOB VIEW_SRC
    "view/*.cpp"
)
# Collect all .cpp files in the 'controller' folder
file(GLOB CONTROLLER_SRC
    "controller/*.cpp"
)
# Collect all .cpp files in the 'model' folder
file(GLOB_RECURSE MODEL_SRC
    "${CMAKE_SOURCE_DIR}/model/*.cpp"
    "${CMAKE_SOURCE_DIR}/model/Creatures/*.cpp"
)

# Add the executable
add_executable(evolution
    main.cpp
    ${VIEW_SRC}
    ${CONTROLLER_SRC}
    ${MODEL_SRC}
)

# Include directories
target_include_directories(evolution PRIVATE
    "${CMAKE_SOURCE_DIR}/view"
    "${CMAKE_SOURCE_DIR}/model"
    "${CMAKE_SOURCE_DIR}/model/Creatures"
    "${CMAKE_SOURCE_DIR}/controller"
    ${SFML_INCLUDE_DIRS}
)

# Add this after your executable is defined in CMakeLists.txt
add_custom_command(TARGET evolution POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/assets" $<TARGET_FILE_DIR:evolution>/assets
)

# Link SFML libraries
target_link_libraries(evolution PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio)

# Copy SFML DLLs after build (Windows specific)
if(WIN32)
    add_custom_command(TARGET evolution POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${SFML_DIR}/../../../bin"
        $<TARGET_FILE_DIR:evolution>
    )
endif()
