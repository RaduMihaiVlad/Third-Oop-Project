#ifndef SHOP_SHOPPINGLIST_CLASS
#define SHOP_SHOPPINGLIST_CLASS

#include <iostream>


using namespace std;

template<class T>
class ShoppingList {
private:
    vector<Product*> listOfProducts;
    vector<T> quantity;
public:
    ShoppingList() {
        listOfProducts.clear();
        quantity.clear();
    }

    ~ShoppingList() {
        for (vector<Product*>::iterator it = listOfProducts.begin() ; it != listOfProducts.end(); ++it) {
            delete (*it);
        }
        listOfProducts.clear();
    }

    void add(Product *p, T currentQuantity) {
        for (int i = 0; i < listOfProducts.size(); ++i) {
            if (listOfProducts[i] == p) {
                quantity[i] += currentQuantity;
                return;
            }
        }
        listOfProducts.push_back(p);
        quantity.push_back(currentQuantity);
    }

    double getTotalCost() {
        double totalCost = 0;
        for (int i = 0; i < listOfProducts.size(); ++i) {
            totalCost = totalCost + listOfProducts[i]->getPrice(quantity[i]);
        }
        return totalCost;
    }

    void execute() {
        for (int i = 0; i < listOfProducts.size(); ++i) {
            listOfProducts[i]->substract(quantity[i]);
            listOfProducts[i]->clearOnHold();
        }
    }
    void reset() {
        listOfProducts.clear();
        quantity.clear();
    }

};



#endif // SHOP_SHOPPINGLIST_CLASS
