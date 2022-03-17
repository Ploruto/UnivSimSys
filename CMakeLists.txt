cmake_minimum_required(VERSION 3.0)

# Set the project name
project (SimUniv)

# Create a sources variable with a link to all cpp files to compile
file(GLOB SOURCES true src/UnivSim.cpp src/utils/math/ussVector.cpp)
# Add an executable with the above sources
add_executable(SimUnivHeaders ${SOURCES})


# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(SimUnivHeaders
    PUBLIC
            ${PROJECT_SOURCE_DIR}/include
)
