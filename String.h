#pragma once

#include <fstream>
#include <iostream>

class String
{
private:
    char* str;
public:
    int Size(const char* str);// определение длинны строки, функция класса
    const char* get_str();// геттер
    int Size();// пользовательская функция(выполняется на объекте класаа)
    String();// конструктор по умолчанию
    String(const char* ob);// конструктор с параметрами
    String( String& ob);//конструктор копирования
    int Search(char My);// поиск символа
    int Search(char* My);// перергрузка для подстроки
    void replacement(char My, char My1);// функция замены симфолов
    char operator[](int index);// получение по индексу
    bool operator==(String& My);// сравнение
    String& operator=(String& My);// присваивание
    ~String();//деструктор
    String& operator+( String& My2);// инкапсуляция
};

//String& operator+( String& My1, String& My2);// инкапсуляция
std::ostream& operator<<(std::ostream& os, String& My);// вывод
std::istream& operator>>(std::istream& os, String& My);//ввод(в разработке)

