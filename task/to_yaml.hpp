#pragma once

#include <string>
#include <vector>

bool check_format(std::string_view name);

char* to_yaml(const std::vector<int>& array, const char* name);
char* to_yaml(const std::vector<int>& array, const char* name, size_t in_size, size_t& out_size);
std::string to_yaml(const std::vector<int>& array, std::string_view name);