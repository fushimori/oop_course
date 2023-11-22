#include <gtest/gtest.h>
#include "figures/point.h"
#include "figures/triangle.h"
#include "figures/octagon.h"
#include "figures/hexagon.h"

TEST(concept_test, type) {
    ASSERT_FALSE(Number<bool>);
    ASSERT_FALSE(Number<char>);
    ASSERT_FALSE(Number<std::string>);

    ASSERT_TRUE(Number<int>);
    ASSERT_TRUE(Number<long long>);
    ASSERT_TRUE(Number<double>);
    ASSERT_TRUE(Number<float>);
    ASSERT_TRUE(Number<uint>);

}

////////////////////////////////////////////////////////////////// 

TEST(point_test, def_constructor){
    Point<int> p;
    ASSERT_EQ(p.x_, 0);
    ASSERT_EQ(p.y_, 0);
}

TEST(point_test, double_constructor){
    Point<double> p(1.0,3.0);
    ASSERT_EQ(p.x_, 1.0);
    ASSERT_EQ(p.y_, 3.0);
}

TEST(point_test, point_constructor){
    Point<double> p1(3.6, 3.4);
    Point<double> p(p1);
    ASSERT_EQ(p.x_, p1.x_);
    ASSERT_EQ(p.y_, p1.y_);
}

TEST(point_test, assignment_empty){
    Point<double> p1;
    Point<double> p;
    p = p1;
    ASSERT_EQ(p.x_, p1.x_);
    ASSERT_EQ(p.y_, p1.y_);
}

TEST(point_test, assignment){
    Point<double> p1(3.6, 3.4);
    Point<double> p;
    p = p1;
    ASSERT_EQ(p.x_, p1.x_);
    ASSERT_EQ(p.y_, p1.y_);
}

TEST(point_test, equality_empty){
    Point<double> p1;
    Point<double> p;
    ASSERT_TRUE(p == p1);
}

TEST(point_test, equality){
    Point<double> p1(3.6, 3.4);
    Point<double> p(p1);
    ASSERT_TRUE(p == p1);
}

TEST(point_test, addition_empty){
    Point<double> p1;
    Point<double> p;
    ASSERT_EQ(p + p1, p);
}

TEST(point_test, addition){
    Point<double> p1{2.3, -10};
    Point<double> p{3.4, 10.5};
    Point<double> p3 = p + p1;
    
    ASSERT_EQ(p1 + p, p3);
}

TEST(point_test, subtraction_empty){
    Point<double> p1;
    Point<double> p;
    ASSERT_EQ(p - p1, p);
}

TEST(point_test, subtraction){
    Point<double> p1{2.3,-10};
    Point<double> p{3.4, 10.05};
    Point<double> rez{1.1, 20.05};
    ASSERT_EQ(p - p1, rez);
}

