/* 
 * File:   CString.cpp
 * Author: matthieu.villard
 * 
 * Created on 10. mars 2016, 11:37
 */

#include <stdlib.h>

#include "cstring.h"

typedef unsigned long long ullong;

ostream& operator <<(ostream& os, const CString& str){
   os << str.c_str;
   return os;
}

CString::CString() {
   c_str = "";
}

CString::CString(const char* c_str){
   size_t size = 0;
   for(const char* pt = c_str; *pt != '\0'; pt++, size++);
   
   this->c_str = new char[size + 1];   
   for(char* pt = this->c_str; (*pt++ = *c_str++) != '\0';);
}

CString::CString(const CString& str){
   const size_t size = str.size();
   c_str = new char[size + 1];
   for(char* dest = c_str, *src = str.c_str; (*dest++ = *src++) != '\0';);
}

CString::CString(const char chr){
   c_str = new char[2];
   c_str[0] = chr;
   c_str[1] = '\0';
}

CString::CString(const int n){
   size_t size;
   if(n < 0)
      size = 3 + log(-n) / log(10);
   else
      size = 2 + log(n) / log(10);
   c_str = new char[size];
   c_str[size - 1] = '\0';
   
   const char FIRST_DIGIT = '0';
   int pos = size - 2;
   int rest = abs(n);
   do{
      const int mod = rest % 10;
      c_str[pos--] = FIRST_DIGIT + mod;
      rest /= 10;
   }while(rest != 0);
   if(n < 0)
      c_str[pos] = '-';
}

CString::CString(const double n){
   
}

CString::~CString() {
}

const size_t CString::size() const{
   size_t size = 0;
   for(const char* pt = c_str; *pt != '\0'; pt++, size++);
   return size;
}

const char* CString::toString() const{
   return c_str;
}





