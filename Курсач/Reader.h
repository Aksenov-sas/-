#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <stdio.h>

using json = nlohmann::json;
using namespace std;

string searchser(json& j, const string& Surname_value) {
    for (auto& element : j.items()) {
        if (element.key() == "Surname" && element.value() == Surname_value) {
            return element.value();
        }
        else {
            return "netu";
        }
    }
}

void reader(path fp) {
    char Userr;
    cout << "Чтобы посмотреть всю Базу данных введите 'a'" << endl;
    cout << "Чтобы посмотреть информацию о студенте по ФИО введите 'f'" << endl;
    cout << "Поиск студента которым исполнилось заданное кол-во лет, введите 'o'" << endl;
    cout << "сдуденты имеющие академ. задолженности 'd'" << endl;
    cout << "студенты сдавшие сессию 'e'" << endl;
    cin >> Userr;
    if (Userr == 'a') {
        // Открываем файл
        ifstream file_stream(fp);

        if (!file_stream.is_open()) {
            cout << "не удалось открыть файл" << endl;
        }

        // Считываем данные из файла в строку
        string file_content((istreambuf_iterator<char>(file_stream)),
            istreambuf_iterator<char>());
        cout << file_content << endl;
        file_stream.close();
    }
    else if (Userr == 'f') {
        json Info;
        string Surname;
        cin >> Surname;
        ifstream file3(fp);
        file3 >> Info;
        searchser(Info,Surname);
        file3.close();
    }
   
}