TEST(point_test, input) {
    std::stringstream input("1 1");
    Point<int> tr1{1, 1};
    Point<int> tr2;
    input >> tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(point_test, input1) {
    Point<int> tr1{1,3};
    std::stringstream input("1 1");

    Point<int> tr2;
    input >> tr2;
    ASSERT_FALSE(tr1 == tr2);
}

TEST(point_test, output) {
    Point<int> p1(1, 3);

    std::ostringstream os;
    os << p1;
    std::string output = "(x: 1; y: 3)";
    ASSERT_EQ(os.str(), output);
}

TEST(point_test, output_empty) {
    Point<int> p1;

    std::ostringstream os;
    os << p1;
    std::string output = "(x: 0; y: 0)";
    ASSERT_EQ(os.str(), output);
}

TEST(point_test, less) {
    Point<double> p1(1, 4);
    Point<double> p2(2, 5);
    ASSERT_TRUE(p1 < p2);
}

TEST(point_test, greater) {
    Point<double> p1(1, 4);
    Point<double> p2(2, 5);
    ASSERT_TRUE(p2 > p1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(triangle_test, point_constructor){
    Point<int> p1(1, 3);
    Point<int> p2(2, 2);
    Point<int> p3(3, 1);

    Triangle<int> tr{p1,p2,p3};
    for(size_t i = 1; i < 4; ++i){
        ASSERT_EQ(tr.get_point(i-1), Point<int>(i, 4 - i));
    }
}

TEST(triangle_test, point_constructor_excp){
    Point<int> p1(1, 3);
    Point<int> p2(1, 3);
    Point<int> p3(3, 1);

    ASSERT_THROW(Triangle<int> tr(p1, p2, p3), std::logic_error);
}


TEST(triangle_test, area_of_empty){
    Triangle<double> tr;
    ASSERT_EQ(tr.area(), 0.0);
}

TEST(triangle_test, area){
    Point<int> p1(-2, 0);
    Point<int> p2(2, 0);
    Point<int> p3(0, 3);

    Triangle<int> tr(p1,p2,p3);
    ASSERT_EQ(tr.area(), 6.0);
}

TEST(triangle_test, center_of_empty){
    Triangle<int> tr1;
    Point<int> p1;
    ASSERT_EQ(tr1.center(), p1);
}

TEST(triangle_test, center){
    Point<int> p1(-2, 0);
    Point<int> p2(2, 0);
    Point<int> p3(0, 3);

    Triangle<int> tr(p1,p2,p3);
    Point<int> prez{0,1};
    std::cout << tr.center() << std::endl;
    ASSERT_EQ(tr.center(), prez );
}

TEST(triangle_test, equality_empty){
    Triangle<double> tr1;
    Triangle<double> tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(triangle_test, equality_1){
    Point<int> p1(-2, 0);
    Point<int> p2(2, 0);
    Point<int> p3(0, 3);

    Triangle<int> tr1{p1,p3,p2};
    Triangle<int> tr2{p2,p1,p3};
    ASSERT_TRUE(tr1 == tr2);
}

TEST(triangle_test, equality_2){
    Point<int> p1(-2, 0);
    Point<int> p2(2, 0);
    Point<int> p3(0, 3);
    Point<int> p4(5, 1);

    Triangle<int> tr1{p1,p3,p2};
    Triangle<int> tr2{p1,p3,p4};
    ASSERT_FALSE(tr1 == tr2);
}

TEST(triangle_test, assignment_empty){
    Triangle<double> tr1;
    Triangle<double> tr2;
    tr1 = tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(triangle_test, assignment){
    Point<int> p1(1, 3);
    Point<int> p2(2, 2);
    Point<int> p3(3, 1);
    
    Triangle<int> tr1;
    Triangle<int> tr2{p1,p2,p3};
    tr1 = tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(triangle_test, assignment1){
    Point<int> p1(1, 3);
    Point<int> p2(2, 2);
    Point<int> p3(3, 1);
    Point<int> p4(1, 1);
    
    Triangle<int> tr1{p1,p3,p4};
    Triangle<int> tr2{p1,p2,p3};
    ASSERT_FALSE(tr1 == tr2);
}

TEST(triangle_test, assignment_move_empty){
    Triangle<double> tr1;
    Triangle<double> tr2;
    tr1 = std::move(tr2);
    ASSERT_TRUE(tr1 == tr2);
}

TEST(triangle_test, assignment_move){
    Point<int> p1(1, 3);
    Point<int> p2(2, 2);
    Point<int> p3(3, 1);
    
    Triangle<int> tr1;
    Triangle<int> tr2{p1,p2,p3};
    tr1 = std::move(tr2);
    ASSERT_TRUE(tr1 == tr2);
}

TEST(triangle_test, get_point_empty){
    Point<int> p1(0, 0);
    Triangle<int> tr1;
    ASSERT_EQ(tr1.get_point(0), p1);
    ASSERT_EQ(tr1.get_point(1), p1);
    ASSERT_EQ(tr1.get_point(2), p1);
}

TEST(triangle_test, get_point){
    Point<int> p1(1, 3);
    Point<int> p2(2, 2);
    Point<int> p3(3, 1);

    Triangle<int> tr1{p1,p2,p3};
    ASSERT_EQ(tr1.get_point(0), p1);
    ASSERT_EQ(tr1.get_point(1), p2);
    ASSERT_EQ(tr1.get_point(2), p3);
}

TEST(triangle_test, get_point_excp){
    Point<int> p1(1, 3);
    Point<int> p2(2, 2);
    Point<int> p3(3, 1);

    Triangle<int> tr1{p1,p2,p3};
    ASSERT_THROW(tr1.get_point(4), std::invalid_argument);
    ASSERT_THROW(tr1.get_point(-1), std::invalid_argument);
}

TEST(triangle_test, operator_double) {
    Point<int> p1(1, 3);
    Point<int> p2(2, 2);
    Point<int> p3(3, 1);
    
    Triangle<int> tr1{p1,p2,p3};
    ASSERT_DOUBLE_EQ(static_cast<double>(tr1), tr1.area());
}

TEST(triangle_test, input) {
    Point<int> p1(1, 3);
    Point<int> p2(2, 2);
    Point<int> p3(3, 1);
    Triangle<int> tr1{p1,p2,p3};

    std::stringstream input("1 3\n3 1\n2 2");

    Triangle<int> tr2;
    input >> tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(triangle_test, input1) {
    Point<int> p1(1, 3);
    Point<int> p2(2, 2);
    Point<int> p3(3, 1);
    Triangle<int> tr1{p1,p2,p3};
    std::stringstream input("1 3\n3 1\n-1 0");

    Triangle<int> tr2;
    input >> tr2;
    ASSERT_FALSE(tr1 == tr2);
}

TEST(triangle_test, input_excp) {
    std::stringstream input("1 3\n3 1\n e 0");

    Triangle<int> tr2;
    ASSERT_THROW(input >> tr2, std::invalid_argument);
}

TEST(triangle_test, input_excp1) {
    std::stringstream input("1 3\n3 1\n 3 1");

    Triangle<int> tr2;
    ASSERT_THROW(input >> tr2, std::logic_error);
}

TEST(triangle_test, output) {
    Point<int> p1(1, 3);
    Point<int> p2(2, 2);
    Point<int> p3(3, 1);
    Triangle<int> tr1{p1, p2, p3};

    std::ostringstream os;
    os << tr1;
    std::string output = "Triangle's coordinates:\n"
                         "(x: 1; y: 3)\n"
                         "(x: 2; y: 2)\n"
                         "(x: 3; y: 1)\n";
    ASSERT_EQ(os.str(), output);
}

TEST(triangle_test, output1) {
    Triangle<int> tr1;

    std::ostringstream os;
    os << tr1;
    std::string output = "Triangle's coordinates:\n"
                         "(x: 0; y: 0)\n"
                         "(x: 0; y: 0)\n"
                         "(x: 0; y: 0)\n";
    ASSERT_EQ(os.str(), output);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(octagon_test, def_constructor){
    Octagon<int> tr;
    ASSERT_EQ(tr.size(), 0);
}

TEST(octagon_test, point_constructor){
    Point<int> p1(1, 8);
    Point<int> p2(2, 7);
    Point<int> p3(3, 6);
    Point<int> p4(4, 5);
    Point<int> p5(5, 4);
    Point<int> p6(6, 3);
    Point<int> p7(7, 2);
    Point<int> p8(8, 1);

    Octagon<int> tr{p1,p2,p3,p4,p5,p6,p7,p8};
    for(size_t i = 1; i < 9; ++i){
        ASSERT_EQ(tr.get_point(i-1), Point<int>(i, 9 - i));
    }
}

TEST(octagon_test, point_constructor_excp){
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1, 0);
    Point<double> p4(1, sqrt(2) + 1);
    Point<double> p5(0, sqrt(2) + 1);
    Point<double> p6(-0.5, sqrt(2));
    Point<double> p7(-1, 0);
    Point<double> p8(-0.5, -sqrt(2));

    ASSERT_THROW(Octagon<double> tr1(p1,p2,p3,p4,p5,p6,p7,p8), std::logic_error);
}


TEST(octagon_test, area_of_empty){
    Octagon<double> tr;
    ASSERT_EQ(tr.area(), 0.0);
}

TEST(octagon_test, area){
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(2));
    Point<double> p4(1, sqrt(2) + 1);
    Point<double> p5(0, sqrt(2) + 1);
    Point<double> p6(-0.5, sqrt(2));
    Point<double> p7(-1, 0);
    Point<double> p8(-0.5, -sqrt(2));

    Octagon<double> oct(p1, p2, p3, p4, p5, p6, p7, p8);
    ASSERT_NEAR(oct.area(), 2.38018, 0.00001);
    
}

TEST(octagon_test, center_of_empty){
    Octagon<double> tr1;
    Point<double> p1;
    ASSERT_EQ(tr1.center(), p1);
}

TEST(octagon_test, center) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(2));
    Point<double> p4(1, sqrt(2) + 1);
    Point<double> p5(0, sqrt(2) + 1);
    Point<double> p6(-0.5, sqrt(2));
    Point<double> p7(-1, 0);
    Point<double> p8(-0.5, -sqrt(2));

    Octagon oct(p1, p2, p3, p4, p5, p6, p7, p8);
    Point<double> prez{0.1875, 0.78033};
    
    ASSERT_NEAR(oct.center().x_, prez.x_, 0.00001);
    ASSERT_NEAR(oct.center().y_, prez.y_, 0.00001);
}

TEST(octagon_test, equality_empty){
    Octagon<double> tr1;
    Octagon<double> tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(octagon_test, equality_1){
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(2));
    Point<double> p4(1, sqrt(2) + 1);
    Point<double> p5(0, sqrt(2) + 1);
    Point<double> p6(-0.5, sqrt(2));
    Point<double> p7(-1, 0);
    Point<double> p8(-0.5, -sqrt(2));

    Octagon<double> tr1{p1,p3,p2,p4,p5,p6,p7,p8};
    Octagon<double> tr2{p2,p1,p3,p8,p4,p5,p6,p7};
    ASSERT_TRUE(tr1 == tr2);
}

TEST(octagon_test, equality_2){
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(2));
    Point<double> p4(1, sqrt(2) + 1);
    Point<double> p5(0, sqrt(2) + 1);
    Point<double> p6(-0.5, sqrt(2));
    Point<double> p7(-1, 0);
    Point<double> p8(-0.5, -sqrt(2));
    Point<double> p9(5, 1);

    Octagon<double> tr1{p1,p3,p2,p4,p5,p6,p7,p8};
    Octagon<double> tr2{p2,p1,p3,p8,p4,p5,p6,p9};
    ASSERT_FALSE(tr1 == tr2);
}

TEST(octagon_test, assignment_empty){
    Octagon<double> tr1;
    Octagon<double> tr2;
    tr1 = tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(octagon_test, assignment){
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(2));
    Point<double> p4(1, sqrt(2) + 1);
    Point<double> p5(0, sqrt(2) + 1);
    Point<double> p6(-0.5, sqrt(2));
    Point<double> p7(-1, 0);
    Point<double> p8(-0.5, -sqrt(2));
    
    Octagon<double> tr1;
    Octagon<double> tr2{p2,p1,p3,p8,p4,p5,p6,p7};
    tr1 = tr2;
    ASSERT_TRUE(tr1 == tr2);
}


TEST(octagon_test, assignment_move_empty){
    Octagon<double> tr1;
    Octagon<double> tr2;
    tr1 = std::move(tr2);
    ASSERT_TRUE(tr1 == tr2);
}

TEST(octagon_test, assignment_move){
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, 2);
    Point<double> p4(1, 1.2 + 1);
    Point<double> p5(0, 1.2 + 1);
    Point<double> p6(-0.5, 1.2);
    Point<double> p7(-1, 0);
    Point<double> p8(-0.5, -1.2);
    
    Octagon<double> tr1;
    Octagon<double> tr2{p2,p1,p3,p8,p4,p5,p6,p7};
    tr1 = std::move(tr2);
    ASSERT_TRUE(tr1 == tr2);
}

TEST(octagon_test, get_point_empty){
    Point<double> p1(0, 0);
    Octagon<double> tr1;
    for(size_t i = 0; i < 8;++i){
        ASSERT_EQ(tr1.get_point(i), p1);
    }
}

TEST(octagon_test, get_point){
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(2));
    Point<double> p4(1, sqrt(2) + 1);
    Point<double> p5(0, sqrt(2) + 1);
    Point<double> p6(-0.5, sqrt(2));
    Point<double> p7(-1, 0);
    Point<double> p8(-0.5, -sqrt(2));
    
    Octagon<double> tr1{p1,p2,p3,p4,p5,p6,p7,p8};
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
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(2));
    Point<double> p4(1, sqrt(2) + 1);
    Point<double> p5(0, sqrt(2) + 1);
    Point<double> p6(-0.5, sqrt(2));
    Point<double> p7(-1, 0);
    Point<double> p8(-0.5, -sqrt(2));
    
    Octagon<double> tr1{p2,p1,p3,p8,p4,p5,p6,p7};
    ASSERT_THROW(tr1.get_point(8), std::invalid_argument);
    ASSERT_THROW(tr1.get_point(-1), std::invalid_argument);
}

