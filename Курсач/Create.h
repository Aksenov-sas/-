#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp> 
#include <Search.h>
#include <filesystem>

using json = nlohmann::json;
using namespace std;
using namespace filesystem;

json create_student_auto(int i) {
    json student;
    student["id"] = i;
    student["Name"] = "ss";
    student["Surname"] = "sss";
    student["Middle name"] = "sss";
    student["birthday"] = "01.01.2000";
    student["Test"] = { {"ssss", "01.02.2021"}, {"ssss", "15.03.2021"} };
    student["Exam"] = { {"ssss", "10.04.2021","5"}, {"ssss", "25.05.2021","5"}};
    return student;
}
json create_student_handle(int i) {
    json student;
    string Name, Surname, Middle_name, birthday, Test_name, Exam_name, Test_date, Exam_date;
    int Test_count, Exam_estimation , Exam_count;
    student["id"] = i;
    cout << "Введите ФИО студента через enter" << endl;
    cin >> Name >> Surname >> Middle_name;
    student["Name"] = Name;
    student["Surname"] = Surname;
    student["Middle name"] = Middle_name;
    cout << "Введите дату рождения студента" << endl;
    cin >> birthday;
    student["birthday"] = birthday;
    cout << "Введите кол-во сданных зачётов студентом (максимум 10)" << endl;
    cin >> Test_count;
    for (int i = 0; i < Test_count; ++i) {
        json Test;
        cout << "Название предмета" << endl;
        cin >> Test_name;
        Test["Name"] = Test_name;
        cout << "Дата сдачи" << endl;
        cin >> Test_date;
        Test["Date"] = Test_date;
        student["Test"][i] = { Test["Name"],Test["Date"] };
    }
    cout << "Введите кол-во экзаменов(максимум 5)" << endl;
    cin >> Exam_count;
    for (int i = 0; i < Exam_count; ++i) {
        json Exam;
        cout << "Название предмета" << endl;
        cin >> Exam_name;
        Exam["Name"] = Exam_name;
        cout << "Дата сдачи" << endl;
        cin >> Exam_date;
        Exam["Date"] = Exam_date;
        cout << "Оценка за экзамен" << endl;
        cin >> Exam_estimation;
        Exam["Estimation"] = Exam_estimation;
        student["Exam"][i] = { Exam["Name"],Exam["Date"],Exam["Estimation"]};
    }
    return student;
}
void create(path dir) {
       json students;
       string fileName;
       string direct = dir.string();
       cout << "Введите название файла" << endl;
       cin >> fileName;
       fileName = direct + '/' + fileName + ".json";
       ofstream db(fileName);

       int StudentCount;
       cout << "Введите кол-во студентов в группе" << endl;;
       cin >> StudentCount;
       char choice;
       cout << "Заполнить автоматически(a) или вручную(h)" << endl;
       cin >> choice;
       if (choice == 'a') {
           for (int i = 0; i < StudentCount; ++i) {
               students[i] = create_student_auto(i) ;
           }
       }
       else {
           for (int i = 0; i < StudentCount; ++i) {
               students[i] = create_student_handle(i);
           };
        }
       db << students.dump(4); // вывод в файл с отступами (4 пробела)
       db.close();

       cout << "JSON файл успешно создан." << std::endl;

}


