#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include <core/2025-01.hpp>
#include <core/util.hpp>

using namespace aoc2025::day1;
TEST_CASE("2025 - util", "[util]") {
    std::string sample = "line1\nline2\nline3";
    auto lines = util::strToVector(sample);
    REQUIRE(lines.size() == 3);
    REQUIRE(lines[0] == "line1");
    REQUIRE(lines[1] == "line2");       
    REQUIRE(lines[2] == "line3");
}

TEST_CASE("2025 - Day 1 -  Dial - Initial Position", "[dial]") {
    Dial dial;
    REQUIRE(dial.getPosition() == 0);

    dial.setPosition(50);
    REQUIRE(dial.getPosition() == 50);

    dial.turnLeft(68);
    REQUIRE(dial.getPosition() == 82);

    dial.turnLeft(30);
    REQUIRE(dial.getPosition() == 52);

    dial.turnRight(48);
    REQUIRE(dial.getPosition() == 0);

    dial.turnLeft(5);
    REQUIRE(dial.getPosition() == 95);

    dial.turnRight(60);
    REQUIRE(dial.getPosition() == 55);

    dial.turnLeft(55);
    REQUIRE(dial.getPosition() == 0);

    dial.turnLeft(1);
    REQUIRE(dial.getPosition() == 99);

    dial.turnLeft(99);
    REQUIRE(dial.getPosition() == 0);   

    dial.turnRight(14);
    REQUIRE(dial.getPosition() == 14);

    dial.turnLeft(82);
    REQUIRE(dial.getPosition() == 32);
}

TEST_CASE("2025 - Day 1 - Dial - Calculate Password", "[dial]") {
    int password = 0;
    Dial dial;
    std::vector<std::string> operations{
        "L68",
        "L30",
        "R48",
        "L5",
        "R60",
        "L55",
        "L1",
        "L99",
        "R14",
        "L82"
    };

    dial.setPosition(50);
    REQUIRE(dial.getPosition() == 50);

    for (const auto& op : operations) {
        dial.turn(op);
    }
    REQUIRE(dial.getClicks() == 3);
}

TEST_CASE("2025 - Day 1 - Dial - Beyond 100 steps Operations", "[dial]") {
    Dial dial;
    dial.setPosition(0);

    dial.turn("R150");
    REQUIRE(dial.getPosition() == 50);
    dial.turn("L250");
    REQUIRE(dial.getPosition() == 0); // 0
    dial.turn("L365");
    REQUIRE(dial.getPosition() == 35);
}

TEST_CASE("2025 - Day 1 - Dial - Count All Clicks", "[dial]") {
    Dial dial(true); // Enable counting all clicks
    std::vector<std::string> operations{
        "L68",
        "L30",
        "R48",
        "L5",
        "R60",
        "L55",
        "L1",
        "L99",
        "R14",
        "L82"
    };

    dial.setPosition(50);
    REQUIRE(dial.getPosition() == 50);

    for (const auto& op : operations) {
        dial.turn(op);
    }
    REQUIRE(dial.getClicks() == 6);
}