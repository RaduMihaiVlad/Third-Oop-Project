#include <iostream>
#include <conio.h>
#include <dos.h>
#include <cstdlib>
#include <windows.h>
#include "Product.h"
#include "Shop.h"
#include "ProductList.h"
#include "ShoppingList.h"
using namespace std;

int input;
//Shop s;
ShoppingList<double> sList;

Shop* Shop::instance = 0;

Shop* Shop::getInstance() {
    if (instance == 0) {
        instance = new Shop();
    }
    return instance;
}

Shop* s = Shop::getInstance();

void addBeer() {
    system("cls");
    cout << "Enter the brand:\n";
    string brand;
    cin >> brand;
    cout << "Enter the type:\n";
    string type;
    cin >> type;
    Product *p1 = new Beer(1.0, 1.0, brand, type);
    if (s->exist(p1)) {
        cout << "We already have this product in shop, so please add the quantity you want to supply:\n";
        int quantity;
        cin >> quantity;
        Product *p = new Beer(quantity, 1.0, brand, type);
        s->add(p);
        delete p; // doar adaug cantitatea in obiectul deja creat, iar asta devine inutil
    } else {
        cout << "Please add the quantity:\n";
        int quantity;
        cin >> quantity;
        cout << "Please add the price/beer:\n";
        double pricePerBeer;
        cin >> pricePerBeer;
        Product *p = new Beer(quantity, pricePerBeer, brand, type);
        s->add(p);
    }
    delete p1;
}
void addCabbage() {
    system("cls");
    Product *p1 = new Cabbage(1.0, 1.0);
    if (s->exist(p1)) {
        cout << "We already have this product in shop, so please add the quantity you want to supply:\n";
        int quantity;
        cin >> quantity;
        Product *p = new Cabbage(quantity, 1.0);
        s->add(p);
        delete p;
    } else {
        cout << "Please add the quantity:\n";
        int quantity;
        cin >> quantity;
        cout << "Please add the price/cabbage:\n";
        double pricePerCabbage;
        cin >> pricePerCabbage;
        Product *p = new Cabbage(quantity, pricePerCabbage);
        s->add(p);
    }
    delete p1;
}
void addFlour() {
    system("cls");
    cout << "Enter the flour's quality\n";
    int quality;
    cin >> quality;
    Product *p1 = new Flour(1.0, 1.0, quality);
    if (s->exist(p1)) {
        cout << "We already have this product in shop, so please add the quantity you want to supply:\n";
        int quantity;
        cin >> quantity;
        Product *p = new Flour(quantity, 1.0, quality);
        s->add(p);
        delete p;
    } else {
        cout << "Please add the quantity:\n";
        int quantity;
        cin >> quantity;
        cout << "Please add the price/kg:\n";
        double pricePerFlour;
        cin >> pricePerFlour;
        Product *p = new Flour(quantity, pricePerFlour, quality);
        s->add(p);
    }
    delete p1;
}
void addPotato() {
    system("cls");
    cout << "Enter the type:\n";
    string type;
    cin >> type;
    Product *p1 = new Potato(1.0, 1.0, type);
    if (s->exist(p1)) {
        cout << "We already have this product in shop, so please add the quantity you want to supply:\n";
        int quantity;
        cin >> quantity;
        Product *p = new Potato(quantity, 1.0, type);
        s->add(p);
        delete p;
    } else {
        cout << "Please add the quantity:\n";
        int quantity;
        cin >> quantity;
        cout << "Please add the price/kg:\n";
        double pricePerPotato;
        cin >> pricePerPotato;
        Product *p = new Potato(quantity, pricePerPotato, type);
        s->add(p);
    }
    delete p1;
}
void addSpilledWine() {
    system("cls");
    cout << "Enter the type:\n";
    string type;
    cin >> type;
    Product *p1 = new SpilledWine(1.0, 1.0, type);
    if (s->exist(p1)) {
        cout << "We already have this product in shop, so please add the quantity you want to supply:\n";
        int quantity;
        cin >> quantity;
        Product *p = new SpilledWine(quantity, 1.0, type);
        s->add(p);
        delete p;
    } else {
        cout << "Please add the quantity:\n";
        int quantity;
        cin >> quantity;
        cout << "Please add the price/liter:\n";
        double pricePerSpilledWine;
        cin >> pricePerSpilledWine;
        Product *p = new SpilledWine(quantity, pricePerSpilledWine, type);
        s->add(p);
    }
    delete p1;
}
void addToy() {
    system("cls");
    cout << "Enter the toy name:\n";
    string toyName;
    cin >> toyName;
    Product *p1 = new Toys(1.0, toyName);
    if (s->exist(p1)) {
        cout << "We already have this product in shop, you cannot supply with another one, please add something else:\n";
    } else {
        cout << "Please add the price/toy:\n";
        double pricePerToy;
        cin >> pricePerToy;
        Product *p = new Toys(pricePerToy, toyName);
        s->add(p);
    }
    delete p1;
}
void addVarietyWine() {
    system("cls");
    cout << "Enter the type:\n";
    string type;
    cin >> type;
    cout << "Enter the collecting year:\n";
    int collectingYear;
    cin >> collectingYear;
    cout << "Enter the country from where it was collected:\n";
    string country;
    cin >> country;
    Product *p1 = new VarietyWine(1.0, 1.0, type, collectingYear, country);
    if (s->exist(p1)) {
        cout << "We already have this product in shop, so please add the quantity you want to supply:\n";
        int quantity;
        cin >> quantity;
        Product *p = new VarietyWine(quantity, 1.0, type, collectingYear, country);
        s->add(p);
        delete p;
    } else {
        cout << "Please add the quantity:\n";
        int quantity;
        cin >> quantity;
        cout << "Please add the price/Wine:\n";
        double pricePerVarietyWine;
        cin >> pricePerVarietyWine;
        Product *p = new VarietyWine(quantity, pricePerVarietyWine, type, collectingYear, country);
        s->add(p);
    }
    delete p1;
}

