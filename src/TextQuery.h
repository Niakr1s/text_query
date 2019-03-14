#if !defined(TEXT_QUERY_H)
#define TEXT_QUERY_H

#include <vector>
#include <memory>
#include <map>
#include <set>

class TextQuery
{
  friend class WordQuery;
  friend class NoQuery;

private:
  std::shared_ptr<std::vector<std::string>> text;
  std::map<std::string, std::set<size_t>> lines;
  std::set<size_t> all_lines();
  std::set<size_t> negate_lines(const std::string &to_negate);
  std::set<size_t> negate_lines(std::set<size_t> &to_negate);

public:
  TextQuery(const std::string &filename);
  ~TextQuery(){};

  void print_text();
  void print_words();
};

#endif // TEXT_QUERY_H