TEST(octagon_test, operator_double) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(2));
    Point<double> p4(1, sqrt(2) + 1);
    Point<double> p5(0, sqrt(2) + 1);
    Point<double> p6(-0.5, sqrt(2));
    Point<double> p7(-1, 0);
    Point<double> p8(-0.5, -sqrt(2));

    Octagon<double> oct(p1, p2, p3, p4, p5, p6, p7, p8);
    ASSERT_NEAR(static_cast<double>(oct), oct.area(), 0.00001);
}

TEST(octagon_test, input) {
    Point<double> p1(1, 8);
    Point<double> p2(2, 7);
    Point<double> p3(3, 6);
    Point<double> p4(4, 5);
    Point<double> p5(5, 4);
    Point<double> p6(6, 3);
    Point<double> p7(7, 2);
    Point<double> p8(8, 1);

    Octagon<double> tr1{p1,p2,p3,p4,p5,p6,p7,p8};

    std::stringstream input("1 8\n8 1\n2 7\n"
                            "7 2\n3 6\n6 3\n"
                            "4 5\n5 4\n");

    Octagon<double> tr2;
    input >> tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(octagon_test, input1) {
    Point<double> p1(1, 8);
    Point<double> p2(2, 7);
    Point<double> p3(3, 6);
    Point<double> p4(4, 5);
    Point<double> p5(5, 4);
    Point<double> p6(6, 3);
    Point<double> p7(7, 2);
    Point<double> p8(8, 1);

    Octagon<double> tr1{p1,p2,p3,p4,p5,p6,p7,p8};

    std::stringstream input("1 8\n8 1\n2 7\n"
                            "7 2\n3 6\n6 3\n"
                            "4 5\n5 0\n");

    Octagon<double> tr2;
    input >> tr2;
    ASSERT_FALSE(tr1 == tr2);
}

TEST(octagon_test, input_excp) {
    std::stringstream input("1 8\n8 1\n2 7\n"
                            "7 2\n3 6\n6 3\n"
                            "4 5\n5 e\n");

    Octagon<double> tr2;
    ASSERT_THROW(input >> tr2, std::invalid_argument);
}

TEST(octagon_test, input_excp1) {
    std::stringstream input("1 8\n8 1\n2 7\n"
                            "7 2\n3 6\n6 3\n"
                            "4 5\n4 5\n");

    Octagon<double> tr2;
    ASSERT_THROW(input >> tr2, std::logic_error);
}

TEST(octagon_test, output) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(2));
    Point<double> p4(1, sqrt(2) + 1);
    Point<double> p5(0, sqrt(2) + 1);
    Point<double> p6(-0.5, sqrt(2));
    Point<double> p7(-1, 0);
    Point<double> p8(-0.5, -sqrt(2));
    Octagon<double> tr1{p1,p2,p3,p4,p5,p6,p7,p8};

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
    Octagon<double> tr1;

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(hexagon_test, def_constructor){
    Hexagon<int> tr;
    ASSERT_EQ(tr.size(), 0);
}

