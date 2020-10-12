//
// Created by ekaterina on 11.10.2020.
//
// Copyright 2020 ekaterina

#ifndef PARSER_STUDENT_HPP
#define PARSER_STUDENT_HPP

#include "JsonAny.hpp"
#include <string>

using nlohmann::json;
class Student {
 public:
  size_t length_name() const;
  size_t length_group() const;
  size_t length_avg() const;
  size_t length_debt() const;

  void print_name(std::ostream &out) const;
  void print_group(std::ostream &out) const;
  void print_avg(std::ostream &out) const;
  void print_debt(std::ostream &out) const;

  static void from_json(const json& j, Student& s);

  void set_name(std::string _name);
  void set_group(std::any _group);
  void set_avg(std::any _avg);
  void set_debt(std::any _debt);

  std::string get_name() const;
  std::any get_group()const;
  std::any get_avg() const;
  std::any get_debt() const;

 private:
  std::string name;
  std::any group;
  std::any avg;
  std::any debt;
};

#endif  // PARSER_STUDENT_HPP
