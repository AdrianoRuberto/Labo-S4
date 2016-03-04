#include <time.h>
#include "BinaryMatrice.h"

int main() {

    srand(time(0));
    BinaryMatrice one = BinaryMatrice(5);
    BinaryMatrice two = BinaryMatrice(5);

    cout << "one:\n";
    one.print();
    cout << "two:\n";
    two.print();

    cout << "\n\none por two\n";
    one.por(two)->print();
    cout << "\none vor two\n";
    one.vor(two).print();
    cout << "\none ior two\n";
    one.ior(two);
    one.print();cout << endl;
    return 0;
}