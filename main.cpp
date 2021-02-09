#include <iostream>
class String
{
 private:
    char* str;
    
public:
    
    int Size(char* str)
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
    
    String(): str(nullptr)//Конструктор по умолчпнию
    {
    }
    
    String(char* ob)//конструктор с параметрами
    {
        int length=Size(ob);
        str = new char[length];
        for (int i = 0; i < length; i++)
        {
            str[i] =ob[i];
        }
    }
    
    String( String& ob)//конструктор копирования
    {
        int length=Size(ob.str);
        str = new char[length];
        for (int i = 0; i < length; i++)
        {
            str[i] =ob.str[i];
        }
    }
    
    ~String()//деструктор
    {
        if(str!=nullptr)
        {
                delete[] str;
            }
    }
    
    int Search(String& My)
    {
    
        for (int i = 0; i < Size(str); ++i)
        {
            if (My.str[0]==str[i])
            {
                return i;
            }
        }
        return -1;
    }
    
   void replacement(char* My, char* My1)// функция замены симфолов
    // сначала символ который хотим замнить, потм символ, который хотим вставить
    {
        for (int i = 0; i < Size(str); ++i)
        {
            if (My[0] == str[i])
            {
                str[i] = My1[0];
            }
        }
        return;
    }
    
    char operator[](int index)
    {
        return this->str[index];
    }
    /*String operator+(String& My)
    {
        int Size2=Size(My.str);// длянна первой строки
        int Size1= Size(str);// длинна второй строки
        String temp;
        str= new char[Size2+Size1];
        if(My.str != nullptr)
        {
            for (int i = 0; i < Size1; i++)
            {
                temp.str[i]=My.str[i];
            }
        }
        return My;
    }*/
    
};

int main()
{
    String k("aaaggg");
    String m("t");
    k.replacement("t", "k");
    return 0;
}
