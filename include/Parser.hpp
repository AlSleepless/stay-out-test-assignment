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