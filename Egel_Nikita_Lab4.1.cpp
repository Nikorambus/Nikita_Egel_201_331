/*
Необходимо сделать меню, к которому можно обращаться несколько раз.
1) проверка на палиндром
2) аналог функции find для с++ строк
3) шифрование сдвигами (шифр Цезаря)
4) на вход получаете некоторый текст, который введен с клавиатуры.
Вывести все названия (то, что внутри кавычек) из текста. Названия могут содержать пробелы.
*/
#include <iostream>
#include <cstring>

using namespace std;

void pal_check() //проверка на палиндром
{
	char pal[255];
	cout << "Enter a line: " << endl;
	cin.ignore();
	cin.getline(pal, 255);

	for (int i = 0; i < strlen(pal); i++) {

		if (pal[i] == ' ') {

			for (int j = i; j <= strlen(pal); j++) {

				pal[j] = pal[j + 1];
			}
		}
		if ((pal[i] >= 'A') && (pal[i] <= 'Z')) {

			pal[i] = pal[i] + 32;
		}
	}

	char pal2[255];

	strcpy_s(pal2, pal);

	int t = strlen(pal) - 1;

	for (int i = 0; i < strlen(pal2); i++) {

		pal2[i] = pal[t];
		t--;
	}

	if (strcmp(pal2, pal) == 0) {

		cout << "\nPalindrom\n\n";
	}
	else {
		cout << "\nNot a palindrom\n\n";
	}
}

void encrypt(char* str_for_encr, int key) //шифрование
{

	for (int i = 0; i < strlen(str_for_encr); i++)
	{

		str_for_encr[i] = char((int(str_for_encr[i]) - 97 + key) % 26 + 97);
	}
}

void crypt() //ввод шифра
{
	cout << "Enter a line: " << endl;
	char str[255];
	cin.ignore();
	cin.getline(str, 255);

	int key;

	cout << "Enter key: " << endl;
	cin >> key;

	encrypt(str, key);

	puts(str);
	cout << "\n\n";
}

void analog(char* str)
{

}

void title(char* str) //поиск ковычек
{
	for (int i = 1; i < strlen(str); i++)
	{
		if (str[i] == (char)'\"')
		{
			i++;
			while (str[i] != (char)'\"')
			{
				cout << str[i];
				i++;
			}
			cout << " ";
		}
	}
	cout << endl;
}

int main()
{
	char str[100];
	int choice = 0;
	while (true)
	{
		cout << "What do you want to do? \n"
			<< "1. Palindrome check. \n"
			<< "2. Analog of the find function. \n"
			<< "3. Shift encryption. \n"
			<< "4. Display all titles. \n"
			<< "5. End. \n" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			pal_check();
			break;
		}
		case 2:
		{
			cout << "\nInput string" << endl;
			cin >> str;
			analog(str);
			break;
		}
		case 3:
		{
			crypt();
			break;
		}
		case 4:
		{
			cout << "\nInput string" << endl;
			cin >> str;
			title(str);
			break;
		}
		case 5:
		{
			return 0;
			break;
		}
		}
	}
}