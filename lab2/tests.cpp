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

TEST(twelve_test, exp_char_constructor){
    ASSERT_THROW(Twelve tw(3,'-'), std::invalid_argument);
}
TEST(twelve_test, exp_init_list_constructor){
    ASSERT_THROW(Twelve tw{"12-"}, std::invalid_argument);
}
TEST(twelve_test, exp_string_constructor){
    std::string str{"WDZXCAB0101"};
    ASSERT_THROW(Twelve tw(str), std::invalid_argument);
}

TEST(twelve_test, copy){
    Twelve tw1("ABABA");
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

TEST(twelve_test, equals){
    std::string str{"0000001"};
    Twelve tw1{str};
    Twelve tw2{"001"};
    ASSERT_TRUE(tw1.equals(tw2));
}

TEST(twelve_test, greater){
    std::string str{"ABB"};
    Twelve tw1{str};
    Twelve tw2{"ABA"};
    ASSERT_TRUE(tw1.greater(tw2));
}

TEST(twelve_test, less){
    std::string str{"ABB"};
    Twelve tw1{str};
    Twelve tw2{"ABA"};
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
    std::string rez{"0"};
    unsigned char* arr = tw3.get_arr();
    for(size_t i = 0; i < 1; i++)
        ASSERT_EQ(arr[i], rez[i]);
}
TEST(twelve_test, subtract_exp){
    std::string str{"101"};
    Twelve tw1{str};
    Twelve tw2{"BBB"};
    ASSERT_THROW(tw1.subtract(tw2), std::logic_error);
}

TEST(twelve_test, print) {
    Twelve tw{'1', '2', 'A', 'B'};
    std::ostringstream os;

    tw.print(os);

    std::string expectedOutput = "12AB";
    EXPECT_EQ(os.str(), expectedOutput);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}