void addNewProduct(int &currentState) {
    cout << "Please select one of the following products to add:\n";
    cout << "1.Beer\n";
    cout << "2.Cabbage\n";
    cout << "3.Flour\n";
    cout << "4.Potato\n";
    cout << "5.Spilled Wine\n";
    cout << "6.Toy\n";
    cout << "7.VarietyWine\n";
    cout << "\n\n\n\n\n";
    cout << "0.Back\n";

    cin >> input;
    if (input == 0) {
        input --;
        currentState = 2;
        return;
    }
    if (input == 1) {
        addBeer();
        return;
    }
    if  (input == 2) {
        addCabbage();
        return;
    }
    if (input == 3) {
        addFlour();
        return;
    }
    if (input == 4) {
        addPotato();
        return;
    }
    if (input == 5) {
        addSpilledWine();
        return;
    }
    if (input == 6) {
        addToy();
        return;
    }
    if (input == 7) {
        addVarietyWine();
        return;
    }
}

void draw(int &currentState) {
    if (currentState == 1) {
        cout << "1.Enter shop manager mode\n";
        cout << "2.Enter buyer mode\n";
        cout << "\n\n\n\n\n";
        cout << "0.Exit\n";

        cin >> input;
        if (input == 1) {
            currentState = 2;
        }
        if (input == 2) {
            currentState = 5;
        }
        if (input == 0) {
            currentState = 0;
        }
        return;
    }
    if (currentState == 2) {
        cout << "1.Print current products\n";
        cout << "2.Add a new product\n";
        cout << "\n\n\n\n\n";
        cout << "0.Back\n";

        cin >> input;
        if (input == 0) {
            currentState = 1;
        }
        if (input == 1) {
            currentState = 3;
        }
        if (input == 2) {
            currentState = 4;
        }
        return;
    }
    if (currentState == 3) {
        cout << *s << "\n";
        cout << "\n\n\n\n\n";
        cout << "0.Back\n";
        cin >> input;
        if (input == 0) { input --;}
        currentState = currentState + input;
        return;
    }
    if (currentState == 4) {
        addNewProduct(currentState);
    }

    if (currentState == 5) {
        cout << "1.Add new product\n";
        cout << "2.Show total cost\n";
        cout << "3.Buy\n";
        cout << "\n\n\n\n\n";
        cout << "0.Back\n";


        cin >> input;
        if (input == 0) {
            currentState = 1;
        }
        if (input == 1) {
            currentState = 6;
        }
        if (input == 2) {
            currentState = 7;
        }
        if (input == 3) {
            currentState = 8;
        }
        return;
    }
    if (currentState == 6) {
        cout << "Please write what you want to buy:\n";
        char text[1000];
        cin.get();
        cin.get(text, 999);
        cin.get();
        Product *pBest = s->bestMatch(text);
        if (pBest->getName() == "None") {
            cout << "Sorry, we didn't find any match, please try again";
            Sleep(1700);
            return;
        }
        cout << "This is the best match we have found:\n";
        cout << *pBest << "\n";
        cout << "Would you like to buy this?\n";
        string answer;
        cin >> answer;
        if (answer == "Yes" || answer ==  "yes") {
            cout << "How much?\n";
            double currentQuantity;
            cin >> currentQuantity;
            if (currentQuantity + pBest->onHold() > pBest->getQuantity()) {
                cout << "We don't have enough quantity. Would you like to buy less?\n";
                cin >> answer;
                if (answer == "yes" || answer == "Yes") {
                    currentState = 6;
                } else {
                    currentState = 5;
                }
            } else {
                cout << "We are adding this product in your shopping cart. Please wait...\n";
                Sleep(3500);
                pBest->addOnHold(currentQuantity);
                sList.add(pBest, currentQuantity);
                cout << "We have added your product in your shopping cart. :) \n";
                Sleep(1700);
                currentState = 5;
            }
        } else {
            currentState = 5;
        }
        return;
    }

    if (currentState == 7) {
        cout << "You have to pay " << sList.getTotalCost() << "\n";
        cout << "\n\n\n\n\n";
        cout << "0.Back\n";
        cin >> input;
        if (input == 0) {
            currentState = 5;
        }
    }
    if (currentState == 8) {
        sList.execute();
        sList.reset();
        cout << "Congratulations, you've finished your shopping session. See you later. :) \n";
        cout << "\n\n\n\n\n";
        cout << "0.Back\n";
        cin >> input;
        if (input == 0) {
            currentState = 1;
        }
    }

}

void setInput() {

    if (_kbhit()) {
        input = _getch() - '0';
    }

}

int main() {

    /*string s;
    getline(cin >> ws, s);
    cout << s;*/

    input = 1;
    int currentState = 1;

    while (currentState) {
        system("cls");
        draw(currentState);

    }


    return 0;
}
