#include <cstdlib>
#include <iostream>
#include "List.h"

using namespace std;

int main(){

	List<string> l;
	l.append("un");
	l.append("deux");
	l.append("trois");
	/*
	for (List<string>::Iterator it = l.begin(); it != l.end(); it++)
		cout << *it << " ";
	cout << endl;
	 */

	return EXIT_SUCCESS;
}