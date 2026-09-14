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
