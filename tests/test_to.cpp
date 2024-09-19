#include <gtest/gtest.h>
// #include <gmock/gmock.h>
#include "../task/to_yaml.hpp"
#include <string>
#include <vector>

TEST(check_format, test){
    std::string input_1 = "array123";
    std::string input_2 = "name with spaces and tabs";
    std::string input_3 = "*start_with_special";
    bool expected_1 = true;
    bool expected_2 = false;
    bool expected_3 = false;

    bool result_1 = check_format(input_1);
    bool result_2 = check_format(input_2);
    bool result_3 = check_format(input_3);

    ASSERT_EQ(result_1, expected_1);
    ASSERT_EQ(result_2, expected_2);
    ASSERT_EQ(result_3, expected_3);
}

TEST(to_yaml_char, first){
    std::vector<int> input_1 = {1, 22, 333};
    std::vector<int> input_2;
    std::vector<int> input_3 = {1, 2, 3};
    const char* name_1 = "array123";
    const char* name_2 = "correct_name";
    const char* name_3 = "&incorrect_name";
    const char* expected_1 = "array123:\n  - 1\n  - 22\n  - 333";
    const char* expected_2 = "correct_name: null";

    const char* result_1 = to_yaml(input_1, name_1);
    const char* result_2 = to_yaml(input_2, name_2);
    EXPECT_THROW(to_yaml(input_3, name_3), std::invalid_argument) << "Неверное имя обработано" << std::endl;

    EXPECT_STREQ(result_1, expected_1);
    EXPECT_STREQ(result_2, expected_2);
}

TEST(to_yaml_sizet, first){
    std::vector<int> input_1 = {-1, 2, 3};
    std::vector<int> input_2;
    std::vector<int> input_3 = {1, 2, 3};
    const char name_1[] = {'a', 'r', 'r', 'a', 'y', '1', '2', '3'};
    const char name_2[] = {'c', 'o', 'r', 'r', 'e', 'c', 't'};
    const char name_3[] = {'&', 'i', 'n', 'c', 'o', 'r', 'r', 'e', 'c', 't'};
    size_t size_1 = 8;
    size_t size_2 = 7;
    size_t size_3 = 10;
    const char expected_1[] = {'a', 'r', 'r', 'a', 'y', '1', '2', '3', ':', '\n',
                                 ' ', ' ', '-', ' ', '-', '1', '\n',
                                 ' ', ' ', '-', ' ', '2', '\n',
                                 ' ', ' ', '-', ' ', '3'};
    const char expected_2[] = {'c', 'o', 'r', 'r', 'e', 'c', 't', ':', ' ', 'n', 'u', 'l', 'l'};
    size_t expected_size_1 = 28;
    size_t expected_size_2 = 13;

    size_t res_size_1;
    size_t res_size_2;
    size_t res_size_3;
    const char * result_1 = to_yaml(input_1, name_1, size_1, res_size_1);
    const char * result_2 = to_yaml(input_2, name_2, size_2, res_size_2);
    EXPECT_THROW(to_yaml(input_3, name_3, size_3, res_size_3), std::invalid_argument) << "Неверное имя обработано" << std::endl;

    ASSERT_EQ(res_size_1, expected_size_1);
    ASSERT_EQ(res_size_2, expected_size_2);

    for (int i=0; i < res_size_1; i++){
        EXPECT_EQ(result_1[i], expected_1[i]);
    }
    for (int i=0; i < res_size_2; i++){
        EXPECT_EQ(result_2[i], expected_2[i]);
    }
}

TEST(to_yaml_string, first){
    std::vector<int> input_1 = {-1, 2, 3};
    std::vector<int> input_2;
    std::vector<int> input_3 = {1, 2, 3};
    std::string name_1 = "array123";
    std::string name_2 = "correct_name";
    std::string name_3 = "&incorrect_name";
    std::string expected_1 = "array123:\n  - -1\n  - 2\n  - 3";
    std::string expected_2 = "correct_name: null";

    std::string result_1 = to_yaml(input_1, name_1);
    std::string result_2 = to_yaml(input_2, name_2);
    EXPECT_THROW(to_yaml(input_3, name_3), std::invalid_argument) << "Неверное имя обработано" << std::endl;

    EXPECT_EQ(result_1, expected_1);
    EXPECT_EQ(result_2, expected_2);
}