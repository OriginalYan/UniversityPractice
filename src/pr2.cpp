#include <iostream>
#include "../main_screen.h"
using namespace std;

int main (int argc, char ** argv) {
    MainScreen *t = new MainScreen();
    t->exec();
    return 0; 
};