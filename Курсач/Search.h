#include <iostream>
#include <filesystem>
#include <string>

using namespace std;
using namespace filesystem;

void showFilesAndDirectories(const path& directory) {
    for (const auto& entry : directory_iterator(directory)) {
        cout << entry.path().filename() << endl;
    }
}
void welcome() {
    cout << "Введите название файла или папки, которую хотите открыть" << endl;
    cout << "Для возврата к корневому каталогу напишите 'back', чтобы вывйти напишите 'quit'" << endl;
    cout << "Для открытия файла введите команду 'open', после чего введите название файла, который нужно открыть" << endl;
}

path searchs() {
    string userInput;
    string userFile;
    setlocale(LC_ALL, "Russian");
    path Dir = "C://";
    path lastDir = Dir;
    cout << "Вы сейчас в папке " << Dir << endl;
    showFilesAndDirectories(Dir);
    
    while (true) {
        cin >> userInput;
        if (userInput == "open") {
            cout << "Введите название" << endl;
            cin >> userFile;
            lastDir = lastDir / userFile;
            //string path_string{lastDir.string() };
            return lastDir;
        }
        path newDir = lastDir / userInput;
        
        if (userInput == "quit") {
            return "Not founded";
        }
        if (userInput == "back") {
            path newDir = Dir;
            lastDir = Dir;
            showFilesAndDirectories(newDir);
        }
        else if (is_directory(newDir)) {
            lastDir = newDir;
            cout << "Папка: " << newDir << endl;
            showFilesAndDirectories(newDir);
        }
        else {
            cout << "Папка или файл не найдены" << endl;
        }
    }

    return "Not founded";
}
path sss() {
    welcome();
    return searchs();
}
