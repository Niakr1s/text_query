#if !defined(TEXT_QUERY_H)
#define TEXT_QUERY_H

#include <map>
#include <memory>
#include <set>
#include <vector>

class TextQuery {
    friend class WordQuery;
    friend class NoQuery;
    friend class OrQuery;
    friend class AndQuery;

   private:
    std::shared_ptr<std::vector<std::string>> text;
    std::map<std::string, std::set<size_t>> lines;
    std::set<size_t> all_lines();

   public:
    TextQuery(const std::string &filename);
    ~TextQuery(){};

    void print_text();
    void print_words();
};

#endif  // TEXT_QUERY_H