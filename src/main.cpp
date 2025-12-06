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
  bool verbose{false};
  app.add_flag("-v,--verbose", verbose, "Enable verbose output");

  // Parse command line arguments
  CLI11_PARSE(app, argc, argv);

  switch (day) {
  case 01: {
    aoc2025::day1::Dial dial1;
    aoc2025::day1::Dial dial2(true);
    std::string fileContent = util::loadFileAsString(filename);
    dial1.setPosition(50);
    dial2.setPosition(50);
    auto operations = util::strToVector(fileContent);
    for (const auto& op : operations) {
      // std::cout << "Position: " << dial.getPosition() << " - Operation: " << op << std::endl;
      dial1.turn(op);
      dial2.turn(op);
      if (verbose)
        std::cout << "Operation: " << op << " Position: " << dial2.getPosition()
                  << " - Clicks: " << dial2.getClicks() << std::endl;
    }
    std::cout << "Final Password Dial 1: " << dial1.getClicks() << std::endl;
    std::cout << "Final Password Dial 2: " << dial2.getClicks() << std::endl;
    break;
  }
  default:
    std::cerr << "Day not implemented: " << day << std::endl;
    return 1;
  }
  return 0;
}
