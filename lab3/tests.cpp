#include <gtest/gtest.h>
#include "figures/triangle.h"
#include "figures/octagon.h"
#include "figures/hexagon.h"

TEST(triangle_test, def_constructor){
    Triangle tr;
    ASSERT_EQ(tr.size(), 0);
}

TEST(triangle_test, point_constructor){
    Point p1(1, 3);
    Point p2(2, 2);
    Point p3(3, 1);

    Triangle tr{p1,p2,p3};
    for(size_t i = 1; i < 4; ++i){
        ASSERT_EQ(tr.get_point(i-1), Point(i, 4 - i));
    }
}

TEST(triangle_test, point_constructor_excp){
    Point p1(1, 3);
    Point p2(1, 3);
    Point p3(3, 1);

    ASSERT_THROW(Triangle tr(p1, p2, p3), std::logic_error);
}


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

TEST(triangle_test, center_of_empty){
    Triangle tr1;
    Point p1;
    ASSERT_EQ(tr1.center(), p1);
}

TEST(triangle_test, center){
    Point p1(-2, 0);
    Point p2(2, 0);
    Point p3(0, 3);

    Triangle tr(p1,p2,p3);
    Point prez{0,1};
    std::cout << tr.center() << std::endl;
    ASSERT_EQ(tr.center(), prez );
}

