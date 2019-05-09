#ifndef SHOP_BEER_CLASS
#define SHOP_BEER_CLASS

#include <iostream>
#include "Product.h"
#include <string.h>
#include "Utils.h"

using namespace std;

class Beer: public Product {
protected:
    string brand;
    string type;

public:


    Beer(double Quantity, double PricePerObject, string Brand, string Type): Product("Beer", PricePerObject, Quantity, "buc"),
                   brand(Brand), type(Type) {}

    Beer(Beer &p) {
        this->name = p.name;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
        this->quantity = p.quantity;
        this->brand = p.brand;
        this->type = p.type;
    }

    Beer &operator =(const Beer &p) {
        this->name = p.name;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
        this->quantity = p.quantity;
        this->brand = p.brand;
        this->type = p.type;
        return (*this);
    }

    string getBrand() const { return brand;}
    string getType() const { return type;}

    void getOutput(ostream &out) {
        out << "Name: " << name << "\n";
        out << "SellingType: " << sellingType << "\n";
        out << "Price/Object: " <<  pricePerObject << "\n";
        out << "Quantity: " << quantity - onHoldProducts << "\n";
        out << "Brand: " << brand << "\n";
        out << "Type: " << type << "\n";
    }

    bool operator ==(const Product &c) {
        return (c.getName() == name && c.getBrand() == brand && c.getType() == type);
    }

    int matchNumber(char *word) {
        int cnt = 0;
        const char *cstr = name.c_str();
        if (stristr(cstr, word)) cnt ++;
        cstr = brand.c_str();
        if (stristr(cstr, word)) cnt ++;
        cstr = type.c_str();
        if (stristr(cstr, word)) cnt ++;
        cstr = sellingType.c_str();
        if (stristr(cstr, word)) cnt ++;
        delete cstr;
        return cnt;
    }


};


#endif // SHOP_BEER_CLASS
