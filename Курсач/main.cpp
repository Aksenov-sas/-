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
	cout << "Чтобы создать файл введите 'create'" << endl << "Для того, чтобы найти существующий файл введите 'search'" << endl << "Чтобы выйти пропишите 'quit'"<<endl;
	cin >> response;
	if (response == "search") {
		path fp = sss();
		string File = fp.string();
		if (File != "Not founded") {
			cout << "Для редактирования введите 'e', для чтения введите 'r'" << endl;
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
			cout << "Файл не был найден." << endl;
		}
	}
	else if (response == "create"){
		cout << "Выберите папку для создания файла" << endl << "Для того, чтобы выбрать папку введите 'open'" << endl << "Чтобы спуститься по кталогу просто введите название папки"<<endl << "Чтобы вернуться к корневому каталогу введите 'quit'" << endl;
		create(searchs());
	}
	else {
		return 0;
	}
	return main();
}