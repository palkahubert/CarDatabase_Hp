#include <gtest/gtest.h>
#include "CarDatabase_HP.h"  // Jeœli testujesz funkcje z CarDatabase_HP

// Przyk³adowe testy
TEST(SampleTest, PositiveTest) {
    EXPECT_EQ(1, 1);  // Spodziewana równoœæ
}

TEST(SampleTest, NegativeTest) {
    EXPECT_NE(1, 2);  // Spodziewana nierównoœæ
}

// G³ówny punkt wejœciowy dla testów
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// Test pozytywny
TEST(SampleTest, PositiveTest) {
    EXPECT_EQ(1, 1);  // Spodziewana równoœæ
}

// Test negatywny
TEST(SampleTest, NegativeTest) {
    EXPECT_NE(1, 2);  // Spodziewana nierównoœæ
}

// G³ówny punkt wejœciowy dla testów
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
