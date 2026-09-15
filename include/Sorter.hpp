/**
 * @file Sorter.hpp
 * @author AlSleepless (bessonov853@gmail.com)
 * @brief Заголовок сортировщика
 * @version 0.1
 * @date 2026-09-14
 *
 * @copyright Copyright (c) 2026
 *
 */

#pragma once

#include "Person.hpp"

#include <cstdint>
#include <vector>

namespace stayout {

enum class SortOption : std::uint8_t {
  ByFirstName = 1,   //!< сортировка по имени
  ByLastName = 2,    //!< сортировка по фамилии
  ByPhoneNumber = 3, //!< сортировка по телефону
};

/**
 * @brief Сортирует массив people по указанному option принципу
 *
 * @param people массив для сортировки
 * @param option вариант сортировки
 */
void sortPeople(std::vector<Person> &people, SortOption option);

} // namespace stayout
