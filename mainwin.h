#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class String
{
protected:
  int Length;
  char* Str;
public:
  String();
  String(const char* ptr);
  String(const String& t);
  String& operator = (String& t);
  String& operator += (const String& t);
  bool operator == (const String& t) const;
  bool operator != (const String& t) const;
  bool is_empty() const;
  const char* getStr() const;
  int getLength() const;

  ostream & show(ostream & os) const;
  friend ostream & operator << (ostream & os, const String & s)
  {
    return s.show(os);
  }

  ~String();
};


class MyString
{
private: 
int Length;
char *Str;

public:
MyString()
{
  Str = nullptr;
  Length = 0;
}
MyString(const char *ptr)
{
  for (int i = 0 ;;i++)
  {
    if(ptr[i] == '\0')
    {
      Length = i;
      break;
    }

  }
  Str = new char[Length];
  for (int i = 0;i< Length;i++)
  {
    Str[i]=ptr[i];
  } 
 
}
MyString(const MyString &other)
{
  this->Length = other.Length;


  this->Str = new char[Length];
  

  for (int i = 0;i<Length;i++)
  {
    this->Str[i] = other.Str[i];
  }
 

}

MyString & operator = (const MyString &other)
{
  this->Length=other.Length;
  if (this->Str != nullptr)
  {
    delete[] this->Str;
  }
  
  this->Str = new char[Length];
  for (int i = 0;i<Length;i++)
  {
    this->Str[i]=other.Str[i];
  }
  
  return *this;
}
bool operator == (const MyString &other)
{
  if (this->Length != other.Length)
  {
    return false;
  }
  else
  {
    for (int i = 0 ; i < this->Length;i++)
    {
      if (this->Str[i] != other.Str[i])
      {
        return false ;
            
      }

    }
    return true;
  }
  
}
bool operator != (const MyString &other)
{
  return !(*this==other);
  
}
void operator +=(const MyString &other)
{
  int j = 0;
  int temp =  this->Length ;
  this->Length+=other.Length ;
  char *tempo ;
  tempo = new char [temp];
  for (int i = 0;i<temp;i++)
  {
    tempo[i] = this->Str[i];
  }

  if (this->Str != nullptr)
  {
    delete[] this->Str;
  }
  this->Str = new char [Length];
  for (int i = 0;i<temp;i++)
  {
    this->Str[i] = tempo[i];
  }
  
  for (int i = temp;i<Length;i++)
  { 
    
    this->Str[i]= other.Str[j];
    j++;
    
  }
  
  
  delete[] tempo;
  tempo = nullptr;
  

}

friend std::ostream& operator<< (std::ostream &out, const MyString &other)
{
    
    out << other.Str;
    return out;
}



~MyString()
{
  delete[] Str;
}
};