/**
 * @file to_yaml.cpp
 * @author Vladimir Docenko
 * @brief Fist part of task (from vector + name to YAML format string)
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "to_yaml.hpp"
#include <stdexcept>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring> // only for strlen in line 32 


/**
 * @brief Function that checks if string is in YAML format
 * 
 * @param name string_view
 * @return true if string is in YAML format
 * @return false if not
 */
bool check_format(std::string_view name){
    if (name.size() == 0) return false;
    if (name.find(" ") != std::string::npos) return false;
    if (name.find("\t") != std::string::npos) return false;
    if (!isalnum(name.at(0))) return false;
    return true;
}
/**
 * @brief Transforms int to size_t (required amount of bytes to keep int in string format)
 * 
 * @param num processed number
 * @return size_t length of char* array, which contains processed num 
 */
size_t to_size(int num){
    size_t ans = 1;
    if (num < 0){
        ans += 1;
        num *= (-1);
    }
    while (num > 9){
        num /= 10;
        ans += 1;
    }
    return ans;
}
/**
 * @brief Overloading of to_yaml function for null-terminated C strings. Basically calls char+size_t overloading of itself
 * 
 * @param array numbers, which should be put in YAML seuqence
 * @param name key of this sequence in YAML (null-terminated)
 * @return char* null-terminated string in YAML format
 * @throws invalid_argument if name is not in YAML format
 */
char* to_yaml(const std::vector<int>& array, const char* name){
    size_t out_size;
    char* ans = to_yaml(array, name, std::strlen(name)+1, out_size);
    return ans;
}

/**
 * @brief Overloading of to_yaml function for char arrays and its length. Transforms vector and its name to YAML format char array
 * 
 * @param array numbers, which should be put in YAML seuqence
 * @param name key of this sequence in YAML (non-null-terminated char array
 * @param in_size length on name array
 * @param out_size reference to value, where size of the returned char array should be put
 * @return char array, which with its size if out_size forms YAML format string
 * @throws invalid_argument if name is not in YAML format
 */
char* to_yaml(const std::vector<int>& array, const char* name, size_t in_size, size_t& out_size){
    std::string_view name_sv = std::string_view(name, in_size);
    if (!check_format(name_sv)){
        throw std::invalid_argument("Name is not in YAML format");
    }
    out_size = in_size + 1;
    if (array.empty()){
        out_size += 5;
    }
    for (int i : array){
        out_size += to_size(i) + 5;
    }
    char* ans = new char[out_size]{0};
    char* current = ans;
    if (name_sv.back() == '\0'){
        in_size -= 1;
    }
    std::copy(name, name+in_size, current);
    current += in_size;
    const char* symbol = ":";
    std::copy(symbol,symbol+1, current);
    current += 1;
    if (array.empty()){
        const char* null = " null";
        std::copy(null, null+5, current);
    }
    for (int i : array){
        const char* nec = "\n  - ";
        std::copy(nec, nec+5, current);
        current += 5;
        std::string repr = std::to_string(i);
        std::copy(repr.c_str(), repr.c_str()+repr.size(), current);
        current += repr.size();
    }
    return ans;
}

/**
 * @brief Overloading of to_yaml function for c++ strings. Transforms vector and its name to YAML format string
 * 
 * @param array numbers, which should be put in YAML seuqence
 * @param name  key of this sequence in YAML (c++ string or string_view)
 * @return std::string: YAML format sequence
 * @throws invalid_argument if name is not in YAML format
 */
std::string to_yaml(const std::vector<int>& array, std::string_view name){ 
    if (!check_format(name)){
        throw std::invalid_argument("Name is not in YAML format");
    }
    std::string ans;
    ans += std::string(name) + ":";
    for (int i : array){
        ans += "\n  - " + std::to_string(i);
    }
    if (array.empty())
        ans += " null";
    return ans;}