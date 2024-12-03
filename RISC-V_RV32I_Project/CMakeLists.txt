# Add this to find Google Test
find_package(GTest REQUIRED)

# Include GTest headers
include_directories(${GTEST_INCLUDE_DIRS})

# Link your test executable with Google Test
target_link_libraries(your_test_target ${GTEST_LIBRARIES} pthread)