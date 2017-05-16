#include <iostream>

using namespace std;

/*
 Adapter Pattern
 Implement by Ahmet Sivri
 Adapter Implementation Type: Object
 Scenario: Suppose that there is a lecture and there is two types of students from Turkey and USA,
 The lecture goes with English and Turkish ones cannot understand that.We need to have a translator
 that will translate the lecture to the Turkish students.
 In this example, a Student class will be the Target, the translator will be the Adapter,
 and the Turkish students will be the Adaptee, like the class diagram below:
 Story adapted from: qa.geeksforgeeks.org/562/what-is-adapter-design-pattern-a-practical-example
 */


//Target class
class Student{
public:
    virtual string speaksEnglish() = 0;
};

//Adaptee Class
class TurkishStudent{
public:
    string speaksTurkish()
    {
        cout<<"We are speaking Turkish"<<endl;
        return "Merhaba!"; //It's kinda useless here.
    }
};

//Adaptor class
class Translator: public Student{
public:
    string speaksEnglish()
    {
        string _hello = _turkish->speaksTurkish();
        cout<<"Adaptor class has been called"<<endl;
        cout<<"Now Turkish students are also able to understand the lecture!"<<endl;
        return _hello;
    }

    Translator(TurkishStudent *turkish): _turkish(turkish) {};

private:
    TurkishStudent *_turkish;
};

//Main works as client here.
int main()
{
    Student *sObj = new Translator(new TurkishStudent);

    string hello = sObj->speaksEnglish();
}