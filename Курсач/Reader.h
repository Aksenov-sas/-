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
    cout << "����� ���������� ��� ���� ������ ������� 'a'" << endl;
    cout << "����� ���������� ���������� � �������� �� ��� ������� 'f'" << endl;
    cout << "����� �������� ������� ����������� �������� ���-�� ���, ������� 'o'" << endl;
    cout << "�������� ������� ������. ������������� 'd'" << endl;
    cout << "�������� ������� ������ 'e'" << endl;
    cin >> Userr;
    if (Userr == 'a') {
        // ��������� ����
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