TEST(hexagon_test, point_constructor){
    Point<int> p1(1, 8);
    Point<int> p2(2, 7);
    Point<int> p3(3, 6);
    Point<int> p4(4, 5);
    Point<int> p5(5, 4);
    Point<int> p6(6, 3);

    Hexagon<int> tr{p1,p2,p3,p4,p5,p6};
    for(size_t i = 1; i < 7; ++i){
        ASSERT_EQ(tr.get_point(i-1), Point<int>(i, 9 - i));
    }
}

TEST(hexagon_test, point_constructor_excp){
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1, 0);
    Point<double> p4(1, sqrt(2) + 1);
    Point<double> p5(0, sqrt(2) + 1);
    Point<double> p6(-0.5, sqrt(2));

    ASSERT_THROW(Hexagon<double> tr1(p1,p2,p3,p4,p5,p6), std::logic_error);
}


TEST(hexagon_test, area_of_empty){
    Hexagon<double> tr;
    ASSERT_EQ(tr.area(), 0.0);
}


TEST(hexagon_test, area){
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(3)/2);
    Point<double> p4(1, sqrt(3));
    Point<double> p5(0, sqrt(3));
    Point<double> p6(-0.5, sqrt(3)/2);

    Hexagon<double> hex(p1, p2, p3, p4, p5, p6);
    ASSERT_NEAR(hex.area(), 2.59808, 0.00001);
    
}

