/**
 * @file Parser.cpp
 * @author AlSleepless (bessonov853@gmail.com)
 * @brief
 * @version 0.1
 * @date 2026-09-15
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "Parser.hpp"
#include <algorithm>
#include <cerrno>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace stayout {

bool Parser::parseLine(std::string_view line, Person &out) {
  if (line.empty())
    return false; // строка пуста

  const auto colonPos = line.find(": ");
  if (colonPos == std::string_view::npos)
    return false; // нет двоеточия

  auto fullName = line.substr(0, colonPos);
  auto phoneNumber = line.substr(colonPos + 2);
  if (phoneNumber.empty())
    return false; // нет номера телефона

  const bool allDigits =
      std::all_of(phoneNumber.begin(), phoneNumber.end(),
                  [](unsigned char ch) { return std::isdigit(ch) != 0; });
  if (!allDigits)
    return false; // номер телефона содержит не только цифры

  const auto spacePos = fullName.find(' ');
  if (spacePos == std::string_view::npos)
    return false; // нет пробела
  if (fullName.find(' ', spacePos + 1) != std::string_view::npos)
    return false; // более одного пробела

  std::string_view lastName = fullName.substr(0, spacePos);
  std::string_view firstName = fullName.substr(spacePos + 1);
  if (lastName.empty() or firstName.empty())
    return false; // нет имени или фамилии

  out.lastName = std::string(lastName);
  out.firstName = std::string(firstName);
  out.phoneNumber = std::string(phoneNumber);
  return true;
}

std::vector<Person> Parser::loadFromStream(std::istream &iStream) const {
  std::vector<Person> people;
  std::string line;
  while (std::getline(iStream, line)) {
    Person person;
    if (parseLine(line, person)) {
      people.push_back(std::move(person));
    }
  }
  return people;
}

std::vector<Person> Parser::loadFromFile(std::string_view path) const {
  std::ifstream fd{std::string(path)};
  if (!fd.is_open())
    throw std::runtime_error(std::string(path) + " : code " +
                             std::strerror(errno));
  return loadFromStream(fd);
}

} // namespace stayout
