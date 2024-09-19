#pragma once

#include <string>
#include <vector>

std::vector<int> from_yaml(const char*);
std::vector<int> from_yaml(const char*, size_t);
std::vector<int> from_yaml(std::string_view);