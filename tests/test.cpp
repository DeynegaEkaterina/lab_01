// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <iostream>
#include "Table.hpp"
#include <fstream>
#include <cstring>
#include "JsonAny.hpp"
#include <vector>

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(Table, FromJson){
  std::string test_json = \
R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    },
    {
      "name": "Petrov Nikita",
      "group": "IU8-31",
      "avg": 33.03,
      "debt": [
        "C++",
        "Linux",
        "Network",
        "SPO"
      ]
    }
  ],
  "_meta": {
    "count": 3
  }
})";

  std::ofstream file_json;//файловый вывод

  file_json.open("file_json1.json");
  file_json << test_json;
  file_json.close();
  Table table = Table::parseFile("file_json1.json");


  std::stringstream str;
  table.print(str);
  std::cout << str.str();
  std::string ref_string =\
R"(| name          | group  | avg   | debt    |
|---------------|--------|-------|---------|
| Ivanov Petr   | 1      | 4.25  | null    |
|---------------|--------|-------|---------|
| Sidorov Ivan  | 31     | 4     | C++     |
|---------------|--------|-------|---------|
| Petrov Nikita | IU8-31 | 33.03 | 4 items |
|---------------|--------|-------|---------|
)";

  EXPECT_EQ(str.str(), ref_string);
}