#include <gtest/gtest.h>
#include "CarDatabase_HP.h"  // Je�li testujesz funkcje z CarDatabase_HP

// Przyk�adowe testy
TEST(SampleTest, PositiveTest) {
    EXPECT_EQ(1, 1);  // Spodziewana r�wno��
}

TEST(SampleTest, NegativeTest) {
    EXPECT_NE(1, 2);  // Spodziewana nier�wno��
}

// G��wny punkt wej�ciowy dla test�w
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// Test pozytywny
TEST(SampleTest, PositiveTest) {
    EXPECT_EQ(1, 1);  // Spodziewana r�wno��
}

// Test negatywny
TEST(SampleTest, NegativeTest) {
    EXPECT_NE(1, 2);  // Spodziewana nier�wno��
}

// G��wny punkt wej�ciowy dla test�w
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
