#ifndef SHOP_VARIETYWINE_CLASS
#define SHOP_VARIETYWINE_CLASS

#include <iostream>
#include <string.h>
#include "Product.h"
#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class VarietyWine: public Product {
protected:

    string type;
    int collectingYear;
    string country;
public:

    VarietyWine(double Quantity, double PricePerObject, string Type, int CollectingYear, string Country): Product("VarietyWine", PricePerObject, Quantity, "buc"),
                                        type(Type), collectingYear(CollectingYear), country(Country) {}

    VarietyWine(VarietyWine &p) {
        this->name = p.name;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
        this->quantity = p.quantity;
        this->type = p.type;
        this->collectingYear = p.collectingYear;
        this->country = p.country;
    }

    VarietyWine &operator =(const VarietyWine &p) {
        this->name = p.name;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
        this->quantity = p.quantity;
        this->type = p.type;
        this->collectingYear = p.collectingYear;
        this->country = p.country;
        return (*this);
    }

    int getCollectingYear() const { return collectingYear;}
    string getCountry() const { return country;}


    bool operator ==(const Product &c) {
        return (c.getName() == name && c.getType() == type &&
                c.getCollectingYear() == collectingYear && c.getCountry() == country);
    }

    void getOutput(ostream &out) {
        out << "Name: " << name << "\n";
        out << "SellingType: " << sellingType << "\n";
        out << "Price/Object: " <<  pricePerObject << "\n";
        out << "Quantity: " << quantity - onHoldProducts << "\n";
        out << "Type: " << type << "\n";
        out << "Collecting year: " << collectingYear << "\n";
        out << "Country: " << country << "\n";
    }

    int matchNumber(char *word) {
        int cnt = 0;
        const char *cstr = name.c_str();
        if (stristr(cstr, word)) cnt ++;
        cstr = sellingType.c_str();
        if (stristr(cstr, word)) cnt ++;
        cstr = type.c_str();
        if (stristr(cstr, word)) cnt ++;
        cstr = country.c_str();
        if (stristr(cstr, word)) cnt ++;
        char yearChar[10];
        itoa(collectingYear, yearChar, 10);
        if (stristr(yearChar, word)) cnt ++;
        delete cstr;
        return cnt;
    }

};


#endif // SHOP_VARIETYWINE_CLASS
