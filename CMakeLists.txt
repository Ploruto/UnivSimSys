cmake_minimum_required(VERSION 3.0)

# Set the project name
project (SimUniv)

# Create a sources variable with a link to all cpp files to compile
file(GLOB SOURCES true
src/UnivSim.cpp src/utils/math/UssVector.cpp
src/entity/Entity.cpp src/spatial/AABB.cpp src/spatial/EntityPoint.cpp
src/spatial/Bounds.cpp src/spatial/Octree.cpp

)

# Add an executable with the above sources
add_library(SimUnivLib ${SOURCES})




#google tests
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
#end google tests



add_subdirectory(test)


target_link_libraries(
  SimUnivLib
  gtest_main
)

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(SimUnivLib
    PUBLIC
            ${PROJECT_SOURCE_DIR}/include
)
