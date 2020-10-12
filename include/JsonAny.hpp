//
// Created by ekaterina on 08.10.2020.
//
// Copyright 2020 Your Name <ekaterina>

#ifndef PARSER_JSONANY_HPP
#define PARSER_JSONANY_HPP
#include <nlohmann/json.hpp>
#include <any>
#include <string>
#include <vector>
namespace nlohmann { //пространство имен
template <>
struct adl_serializer<std::any> { //специализация шаблона
  static void from_json(const json& j, std::any& any_var) {
    //Эта функция обычно вызывается get()функцией класса
    // basic_json (либо явным образом, либо с помощью
    // операторов преобразования).
    if (j.is_null()) {
      any_var = nullptr;
    } else if (j.is_number_integer()) {
      any_var = j.get<int>();
    } else if (j.is_number_float()) {
      any_var = j.get<double>();
    } else if (j.is_string()) {
      any_var = j.get<std::string>();
    } else if (j.is_array()) {
      std::vector<std::string> v(0);
      for (json::const_iterator it = j.cbegin(); it != j.cend(); ++it) {
        std::string str = it.value();
        v.push_back(str);
      }
      any_var = v;
    }
  }
};

}// namespace nlohmann

#endif  // PARSER_JSONANY_HPP
