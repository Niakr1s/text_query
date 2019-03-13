#if !defined(QUERYRESULT_H)
#define QUERYRESULT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <memory>
#include <set>

class QueryResult
{

private:
  std::shared_ptr<std::vector<std::string>> text;
  std::string name;
  std::set<size_t> lines;

public:
  QueryResult(std::shared_ptr<std::vector<std::string>> t,
              const std::string &s,
              const std::set<size_t> &l) : text(t), name(s), lines(l){};
  ~QueryResult(){};

  std::ostream &print(std::ostream &out = std::cout);
};

#endif // QUERYRESULT_H
