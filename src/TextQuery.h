#if !defined(TEXT_QUERY_H)
#define TEXT_QUERY_H

#include <vector>
#include <memory>
#include <map>
#include <set>
// #include "Queries.h"

class TextQuery
{
  friend class WordQuery;
  friend class NoQuery;

private:
  std::shared_ptr<std::vector<std::string>> text;
  std::map<std::string, std::set<size_t>> lines;
  std::set<size_t> all_lines();
  std::set<size_t> not_lines(const std::string &word);

public:
  TextQuery(const std::string &filename);
  ~TextQuery(){};

  void print_text();
  void print_words();
};

#endif // TEXT_QUERY_H