#ifndef SHOP_SPILLEDWINE_CLASS
#define SHOP_SPILLEDWINE_CLASS


#include <iostream>
#include "Product.h"
#include <string.h>
#include "Utils.h"
using namespace std;

class SpilledWine: public Product {
protected:
    string type;
public:
    SpilledWine(double Quantity, double PricePerObject, string Type): Product("SpilledWine", PricePerObject, Quantity, "volume"), type(Type) {}

    SpilledWine(SpilledWine &p) {
        this->name = p.name;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
        this->quantity = p.quantity;
        this->type = p.type;
    }

    SpilledWine &operator =(const SpilledWine &p) {
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
        if (stristr(cstr, word)) cnt ++;
        delete cstr;
        return cnt;
    }

};


#endif // SHOP_SPILLEDWINE_CLASS