TEST(hexagon_test, center_of_empty){
    Hexagon<double> tr1;
    Point<double> p1;
    ASSERT_EQ(tr1.center(), p1);
}

TEST(hexagon_test, center) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(3)/2);
    Point<double> p4(1, sqrt(3));
    Point<double> p5(0, sqrt(3));
    Point<double> p6(-0.5, sqrt(3)/2);

    Hexagon<double> hex(p1, p2, p3, p4, p5, p6);
    Point<double> prez{ 0.5, 0.866025};
    ASSERT_NEAR(hex.center().x_, prez.x_, 0.00001);
    ASSERT_NEAR(hex.center().y_, prez.y_, 0.00001);
}

TEST(hexagon_test, equality_empty){
    Hexagon<double> tr1;
    Hexagon<double> tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(hexagon_test, equality_1){
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(3)/2);
    Point<double> p4(1, sqrt(3));
    Point<double> p5(0, sqrt(3));
    Point<double> p6(-0.5, sqrt(3)/2);

    Hexagon<double> tr1{p1,p3,p2,p4,p5,p6};
    Hexagon<double> tr2{p2,p1,p3,p4,p5,p6};
    ASSERT_TRUE(tr1 == tr2);
}

TEST(hexagon_test, equality_2){
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(3)/2);
    Point<double> p4(1, sqrt(3));
    Point<double> p5(0, sqrt(3));
    Point<double> p6(-0.5, sqrt(3)/2);
    Point<double> p7(0.5, sqrt(3));

    Hexagon<double> tr1{p1,p3,p2,p4,p5,p6};
    Hexagon<double> tr2{p2,p1,p3,p4,p5,p7};
    ASSERT_FALSE(tr1 == tr2);
}

