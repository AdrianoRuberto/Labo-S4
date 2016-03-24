/*
 * File:   CString.cpp
 * Author: Matthieu Villard
 * Author: Adriano Ruberto
 *
 * Created on 10. mars 2016, 11:37
 */
#include <string.h>
#include <stdio.h>
#include <stdexcept>
#include <math.h>

#include "cstring.h"


typedef unsigned long long ullong;

ostream &operator<<(ostream &os, const String &str) {
    os << str.c_str;
    return os;
}

String::String() {
    c_str = new char[1];
    c_str[0] = '\0';
}

String::String(const char *cstr) {
    this->c_str = new char[strlen(cstr) + 1];
    strcpy(c_str, cstr);
}

String::String(const String &str) {
    c_str = new char[str.size() + 1];
    strcpy(c_str, str.c_str);
}

String::String(const char chr) {
    c_str = new char[2];
    c_str[0] = chr;
    c_str[1] = '\0';
}

String::String(const int n) {
    const size_t size = (size_t) log10((n > 0 ? n : -n)) + 2 + (n < 0);
    c_str = new char[size];
    sprintf(c_str, "%d", n);
}

String::String(const double n) {
}

String::String(const bool b) {
    c_str = (char *) (b ? "true" : "false");
}

String::~String() {
    delete c_str;
}

const size_t String::size() const {
    return strlen(c_str);
}

const char *String::toString() const {
    return c_str;
}

char &String::getChar(size_t index) {
    if (index > size())
        throw out_of_range("Index is out of range");

    return c_str[index];
}

bool String::equal(const char *const cstr) const {
    return !strcmp(c_str, cstr);
}

bool String::equal(const String &str) const {
    return equal(str.c_str);
}

bool String::operator==(const String &a) const {
    return equal(a);
}

bool String::operator==(const char *const cstr) const {
    return equal(cstr);
}

String String::operator+=(const char *const cstr) {

}

String String::append(const char *const cstr) const {
    char *tmp = new char[size() + strlen(cstr) + 1];
    strcpy(tmp, c_str);
    strcat(tmp, cstr);
    return tmp;
}

String String::append(const char c) const {
    return append(String(c));
}


String String::append(const String &str) const {
    return append(str.c_str);
}

String String::impappend(const char *const cstr) {
    const char *tmp = c_str;
    c_str = new char[size() + strlen(cstr) + 1];
    strcpy(c_str, tmp);
    strcat(c_str, cstr);
    delete tmp;
    return c_str;
}

String String::impappend(const char c) {
    return impappend(String(c));
}

String String::impappend(const String &str) {
    return impappend(str.c_str);
}

char *String::getChars(const size_t a, const size_t b){
    if(a > b)
        return getChars(b, a);
    if(b > size())
        throw out_of_range("Index is out of range");

    const size_t chunk = b - a + 1;
    char *res = new char[chunk + 1];

    strncpy(res, c_str + a, chunk);
    res[chunk] = '\0';

    return res;
}