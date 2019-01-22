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
    string type; 
    cout << "Введите название" << endl; 
    cin >> element.Name;
    cout << "Введите адрес" << endl; 
    cin >> element.Adress;
    cout << "Введите тип" << endl;
    cin >> type; 
    if (type == "Федеральный") {
        element.type = FEDERAL;
    } else if (type == "Региональный") {
        element.type = REGIONAL;
    } else {
        cout << "Такого типа нет." << endl;
        return;
    }
    cout << "Введите год основания" << endl;
    cin >> element.Foundation_Year;
 
    cout << "Введите номер лицензии" << endl;
    cin >> element.License_Number;
          
    cout << "Введите номер аккредитации" << endl; 
    cin >> element.Accreditation_Number;

    cout << "Введите дату окончания аккредитации" << endl;
    cin >> element.Accreditation_End_Date;
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
    string type; 
    cout << "Введите номер редактируемой записи" << endl;
    cin >> code;
    PTY element;
    cout << "Введите новое название" << endl;
    cin >> element.Name;
    cout << "Введите новый адрес" << endl;
    cin >> element.Adress;
    cout << "Введите новый тип" << endl;
    cin >> type; 
    if (type == "Федеральный") {
        element.type = FEDERAL;
    } else if (type == "Региональный") {
        element.type = REGIONAL;
    } else {
        cout << "Такого типа нет." << endl;
        return;
    }
    cout << "Введите новый год основания" << endl;
    cin >> element.Foundation_Year;
    cout << "Введите новый номер лицензии" << endl;
    cin >> element.License_Number;
    cout << "Введите новый номер аккредитации" << endl;
    cin >> element.Accreditation_Number;
    cout << "Введите новую дату окончания аккредитации" << endl;
    cin >> element.Accreditation_End_Date;
    dataEditByID(code, element);
}
void MainScreen::navigateToView() {
    for (int i = 0; i < this->data.size(); i++) {
        cout << i << ": "<< this->data.at(i).Name << " " << this->data.at(i).Adress << " " << this->data.at(i).type << " " << this->data.at(i).Foundation_Year << " " << this->data.at(i).License_Number << " " << this->data.at(i).Accreditation_Number << " " << this->data.at(i).Accreditation_End_Date << endl;
    }
}

bool MainScreen::isEmpty() {
   return data.empty();
}