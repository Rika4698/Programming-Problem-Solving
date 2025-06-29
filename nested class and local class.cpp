#include<iostream>
using namespace std;

class Person
{
    public:
    string name;

    class Address
    {
    public:
        string country;
        int hno;
    };
    Address addre;
    void display()
    {
        cout<<"Person name = "<<name<<endl;

        cout<<"Country = "<<addre.country<<endl<<"House no = "<<addre.hno<<endl;

        class Profession
        {
        public:
            string name;
            string place;
        };
        Profession x1;
        x1.name = "Businessman";
        x1.place = "Dhaka";


        cout<<"Profession = "<<x1.name<<endl;
        cout<<"Profession place = "<<x1.place<<endl;

    }



};



 int main()
    {
    Person y1;
    y1.name = "MD Shahin";
    y1.addre.country = "Bangladesh";
    y1.addre.hno = 24;
    y1.display();

    return 0;
    }
