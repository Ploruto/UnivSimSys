cmake_minimum_required(VERSION 3.0)

# Set the project name
project (SimUniv)

# Create a sources variable with a link to all cpp files to compile
file(GLOB SOURCES true utils/math/UssVectorTest.cpp
event/EventTest.cpp
entity/EntityTest.cpp
spatial/EntityPointTest.cpp spatial/AABBTest.cpp
spatial/OctreeTest.cpp


  
  )


# Add an executable with the above sources
add_executable(SimUnivTests ${SOURCES})


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
#

target_link_libraries(
  SimUnivTests
  SimUnivLib
)