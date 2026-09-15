/**
 * @file Person.hpp
 * @author AlSleepless (bessonov853@gmail.com)
 * @brief Заголовок хранилища данных о персоне
 * @version 0.1
 * @date 2026-09-14
 *
 * @copyright Copyright (c) 2026
 *
 */

#pragma once

#include <string>

namespace stayout {

struct Person {
  std::string firstName;
  std::string lastName;
  std::string phoneNumber;
};

} // namespace stayout
