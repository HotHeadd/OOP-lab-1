/**
 * @file from_yaml.cpp
 * @author Vladimir Docenko
 * @brief Second part of task (from YAML string to vector)
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "from_yaml.hpp"
#include "to_yaml.hpp"
#include <vector>
#include <string>
#include <string_view>
#include <stdexcept>

/**
 * @brief Transfroms line of yaml string (not first) to element of int vector
 * 
 * @param line representation one line (not first) of the YAML string
 * @return int element of int vector
 * @throws invalid_argument if line not in YAML format or if there's no integer in line
 */
int line_to_int(std::string_view line){
    line = line.substr(0, line.find_last_not_of(" ")+1);
    int ans=0;
    short multiply = 1;
    bool no_minus = true;
    auto curr = line.begin();
    while (*curr == ' '){
        curr ++;
        if (*curr == '-'){
            if (no_minus) no_minus = false;
            else break;
            curr++;
        }
        if (curr == line.end())
            throw std::invalid_argument("Empty value in one of lines");
    }
    if (*curr == '-'){
        multiply = -1;
        curr ++;
    }
    for (curr; curr != line.end(); curr++){
        if (!std::isdigit(*curr))
            throw std::invalid_argument("Integer format error");
        ans *= 10;
        ans += (multiply)*(*curr - '0');
    }
    return ans;
}

/**
 * @brief Overloading of from yaml function for null-terminated strings. Basically calls overloading of itself for c++ strings 
 * 
 * @param input null-terminated c-string, YAML sequence string
 * @return std::vector<int> integers from YAML string
 * @throws invalid_argument if input is not in YAML format
 */
std::vector<int> from_yaml(const char* input){
    return from_yaml(std::string_view(input));
}

/**
 * @brief Overloading of from yaml function for char arrays. Basically calls overloading of itself for c++ strings 
 * 
 * @param input char array, YAML sequence string
 * @return std::vector<int> integers from YAML string
 * @throws invalid_argument if input is not in YAML format
 */
std::vector<int> from_yaml(const char* input, size_t size){
    return from_yaml(std::string_view(input, size));
}

/**
 * @brief Overloading of from yaml function for c++ strings 
 * 
 * @param input std::string_view, YAML sequence string
 * @return std::vector<int> integers from YAML string
 * @throws invalid_argument if input is not in YAML format
 */
std::vector<int> from_yaml(std::string_view input){
    if (input.find("\t") != std::string::npos)
        throw std::invalid_argument("Tabs are forbidden in YAML");
    std::vector<int> ans;
    std::size_t index = input.find("\n");
    std::size_t cursor = index;
    std::string_view line = input.substr(0, cursor);
    if ((index == std::string::npos) and (input.find("null") == std::string::npos))
        throw std::invalid_argument("No null in empty sequence");
    if ((index != std::string::npos) and (line.back() != ':'))
        throw std::invalid_argument("Not YAML format: letters after \":\"");
    index = line.find(":");
    if (index == std::string::npos)
        throw std::invalid_argument("Wrong string format. (no \":\")");
    std::string_view name = line.substr(0, index);
    if (!check_format(name)){
        throw std::invalid_argument("Name is not in YAML format");
    }
    while (true){
        if ((cursor == std::string::npos) or (input[cursor] == input.back()))
            return ans;
        input.remove_prefix(cursor+1);
        cursor = input.find('\n');
        line = input.substr(0, cursor);
        index = line.find_first_not_of(" ");
        if ((line.front() != ' ') or (index == std::string::npos) or(line[index] != '-'))
            throw std::invalid_argument("One of the lines is not in YAML format (space or -)");
        ans.push_back(line_to_int(line));
    }
}