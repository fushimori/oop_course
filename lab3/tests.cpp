#include <gtest/gtest.h>
#include "figures/triangle.h"
#include "figures/octagon.h"
#include "figures/hexagon.h"

TEST(triangle_test, area_of_empty){
    Triangle tr;
    ASSERT_EQ(tr.area(), 0.0);
}

TEST(triangle_test, area){
    Point p1(-2, 0);
    Point p2(2, 0);
    Point p3(0, 3);

    Triangle tr(p1,p2,p3);
    ASSERT_EQ(tr.area(), 6.0);
}

TEST(octagon_test, area_of_empty){
    Octagon tr;
    ASSERT_EQ(tr.area(), 0.0);
}

TEST(octagon_test, area){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(2));
    Point p4(1, sqrt(2) + 1);
    Point p5(0, sqrt(2) + 1);
    Point p6(-0.5, sqrt(2));
    Point p7(-1, 0);
    Point p8(-0.5, -sqrt(2));

    Octagon oct(p1, p2, p3, p4, p5, p6, p7, p8);
    //std::cout << oct.area();
    ASSERT_NEAR(oct.area(), 2.38018, 0.00001);
    
}

TEST(hexagon_test, area_of_empty){
    Hexagon tr;
    ASSERT_EQ(tr.area(), 0);
}


TEST(hexagon_test, area){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(3)/2);
    Point p4(1, sqrt(3));
    Point p5(0, sqrt(3));
    Point p6(-0.5, sqrt(3)/2);

    Hexagon hex(p1, p2, p3, p4, p5, p6);
    //std::cout << hex.area();
    ASSERT_NEAR(hex.area(), 2.59808, 0.00001);
    
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}