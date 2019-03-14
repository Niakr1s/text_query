#if !defined(ORQUERY_H)
#define ORQUERY_H

#include "BinaryQuery.h"

class OrQuery : public BinaryQuery
{
  private:
    /* data */
  public:
    OrQuery(/* args */);

    ~OrQuery();
};

#endif // ORQUERY_H