TEST(hexagon_test, assignment_empty){
    Hexagon<double> tr1;
    Hexagon<double> tr2;
    tr1 = tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(hexagon_test, assignment){
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(3)/2);
    Point<double> p4(1, sqrt(3));
    Point<double> p5(0, sqrt(3));
    Point<double> p6(-0.5, sqrt(3)/2);
    
    Hexagon<double> tr1;
    Hexagon<double> tr2{p2,p1,p3,p4,p5,p6};
    tr1 = tr2;
    ASSERT_TRUE(tr1 == tr2);
}


TEST(hexagon_test, assignment_move_empty){
    Hexagon<double> tr1;
    Hexagon<double> tr2;
    tr1 = std::move(tr2);
    ASSERT_TRUE(tr1 == tr2);
}

TEST(hexagon_test, assignment_move){
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(3)/2);
    Point<double> p4(1, sqrt(3));
    Point<double> p5(0, sqrt(3));
    Point<double> p6(-0.5, sqrt(3)/2);
    
    Hexagon<double> tr1;
    Hexagon<double> tr2{p2,p1,p3,p4,p5,p6};
    tr1 = std::move(tr2);
    ASSERT_TRUE(tr1 == tr2);
}

TEST(hexagon_test, get_point_empty){
    Point<double> p1(0, 0);
    Hexagon<double> tr1;
    for(size_t i = 0; i < 6;++i){
        ASSERT_EQ(tr1.get_point(i), p1);
    }
}

