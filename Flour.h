#ifndef SHOP_FLOUR_CLASS
#define SHOP_FLOUR_CLASS


#include <iostream>
#include "Product.h"
#include <string.h>
#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Flour: public Product {
protected:
    int quality;
public:

    Flour(double Quantity, double PricePerObject, int Quality): Product("Flour", PricePerObject, Quantity, "kg"), quality(Quality) {}

    Flour(Flour &p) {
        this->name = p.name;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
        this->quantity = p.quantity;
        this->quality = p.quality;
    }

    Flour &operator =(const Flour &p) {
        this->name = p.name;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
        this->quantity = p.quantity;
        this->quality = p.quality;
        return (*this);
    }

    int getQuality() const { return quality;}

    bool operator ==(const Product &c) {
        return (c.getName() == name && c.getQuality() == quality);
    }

    void getOutput(ostream &out) {
        out << "Name: " << name << "\n";
        out << "SellingType: " << sellingType << "\n";
        out << "Price/Object: " <<  pricePerObject << "\n";
        out << "Quantity: " << quantity - onHoldProducts << "\n";
        out << "Quality: " << quality << "\n";
    }

    int matchNumber(char *word) {
        int cnt = 0;
        const char *cstr = name.c_str();
        if (stristr(cstr, word)) cnt ++;
        cstr = sellingType.c_str();
        if (stristr(cstr, word)) cnt ++;
        char qualityChar[10];
        itoa(quality, qualityChar, 10);
        if (stristr(qualityChar, word)) cnt ++;
        delete cstr;
        return cnt;
    }

};


#endif // SHOP_FLOUR_CLASS
