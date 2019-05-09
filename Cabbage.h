#ifndef SHOP_CABBAGE_CLASS
#define SHOP_CABBAGE_CLASS

#include <iostream>
#include "Product.h"
#include <string.h>
#include "Utils.h"

using namespace std;


class Cabbage: public Product {

public:
    Cabbage(double Quantity, double PricePerObject): Product("Cabbage", PricePerObject, Quantity, "buc") {}

    Cabbage(Cabbage &p) {
        this->name = p.name;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
        this->quantity = p.quantity;
    }

    Cabbage &operator =(const Cabbage &p) {
        this->name = p.name;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
        this->quantity = p.quantity;
        return (*this);
    }

    bool operator ==(const Product &c) {
        return (c.getName() == name);
    }

    void getOutput(ostream &out) {
        out << "Name: " << name << "\n";
        out << "SellingType: " << sellingType << "\n";
        out << "Price/Object: " <<  pricePerObject << "\n";
        out << "Quantity: " << quantity - onHoldProducts << "\n";
    }

    int matchNumber(char *word) {
        int cnt = 0;
        const char *cstr = name.c_str();
        if (stristr(cstr, word)) cnt ++;
        cstr = sellingType.c_str();
        if (stristr(cstr, word)) cnt ++;
        delete cstr;
        return cnt;
    }



};


#endif // SHOP_CABBAGE_CLASS
