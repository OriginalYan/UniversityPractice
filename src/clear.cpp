#include "../clear.h"
#include <iostream>

using namespace std;

void Clear::clear() {
    for (int i = 0; i < 100; i++) {
        cout << endl; 
    }
};