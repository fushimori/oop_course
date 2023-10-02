#include <gtest/gtest.h>
#include "include.h"

TEST(twelve_test, def_constructor){
    Twelve tw;
    ASSERT_EQ(tw.get_arr(), nullptr);
    ASSERT_EQ(tw.get_size(), 0);
}

TEST(twelve_test, char_constructor){
    Twelve tw(100);
    ASSERT_EQ(tw.get_size(), 100);
    unsigned char* arr = tw.get_arr();
    for(size_t i = 0; i < tw.get_size(); i++)
        ASSERT_EQ(arr[i], '0'); 
}

TEST(twelve_test, init_list_constructor){
    Twelve tw{'B','A','9','8','7','6','5','4','3','2','1','0'};
    ASSERT_EQ(tw.get_size(), 12);
    unsigned char* arr = tw.get_arr();
    for(size_t i = 0; i < 10; i++){
        ASSERT_EQ(arr[i], '0' + i);
    }
    for(size_t i = 10; i < 12; i++){
        ASSERT_EQ(arr[i], 'A' + i - 10);
    }
    
}

TEST(twelve_test, string_constructor){
    std::string str{"BA9876543210"};
    Twelve tw(str);
    ASSERT_EQ(tw.get_size(), 12);
    unsigned char* arr = tw.get_arr();
    for(size_t i = 0; i < 12; i++){
        ASSERT_EQ(arr[i], str[11 - i]);
    }
    
}

TEST(twelve_test, exp_char_constructor_1){
    ASSERT_THROW(Twelve tw(3,'-'), std::invalid_argument);
}
TEST(twelve_test, exp_char_constructor_2){
    ASSERT_THROW(Twelve tw(3,'C'), std::invalid_argument);
}
TEST(twelve_test, exp_char_constructor_3){
    char s;
    ASSERT_THROW(Twelve tw(3,s), std::invalid_argument);
}

TEST(twelve_test, exp_init_list_constructor_1){
    ASSERT_THROW(Twelve tw{"12-"}, std::invalid_argument);
}
TEST(twelve_test, exp_init_list_constructor_2){
    ASSERT_THROW(Twelve tw{"12С"}, std::invalid_argument);
}
TEST(twelve_test, exp_init_list_constructor_3){
    ASSERT_THROW(Twelve tw{""}, std::invalid_argument);
}

TEST(twelve_test, exp_string_constructor_1){
    std::string str{"10D"};
    ASSERT_THROW(Twelve tw(str), std::invalid_argument);
}
TEST(twelve_test, exp_string_constructor_2){
    std::string str{"23+1"};
    ASSERT_THROW(Twelve tw(str), std::invalid_argument);
}
TEST(twelve_test, exp_string_constructor_3){
    std::string str{""};
    ASSERT_THROW(Twelve tw(str), std::invalid_argument);
}

TEST(twelve_test, copy){
    Twelve tw1("ABABA");
    Twelve tw2(tw1);
    ASSERT_TRUE(tw1.equals(tw2));
}
TEST(twelve_test, copy_1){
    Twelve tw1;
    Twelve tw2(tw1);
    ASSERT_TRUE(tw1.equals(tw2));
}

TEST(twelve_test, move){
    std::string str{"BABAB"};
    Twelve tw1{str};
    Twelve tw2(std::move(tw1));
    ASSERT_EQ(tw1.get_size(), 0);
    ASSERT_EQ(tw1.get_arr(), nullptr);
    ASSERT_EQ(tw2.get_size(), 5);
    unsigned char* arr = tw2.get_arr();
    for(size_t i = 0; i < 4; i++)
        ASSERT_EQ(arr[i], str[4 - i]);
}
TEST(twelve_test, move_1){
    Twelve tw1;
    Twelve tw2(std::move(tw1));
    ASSERT_EQ(tw1.get_size(), 0);
    ASSERT_EQ(tw1.get_arr(), nullptr);
    ASSERT_EQ(tw2.get_size(), 0);
    ASSERT_EQ(tw2.get_arr(), nullptr);
}

TEST(twelve_test, equals){
    std::string str{"0000001"};
    Twelve tw1{str};
    Twelve tw2{"001"};
    ASSERT_TRUE(tw1.equals(tw2));
}
TEST(twelve_test, equals_1){
    Twelve tw1;
    Twelve tw2;
    ASSERT_TRUE(tw1.equals(tw2));
}
TEST(twelve_test, equals_2){
    Twelve tw1;
    Twelve tw2("123");
    ASSERT_FALSE(tw1.equals(tw2));
}

TEST(twelve_test, greater){
    std::string str{"ABB"};
    Twelve tw1{str};
    Twelve tw2{"ABA"};
    ASSERT_TRUE(tw1.greater(tw2));
}
TEST(twelve_test, greater_1){
    std::string str{"ABA"};
    Twelve tw1{str};
    Twelve tw2{"ABB"};
    ASSERT_FALSE(tw1.greater(tw2));
}
TEST(twelve_test, greater_2){
    std::string str{"AAA"};
    Twelve tw1{str};
    Twelve tw2{"AAA"};
    ASSERT_FALSE(tw1.greater(tw2));
}

