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
 *
 * @param os поток вывода
 * @param people массив персон для вывода
 */
void print(std::ostream &os, std::vector<Person> &people);

} // namespace stayout
