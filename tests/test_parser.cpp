/**
 * @file test_parser.hpp
 * @author AlSleepless (bessonov853@gmail.com)
 * @brief Модульные тесты на парсер. Для корректной работы запускать через ctest
 * @version 0.1
 * @date 2026-09-14
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "Parser.hpp"
#include <gtest/gtest.h>

using namespace stayout;

// parse line

TEST(ParseLineTest, Valid) {
  Person person;
  ASSERT_TRUE(Parser::parseLine("Дегтярёв Александр: 0123456789", person));
  EXPECT_EQ(person.lastName, "Дегтярёв");
  EXPECT_EQ(person.firstName, "Александр");
  EXPECT_EQ(person.phoneNumber, "0123456789");
}

TEST(ParseLineTest, InvalidEmpty) {
  Person person;
  EXPECT_FALSE(Parser::parseLine("", person));
}

TEST(ParseLineTest, InvalidNoSpaces) {
  Person person;
  EXPECT_FALSE(Parser::parseLine("БессоновАлександр:0123456789", person));
}

TEST(ParseLineTest, InvalidNoColon) {
  Person person;
  EXPECT_FALSE(Parser::parseLine("Дегтярёв Александр 0123456789", person));
}

TEST(ParseLineTest, InvalidNoPhone) {
  Person person;
  EXPECT_FALSE(Parser::parseLine("Дегтярёв Александр: ", person));
}

TEST(ParseLineTest, InvalidThirdName) {
  Person person;
  EXPECT_FALSE(
      Parser::parseLine("Дегтярёв Александр Вячеславович: 0123456789", person));
}

// load from stream

TEST(ParserStream, Valid) {
  Parser parser;
  std::istringstream iStream(
      "Дегтярёв Александр: 0123456789\nСоколов Алексей: 987654321\n");
  auto people = parser.loadFromStream(iStream);

  ASSERT_EQ(people.size(), 2u);
  EXPECT_EQ(people[0].lastName, "Дегтярёв");
}

TEST(ParserStream, InvalidLineSkip) {
  Parser parser;
  std::istringstream iStream(
      "Дегтярёв Александр: 0123456789\n\nСоколов Алексей: 987654321\n");
  auto people = parser.loadFromStream(iStream);
  EXPECT_EQ(people.size(), 2u);
}

TEST(ParserStream, InvalidEmpty) {
  Parser parser;
  std::istringstream iStream("");
  EXPECT_TRUE(parser.loadFromStream(iStream).empty());
}

// load from file

TEST(ParserFile, Valid) {
  Parser parser;
  auto people = parser.loadFromFile("data/input.txt");
  EXPECT_THROW(parser.loadFromFile("invalidPath.txt"), std::runtime_error);
}

TEST(ParserFile, ThrowsOnMissingFile) {
  Parser parser;
  EXPECT_THROW(parser.loadFromFile("invalidPath.txt"), std::runtime_error);
}
