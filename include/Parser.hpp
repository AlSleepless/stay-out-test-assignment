/**
 * @file Parser.hpp
 * @author AlSleepless (bessonov853@gmail.com)
 * @brief Заголовок парсера
 * @version 0.1
 * @date 2026-09-14
 *
 * @copyright Copyright (c) 2026
 *
 */

#pragma once

#include "Person.hpp"

#include <string>
#include <string_view>
#include <vector>

namespace stayout {

class Parser {
public:
  /**
   * @brief получить персон из файла
   *
   * @param path путь к текстовому файлу со строками формата "Фамилия Имя:
   * телефон"
   * @return std::vector<Person>
   */
  std::vector<Person> loadFromFile(std::string_view path) const;

  /**
   * @brief получить персон из потока ввода
   *
   * @param iStream поток ввода
   * @return std::vector<Person>
   */
  std::vector<Person> loadFromStream(std::istream &iStream) const;

  /**
   * @brief разбор строки на структуры персон
   *
   * @param line строка для разбора
   * @param out возвращаемый при успехе результат
   * @return true строка успешно разобрана
   * @return false не удалось разобрать строку
   */
  static bool parseLine(std::string_view line, Person &out);
};

} // namespace stayout