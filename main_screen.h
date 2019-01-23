#ifndef MAIN_SCREEN_H_
#define MAIN_SCREEN_H_
#include <iostream>
#include <string.h>
#include <list>
#include <vector>
#include "clear.h"

using namespace std;

struct PTY {
    string Coordinates;  
    string type; 
    string Okrug; 
    int Year; 
};

class MainScreen {
    private:
        vector<PTY> data; 
        bool exit_key = false;
        Clear* cls = new Clear();
        bool int_error = false;

    public: 
        void exec();
        void choose(const string& code);
        void navigateToAdd();
        void navigateToDelete();
        void navigateToEdit();
        void navigateToView();
        void navigateToMenu();
        void dataPush(const PTY& newdata);
        void dataRemoveByID(int id);
        void dataEditByID(int id, const PTY& newdata);
        bool isEmpty();
        vector<PTY> getData(); 
};

#endif