TEST(triangle_test, equality_empty){
    Triangle tr1;
    Triangle tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(triangle_test, equality_1){
    Point p1(-2, 0);
    Point p2(2, 0);
    Point p3(0, 3);

    Triangle tr1{p1,p3,p2};
    Triangle tr2{p2,p1,p3};
    ASSERT_TRUE(tr1 == tr2);
}

TEST(triangle_test, equality_2){
    Point p1(-2, 0);
    Point p2(2, 0);
    Point p3(0, 3);
    Point p4(5, 1);

    Triangle tr1{p1,p3,p2};
    Triangle tr2{p1,p3,p4};
    ASSERT_FALSE(tr1 == tr2);
}

TEST(triangle_test, assignment_empty){
    Triangle tr1;
    Triangle tr2;
    tr1 = tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(triangle_test, assignment){
    Point p1(1, 3);
    Point p2(2, 2);
    Point p3(3, 1);
    
    Triangle tr1;
    Triangle tr2{p1,p2,p3};
    tr1 = tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(triangle_test, assignment1){
    Point p1(1, 3);
    Point p2(2, 2);
    Point p3(3, 1);
    Point p4(1, 1);
    
    Triangle tr1{p1,p3,p4};
    Triangle tr2{p1,p2,p3};
    ASSERT_FALSE(tr1 == tr2);
}

TEST(triangle_test, assignment_move_empty){
    Triangle tr1;
    Triangle tr2;
    tr1 = std::move(tr2);
    ASSERT_TRUE(tr1 == tr2);
}

TEST(triangle_test, assignment_move){
    Point p1(1, 3);
    Point p2(2, 2);
    Point p3(3, 1);
    
    Triangle tr1;
    Triangle tr2{p1,p2,p3};
    tr1 = std::move(tr2);
    ASSERT_TRUE(tr1 == tr2);
}

TEST(triangle_test, get_point_empty){
    Point p1(0, 0);
    Triangle tr1;
    ASSERT_EQ(tr1.get_point(0), p1);
    ASSERT_EQ(tr1.get_point(1), p1);
    ASSERT_EQ(tr1.get_point(2), p1);
}

TEST(triangle_test, get_point){
    Point p1(1, 3);
    Point p2(2, 2);
    Point p3(3, 1);

    Triangle tr1{p1,p2,p3};
    ASSERT_EQ(tr1.get_point(0), p1);
    ASSERT_EQ(tr1.get_point(1), p2);
    ASSERT_EQ(tr1.get_point(2), p3);
}

TEST(triangle_test, get_point_excp){
    Point p1(1, 3);
    Point p2(2, 2);
    Point p3(3, 1);

    Triangle tr1{p1,p2,p3};
    ASSERT_THROW(tr1.get_point(4), std::invalid_argument);
    ASSERT_THROW(tr1.get_point(-1), std::invalid_argument);
}

TEST(triangle_test, operator_double) {
    Point p1(1, 3);
    Point p2(2, 2);
    Point p3(3, 1);
    
    Triangle tr1{p1,p2,p3};
    ASSERT_DOUBLE_EQ(static_cast<double>(tr1), tr1.area());
}

TEST(triangle_test, input) {
    Point p1(1, 3);
    Point p2(2, 2);
    Point p3(3, 1);
    Triangle tr1{p1,p2,p3};

    std::stringstream input("1 3\n3 1\n2 2");

    Triangle tr2;
    input >> tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(triangle_test, input1) {
    Point p1(1, 3);
    Point p2(2, 2);
    Point p3(3, 1);
    Triangle tr1{p1,p2,p3};
    std::stringstream input("1 3\n3 1\n-1 0");

    Triangle tr2;
    input >> tr2;
    ASSERT_FALSE(tr1 == tr2);
}

TEST(triangle_test, input_excp) {
    std::stringstream input("1 3\n3 1\n e 0");

    Triangle tr2;
    ASSERT_THROW(input >> tr2, std::invalid_argument);
}

TEST(triangle_test, input_excp1) {
    std::stringstream input("1 3\n3 1\n 3 1");

    Triangle tr2;
    ASSERT_THROW(input >> tr2, std::logic_error);
}

TEST(triangle_test, output) {
    Point p1(1, 3);
    Point p2(2, 2);
    Point p3(3, 1);
    Triangle tr1{p1, p2, p3};

    std::ostringstream os;
    os << tr1;
    std::string output = "Triangle's coordinates:\n"
                         "(x: 1; y: 3)\n"
                         "(x: 2; y: 2)\n"
                         "(x: 3; y: 1)\n";
    ASSERT_EQ(os.str(), output);
}

TEST(triangle_test, output1) {
    Triangle tr1;

    std::ostringstream os;
    os << tr1;
    std::string output = "Triangle's coordinates:\n"
                         "(x: 0; y: 0)\n"
                         "(x: 0; y: 0)\n"
                         "(x: 0; y: 0)\n";
    ASSERT_EQ(os.str(), output);
}


//////

TEST(octagon_test, def_constructor){
    Octagon tr;
    ASSERT_EQ(tr.size(), 0);
}

TEST(octagon_test, point_constructor){
    Point p1(1, 8);
    Point p2(2, 7);
    Point p3(3, 6);
    Point p4(4, 5);
    Point p5(5, 4);
    Point p6(6, 3);
    Point p7(7, 2);
    Point p8(8, 1);

    Octagon tr{p1,p2,p3,p4,p5,p6,p7,p8};
    for(size_t i = 1; i < 9; ++i){
        ASSERT_EQ(tr.get_point(i-1), Point(i, 9 - i));
    }
}

TEST(octagon_test, point_constructor_excp){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1, 0);
    Point p4(1, sqrt(2) + 1);
    Point p5(0, sqrt(2) + 1);
    Point p6(-0.5, sqrt(2));
    Point p7(-1, 0);
    Point p8(-0.5, -sqrt(2));

    ASSERT_THROW(Octagon tr1(p1,p2,p3,p4,p5,p6,p7,p8), std::logic_error);
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
    ASSERT_NEAR(oct.area(), 2.38018, 0.00001);
    
}

TEST(octagon_test, center_of_empty){
    Octagon tr1;
    Point p1;
    ASSERT_EQ(tr1.center(), p1);
}

TEST(octagon_test, center) {
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(2));
    Point p4(1, sqrt(2) + 1);
    Point p5(0, sqrt(2) + 1);
    Point p6(-0.5, sqrt(2));
    Point p7(-1, 0);
    Point p8(-0.5, -sqrt(2));

    Octagon oct(p1, p2, p3, p4, p5, p6, p7, p8);
    Point prez{0.1875, 0.78033};
    
    ASSERT_NEAR(oct.center().x_, prez.x_, 0.00001);
    ASSERT_NEAR(oct.center().y_, prez.y_, 0.00001);
}

TEST(octagon_test, equality_empty){
    Octagon tr1;
    Octagon tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(octagon_test, equality_1){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(2));
    Point p4(1, sqrt(2) + 1);
    Point p5(0, sqrt(2) + 1);
    Point p6(-0.5, sqrt(2));
    Point p7(-1, 0);
    Point p8(-0.5, -sqrt(2));

    Octagon tr1{p1,p3,p2,p4,p5,p6,p7,p8};
    Octagon tr2{p2,p1,p3,p8,p4,p5,p6,p7};
    ASSERT_TRUE(tr1 == tr2);
}

TEST(octagon_test, equality_2){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(2));
    Point p4(1, sqrt(2) + 1);
    Point p5(0, sqrt(2) + 1);
    Point p6(-0.5, sqrt(2));
    Point p7(-1, 0);
    Point p8(-0.5, -sqrt(2));
    Point p9(5, 1);

    Octagon tr1{p1,p3,p2,p4,p5,p6,p7,p8};
    Octagon tr2{p2,p1,p3,p8,p4,p5,p6,p9};
    ASSERT_FALSE(tr1 == tr2);
}

TEST(octagon_test, assignment_empty){
    Octagon tr1;
    Octagon tr2;
    tr1 = tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(octagon_test, assignment){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(2));
    Point p4(1, sqrt(2) + 1);
    Point p5(0, sqrt(2) + 1);
    Point p6(-0.5, sqrt(2));
    Point p7(-1, 0);
    Point p8(-0.5, -sqrt(2));
    
    Octagon tr1;
    Octagon tr2{p2,p1,p3,p8,p4,p5,p6,p7};
    tr1 = tr2;
    ASSERT_TRUE(tr1 == tr2);
}


TEST(octagon_test, assignment_move_empty){
    Octagon tr1;
    Octagon tr2;
    tr1 = std::move(tr2);
    ASSERT_TRUE(tr1 == tr2);
}

TEST(octagon_test, assignment_move){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, 2);
    Point p4(1, 1.2 + 1);
    Point p5(0, 1.2 + 1);
    Point p6(-0.5, 1.2);
    Point p7(-1, 0);
    Point p8(-0.5, -1.2);
    
    Octagon tr1;
    Octagon tr2{p2,p1,p3,p8,p4,p5,p6,p7};
    tr1 = std::move(tr2);
    ASSERT_TRUE(tr1 == tr2);
}

