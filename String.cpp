//
// Created by nik on 09.02.2021.
//

#include "String.h"

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

const char* String::get_str()// геттер
{
    int size = this->Size();
    
    if (size == 0) return nullptr;
    /*char* result = new char[size];
    
    for (int i=0; i<size; i++)
    {
        result[i] = str[i];
    }*/
    
    return &str[0];
}


String::String()//Конструктор по умолчпнию
{
    str = nullptr;
}

String::String(const char* ob)//конструктор с параметрами
{
    int length=Size(ob);
    str = new char[length+1];
    
    for (int i = 0; i < length; i++)
    {
        str[i] = ob[i];
    }
    str[length] = '\0';
}

String::String(String& ob)//конструктор копирования
{
    int length=Size(ob.str);
    
    str = new char[length+1];
    for (int i = 0; i < length; i++)
    {
        str[i] =ob.str[i];
    }
    str[length] = '\0';
}

String::~String()//деструктор
{
    if(str!=nullptr)
    {
        delete[] str;
    }
}

int String::Search(char My)// поиск
{
    
    for (int i = 0; i < Size(str); i++)
    {
        if (My==str[i])
        {
            std::cout << "position: ";
            return i;
        }
    }
    return -1;
}

int String::Search(char* My)
{
    int size = Size(str);
    int size_m = Size(My);
    for (int i = 0; i < size; i++)
    {
        if ((My[0]==str[i]) && (size-i >= size_m))
        {
            for (int j = 1; j < size_m; j++)
            {
                if ((My[j]!=str[j+i]) && (size-i >= size_m))
                {
                    break;
                }
                else if((j == size_m - 1) &&  My[j] == str [i+j])
                {
                    std::cout << "position: ";
                    return i;
                }
                else if(size-i < size_m)
                    return -1;
                
            }
            
        }
    }
    return -1;
}

void String::replacement(char My, char My1)// функция замены симфолов
// сначала символ который хотим замнить, потм символ, который хотим вставить
{
    int counter = 0;
    
    for (int i = 0; i < Size(str); ++i)
    {
        if (My == str[i])
        {
            str[i] = My1;
            counter++;
        }
    }
    std::cout << "number of replaced characters: " << counter << std::endl;
    return;
}

String& String::operator+(String& My2)// инкапсулция
{
    int s1 = Size(this->str);
    int s2 = My2.Size();
    
    //const char* tmp = this->get_str();
    //delete [] this->str;
    char* tmp = new char [s1+s2+1];
    for (int i = 0; i < s1; i++)
    {
        tmp[i] =str[i];
    }
    for(int i = 0; i < s2; i++)
    {
        tmp[s1+i]=My2[i];
    }
    tmp[s1+s2]='\0';
    String *temp = new String(tmp);
    return *temp;
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
    this->str = new char [size+1];
    for (int i = 0; i < size; i++)
    {
        this->str[i]=My[i];
    }
    this->str[size] = '\0';
    return *this;
}

std::ostream& operator<<(std::ostream& os, String& My)// вывод
{
    int length = My.Size();
    
    for (int i = 0; i < length; i++)
    {
        os << My[i];
    }
    
    return os;
}

std::istream& operator>>(std::istream& is, String& My)// оператор ввода(в разработке)
{
    char* m = new char[1024];
    
    for(int i=0; i < 1024; i++)
    {
        m[i] = '\0';
    }
    is >> m;
    String tmp(m);
    My = tmp;
    return is;
}

bool String::operator==(String& My)// оператор сравнения
{
    
    if (this->Size() != My.Size()) return false;
    for (int i = 0; i < this->Size(); i++)
    {
        if (this->str[i] != My[i]) return false;
    }
    
    return true;
}
