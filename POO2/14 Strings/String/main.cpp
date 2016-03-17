/* 
 * File:   main.cpp
 * Author: matthieu.villard
 *
 * Created on 10. mars 2016, 11:34
 */

#include <cstdlib>
#include <iostream>
#include "cstring.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
   CString str = CString("abcdefg");
   CString str2 = 2.5;
   cout << str;
   return 0;
}

