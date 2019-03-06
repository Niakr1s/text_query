#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstring>
#include "fns.h"

using namespace std;

int count()
{
    static int cnt = 0;
    return ++cnt;
}

int main()
{
    cout << factorial(5) << endl;

    for (int i = 0; i < 5; ++i)
    {
        cout << count() << endl;
    }

    return 0;
}