#ifndef SHOP_TOYS_CLASS
#define SHOP_TOYS_CLASS

#include <iostream>
#include <string.h>
#include "Product.h"
#include "Utils.h"
using namespace std;

class Toys: public Product {
protected:
    string toyName;
public:
    Toys(double PricePerObject, string ToyName): Product("Toys", PricePerObject, 1.0, "kg"), toyName(ToyName) {}

    Toys(Toys &p) {
        this->name = p.name;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
        this->quantity = p.quantity;
        this->toyName = p.toyName;
    }

    Toys &operator =(const Toys &p) {
        this->name = p.name;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
        this->quantity = p.quantity;
        this->toyName = p.toyName;
        return (*this);
    }

    string getToyName() const { return toyName;}

    bool operator ==(const Product &c) {
        return (c.getName() == name && c.getToyName() == toyName);
    }

    void getOutput(ostream &out) {
        out << "Name: " << name << "\n";
        out << "SellingType: " << sellingType << "\n";
        out << "Price/Object: " <<  pricePerObject << "\n";
        out << "Quantity: " << quantity - onHoldProducts << "\n";
        out << "Toy Name: " << toyName << "\n";
    }

    int matchNumber(char *word) {
        int cnt = 0;
        const char *cstr = name.c_str();
        if (stristr(cstr, word)) cnt ++;
        cstr = sellingType.c_str();
        if (stristr(cstr, word)) cnt ++;
        cstr = toyName.c_str();
        if (stristr(cstr, word)) cnt ++;
        delete cstr;
        return cnt;
    }

};

#endif // SHOP_TOYS_CLASS
