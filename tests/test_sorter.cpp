/**
 * @file test_sorter.hpp
 * @author AlSleepless (bessonov853@gmail.com)
 * @brief Модульные тесты на сортировщик
 * @version 0.1
 * @date 2026-09-14
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "Sorter.hpp"
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

} // namespace

// ---------- По имени ----------

TEST(SorterTest, ByFirstName) {
  auto people = getPeopleSample();
  sortPeople(people, SortOption::ByFirstName);

  EXPECT_EQ(people[0].firstName, "Александр");
  EXPECT_EQ(people[1].firstName, "Александр");
  EXPECT_EQ(people[2].firstName, "Анатолий");
  EXPECT_EQ(people[3].firstName, "Меченый");
  EXPECT_EQ(people[4].firstName, "Пётр");

  EXPECT_EQ(people[0].lastName, "Дегтярёв");
  EXPECT_EQ(people[1].lastName, "Стрелок");
}

TEST(SorterTest, ByLastName) {
  auto people = getPeopleSample();
  sortPeople(people, SortOption::ByLastName);

  EXPECT_EQ(people[0].lastName, "Дегтярёв");
  EXPECT_EQ(people[1].lastName, "Сидорович");
  EXPECT_EQ(people[2].lastName, "Стрелок");
  EXPECT_EQ(people[3].lastName, "Стрелок");
  EXPECT_EQ(people[4].lastName, "Стрелок");

  EXPECT_EQ(people[2].firstName, "Александр");
  EXPECT_EQ(people[3].firstName, "Меченый");
  EXPECT_EQ(people[4].firstName, "Пётр");
}

TEST(SorterTest, ByPhoneNumber) {
  auto people = getPeopleSample();
  sortPeople(people, SortOption::ByPhoneNumber);

  EXPECT_EQ(people[0].phoneNumber, "3");
  EXPECT_EQ(people[1].phoneNumber, "20");
  EXPECT_EQ(people[2].phoneNumber, "100");
  EXPECT_EQ(people[3].phoneNumber, "23452345");
  EXPECT_EQ(people[4].phoneNumber, "56785678");
}

TEST(SorterTest, EmptyDataNoExcept) {
  std::vector<Person> people;
  sortPeople(people, SortOption::ByFirstName);
  EXPECT_TRUE(people.empty());
}

TEST(SorterTest, SinglePerson) {
  std::vector<Person> people = {{"Меченый", "Стрелок", "1"}};
  sortPeople(people, SortOption::ByPhoneNumber);
  ASSERT_EQ(people.size(), 1u);
  EXPECT_EQ(people[0].firstName, "Меченый");
  EXPECT_EQ(people[0].lastName, "Стрелок");
  EXPECT_EQ(people[0].phoneNumber, "1");
}
