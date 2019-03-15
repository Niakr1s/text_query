#include "Query.h"
#include "TextQuery.h"

int main(int argc, char *argv[]) {
    TextQuery tq("text.txt");

    auto m = Query("(|)|\nmotor | swam");
    auto no_m = ~m;
    std::cout << m.eval(tq);
    std::cout << no_m.eval(tq);
    auto new_q = m | Query("which");
    std::cout << new_q.eval(tq);

    return 0;
}
