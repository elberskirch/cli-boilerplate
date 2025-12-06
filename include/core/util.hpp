#pragma once

#include <fstream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

namespace util {
using namespace std::literals;

static std::vector<std::string> strToVector(const std::string& input,
                                            const std::string& delim = "\n") {
  std::vector<std::string> result;
  auto view = input | std::views::split(delim);
  for (auto part : view) {
    result.emplace_back(std::string(part.begin(), part.end()));
  }
  return result;
};

static std::string loadFileAsString(const std::string& filepath) {
  std::ifstream file(filepath);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file: " + filepath);
  }
  std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
  file.close();
  return content;
}
} // namespace util