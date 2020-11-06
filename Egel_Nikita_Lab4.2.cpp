/*
1.string file_format(const string file_path_full) по введенному полному расположению файла получить расширение,
2.string file_name(const string file_path_full) по введенному полному расположению файла получить название,
3.string file_path (const string file_path_full) по введенному полному расположению файла получить расположение,
4.char file_disk (const string file_path_full) по введенному полному расположению файла получить название диска,
5.bool file_rename(string * file_path_full) по введенному полному расположению файла и новому имени  переименовать файл,
6.bool file_copy(const string file_path_full) по введенному полному расположению файла создать копию файла (имя копии получается приписыванием  «_copy» к имени файла).

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//расширение
string file_format(const string file_path_full) {
    return file_path_full.substr(file_path_full.rfind(".") + 1, file_path_full.size());
}

//название
string file_name(const string file_path_full) {
    return file_path_full.substr(file_path_full.rfind("\\") + 1, file_path_full.size());
}

//расположение
string file_path(const string file_path_full) {
    return file_path_full.substr(0, file_path_full.rfind("\\") + 1);
}

//название диска
char file_disk(const string file_path_full) {
    return file_path_full[0];
}

//переименовать
void file_rename(string* file_path_full, const string new_name) {
    *file_path_full = file_path(*file_path_full) + new_name + "." + file_format(*file_path_full);
}

//создать копию
bool file_copy(const string path) {
    fstream fs_1, fs_2;

    fs_1.open(path, std::fstream::in);
    if (fs_1.fail()) {
        return false;
    }

    fs_2.open(file_path(path) + path.substr(path.rfind("\\") + 1, path.rfind(".") - path.rfind("\\") - 1) + "_copy." + file_format(path), std::fstream::out); // создание файла, режим: на запись
    if (fs_2.fail()) {
        return false;
    }

    //считывание и запись
    string str;
    while (getline(fs_1, str)) {
        fs_2 << str << endl;
    }

    fs_1.close();
    fs_2.close();
    return true;
}


int main() {
    int choice = 0;
    while (true) {
        cout << "What do you want to do? \n"
            << "1. Get the file extension. \n"
            << "2. Get the file name. \n"
            << "3. Get the location of the file. \n"
            << "4. Get the name of the disc. \n"
            << "5. Rename file. \n"
            << "6. Copy. \n"
            << "7. End. \n" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
        {
            string path;
            cout << "Input full path: ";
            cin >> path;
            cout << "Extation: " << file_format(path) << endl;
            break;
        }
        case 2:
        {
            string path;
            cout << "Input full path: ";
            cin >> path;
            cout << "Name: " << file_name(path) << endl;
            break;
        }
        case 3:
        {
            string path;
            cout << "Input full path: ";
            cin >> path;
            cout << "Path: " << file_path(path) << endl;
            break;
        }
        case 4:
        {
            string path;
            cout << "Input full path: ";
            cin >> path;
            cout << "Name of the disk: " << file_disk(path) << endl;
            break;
        }
        case 5:
        {
            string path;
            cout << "Input full path: ";
            cin >> path;
            string new_name;
            cout << "Input new name: ";
            cin >> new_name;
            file_rename(&path, new_name);
            cout << "New path: " << path << endl;
            break;
        }
        case 6:
        {
            string path;
            cout << "Input full path: ";
            cin >> path;
            (file_copy(path)) ? cout << "Copied" << endl : cout << "Error" << endl;
            break;
        }
        case 7:
        {
            return 0;
        }
        }
    }
    return 0;
}
