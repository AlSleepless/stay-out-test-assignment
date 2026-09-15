/**
 * @file main.cpp
 * @author AlSleepless (bessonov853@gmail.com)
 * @brief
 * @version 0.1
 * @date 2026-09-15
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "Parser.hpp"
#include "Printer.hpp"
#include "Sorter.hpp"

#include <exception>
#include <iostream>
#include <string>

using namespace stayout;

namespace {

/**
 * @brief обработка пользовательского ввода режима сортировки
 *
 * @return int 0 если ошибка, иначе номер SortOption
 */
int parseMode() {
  std::cout << "Для сортировки по именам введите – 1,\n"
               "по фамилиям введите – 2,\n"
               "по телефонам введите – 3\n"
               "Ввод: ";

  int mode = 0;
  if (!(std::cin >> mode))
    return 0;
  if (mode < 1 || mode > 3)
    return 0;
  return mode;
}

} // namespace

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Использование: " << argv[0] << " <путь_к_файлу>\n";
    return EXIT_FAILURE;
  }

  std::vector<Person> people;
  try {
    Parser parser;
    people = parser.loadFromFile(argv[1]);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }

  if (people.empty()) {
    std::cerr << "Нет данных для обработки.\n";
    return EXIT_FAILURE;
  }

  const int mode = parseMode();
  if (mode == 0) {
    std::cerr << "Некорректный параметр сортировки.\n";
    return EXIT_FAILURE;
  }

  printSorted(std::cout, people, static_cast<SortOption>(mode));
  return EXIT_SUCCESS;
}
