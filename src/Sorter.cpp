/**
 * @file Sorter.cpp
 * @author AlSleepless (bessonov853@gmail.com)
 * @brief реализация системы сортировки
 * @version 0.1
 * @date 2026-09-15
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "Sorter.hpp"
#include <algorithm>

namespace stayout {

namespace {

bool lessByFirstName(const Person &a, const Person &b) {
  if (a.firstName != b.firstName)
    return a.firstName < b.firstName;
  return a.lastName < b.lastName;
}

bool lessByLastName(const Person &a, const Person &b) {
  if (a.lastName != b.lastName)
    return a.lastName < b.lastName;
  return a.firstName < b.firstName;
}

bool lessByPhone(const Person &a, const Person &b) {
  return std::stoull(a.phoneNumber) < std::stoull(b.phoneNumber);
}

} // namespace

void sortPeople(std::vector<Person> &people, SortOption option) {
  switch (option) {
  case SortOption::ByFirstName:
    std::sort(people.begin(), people.end(), lessByFirstName);
    break;
  case SortOption::ByLastName:
    std::sort(people.begin(), people.end(), lessByLastName);
    break;
  case SortOption::ByPhoneNumber:
    std::sort(people.begin(), people.end(), lessByPhone);
    break;
  }
}

} // namespace stayout