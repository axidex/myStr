#define _CRT_SECURE_NO_WARNINGS
#include "mainwin.h"
#include <iostream>
#include <cstring>

using namespace std;

String::String()
{
  Str = 0;
  Length = 0;
}

String::String(const char* ptr)
  : Length(strlen(ptr)), Str(new char[Length + 1])
{
  strcpy(Str, ptr);
}

String::String(const String& t)
  : Length(strlen(t.Str)), Str(new char[Length + 1])
{
  strcpy(Str, t.Str);
}
String& String::operator = (String& t)
{
  swap(Length, t.Length);
  swap(Str, t.Str);
  return *this;
}

String& String::operator += (const String& t)
{
  int newLength = Length + t.Length;
  char *newStr = new char[newLength + 1];
  strcpy(newStr, Str);
  strcat(newStr, t.Str);
  delete[] Str;
  Str = newStr;
  Length = newLength;
  return *this;
}

bool String::operator == (const String& t) const
{
  return Length == t.Length && strcmp(Str, t.Str) == 0;
}

bool String::operator != (const String& t) const
{
  return !(operator == (t));
}

bool String::is_empty() const
{
  return Str == 0 || Str[0] == '\0';
}

const char* String::getStr() const
{
  return Str;
}

int String::getLength() const
{
  return Length;
}

ostream & String::show(ostream & os) const
{
  return os << (Str ? Str : "");
}

String::~String()
{
  Length = 0;
  delete[] Str;
  Str = nullptr;
}

