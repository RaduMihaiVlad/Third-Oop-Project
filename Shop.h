#ifndef SHOP_CLASS_OOP
#define SHOP_CLASS_OOP

#include <iostream>
#include <vector>
#include "Product.h"
#include "ProductList.h"
#include <stdio.h>
#include <string.h>

using namespace std;

class Shop {

private:
    vector<Product*> listOfProducts;
    //Product **listOfProducts;
    int listSize;
    int listCapacity;
    Product *failSearch;

    Shop() {
        listSize = 0;
        listOfProducts.clear();
        failSearch = new Product("None", 1, 1, "None");
    }

    static Shop* instance;

public:

    static Shop* getInstance();

    ~Shop() {
        delete failSearch;
        for (vector<Product*>::iterator it = listOfProducts.begin() ; it != listOfProducts.end(); ++it) {
            delete (*it);
        }
        listOfProducts.clear();
    }



    /*Shop(Shop &s) {
        this->listSize = s.listSize;
        listOfProducts.clear();
        for (int i = 0; i < listSize; ++i) {
            listOfProducts.push_back(s.listOfProducts[i]);
        }

    }*/

    void checkCurrentProduct(Product *p) {
        listOfProducts.push_back(p);
        listSize ++;
    }

    bool exist(Product *p) {
        for (int i = 0; i < listOfProducts.size(); ++i) {
            if (listOfProducts[i]->operator==(*p)) {
                return true;
            }
        }
        return false;
    }

    void add(Product *p) {

        // if p exists in list we add his quantity

        for (int i = 0; i < listSize; ++i) {
            if (listOfProducts[i]->operator==(*p)) {
                if (listOfProducts[i]->getName() != "Toys") {
                    listOfProducts[i]->addQuantity((*p).getQuantity());
                }
                return;
            }
        }

        // else we make a new product

        checkCurrentProduct(p);
    }

    friend ostream &operator <<(ostream &out, const Shop &s) {
        for (int i = 0; i < s.listSize; ++i) {
            Product *currentElement = s.listOfProducts[i];
            out << *currentElement << "\n";
        }
        return out;
    }

    Product *bestMatch(char *text) {
        int cntMax = -1;
        int pos = 0;
        int wordNumber = 0;
        char **words = new char*[1000];
        char *currentWord = strtok(text, " ");
        while (currentWord != NULL) {
            words[wordNumber] = new char[strlen(currentWord) + 1];
            strcpy(words[wordNumber], currentWord);
            wordNumber ++;
            currentWord = strtok(NULL, " ");
        }
        for (int i = 0; i < listOfProducts.size(); ++i) {
            int cntCurrent = 0;
            for (int j = 0; j < wordNumber; ++j) {
                cntCurrent = cntCurrent + listOfProducts[i]->matchNumber(words[j]);
            }
            if (cntCurrent > cntMax && listOfProducts[i]->getQuantity() > 0.0  ) {
                cntMax = cntCurrent;
                pos = i;
            }
        }
        /*for (int i = 0; i < 1000; ++i) {
            delete[] words[i];
        }*/
        delete[] words;
        if (cntMax == 0) {
            return failSearch;
        }
        return listOfProducts[pos];
    }




};



#endif // SHOP_CLASS_OOP
