/**
 * @file test_printer.hpp
 * @author AlSleepless (bessonov853@gmail.com)
 * @brief Модульные тесты на систему вывода информации
 * @version 0.1
 * @date 2026-09-14
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "Printer.hpp"
#include <gtest/gtest.h>

using namespace stayout;

namespace {
std::vector<Person> getPeopleSample() {
  return {
      {"Меченый", "Стрелок", "100"},         //
      {"Александр", "Дегтярёв", "20"},       //
      {"Александр", "Стрелок", "3"},         //
      {"Анатолий", "Сидорович", "23452345"}, //
      {"Пётр", "Стрелок", "56785678"},       //
  };
}

std::string render(std::vector<Person> people, SortOption option) {
  std::ostringstream oss;
  printSorted(oss, std::move(people), option);
  return oss.str();
}

} // namespace

TEST(PrinterTest, ByFirstNameCorrectFirstField) {
  std::ostringstream oss;
  printSorted(oss, getPeopleSample(), SortOption::ByFirstName);
  const auto out = oss.str();

  EXPECT_NE(out.find("Александр Дегтярёв: 20"), std::string::npos);
  EXPECT_NE(out.find("Александр Стрелок: 3"), std::string::npos);
  EXPECT_NE(out.find("Анатолий Сидорович: 23452345"), std::string::npos);
  EXPECT_NE(out.find("Меченый Стрелок: 100"), std::string::npos);
  EXPECT_NE(out.find("Пётр Стрелок: 56785678"), std::string::npos);
}

TEST(PrinterTest, ByFirstNameCorrectOrder) {
  std::ostringstream oss;
  printSorted(oss, getPeopleSample(), SortOption::ByFirstName);
  const auto out = oss.str();

  const auto pAlex = out.find("Александр");
  const auto pAnatol = out.find("Анатолий");
  const auto pMech = out.find("Меченый");
  const auto pPetr = out.find("Пётр");

  EXPECT_LT(pAlex, pAnatol);
  EXPECT_LT(pAnatol, pMech);
  EXPECT_LT(pMech, pPetr);
}

// ---------- Сортировка по фамилии ----------

TEST(PrinterTest, ByLastNameCorrectFirstField) {
  std::ostringstream oss;
  printSorted(oss, getPeopleSample(), SortOption::ByLastName);
  const auto out = oss.str();

  EXPECT_NE(out.find("Дегтярёв Александр: 20"), std::string::npos);
  EXPECT_NE(out.find("Сидорович Анатолий: 23452345"), std::string::npos);
  EXPECT_NE(out.find("Стрелок Александр: 3"), std::string::npos);
  EXPECT_NE(out.find("Стрелок Меченый: 100"), std::string::npos);
  EXPECT_NE(out.find("Стрелок Пётр: 56785678"), std::string::npos);
}

TEST(PrinterTest, ByLastNameCorrectOrder) {
  std::ostringstream oss;
  printSorted(oss, getPeopleSample(), SortOption::ByLastName);
  const auto out = oss.str();

  const auto pDegt = out.find("Дегтярёв");
  const auto pSidor = out.find("Сидорович");
  const auto pStrel = out.find("Стрелок");

  EXPECT_LT(pDegt, pSidor);
  EXPECT_LT(pSidor, pStrel);
}

// ---------- Сортировка по телефону ----------

TEST(PrinterTest, ByPhoneCorrectFirstField) {
  std::ostringstream oss;
  printSorted(oss, getPeopleSample(), SortOption::ByPhoneNumber);
  const auto out = oss.str();

  EXPECT_NE(out.find("3: Стрелок Александр"), std::string::npos);
  EXPECT_NE(out.find("20: Дегтярёв Александр"), std::string::npos);
  EXPECT_NE(out.find("100: Стрелок Меченый"), std::string::npos);
  EXPECT_NE(out.find("23452345: Сидорович Анатолий"), std::string::npos);
  EXPECT_NE(out.find("56785678: Стрелок Пётр"), std::string::npos);
}

TEST(PrinterTest, ByPhoneCorrectOrder) {
  std::ostringstream oss;
  printSorted(oss, getPeopleSample(), SortOption::ByPhoneNumber);
  const auto out = oss.str();

  const auto p3 = out.find("3:");
  const auto p20 = out.find("20:");
  const auto p100 = out.find("100:");
  const auto p23m = out.find("23452345:");
  const auto p56m = out.find("56785678:");

  EXPECT_LT(p3, p20);
  EXPECT_LT(p20, p100);
  EXPECT_LT(p100, p23m);
  EXPECT_LT(p23m, p56m);
}