TEST(hexagon_test, get_point){
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(3)/2);
    Point<double> p4(1, sqrt(3));
    Point<double> p5(0, sqrt(3));
    Point<double> p6(-0.5, sqrt(3)/2);
    
    Hexagon<double> tr1{p1,p2,p3,p4,p5,p6};
    ASSERT_EQ(tr1.get_point(0), p1);
    ASSERT_EQ(tr1.get_point(1), p2);
    ASSERT_EQ(tr1.get_point(2), p3);
    ASSERT_EQ(tr1.get_point(3), p4);
    ASSERT_EQ(tr1.get_point(4), p5);
    ASSERT_EQ(tr1.get_point(5), p6);
}

TEST(hexagon_test, get_point_excp){
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(3)/2);
    Point<double> p4(1, sqrt(3));
    Point<double> p5(0, sqrt(3));
    Point<double> p6(-0.5, sqrt(3)/2);
    
    Hexagon<double> tr1{p2,p1,p3,p4,p5,p6};
    ASSERT_THROW(tr1.get_point(6), std::invalid_argument);
    ASSERT_THROW(tr1.get_point(-1), std::invalid_argument);
}

TEST(hexagon_test, operator_double) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(3)/2);
    Point<double> p4(1, sqrt(3));
    Point<double> p5(0, sqrt(3));
    Point<double> p6(-0.5, sqrt(3)/2);
    
    Hexagon<double> tr1{p2,p1,p3,p4,p5,p6};
    ASSERT_NEAR(static_cast<double>(tr1), tr1.area(), 0.00001);
}

TEST(hexagon_test, input) {
    Point<double> p1(1, 8);
    Point<double> p2(2, 7);
    Point<double> p3(3, 6);
    Point<double> p4(4, 5);
    Point<double> p5(5, 4);
    Point<double> p6(6, 3);

    Hexagon<double> tr1{p1,p2,p3,p4,p5,p6};

    std::stringstream input("1 8\n4 5\n2 7\n"
                            "5 4\n3 6\n6 3\n");

    Hexagon<double> tr2;
    input >> tr2;
    ASSERT_TRUE(tr1 == tr2);
}

TEST(hexagon_test, input1) {
    Point<double> p1(1, 8);
    Point<double> p2(2, 7);
    Point<double> p3(3, 6);
    Point<double> p4(4, 5);
    Point<double> p5(5, 4);
    Point<double> p6(6, 3);

    Hexagon<double> tr1{p1,p2,p3,p4,p5,p6};

    std::stringstream input("1 8\n8 1\n2 7\n"
                            "7 2\n3 6\n6 1\n");

    Hexagon<double> tr2;
    input >> tr2;
    ASSERT_FALSE(tr1 == tr2);
}

TEST(hexagon_test, input_excp) {
    std::stringstream input("1 8\n8 1\n2 7\n"
                            "7 2\n3 6\n4 e\n");

    Hexagon<double> tr2;
    ASSERT_THROW(input >> tr2, std::invalid_argument);
}

TEST(hexagon_test, input_excp1) {
    std::stringstream input("1 8\n8 1\n2 7\n"
                            "7 2\n3 6\n3 6\n");

    Hexagon<double> tr2;
    ASSERT_THROW(input >> tr2, std::logic_error);
}

TEST(hexagon_test, output) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1.5, sqrt(3)/2);
    Point<double> p4(1, sqrt(3));
    Point<double> p5(0, sqrt(3));
    Point<double> p6(-0.5, sqrt(3)/2);
    
    Hexagon<double> tr1{p2,p1,p3,p4,p5,p6};

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
    Hexagon<double> tr1;

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