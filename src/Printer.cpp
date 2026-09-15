/**
 * @file Printer.cpp
 * @author AlSleepless (bessonov853@gmail.com)
 * @brief реализация системы вывода
 * @version 0.1
 * @date 2026-09-15
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "Printer.hpp"
#include "Sorter.hpp"

#include <ostream>

namespace stayout {

void printSorted(std::ostream &os, std::vector<Person> people,
                 SortOption option) {
  sortPeople(people, option);

  for (const auto &person : people) {
    switch (option) {
    case SortOption::ByFirstName:
      os << person.firstName << ' ' << person.lastName << ": "
         << person.phoneNumber << '\n';
      break;
    case SortOption::ByLastName:
      os << person.lastName << ' ' << person.firstName << ": "
         << person.phoneNumber << '\n';
      break;
    case SortOption::ByPhoneNumber:
      os << person.phoneNumber << ": " << person.lastName << ' '
         << person.firstName << '\n';
      break;
    }
  }
}

} // namespace stayout