TEST(twelve_test, less){
    std::string str{"ABB"};
    Twelve tw1{str};
    Twelve tw2{"ABA"};
    ASSERT_FALSE(tw1.less(tw2));
}
TEST(twelve_test, less_1){
    std::string str{"ABA"};
    Twelve tw1{str};
    Twelve tw2{"ABB"};
    ASSERT_TRUE(tw1.less(tw2));
}
TEST(twelve_test, less_2){
    std::string str{"AAA"};
    Twelve tw1{str};
    Twelve tw2{"AAA"};
    ASSERT_FALSE(tw1.less(tw2));
}

TEST(twelve_test, add_1){
    std::string str{"BBB"};
    Twelve tw1{str};
    Twelve tw2{"00000000000001"};
    Twelve tw3 = tw1.add(tw2);
    std::string rez{"1000"};
    unsigned char* arr = tw3.get_arr();
    for(size_t i = 0; i < 4; i++)
        ASSERT_EQ(arr[i], rez[3 - i]);
}
TEST(twelve_test, add_2){
    std::string str{"00000000000001"};
    Twelve tw1{str};
    Twelve tw2{"BBB"};
    Twelve tw3 = tw1.add(tw2);
    std::string rez{"1000"};
    unsigned char* arr = tw3.get_arr();
    for(size_t i = 0; i < 4; i++)
        ASSERT_EQ(arr[i], rez[3 - i]);
}
TEST(twelve_test, add_3){
    std::string str(5,'1');
    Twelve tw1{str};
    Twelve tw2(10,'0');
    Twelve tw3 = tw1.add(tw2);
    std::string rez{"11111"};
    unsigned char* arr = tw3.get_arr();
    for(size_t i = 0; i < 5; i++)
        ASSERT_EQ(arr[i], rez[4 - i]);
}
TEST(twelve_test, add_4){
    std::string str{"1111"};
    Twelve tw1;
    Twelve tw2(str);
    ASSERT_TRUE(tw2.equals(tw1.add(tw2)));
}
TEST(twelve_test, add_5){
    std::string str{"1111"};
    Twelve tw1(str);
    Twelve tw2;
    ASSERT_TRUE(tw1.equals(tw1.add(tw2)));
}
TEST(twelve_test, add_6){
    Twelve tw1;
    Twelve tw2;
    ASSERT_TRUE(tw1.equals(tw1.add(tw2)));
}
TEST(twelve_test, add_7){
    Twelve tw1("0");
    Twelve tw2("0");
    ASSERT_TRUE(tw1.equals(tw1.add(tw2)));
}

TEST(twelve_test, subtract_1){
    std::string str{"BBB"};
    Twelve tw1{str};
    Twelve tw2{"00000000000001"};
    Twelve tw3 = tw1.subtract(tw2);
    std::string rez{"BBA"};
    unsigned char* arr = tw3.get_arr();
    for(size_t i = 0; i < 3; i++)
        ASSERT_EQ(arr[i], rez[2 - i]);
}
TEST(twelve_test, subtract_2){
    std::string str{"BBB"};
    Twelve tw1{str};
    Twelve tw2{"BBB"};
    Twelve tw3 = tw1.subtract(tw2);
    unsigned char* arr = tw3.get_arr();
    ASSERT_EQ(arr[0], '0');
}
TEST(twelve_test, subtract_3){
    Twelve tw1{"AAA"};
    Twelve tw2;
    ASSERT_TRUE(tw1.equals(tw1.subtract(tw2)));
}
TEST(twelve_test, subtract_4){
    Twelve tw1;
    Twelve tw2;
    Twelve tw3 = tw1.subtract(tw2);
    unsigned char* arr = tw3.get_arr();
    ASSERT_EQ(arr[0],'0');
}
TEST(twelve_test, subtract_5){
    Twelve tw1("0");
    Twelve tw2("0");
    Twelve tw3 = tw1.subtract(tw2);
    unsigned char* arr = tw3.get_arr();
    ASSERT_EQ(arr[0],'0');
}

TEST(twelve_test, subtract_exp_1){
    std::string str{"101"};
    Twelve tw1{str};
    Twelve tw2{"BBB"};
    ASSERT_THROW(tw1.subtract(tw2), std::logic_error);
}
TEST(twelve_test, subtract_exp_2){
    Twelve tw1;
    Twelve tw2{"BBB"};
    ASSERT_THROW(tw1.subtract(tw2), std::logic_error);
}

TEST(twelve_test, print) {
    Twelve tw{'0','1', '2', 'A', 'B'};
    std::ostringstream os;

    tw.print(os);

    std::string expectedOutput = "12AB";
    EXPECT_EQ(os.str(), expectedOutput);
}
TEST(twelve_test, print_1) {
    Twelve tw(100);
    std::ostringstream os;

    tw.print(os);

    std::string expectedOutput = "0";
    EXPECT_EQ(os.str(), expectedOutput);
}
TEST(twelve_test, print_2) {
    Twelve tw{"00012345"};
    std::ostringstream os;

    tw.print(os);

    std::string expectedOutput = "12345";
    EXPECT_EQ(os.str(), expectedOutput);
}
TEST(twelve_test, print_3) {
    Twelve tw;
    std::ostringstream os;

    tw.print(os);

    std::string expectedOutput = "";
    EXPECT_EQ(os.str(), expectedOutput);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}