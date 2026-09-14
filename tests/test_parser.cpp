/**
 * @file test_parser.hpp
 * @author AlBessonov (bessonov853@gmail.com)
 * @brief Модульные тесты на парсер
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

TEST(ParserTest, ValidLine) {
  Person p;
  ASSERT_TRUE(Parser::parseLine("Бессонов Александр: 0123456789", p));
  EXPECT_EQ(p.lastName, "Бессонов");
  EXPECT_EQ(p.firstName, "Александр");
  EXPECT_EQ(p.phoneNumber, "0123456789");
}

TEST(ParserTest, InvalidLineEmpty) {
  Person p;
  EXPECT_FALSE(Parser::parseLine("", p));
}

TEST(ParserTest, InvalidLineNoSpaces) {
  Person p;
  EXPECT_FALSE(Parser::parseLine("БессоновАлександр:0123456789", p));
}

TEST(ParserTest, InvalidLineNoColon) {
  Person p;
  EXPECT_FALSE(Parser::parseLine("Бессонов Александр 0123456789", p));
}

TEST(ParserTest, InvalidLineNoPhone) {
  Person p;
  EXPECT_FALSE(Parser::parseLine("Бессонов Александр: ", p));
}

TEST(ParserTest, InvalidLineThirdName) {
  Person p;
  EXPECT_FALSE(
      Parser::parseLine("Бессонов Александр Вячеславович: 0123456789", p));
}

// TODO load from file
