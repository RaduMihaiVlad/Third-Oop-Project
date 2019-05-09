#ifndef UTILS_SHOP_PROJECT
#define UTILS_SHOP_PROJECT

#include <iostream>
#include <string.h>

using namespace std;

char* stristr(const char* haystack, const char* needle) {
    do {
        const char* h = haystack;
        const char* n = needle;
        while (tolower((unsigned char) *h) == tolower((unsigned char ) *n) && *n) {
            h++;
            n++;
        }
        if (*n == 0) {
            return (char *) haystack;
        }
    } while (*haystack++);
    return 0;
}


#endif // UTILS_SHOP_PROJECT
