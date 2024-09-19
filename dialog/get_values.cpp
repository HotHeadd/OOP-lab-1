/**
 * @file get_values.cpp
 * @author Vladimir Docenko
 * @brief 
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

#include "get_values.hpp"
#include "../task/to_yaml.hpp"


namespace get_values{
	/**
	 * @brief Get the menu opt functtion. For getting exactly 1 char for choosing menu option
	 * 
	 * @param input stream (for wider usage and comfortable testing)
	 * @param output stream (for wider usage and comfortable testing)
	 * @return char (menu option)
	 * @throws runtime_error when invalid stream or EOF found
	 */
	char get_menu_opt(std::istream& input, std::ostream& output){
		char buk;
		input.get(buk);
		while (!(input.good()) || (input.get() != '\n')){
			if (input.bad())
				throw std::runtime_error("Failed. Probably wrong stream");
			if (input.eof())
				throw std::runtime_error("EOF detected");
			input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			input.clear();
			output << "Please, try again: ";
			input.get(buk);
		}
		return buk;
	}
}