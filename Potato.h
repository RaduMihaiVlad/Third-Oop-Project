#ifndef SHOP_POTATO_CLASS
#define SHOP_POTATO_CLASS

#include <iostream>
#include "Product.h"
#include <string.h>
#include "Utils.h"
using namespace std;

class Potato: public Product {
protected:
    string type;

public:
    Potato(double Quantity, double PricePerObject, string Type): Product("Potato", PricePerObject, Quantity, "kg"), type(Type) {}

    Potato(Potato &p) {
        this->name = p.name;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
        this->quantity = p.quantity;
        this->type = p.type;
    }

    Potato &operator =(const Potato &p) {
        this->name = p.name;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
        this->quantity = p.quantity;
        this->type = p.type;
        return (*this);
    }

    string getType() const { return type;}

    bool operator ==(const Product &c) {
        return (c.getName() == name && c.getType() == type);
    }

    void getOutput(ostream &out) {
        out << "Name: " << name << "\n";
        out << "SellingType: " << sellingType << "\n";
        out << "Price/Object: " <<  pricePerObject << "\n";
        out << "Quantity: " << quantity - onHoldProducts << "\n";
        out << "Type: " << type << "\n";
    }

    int matchNumber(char *word) {
        int cnt = 0;
        const char *cstr = name.c_str();
        if (stristr(cstr, word)) cnt ++;
        cstr = sellingType.c_str();
        if (stristr(cstr, word)) cnt ++;
        cstr = type.c_str();
        if (stristr(cstr, word)) cnt++;

        delete cstr;
        return cnt;
    }

};

#endif // SHOP_POTATO_CLASS
