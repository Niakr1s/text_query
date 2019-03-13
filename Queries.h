#if !defined(QUERIS_H)
#define QUERIS_H

#include "QueryBase.h"
#include <string>
#include <memory>
#include "QueryResult.h"
#include "TextQuery.h"

class TextQuery;
class WordQuery;
class NoQuery;
class BinaryQuery;

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

class NoQuery : public QueryBase
{
private:
  std::string word;

public:
  NoQuery(const std::string &s) : word(s){};
  ~NoQuery(){};

  QueryResult eval(TextQuery &tq) const override;
  std::string rep() const override;
};

class BinaryQuery : public QueryBase
{
  friend class Query;

protected:
  std::string left;
  std::string right;

public:
  BinaryQuery(const std::string &l,
              const std::string &r) : QueryBase(),
                                      left(l), right(r){};
  ~BinaryQuery(){};
};

// class OrQuery : public BinaryQuery
// {
//   public:
//     using BinaryQuery::BinaryQuery; // using parent constructors
//     ~OrQuery(){};

//     QueryResult eval(TextQuery &tq) const override;
//     std::string rep() const override;
// };

// class AndQuery : public BinaryQuery
// {
//   public:
//     using BinaryQuery::BinaryQuery; // using parent constructors
//     ~AndQuery(){};

//     QueryResult eval(TextQuery &tq) const override;
//     std::string rep() const override;
// };

#endif // QUERIS_H