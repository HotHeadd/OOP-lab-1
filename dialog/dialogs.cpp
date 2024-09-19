#include "dialogs.hpp"
#include "get_values.hpp"
#include "to_yaml.hpp"
#include "from_yaml.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <stdexcept>


using namespace get_values;

void menu(int mode){
    std::cout << std::endl << "Choose an option" << std::endl;
    std::cout << "(1) Convert from array to yaml" << std::endl;
    std::cout << "(2) Convert yaml string to array" << std::endl;
    std::cout << "(3) Change overloading mode (current is " << mode << ")" <<  std::endl;
    std::cout << ">> ";
}

void print_array(std::string name, std::vector<int> array){
    std::cout << "Array named \"" << name << "\"" << std::endl;
    for (int i: array){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void d_arr_to_yaml(int& mode){
    std::cout << "Input yaml array key: ";
    std::string name;
    std::getline(std::cin, name);
    if (std::cin.eof()){
        throw std::runtime_error("EOF detected");
    }
    std::cout << "Input amount of elements in the array: ";
    int amount = get_num<int>(std::cin, std::cout);
    std::vector<int> array;
    for (int i=0; i<amount; i++){
        std::cout << "Input element " << i << ": ";
        array.push_back(get_num<int>(std::cin, std::cout));
    }
    try{
        if (mode == 1){
            char* ans = to_yaml(array, name.c_str());
            std::cout << "Here is your answer (mode 1):\n" << ans << std::endl;
            delete[] ans;
        }
        if (mode == 2){
            size_t out_size;
            char* ans = to_yaml(array, name.c_str(), name.size(), out_size);
            std::cout << "Here is your answer (mode 2):" << std::endl;
            for (int i=0; i<out_size; i++){
                std::cout << ans[i];
            }
            std::cout << std::endl;
            delete[] ans;
        }
        if (mode == 3){
            std::string ans = to_yaml(array, name);
            std::cout << "Here is your answer (mode 3)\n" << ans << std::endl;
        }
    }
    catch(std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    }
}

void d_yaml_to_arr(int& mode){
    std::cout << "Input YAML format string. Put empty string to stop the input." << std::endl;
    std::string curr_line, input_string;
    while (true){
        std::getline(std::cin, curr_line);
        if (std::cin.eof()){
            throw std::runtime_error("EOF detected");
        }
        if (curr_line.size() == 0)
            break;
        if (input_string.size() != 0)
            input_string += "\n";
        input_string += curr_line; 
    }
    std::cout << "Your line\n\"" << input_string << "\"\n";
    try{
        std::vector<int> ans;
        if (mode == 1)
            ans = from_yaml(input_string.c_str());
        if (mode == 2)
            ans = from_yaml(input_string.c_str(), input_string.size());
        if (mode == 3)
            ans = from_yaml(input_string);
        std::cout << "Here is your answer" << std::endl;
        for (int i : ans){
            std::cout << i << " ";
        }
        if (ans.empty())
            std::cout << "Array is empty" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    }
}

void change_mode(int& mode){
    std::cout << "Choose new overloading mode" << std::endl;
    std::cout << "(1) char* null-terminated" << std::endl;
    std::cout << "(2) char* + size_t" << std::endl;
    std::cout << "(3) std::string" << std::endl << ">> ";
    switch (get_menu_opt(std::cin, std::cout)){
        case '1':
            mode = 1;
            break;
        case '2':
            mode = 2;
            break;
        case '3':
            mode = 3;
            break;
        default:
            std::cout << "Wrong menu option! No changes applied" << std::endl;
    }
}