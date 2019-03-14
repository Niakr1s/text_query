#if !defined(WORDQUERY_H)
#define WORDQUERY_H

#include <string>
#include <memory>
#include "QueryBase.h"
#include "QueryResult.h"
#include "TextQuery.h"

class WordQuery : public QueryBase
{
  private:
    std::string word;

  public:
    WordQuery(const std::string &s) : word(s){};
    ~WordQuery(){};

    QueryResult eval(TextQuery &tq) const override;
    std::string rep() const override;
};

#endif // WORDQUERY_H
