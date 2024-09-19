/**
 * @file get_values.hpp
 * @author VLadimir Docenko
 * @brief 
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once
#include <iostream>
#include <limits>

namespace get_values{
    char get_menu_opt(std::istream& input, std::ostream& output);
    /**
     * @brief Template function to get int/double/ll/etx.
     * 
     * @tparam T 
     * @param input stream (for wider usage and comfortable testing)
     * @param output stream (for wider usage and comfortable testing)
     * @param min value of template object
     * @param max value of template object
     * @return T num object
     */
    template <typename T>
	T get_num(std::istream& input, std::ostream& output, 
                T min = std::numeric_limits<T>::lowest(), 
                T max = std::numeric_limits<T>::max()){
        T a;
		while(true) {
            input >> a;
            if(input.eof())
                throw std::runtime_error("Failed to read number: EOF");
            else if(input.bad())
                throw std::runtime_error("Failed to read number");
            // прочие ошибки (неправильный формат ввода) либо число не входит в заданный диапазон
            else if(input.fail() || a < min || a > max || (input.get() != '\n')) {
                input.clear();
                input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                output << "Wrong data format; Try again: ";
            }
            else // успешный ввод
                return a;
        }
	}
}
