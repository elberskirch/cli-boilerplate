#include <CLI/CLI.hpp>
#include <core/2025-01.hpp>
#include <core/util.hpp>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  CLI::App app{"CLI Boilerplate Application"};
  app.set_version_flag("--version", "0.1.0");

  int day = 0;
  app.add_option("-d,--day", day, "Day of the challenge to run")->required();
  std::string filename;
  app.add_option("-i,--input", filename, "input file name")->required();

  // Parse command line arguments
  CLI11_PARSE(app, argc, argv);

  switch (day) {
  case 01: {
    aoc2025::day1::Dial dial;
    std::string fileContent = util::loadFileAsString(filename);
    dial.setPosition(50);
    auto operations = util::strToVector(fileContent);
    for (const auto& op : operations) {
      std::cout << "Position: " << dial.getPosition() << " - Operation: " << op << std::endl;
      dial.turn(op);
    }
    std::cout << "Final Password: " << dial.getClicks() << std::endl;
    break;
  }
  default:
    std::cerr << "Day not implemented: " << day << std::endl;
    return 1;
  }
  return 0;
}