TEST(octagon_test, get_point_empty){
    Point p1(0, 0);
    Octagon tr1;
    for(size_t i = 0; i < 8;++i){
        ASSERT_EQ(tr1.get_point(i), p1);
    }
}

TEST(octagon_test, get_point){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(2));
    Point p4(1, sqrt(2) + 1);
    Point p5(0, sqrt(2) + 1);
    Point p6(-0.5, sqrt(2));
    Point p7(-1, 0);
    Point p8(-0.5, -sqrt(2));
    
    Octagon tr1{p1,p2,p3,p4,p5,p6,p7,p8};
    ASSERT_EQ(tr1.get_point(0), p1);
    ASSERT_EQ(tr1.get_point(1), p2);
    ASSERT_EQ(tr1.get_point(2), p3);
    ASSERT_EQ(tr1.get_point(3), p4);
    ASSERT_EQ(tr1.get_point(4), p5);
    ASSERT_EQ(tr1.get_point(5), p6);
    ASSERT_EQ(tr1.get_point(6), p7);
    ASSERT_EQ(tr1.get_point(7), p8);
}

TEST(octagon_test, get_point_excp){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(2));
    Point p4(1, sqrt(2) + 1);
    Point p5(0, sqrt(2) + 1);
    Point p6(-0.5, sqrt(2));
    Point p7(-1, 0);
    Point p8(-0.5, -sqrt(2));
    
    Octagon tr1{p2,p1,p3,p8,p4,p5,p6,p7};
    ASSERT_THROW(tr1.get_point(8), std::invalid_argument);
    ASSERT_THROW(tr1.get_point(-1), std::invalid_argument);
}

