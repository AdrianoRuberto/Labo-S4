#include <cstdlib>
#include <iostream>
#include "List.h"

using namespace std;

int main() {


	cout << "Test avec des strings" << endl;
	List<string> strings;
	strings.append("un");
	strings.append("deux");
	strings.append("trois");

	for (List<string>::Iterator it = strings.begin(); it != strings.end(); it++)
		cout << *it << " ";

	cout << endl;
	cout << "Test avec des ints" << endl;
	List<int> ints;
	ints.insert(3);
	ints.insert(2);
	ints.insert(1);
	for (List<int>::Iterator it = ints.begin(); it != ints.end(); it++)
		cout << *it << " ";
	cout << ints[2] << endl;
	cout << endl;
	cout << "Test " << endl;

	List<int> ints2(ints);
	cout << ints2 << endl;

	return 0;
}