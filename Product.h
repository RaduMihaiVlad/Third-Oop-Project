#ifndef SHOP_PRODUCT_CLASS
#define SHOP_PRODUCT_CLASS

#include <iostream>

using namespace std;

class Product {
protected:
    string name;
    double pricePerObject;
    double quantity;
    string sellingType;
    double onHoldProducts;

public:

    Product() {
        name = "";
        sellingType = "";
        pricePerObject = 0.0;
        quantity = 0.0;
        onHoldProducts = 0.0;

    }

    Product(string Name, double PricePerObject, double Quantity, string SellingType):
        name(Name), pricePerObject(PricePerObject),
        sellingType(SellingType), quantity(Quantity), onHoldProducts(0.0) {}

    Product(const Product &p) {
        this->name = p.name;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
        this->quantity = p.quantity;
        this->onHoldProducts = p.onHoldProducts;
    }

    virtual ~Product() {}

    Product &operator =(const Product &p) {
        this->name = p.name;
        this->pricePerObject = p.pricePerObject;
        this->sellingType = p.sellingType;
        this->quantity = p.quantity;
        this->onHoldProducts = p.onHoldProducts;
        return (*this);
    }

    friend istream &operator >>(istream &in, Product &p) {
        in >> p.name >> p.sellingType >> p.pricePerObject >> p.quantity >> p.onHoldProducts;
        return in;
    }

    virtual void getOutput(ostream &out) {
        out << "Name: " << name << "\n";
        out << "SellingType: " << sellingType << "\n";
        out << "Price/Object: " <<  pricePerObject << "\n";
        out << "Quantity: " << quantity << "\n";
    }

    friend ostream &operator <<(ostream &out, Product &p) {
        p.getOutput(out);
        return out;
    }

    string getName() const{ return name;}
    double getPricePerObject() const{ return pricePerObject;}
    string getSellingType() const{ return sellingType;}
    double getQuantity() const{ return quantity;}
    void addQuantity(double quant) { quantity += quant;}
    double onHold() { return onHoldProducts;}
    void addOnHold(double onHoldQuantity) { onHoldProducts += onHoldQuantity;}
    void clearOnHold() { onHoldProducts = 0;}



    double getPrice(double objectNumber) {
        return (double) objectNumber * pricePerObject;
    }

    virtual bool operator ==(const Product &p1) {
        cout << "P\n";
        return (p1.name == name);
    }

    void substract(double currentQuantity) {
        if (quantity < currentQuantity) throw("Not enought quantity");
        quantity = quantity - currentQuantity;
    }

    virtual string getBrand() const {}
    virtual string getType() const {}
    virtual int getQuality() const {}
    virtual string getToyName() const {}
    virtual int getCollectingYear() const {}
    virtual string getCountry() const {}
    virtual int matchNumber(char *word) {}

};


#endif // SHOP_PRODUCT_CLASS