TEST(octagon_test, operator_double) {
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(2));
    Point p4(1, sqrt(2) + 1);
    Point p5(0, sqrt(2) + 1);
    Point p6(-0.5, sqrt(2));
    Point p7(-1, 0);
    Point p8(-0.5, -sqrt(2));

    Octagon oct(p1, p2, p3, p4, p5, p6, p7, p8);
    ASSERT_NEAR(static_cast<double>(oct), oct.area(), 0.00001);
}

TEST(octagon_test, input) {
    Point p1(1, 8);
    Point p2(2, 7);
    Point p3(3, 6);
    Point p4(4, 5);
    Point p5(5, 4);
    Point p6(6, 3);
    Point p7(7, 2);
    Point p8(8, 1);

    Octagon tr1{p1,p2,p3,p4,p5,p6,p7,p8};

    std::stringstream input("1 8\n8 1\n2 7\n"
                            "7 2\n3 6\n6 3\n"
                            "4 5\n5 4\n");

    Octagon tr2;
    input >> tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(octagon_test, input1) {
    Point p1(1, 8);
    Point p2(2, 7);
    Point p3(3, 6);
    Point p4(4, 5);
    Point p5(5, 4);
    Point p6(6, 3);
    Point p7(7, 2);
    Point p8(8, 1);

    Octagon tr1{p1,p2,p3,p4,p5,p6,p7,p8};

    std::stringstream input("1 8\n8 1\n2 7\n"
                            "7 2\n3 6\n6 3\n"
                            "4 5\n5 0\n");

    Octagon tr2;
    input >> tr2;
    ASSERT_FALSE(tr1 == tr2);
}

TEST(octagon_test, input_excp) {
    std::stringstream input("1 8\n8 1\n2 7\n"
                            "7 2\n3 6\n6 3\n"
                            "4 5\n5 e\n");

    Octagon tr2;
    ASSERT_THROW(input >> tr2, std::invalid_argument);
}

TEST(octagon_test, input_excp1) {
    std::stringstream input("1 8\n8 1\n2 7\n"
                            "7 2\n3 6\n6 3\n"
                            "4 5\n4 5\n");

    Octagon tr2;
    ASSERT_THROW(input >> tr2, std::logic_error);
}

TEST(octagon_test, output) {
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(2));
    Point p4(1, sqrt(2) + 1);
    Point p5(0, sqrt(2) + 1);
    Point p6(-0.5, sqrt(2));
    Point p7(-1, 0);
    Point p8(-0.5, -sqrt(2));
    Octagon tr1{p1,p2,p3,p4,p5,p6,p7,p8};

    std::ostringstream os;
    os << tr1;
    std::string output = "Octagon's coordinates:\n"
                         "(x: 0; y: 0)\n"
                         "(x: 1; y: 0)\n"
                         "(x: 1.5; y: 1.41421)\n"
                         "(x: 1; y: 2.41421)\n"
                         "(x: 0; y: 2.41421)\n"
                         "(x: -0.5; y: 1.41421)\n"
                         "(x: -1; y: 0)\n"
                         "(x: -0.5; y: -1.41421)\n";
    ASSERT_EQ(os.str(), output);
}

TEST(octagon_test, output1) {
    Octagon tr1;

    std::ostringstream os;
    os << tr1;
    std::string output = "Octagon's coordinates:\n"
                         "(x: 0; y: 0)\n"
                         "(x: 0; y: 0)\n"
                         "(x: 0; y: 0)\n"
                         "(x: 0; y: 0)\n"
                         "(x: 0; y: 0)\n"
                         "(x: 0; y: 0)\n"
                         "(x: 0; y: 0)\n"
                         "(x: 0; y: 0)\n";
    ASSERT_EQ(os.str(), output);
}

//////

TEST(hexagon_test, def_constructor){
    Hexagon tr;
    ASSERT_EQ(tr.size(), 0);
}

TEST(hexagon_test, point_constructor){
    Point p1(1, 8);
    Point p2(2, 7);
    Point p3(3, 6);
    Point p4(4, 5);
    Point p5(5, 4);
    Point p6(6, 3);

    Hexagon tr{p1,p2,p3,p4,p5,p6};
    for(size_t i = 1; i < 7; ++i){
        ASSERT_EQ(tr.get_point(i-1), Point(i, 9 - i));
    }
}

