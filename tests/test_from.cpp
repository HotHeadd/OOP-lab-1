#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../task/from_yaml.hpp"
#include <vector>
#include <string>

using namespace testing;

TEST(from_char, first){
    const char* input_1 = "asdf:\n - 123\n - -234";
    const char* input_2 = "asdf:";

    std::vector result_1 = from_yaml(input_1);

    EXPECT_THAT(result_1, ElementsAre(123, -234));
    EXPECT_ANY_THROW(from_yaml(input_2));
}

TEST(from_sizet, first){
    const char input_1[] = {
        'a', 's', 'd', 'f', ':', '\n', 
        ' ', '-', '1', '2', '3', '\n',
        ' ', '-', '-', '2', '3', '4'
    };
    size_t size_1 = 18;
    const char input_2[] = {'a', 's', 'd', ':'};
    size_t size_2 = 4;

    std::vector result_1 = from_yaml(input_1, size_1);

    EXPECT_THAT(result_1, ElementsAre(123, -234));
    EXPECT_ANY_THROW(from_yaml(input_2, size_2));
}

TEST(from_string, correct){
    std::string input_1 = "asdf:\n - 123\n - -234";
    std::string input_2 = "asdf: null";
    std::string input_3 = "asdf:\n -123";

    std::vector result_1 = from_yaml(input_1);
    std::vector result_2 = from_yaml(input_2);
    std::vector result_3 = from_yaml(input_3);

    EXPECT_THAT(result_1, ElementsAre(123, -234));
    EXPECT_THAT(result_2, ElementsAre());
    EXPECT_THAT(result_3, ElementsAre(123));
}

TEST(from_string, throws){
    std::string input_1 = "asdf:\n123\n - 324";
    std::string input_2 = "asdf:";
    std::string input_3 = "!sdf:\n - 123\n - -234";
    std::string input_4 = "asnf null";
    std::string input_5 = "sdf\n - 123\n - -234";
    std::string input_6 = "sdf\n- 123\n - -234";
    std::string input_7 = "sdf:\n -123 455";
    std::string input_8 = ":\n -123455";
    std::string input_9 = "s:df\n -123455";
    std::string input_10 = "sdf:\n -123 asd   ";
    std::string input_11 = "sdf:\n -\t123";
    std::string input_12 = "asdf:\n - 123\n - -234\n -   ";

    EXPECT_ANY_THROW(from_yaml(input_1));
    EXPECT_ANY_THROW(from_yaml(input_2));
    EXPECT_ANY_THROW(from_yaml(input_3));
    EXPECT_ANY_THROW(from_yaml(input_4));
    EXPECT_ANY_THROW(from_yaml(input_5));
    EXPECT_ANY_THROW(from_yaml(input_6));
    EXPECT_ANY_THROW(from_yaml(input_7));
    EXPECT_ANY_THROW(from_yaml(input_8));
    EXPECT_ANY_THROW(from_yaml(input_9));
    EXPECT_ANY_THROW(from_yaml(input_10));
    EXPECT_ANY_THROW(from_yaml(input_11));
    EXPECT_ANY_THROW(from_yaml(input_12));
}
