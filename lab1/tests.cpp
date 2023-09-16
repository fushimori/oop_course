#include <gtest/gtest.h>
#include "vowel_counter.h"

TEST(test, num1){
    ASSERT_TRUE(counter("") == 0);
}

TEST(test, num2){
    ASSERT_TRUE(counter("               ") == 0);
}

TEST(test, num3){
    ASSERT_TRUE(counter("             a  ") == 1);
}

TEST(test, num4){
    ASSERT_TRUE(counter(" ae o u yi ") == 6);
}

TEST(test, num5){
    ASSERT_TRUE(counter("pqwrtsdf g hjklz xc vbnm") == 0);
}

TEST(test, num6){
    ASSERT_TRUE(counter("paw ertsc ") == 2);
}

TEST(test, num7){
    ASSERT_TRUE(counter("paw ertsc oqieoioiyp ncbdge ") == 11);
}

TEST(test, num8){
    ASSERT_TRUE(counter("112&*^%_+)7890~:;<.>/?3456") == 0);
}

TEST(test, num9){
    ASSERT_FALSE(counter("dOn pErIdOn") == 4);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}