#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>
class String
{
public:
	//Constructor Destructor
    String();
	String(const char* str);
    ~String();


	//Operators
	//Equality Operator
	bool operator==(String &other);
	bool operator==(char* other);
	//Assignment Operator
	void operator=(String &other);
	void operator=(char* other);
	//Plus Operator
	void operator+(String &other);
	//Plus Equals Operator
	void operator+=(String &other);
	//Subscript Operator
	char operator[](int Index);

	//Functions
	void Resize(int Length);
	int Length();
	char CharacterAt(int Index);
	bool EqualTo(String &String2);
	void Append(String &String2);
	void Prepend(String &String2);
	char* CStr();
	void ToLower();
	void ToUpper();
	int Find(String &FindString);
	int Find(int StartIndex, String &FindString);
	void Replace(String &FindString, String &ReplaceString);
	void ReadFromConsole();
	void WriteToConsole();

private:
    int size;
    int length;
    char* string;
};

#endif