#pragma once

namespace aoc2025 {
namespace day1 {
class Dial {
private:
  int position;
  int min_position;
  int max_position;
  int clicks;
  bool countAllClicks;

public:
  Dial(bool allClicks = false)
      : position(0), min_position(0), max_position(99), clicks(0), countAllClicks(allClicks) {}

  void setPosition(int pos) {
    if (pos < min_position || pos > max_position) {
      throw std::out_of_range("Position out of range");
    }
    position = pos;
    clicks = 0;
  }

  int getPosition() const {
    return position;
  }

  int getClicks() const {
    return clicks;
  }

  void incrementClicks(int count) {
    clicks += count;
  }

  void turnLeft(int steps) {
    position = (100 + (position - (steps % 100))) % 100;
  }

  void turnRight(int steps) {
    position = (position + steps) % 100;
  }

  void turn(const std::string& operation) {
    if (operation.empty()) {
      throw std::invalid_argument("Operation string is empty");
    }
    char direction = operation[0];
    int steps = std::stoi(operation.substr(1));

    if (direction == 'L') {
      turnLeft(steps);
    } else if (direction == 'R') {
      turnRight(steps);
    } else {
      throw std::invalid_argument("Invalid turn direction");
    }

    if (getPosition() == 0) {
      if (!countAllClicks) {
        incrementClicks(1);
      }
    }
  }
};

} // namespace day1
} // namespace aoc2025