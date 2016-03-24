#include <iostream>
#include "cstring.h"

using namespace std;

int main() {
    CString test("abcdef");

    cout << test.getChars(3,8) << endl;
    cout << test.getChars(1,5) << endl;
    return 0;
}