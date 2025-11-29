#include <CLI/CLI.hpp>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  CLI::App app{"CLI Boilerplate Application"};
  app.set_version_flag("--version", "0.1.0");

  // Command line options
  bool verbose = false;
  app.add_flag("-v,--verbose", verbose, "Enable verbose output");

  std::string name;
  app.add_option("-n,--name", name, "Your name")->default_val("World");

  int count = 1;
  app.add_option("-c,--count", count, "Number of times to repeat")->check(CLI::PositiveNumber);

  // Parse command line arguments
  CLI11_PARSE(app, argc, argv);

  // Application logic
  if (verbose) {
    std::cout << "Verbose mode enabled" << std::endl;
    std::cout << "Arguments parsed successfully" << std::endl;
  }

  for (int i = 0; i < count; ++i) {
    std::cout << "Hello, " << name << "!" << std::endl;
  }

  return 0;
}
