#if !defined(STRUTILITY_H)
#define STRUTILITY_H

#include <memory>
#include <string>
#include "QueryBase.h"

std::shared_ptr<QueryBase> parse(std::string &s);
void remove_spaces(std::string &s);
bool remove_outer_braces(std::string &s);
std::pair<std::string, std::string> split_string(
    const std::string &s, std::string::const_iterator it);

#endif  // STRUTILITY_H
