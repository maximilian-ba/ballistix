#include <gtest/gtest.h>
#include <Ballistix/Ballistix.hpp>

TEST(BallistixTest, LibraryIncludesCorrectly) {
    // Ensure target_link_libraries(Ballistix) works
    ASSERT_TRUE(true);
}

TEST(BallistixTest, SimpleMathCheck) {
    // Small test, to see if GTest is running
    EXPECT_EQ(1 + 1, 2);
}