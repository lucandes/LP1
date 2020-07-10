#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <cctype>

std::string int_to_money(const int &value);
int money_to_int(const std::string &money);

#endif