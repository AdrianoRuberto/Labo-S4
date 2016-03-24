#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "cstring.h"

using namespace std;

int main() {
    String t2(-123);
    cout << t2 << endl;

    String tru(true);
    String fal(false);
    cout << tru << endl;
    cout << fal << endl;

    /*
        String dbl[] = {123.4, 123.45, -123.4, -123.45, 987.12341234};
        for(String s : dbl){
            cout << s << endl;
        }
     */

    String a("abc");
    String b("def");
    cout << a << endl << b << endl;
    cout << a.append(b) << endl;
    cout << a << endl;
    cout << a.impappend(b) << endl;
    cout << a << endl;
    a.impappend("xyz123");
    cout << a << endl;
    cout << a.append('c') << endl;
    cout << a.impappend('d') << endl;
    cout << a << endl;


    String test("abcdef");
    try {
        cout << test.getChars(3, 8) << endl;
    } catch (const out_of_range &oor) {
        cout << oor.what() << endl;
    }
    try {
        cout << test.getChars(8, 8) << endl;
    } catch (const out_of_range &orr) {
        cout << orr.what() << endl;
    }
    cout << test.getChars(1, 5) << endl;
    cout << test.getChars(5, 1) << endl;
    cout << test.getChars(1, 1) << endl;

    return EXIT_SUCCESS;
}