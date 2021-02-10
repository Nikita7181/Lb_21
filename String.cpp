//
// Created by nikmi on 09.02.2021.
//

#include "String.h"
#include <iostream>

int String::Size(const char* str_t)// функция получения размреа строки
{
   int counter=0;
    if (str_t!=nullptr)
    {
        while (str_t[counter] != '\0')
        {
            counter++;
        }
    }
    return counter;
}

int String::Size()// пользовательская функция получения размера
{
    int counter=0;
    if (str!=nullptr)
    {
        while (str[counter] != '\0')
        {
            counter++;
        }
    }
    return counter;
}

char* String::get_str()// геттер
{
    int size = this->Size();
    if (size == 0) return nullptr;
    char* result = new char[size];
    for (int i=0; i<size; i++)
    {
        result[i] = str[i];
    }
    return result;
}


String::String(): str(nullptr)//Конструктор по умолчпнию
{
}

String::String(const char* ob)//конструктор с параметрами
{
    int length=Size(ob);
    str = new char[length];
    for (int i = 0; i < length; i++)
    {
        str[i] =ob[i];
    }
}

String::String( String& ob)//конструктор копирования
{
    int length=Size(ob.str);
    str = new char[length];
    for (int i = 0; i < length; i++)
    {
        str[i] =ob.str[i];
    }
}

String::~String()//деструктор
{
    if(str!=nullptr)
    {
        delete[] str;
    }
}

int String::Search(String& My)// поиск
{
    
    for (int i = 0; i < Size(str); ++i)
    {
        if (My.str[0]==str[i])
        {
            std::cout << "position: ";
            return i;
        }
    }
    return -1;
}

void String::replacement(char* My, char* My1)// функция замены симфолов
// сначала символ который хотим замнить, потм символ, который хотим вставить
{
    int counter = 0;
    for (int i = 0; i < Size(str); ++i)
    {
        if (My[0] == str[i])
        {
            str[i] = My1[0];
            counter++;
        }
    }
    std::cout << "number of replaced characters: " << counter << std::endl;
    return;
}

String & String::operator+( String& My2 )// инкапсуляция
{
    int s1 = this->Size();
    int s2 = My2.Size();
    
    char * tmp = this->get_str();
    delete [] this->str;
    this->str=nullptr;
    this->str = new char [s1+s2];
    for (int i = s1+s2; i < Size(); i++)
    {
        this->str[i] ='\0';
    }
    for (int i = 0; i < s1; i++)
    {
        this->str[i] =tmp[i];
    }
    for(int i = 0; i < s2; i++) 
    {
        this->str[s1+i]=My2[i];
    }
    return * this;
}

char String::operator[](int index)
{
    return this->str[index];
}

String& String::operator=(String& My)// оператор присваивания
{
    if (this == &My)
        return *this;
    
    delete [] this->str;
    int size = My.Size();
    this->str = new char [size];
    for (int i = 0; i < size; i++)
    {
        this->str[i]=My[i];
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, String& My)// вывод
{
    int length = My.Size();
    for (int i = 0; i < length; ++i)
    {
        os << My[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, String& My)// оператор ввода
{

}

bool String::operator==(String& My)
{

    if (this->Size() != My.Size()) return false;
    for (int i = 0; i < this->Size(); i++)
    {
        if (this->str[i] != My[i]) return false;
    }
    return true;
}
