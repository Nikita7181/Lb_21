#pragma once
#include <fstream>

class String
{
private:
    char* str;
    int Size(const char* str);// определение длинны строки, функция класса
public:
    char* get_str();// геттер
    int Size();// пользовательская функция(выполняется на объекте класаа)
    String();// конструктор по умолчанию
    String(const char* ob);// конструктор с параметрами
    String( String& ob);//конструктор копирования
    int Search(char My);// поиск подстроки
    int Search(char* My);
    void replacement(String My, String My1);// функция замены симфолов
    char operator[](int index);// получение по индексу
    bool operator==(String& My);// сравнение
    String& operator=(String& My);// присваивание
    ~String();//деструктор
    String& operator+( String& My2);// инкапсуляция
};

std::ostream& operator<<(std::ostream& os, String& My);// вывод
std::istream& operator>>(std::istream& os, String& My);//ввод(в разработке)

