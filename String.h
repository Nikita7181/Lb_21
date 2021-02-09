#pragma once
#include <fstream>

class String
{
private:
    char* str;
public:
    char* get_str();
    int Size(const char* str);// определение длинны строки, функция класса
    int Size();
    String();// конструктор по умолчанию
    String(const char* ob);// конструктор с параметрами
    String( String& ob);//конструктор копирования
    int Search(String& My);// поиск подстроки
    void replacement(char* My, char* My1);// функция замены симфолов
    char operator[](int index);
    bool operator==(String& My);
    String & operator=(String& My);
    ~String();//деструктор

    String & operator+( String& My2);// инкапсуляция
};


std::ostream& operator<<(std::ostream& is, String& My);//вывод
std::istream& operator>>(std::istream& os, String& My);//ввод
