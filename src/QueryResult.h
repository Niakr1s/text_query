#if !defined(QUERYRESULT_H)
#define QUERYRESULT_H

#include <vector>
#include <memory>
#include <set>

class QueryResult
{
  friend class NoQuery;
  friend class OrQuery;
  friend class AndQuery;

private:
  std::shared_ptr<std::vector<std::string>> text;
  std::string name;
  std::set<size_t> lines;

public:
  QueryResult(std::shared_ptr<std::vector<std::string>> t,
              const std::string &s,
              const std::set<size_t> &l) : text(t), name(s), lines(l){};
  ~QueryResult(){};

  void print();
};

#endif // QUERYRESULT_H
