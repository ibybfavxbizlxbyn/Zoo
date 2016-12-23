#ifndef ZOO_H_INCLUDED
#define ZOO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

class zoo
{
private:
    string animal;
    bool gender;
    string name;
    int price;
    int quantity;
public:

    /*
        Constructor
    */
    zoo(const string animal_ = "penguin", const bool gender_ = 0, const string name_ = "vasya", const int price = 1000000, const int quantity_ = 10)
    {
        cout << "Would you like to enter animal info from file \"animal-info.txt\"(y/n): ";
        char choise;
        bool from_file;
        cin >> choise;
        if (choise == 'y')
        {
            from_file = true;
        } else
        if (choise == 'n')
        {
            from_file = false;
        } else
        {
            cout << "Error(1): Wrong input of DATA;";
            system("pause");
            return 1;
        }

        if (from_file == false)
        {
            animal = animal_;
            gender = gender_;
            name = name_;
            price = price_;
            quantity = quantity_;
        } else
        {
            ifstream fin;
            fin.open("animal-info.txt");
            if (!fin.is_open())
            {
                cout << "Error(2): Could not open a file;"
                system("pause");
                return 2;
            } else
            {
                fin >> animal;
                fin >> gender;
                fin >> name;
                fin >> price;
                fin >> quantity;
            }
        }
    }

    /*
        Destructor
    */
    ~zoo()
    {
        cout << "Animal: " << animal << endl << "Gender: " << gender << endl << "Price: " << price << endl
        << "Quantity: " << quantity << "RIP " << name << endl;
    }

    /*
        Get and Set methods
    */
    void setAnimal (const string animal_ = "penguin")
    {
        animal = animal_;
    }
    string getAnimal () const
    {
        return animal;
    }
    void setGender (const bool gender_ = 0)
    {
        gender = gender_;
    }
    bool getGender () const
    {
        return gender;
    }
    void setName (const string name_)
    {
        name = name_;
    }
    string getName () const
    {
        return name;
    }
    void setPrice (const int price_)
    {
        price = price_;
    }
    int getPrice () const
    {
        return price;
    }
    void setQuantity (const int quantity_)
    {
        quantity = quantity_;
    }
    int getQuantiy () const
    {
        return quantity;
    }

};

#endif // ZOO_H_INCLUDED
