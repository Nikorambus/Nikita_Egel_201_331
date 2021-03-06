﻿#include <iostream>		// Подключаем библиотеку iostream
#include <bitset>		// Подключаем библиотеку bitset
using namespace std;

int main() {	// Объявление функции

	setlocale(LC_ALL, "Russian"); // Поддержка Русского транслита

	// 1) ФИО, номер группы; (1 балл) 
	cout << "1." << endl;
	cout << "Егель Никита Эдуардович, 201-331\n" << endl;



	// 2) Минимальные и максимальные значения встроенных типов данных, а так же их размер; (10 баллов)
	cout << "2." << endl;
	cout << "min int = -2147483648, max int = 2147483647, size of int = 4" <<
		"\nmin unsigned int = 0, max unsigned int =  4 294 967 295, size of unsigned int = 4" <<
		"\nmin short = -32 768, max short = 32 767, size of short = 2" <<
		"\nmin unsigned short = 0, max unsigned short = 65 535, size of unsigned short = 2" <<
		"\nmin long = -2 147 483 648, max long = 2 147 483 647, size of long = 4" <<
		"\nmin long long = −9 223 372 036 854 775 808, max long long = 9 223 372 036 854 775 807, size of long long = 8" <<
		"\nmin double = -9 223 372 036 854 775 808, max double = 9 223 372 036 854 775 807, size of double = 8" <<
		"\nmin char = 0, max char = 255, size of char = 1" <<
		"\nmin bool = 0, max bool = 255, size of bool = 1\n" << endl;



	/* 3) Запросить у пользователя некоторое целое число и вывести на экран это число в бинарном и
	шестнадцатиричном виде, а так же результат преобразования типов ко всем встроенным; (5 баллов) */
	cout << "3." << endl;
	cout << "Введите число: ";
	int num;
	cin >> num;


	cout << "В бинарном виде " << bitset<16>(num) <<
		"\nВ шестнадцатиричном виде " << hex << num << dec <<
		"\nbool " << bool(num) <<
		"\ndouble " << double(num) <<
		"\nchar " << char(num) << "\n" << endl;




	/* 4) Записать условие и полное решение уравнения вида 𝑎 ∗ 𝑥 = 𝑏 (a отлично от нуля), причем
	значения коэффициентов (целые числа) вводит пользователь;(10 баллов)  */
	cout << "4." << endl;
	int a, b;	// Задаём целочисленный тип данных integer для коэффицентов a и b
	cout << "Введите коэффиценты a * x = b:\n";
	// Ввод коэфицентов a и b соответственно:
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	// Используем операторы условия if и else для описания условия, что a отлично от нуля
	if (a > 0) {
		cout << "\n" << a << " * x = " << b <<
			"\nx = " << b << " / " << a <<
			"\nx = " << b / a <<
			"\nОтвет: " << b / a << ".\n" << endl;
	}
	else { // Если условие if будет не выполненно, то будет выведено следующее
		cout << "Коэффицент a равен или меньше нуля -> исправьте\n" << endl;
	}


	/* 5) Записать программу для нахождения середины отрезка, заданного целыми координатами
	концевых точек.(10 баллов) */
	cout << "5." << endl;
	cout << "Введите координаты отрезка на прямой:\n";
	// Задаём целочисленный тип данных integer для коэффицентов x и y
	int x, y;
	// Задаём координаты (x, y) начала и конца отрезка соответственно:
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "\nСередина отрезка находится в точке с координатой " <<
		(x + y) / 2 << ".\n" << endl;


	return 0;
}