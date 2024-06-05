#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <stdio.h>

using json = json;
using namespace std;
void showFile(path fp){
    ifstream file_stream(fp);

    if (!file_stream.is_open()) {
        cout << "�� ������� ������� ����" << endl;
    }

    // ��������� ������ �� ����� � ������
    string file_content((istreambuf_iterator<char>(file_stream)),
        istreambuf_iterator<char>());
    cout << file_content << endl;
    file_stream.close();

}

int editing(path fp) {
    int StudentId;
    string UserResponse;
    showFile(fp);
    cout << "������� id ��������, ������ �������� ����� ��������" << endl;
    cin >> StudentId;
    cout << "��� ����� ��������?" << endl;
    cin >> UserResponse;
    if (UserResponse == "Name" || UserResponse == "Surname" || UserResponse == "Middle name" || UserResponse == "birthday" ) {
        ifstream file(fp);
        json newInfo;
        string New;
        file >> newInfo;
        cout << "������� ����� ��������" << endl;
        cin >> New;
        newInfo[StudentId][UserResponse] = New;
        ofstream file1(fp);
        file1 << newInfo;
        file1.close();
        showFile(fp);
    }
    else {
        ifstream file(fp);
        json newInfo;
        string New;
        file >> newInfo;

        cout << "���� �� ������ �������� ���� 'd',������ 'e',�������� 'n'" << endl;
        char Response1;
        int Response2;
        cin >> Response1;
        if (Response1 == 'd') {
            Response2 = 1;
        }
        else if (Response1 == 'n') {
            Response2 = 0;
        }
        else if (Response1 == 'e') {
            Response2 = 2;
        }
        string NameEx;
        string Response3;
        cout << "������� ������������ ��������/������, ������� ����� ��������"<<endl;
        cin >> NameEx;
        cout << "������� ����� ��������"<<endl;
        cin >> Response3;
        int size = sizeof(newInfo[StudentId][UserResponse]) / sizeof(newInfo[StudentId][UserResponse][0]);
        for (int i = 0; i < size; ++i) {
            if (newInfo[StudentId][UserResponse][i][Response2] == NameEx) {
                newInfo[StudentId][UserResponse][i][Response2] = Response3;
            }
        }
        ofstream file1(fp);
        file1 << newInfo;
        file1.close();
        showFile(fp);
    }
    cout << "����� ��������� �������������� ������� 'q', ����� ���������� ������� 'enter'"<< endl;
    char Quit;
    cin >> Quit;
    if (Quit == 'q') {
        return 0;
    }
    else {
        editing(fp);
    }
    

    

}
