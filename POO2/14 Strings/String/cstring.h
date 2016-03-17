/* 
 * File:   CString.h
 * Author: matthieu.villard
 *
 * Created on 10. mars 2016, 11:37
 */

#ifndef CSTRING_H
#define	CSTRING_H

#include <iostream>
#include <math.h>

using namespace std;
class CString 
{
   friend ostream& operator <<(ostream& os, const CString& str);
   
   public:
      CString();
      CString(const char* c_str);
      CString(const CString& str);
      CString(const char chr);
      CString(const int n);
      CString(const double n);
      ~CString();
      const size_t size() const;
      const char* toString() const;
      
   private:
      char* c_str;
};

#endif	/* CSTRING_H */

