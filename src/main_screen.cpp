#include "../main_screen.h"


vector<PTY> MainScreen::getData() {
    return this->data;
}

void MainScreen::exec() {
    navigateToMenu();
    while (!exit_key) {
        string get_command = "";
        cin >> get_command; 
        if (get_command == "menu") {
            navigateToMenu();
        } else if (get_command == "exit") {
            exit_key = true;
        } else if (get_command == "clear") {
            this->cls->clear();
        } else {
            cout << "Команда не распознана " << get_command << endl;
        }
    }
};

void MainScreen::navigateToMenu() {
    string code = ""; 
    cout << "/delete - Удаление" << endl; 
    cout << "/add: Добавление" << endl; 
    cout << "/edit: Изменение" << endl; 
    cout << "/view: Просмотр" << endl; 
    cin >> code; 
    choose(code);
}

void MainScreen::choose(const string& code) {
    if (code == "/delete") {
        navigateToDelete();
    } else if (code == "/add") {
        navigateToAdd();
    } else if (code == "/edit") { 
        navigateToEdit();
    } else if (code == "/view") {
        navigateToView();
    } else if (code == "/exit") {
        navigateToView();
    } else {
        cout << "Команда не распознана" << endl;
    }
}

void MainScreen::navigateToAdd() {
    PTY element; 
    cout << "Введите GPS - Координаты" << endl; 
    cin >> element.Coordinates;
    cout << "Вид дерева: 1 - малое, 2 - большое" << endl; 
    cin >> element.type; 
    if (element.type == "1"){
        element.type = "Малое";
    } else if(element.type == "2"){
        element.type = "Большое";
    } else {
        element.type = "Тип не распознан";
    }
    cout << "Введите округ" << endl;
    cin >> element.Okrug;
    cout << "Введите номер лицензии" << endl;
    cin >> element.Year;
    cout << "Данные добавлны" << endl;
    dataPush(element);
} 

void MainScreen::dataPush(const PTY &newdata){ 
    this->data.push_back(newdata);
}

void MainScreen::dataRemoveByID(int id){
    this->data.erase(data.begin() + id); 
}

void MainScreen::dataEditByID(int id, const PTY &newdata){
    this->data.at(id) = newdata;
}

void MainScreen::navigateToDelete() {
    int code = -1;
    cout << "Введите номер удаляемой записи" << endl;
    cin >> code;
    dataRemoveByID(code);
    cout << "ДАННЫЕ УСПЕШНО УДАЛЕНЫ" << endl;
}

void MainScreen::navigateToEdit() {
    int code = -1;
    cout << "Введите номер редактируемой записи" << endl;
    cin >> code;

    PTY element;
    cout << "Введите новые координаты" << endl;
    cin >> element.Coordinates;
    cout << "Введите новый тип" << endl;
    cin >> element.type; 
    if (element.type == "1"){
        element.type = "Малое";
    } else if(element.type == "2"){
        element.type = "Большое";
    } else {
        element.type = "Тип не распознан";
    }
    cout << "Введите новый округ" << endl;
    cin >> element.Okrug;
    cout << "Введите новый год" << endl;
    cin >> element.Year;

    dataEditByID(code, element);
}
void MainScreen::navigateToView() {
    for (int i = 0; i < this->data.size(); i++) {
        cout << i << ": "<< this->data.at(i).Coordinates << " " << this->data.at(i).type << " " << this->data.at(i).type << " " << this->data.at(i).Okrug << " " << this->data.at(i).Year << endl;
    }
}

bool MainScreen::isEmpty() {
   return data.empty();
}