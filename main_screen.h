#ifndef MAIN_SCREEN_H_
#define MAIN_SCREEN_H_
#include <iostream>
#include <string.h>
#include <list>
#include <vector>
#include "clear.h"

using namespace std;

enum Type {
    FEDERAL, REGIONAL
};

struct PTY {
    string Name; 
    string Adress; 
    Type type; 
    int Foundation_Year; 
    int License_Number; 
    int Accreditation_Number; 
    string Accreditation_End_Date; 
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