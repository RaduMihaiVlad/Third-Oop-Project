#ifndef SHOP_SHOPPRODUCT_CLASS
#define SHOP_SHOPPRODUCT_CLASS

/*#include <iostream>
#include "Product.h"

using namespace std;

class ShopProduct: public Product {
private:
    double quantity;
public:
    ShopProduct() {
        name = "";
        sellingType = "";
        quantity = 0;
        pricePerObject = 0;
    }


    ShopProduct(string Name, double Quantity, double PricePerObject, string SellingType, string Brand = "", string Type = ""):
        Product(Name, PricePerObject, SellingType, Brand, Type), quantity(Quantity) {}

    ~ShopProduct() {}

    ShopProduct(const ShopProduct &p) {
        this->name = p.name;
        this->quantity = p.quantity;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
    }

    ShopProduct &operator =(const ShopProduct &p) {
        this->name = p.name;
        this->quantity = p.quantity;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
        return (*this);
    }


    double getQuantity() const { return quantity;}

    void addQuantity(double Quantity) {
        quantity += Quantity;
    }
    void substract(double substractedQuantity) {
        if (substractedQuantity > quantity) throw("Not enought quantity.");
        quantity = quantity - substractedQuantity;
    }

    friend istream &operator >>(istream &in, ShopProduct &p) {
        in >> p.name >> p.sellingType >> p.quantity >> p.pricePerObject
                >> p.brand >> p.type;
        return in;
    }

    friend ostream &operator <<(ostream &out, ShopProduct &p) {
        out << "Name: " << p.name << "\n";
        out << "SellingType: " << p.sellingType << "\n";
        out << "Quantity: " << p.quantity << "\n";
        out << "Price/Object: " <<  p.pricePerObject << "\n";
        out << "Brand: " << p.brand << "\n";
        out << "Type: " << p.type << "\n";
        return out;
    }

    friend bool operator ==(const ShopProduct &s1, const ShopProduct &s2) {
        if (s1.name == s2.name && s1.brand == s2.brand && s1.type == s2.type) return true;
        return false;
    }
    friend bool operator !=(const ShopProduct &s1, const ShopProduct &s2) {
        return !(s1 == s2);
    }


};*/



#endif // SHOP_SHOPPRODUCT_CLASS
