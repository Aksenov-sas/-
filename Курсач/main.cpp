#include "Search.h"
#include "stdio.h"
#include "Create.h"
#include "Editing.h"
#include "Reader.h"
#include <Windows.h>

int main(){
	ULARGE_INTEGER freeBytesAvailable;
	ULARGE_INTEGER totalNumberOfBytes;
	ULARGE_INTEGER totalNumberOfFreeBytes;
	setlocale(LC_ALL, "RUSSIAN");
	string response;
	cout << "����� ������� ���� ������� 'create'" << endl << "��� ����, ����� ����� ������������ ���� ������� 'search'" << endl << "����� ����� ��������� 'quit'"<<endl;
	cin >> response;
	if (response == "search") {
		path fp = sss();
		string File = fp.string();
		if (File != "Not founded") {
			cout << "��� �������������� ������� 'e', ��� ������ ������� 'r'" << endl;
			string rs;
			cin >> rs;
			if (rs == "e") {
				editing(fp);
			}
			else {
				reader(fp);
			}
		}
		else {
			cout << "���� �� ��� ������." << endl;
		}
	}
	else if (response == "create"){
		cout << "�������� ����� ��� �������� �����" << endl << "��� ����, ����� ������� ����� ������� 'open'" << endl << "����� ���������� �� ������� ������ ������� �������� �����"<<endl << "����� ��������� � ��������� �������� ������� 'quit'" << endl;
		create(searchs());
	}
	else {
		return 0;
	}
	return main();
}