TEST(hexagon_test, point_constructor_excp){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1, 0);
    Point p4(1, sqrt(2) + 1);
    Point p5(0, sqrt(2) + 1);
    Point p6(-0.5, sqrt(2));

    ASSERT_THROW(Hexagon tr1(p1,p2,p3,p4,p5,p6), std::logic_error);
}


TEST(hexagon_test, area_of_empty){
    Hexagon tr;
    ASSERT_EQ(tr.area(), 0.0);
}


TEST(hexagon_test, area){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(3)/2);
    Point p4(1, sqrt(3));
    Point p5(0, sqrt(3));
    Point p6(-0.5, sqrt(3)/2);

    Hexagon hex(p1, p2, p3, p4, p5, p6);
    ASSERT_NEAR(hex.area(), 2.59808, 0.00001);
    
}

TEST(hexagon_test, center_of_empty){
    Hexagon tr1;
    Point p1;
    ASSERT_EQ(tr1.center(), p1);
}

TEST(hexagon_test, center) {
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(3)/2);
    Point p4(1, sqrt(3));
    Point p5(0, sqrt(3));
    Point p6(-0.5, sqrt(3)/2);

    Hexagon hex(p1, p2, p3, p4, p5, p6);
    Point prez{ 0.5, 0.866025};
    ASSERT_NEAR(hex.center().x_, prez.x_, 0.00001);
    ASSERT_NEAR(hex.center().y_, prez.y_, 0.00001);
}

TEST(hexagon_test, equality_empty){
    Hexagon tr1;
    Hexagon tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(hexagon_test, equality_1){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(3)/2);
    Point p4(1, sqrt(3));
    Point p5(0, sqrt(3));
    Point p6(-0.5, sqrt(3)/2);

    Hexagon tr1{p1,p3,p2,p4,p5,p6};
    Hexagon tr2{p2,p1,p3,p4,p5,p6};
    ASSERT_TRUE(tr1 == tr2);
}

TEST(hexagon_test, equality_2){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(3)/2);
    Point p4(1, sqrt(3));
    Point p5(0, sqrt(3));
    Point p6(-0.5, sqrt(3)/2);
    Point p7(0.5, sqrt(3));

    Hexagon tr1{p1,p3,p2,p4,p5,p6};
    Hexagon tr2{p2,p1,p3,p4,p5,p7};
    ASSERT_FALSE(tr1 == tr2);
}

TEST(hexagon_test, assignment_empty){
    Hexagon tr1;
    Hexagon tr2;
    tr1 = tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(hexagon_test, assignment){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(3)/2);
    Point p4(1, sqrt(3));
    Point p5(0, sqrt(3));
    Point p6(-0.5, sqrt(3)/2);
    
    Hexagon tr1;
    Hexagon tr2{p2,p1,p3,p4,p5,p6};
    tr1 = tr2;
    ASSERT_TRUE(tr1 == tr2);
}


TEST(hexagon_test, assignment_move_empty){
    Hexagon tr1;
    Hexagon tr2;
    tr1 = std::move(tr2);
    ASSERT_TRUE(tr1 == tr2);
}

TEST(hexagon_test, assignment_move){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(3)/2);
    Point p4(1, sqrt(3));
    Point p5(0, sqrt(3));
    Point p6(-0.5, sqrt(3)/2);
    
    Hexagon tr1;
    Hexagon tr2{p2,p1,p3,p4,p5,p6};
    tr1 = std::move(tr2);
    ASSERT_TRUE(tr1 == tr2);
}

TEST(hexagon_test, get_point_empty){
    Point p1(0, 0);
    Hexagon tr1;
    for(size_t i = 0; i < 6;++i){
        ASSERT_EQ(tr1.get_point(i), p1);
    }
}

