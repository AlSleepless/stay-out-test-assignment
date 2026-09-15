/**
 * @file Printer.hpp
 * @author AlSleepless (bessonov853@gmail.com)
 * @brief Заголовок системы вывода информации
 * @version 0.1
 * @date 2026-09-14
 *
 * @copyright Copyright (c) 2026
 *
 */

#pragma once

#include "Person.hpp"
#include "Sorter.hpp"

#include <ostream>
#include <vector>

namespace stayout {

/**
 * @brief Вывести массив персон
 * @todo сделать опции форматов вывода (firstNameFirst, lastNameFirst,
 * phoneNumberFirst)
 *
 * @param os поток вывода
 * @param people массив персон для вывода (копия!)
 * @param option метод сортировки
 */
void printSorted(std::ostream &os, const std::vector<Person> people,
                 const SortOption option);

} // namespace stayout
