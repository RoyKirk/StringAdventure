#include "String.h"
#include <iostream>


String::String()
{
	this->length = 0;
	this->size = this->length + 1;
	this->string = new char[this->size];
	strcpy(this->string, "");
}
String::String(const char* String1)
{
	this->length = strlen(String1);
	this->size = this->length + 1;
	this->string = new char[this->size];
	strcpy(this->string, String1);
}

String::~String()
{
	delete[] this->string;
}



//Operators
//Equality Operator
bool String::operator==(String &other)
{
	bool temp = strcmp(this->string, other.CStr());
	return !temp;
}
bool String::operator==(char* other)
{
	bool temp = strcmp(this->string, other);
	return !temp;
}
//Assignment Operator
void String::operator=(String &other)
{
	Resize(other.Length());
	strcpy(this->string, other.CStr());
}
//Assignment Operator
void String::operator=(char* other)
{
	Resize(strlen(other));
	strcpy(this->string, other);
}
//Plus Operator
void String::operator+(String &other)
{
	Append(other);
}

//Plus Equals Operator
void String::operator+=(String &other)
{
	Append(other);
}
//Subscript Operator
char String::operator[](int Index)
{
    return this->string[Index];
}

//Functions
void String::Resize(int Length)
{
	char* temp = new char[this->size];
	this->length += Length;
	this->size = this->length + 1;
	strcpy(temp, this->string);
	delete[] this->string;
	this->string = new char[this->size];
	strcpy(this->string, temp);
	delete[] temp;
}

int String::Length()
{
	return this->length;
}
char String::CharacterAt(int Index)
{
	return this->string[Index];
}
bool String::EqualTo(String &String2)
{
	bool temp = strcmp (this->string, String2.CStr());
	return !temp;
}

void String::Append(String &String2)
{
	Resize(String2.Length());
	strcat(this->string, String2.CStr());
}
void String::Prepend(String &String2)
{
	Resize(String2.Length());
	char* temp = new char[this->size];
	strcpy(temp,this->string);
	strcpy(this->string,String2.CStr());
	strcat(this->string, temp);
	delete[] temp;
}
char* String::CStr()
{
	return this->string;
}
void String::ToLower()
{
	for(int i = 0; i <= this->length; i++)
	{
		//changing only upper case letters to lower case
		if(this->string[i] <= 90 && this->string[i] >= 65)
		{
			this->string[i] += 32;
		}
	}
}
void String::ToUpper()
{
	for(int i = 0; i <= this->length; i++)
	{
		//changing only lower case letters to upper case
		if(this->string[i] <= 122 && this->string[i] >= 97)
		{
			this->string[i] -= 32;
		}
	}
}
int String::Find(String &FindString)
{
	for(int i = 0; i <= this->length; i++)
	{
		//create temporary string from string being searched to be compared to string searched for
		int tempSize = FindString.Length() + 1;
		char* temp = new char[tempSize];
		for(int j = 0; j <= FindString.Length(); j++)
		{
			//ensuring the temporary array will have a null terminator
			if(j == FindString.Length())
			{
				temp[j] = 0;
			}
			else
			{
				temp[j] = this->string[j+i];
			}
		}
		
		String tempS = temp;
		if(tempS == FindString)
		{
			delete[] temp;
			return i;
		}

		delete[] temp;
	}
	return -1;
}
int String::Find(int StartIndex, String &FindString)
{
	for(int i = StartIndex; i <= this->length; i++)
	{
		//create temporary string from string being searched to be compared to string searched for
		int tempSize = FindString.Length() + 1;
		char* temp = new char[tempSize];
		for(int j = 0; j <= FindString.Length(); j++)
		{
			//ensuring the temporary array will have a null terminator
			if(j == FindString.Length())
			{
				temp[j] = 0;
			}
			else
			{
				temp[j] = this->string[j+i];
			}
		}
		
		String tempS = temp;
		if(tempS == FindString)
		{
			delete[] temp;
			return i;
		}

		delete[] temp;
	}
	return -1;
}
void String::Replace(String &FindString, String &ReplaceString)
{
	for(int i = 0; i <= this->length; i++)
	{
		//create temporary string from string being searched to be compared to string searched for
		int tempSize = FindString.Length() + 1;
		char* temp = new char[tempSize];
		for(int j = 0; j <= FindString.Length(); j++)
		{
			//ensuring the temporary array will have a null terminator
			if(j == FindString.Length())
			{
				temp[j] = 0;
			}
			else
			{
				temp[j] = this->string[j+i];
			}
		}
		
		String tempS = temp;
		if(tempS == FindString)
		{
			//creating a temporary array to store the original string with the words replaced before copying it to the original string
			int tempSize2 = this->length - FindString.Length() + ReplaceString.Length() + 1;
			char* temp2 = new char[tempSize2];
			for(int k = 0; k < i; k++)
			{
				temp2[k] = this->string[k];
			}
			int pos = 0;
			for(int k = i; k < i + ReplaceString.Length(); k++)
			{
				temp2[k] = ReplaceString[pos];
				pos++;
			}
			for(int k = i + ReplaceString.Length(); k < tempSize2 ; k++)
			{
				temp2[k] = this->string[k - ReplaceString.Length() + FindString.Length()];
			}



			Resize(strlen(temp2));
			strcpy(this->string, temp2);
			delete[] temp2;
			i += ReplaceString.Length();
		}

		delete[] temp;
	}

}
void String::ReadFromConsole()
{
	//char* temp = new char[];
	//std::cin >> temp;
	//delete[] this->string;
	//this->string = new char[strlen(temp)+1];
	//strcpy(this->string, temp);
	//delete[] temp;

	//String *temp = new String;
	//std::cin.getline(temp->string,256);
	//*this = *temp;


	//creating temporary array to store console input and then copy it to the original string
	char temp[256];
	std::cin.getline(temp,256);
	Resize(strlen(temp));
	strcpy(this->string, temp);

}
void String::WriteToConsole()
{
	std::cout << this->string << std::endl;
}