TEST(hexagon_test, get_point){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(3)/2);
    Point p4(1, sqrt(3));
    Point p5(0, sqrt(3));
    Point p6(-0.5, sqrt(3)/2);
    
    Hexagon tr1{p1,p2,p3,p4,p5,p6};
    ASSERT_EQ(tr1.get_point(0), p1);
    ASSERT_EQ(tr1.get_point(1), p2);
    ASSERT_EQ(tr1.get_point(2), p3);
    ASSERT_EQ(tr1.get_point(3), p4);
    ASSERT_EQ(tr1.get_point(4), p5);
    ASSERT_EQ(tr1.get_point(5), p6);
}

TEST(hexagon_test, get_point_excp){
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(3)/2);
    Point p4(1, sqrt(3));
    Point p5(0, sqrt(3));
    Point p6(-0.5, sqrt(3)/2);
    
    Hexagon tr1{p2,p1,p3,p4,p5,p6};
    ASSERT_THROW(tr1.get_point(6), std::invalid_argument);
    ASSERT_THROW(tr1.get_point(-1), std::invalid_argument);
}

TEST(hexagon_test, operator_double) {
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(3)/2);
    Point p4(1, sqrt(3));
    Point p5(0, sqrt(3));
    Point p6(-0.5, sqrt(3)/2);
    
    Hexagon tr1{p2,p1,p3,p4,p5,p6};
    ASSERT_NEAR(static_cast<double>(tr1), tr1.area(), 0.00001);
}

TEST(hexagon_test, input) {
    Point p1(1, 8);
    Point p2(2, 7);
    Point p3(3, 6);
    Point p4(4, 5);
    Point p5(5, 4);
    Point p6(6, 3);

    Hexagon tr1{p1,p2,p3,p4,p5,p6};

    std::stringstream input("1 8\n4 5\n2 7\n"
                            "5 4\n3 6\n6 3\n");

    Hexagon tr2;
    input >> tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(hexagon_test, input1) {
    Point p1(1, 8);
    Point p2(2, 7);
    Point p3(3, 6);
    Point p4(4, 5);
    Point p5(5, 4);
    Point p6(6, 3);

    Hexagon tr1{p1,p2,p3,p4,p5,p6};

    std::stringstream input("1 8\n8 1\n2 7\n"
                            "7 2\n3 6\n6 1\n");

    Hexagon tr2;
    input >> tr2;
    ASSERT_FALSE(tr1 == tr2);
}

TEST(hexagon_test, input_excp) {
    std::stringstream input("1 8\n8 1\n2 7\n"
                            "7 2\n3 6\n4 e\n");

    Hexagon tr2;
    ASSERT_THROW(input >> tr2, std::invalid_argument);
}

TEST(hexagon_test, input_excp1) {
    std::stringstream input("1 8\n8 1\n2 7\n"
                            "7 2\n3 6\n3 6\n");

    Hexagon tr2;
    ASSERT_THROW(input >> tr2, std::logic_error);
}

TEST(hexagon_test, output) {
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(1.5, sqrt(3)/2);
    Point p4(1, sqrt(3));
    Point p5(0, sqrt(3));
    Point p6(-0.5, sqrt(3)/2);
    
    Hexagon tr1{p2,p1,p3,p4,p5,p6};

    std::ostringstream os;
    os << tr1;
    std::string output = "Hexagon's coordinates:\n"
                        "(x: 1; y: 0)\n"
                        "(x: 0; y: 0)\n"
                        "(x: 1.5; y: 0.866025)\n"
                        "(x: 1; y: 1.73205)\n"
                        "(x: 0; y: 1.73205)\n"
                        "(x: -0.5; y: 0.866025)\n";
    ASSERT_EQ(os.str(), output);
}

TEST(hexagon_test, output1) {
    Hexagon tr1;

    std::ostringstream os;
    os << tr1;
    std::string output = "Hexagon's coordinates:\n"
                         "(x: 0; y: 0)\n"
                         "(x: 0; y: 0)\n"
                         "(x: 0; y: 0)\n"
                         "(x: 0; y: 0)\n"
                         "(x: 0; y: 0)\n"
                         "(x: 0; y: 0)\n";
    ASSERT_EQ(os.str(), output);
} 





int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}