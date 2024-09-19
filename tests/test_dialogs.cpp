#include <gtest/gtest.h>
// #include <gmock/gmock.h>
#include "../dialog/get_values.hpp"
#include <string>
#include <fstream>
#include <sstream>

using namespace get_values;

TEST(get_menu_opt, test){
    char expected_1 = 'a';
    char expected_2 = 'd';
    std::istringstream fake_input("a\nabc\nd\n");
    std::ostringstream fake_output;
    std::ifstream fake_file;
    fake_file.open("example");
    fake_file.setstate(std::ios::badbit);
    char result_1 = get_menu_opt(fake_input, fake_output);
    char result_2 = get_menu_opt(fake_input, fake_output);

    ASSERT_EQ(result_1, expected_1);
    ASSERT_EQ(result_2, expected_2);
    ASSERT_EQ("Please, try again: ", fake_output.str());

    EXPECT_THROW(get_menu_opt(fake_input, fake_output), std::runtime_error);
    EXPECT_THROW(get_menu_opt(fake_file, fake_output), std::runtime_error);
}

TEST(get_num, test){
    int expected_1 = 123;
    double expected_2 = 2.5;
    unsigned expected_3 = 3;
    std::istringstream fake_input("123\n2.5abc\n2.5\n a3\n*4\n  3\n");
    std::ostringstream fake_output;
    std::ifstream fake_file;
    fake_file.open("example");

    int result_1 = get_num<int>(fake_input, fake_output);
    double result_2 = get_num<double>(fake_input, fake_output);

    ASSERT_EQ(result_1, expected_1);
    ASSERT_EQ(result_2, expected_2);
    ASSERT_EQ("Wrong data format; Try again: ", fake_output.str());
    fake_output.str(std::string());

    unsigned result_3 = get_num<unsigned>(fake_input, fake_output);
    ASSERT_EQ(result_3, expected_3);
    ASSERT_EQ("Wrong data format; Try again: Wrong data format; Try again: ", fake_output.str());

    EXPECT_THROW(get_num<int>(fake_input, fake_output), std::runtime_error);
    EXPECT_THROW(get_num<int>(fake_file, fake_output), std::runtime_error);
}
