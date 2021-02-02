#include <iostream>

using namespace std;

void input_m(int*& mas, int* size){

	if (mas != nullptr) delete[]mas;

	cout << "Колличество эллементов массива: " << endl;
	cin >> *size;
	cout << "Введите элементы масива: " << endl;
	mas = new int[*size];
	for (int i = 0; i < *size; i++) {
		cin >> mas[i];
	}
}

void output_m(int* mas, int size){

	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << endl;
	}
}

int sum_chet(int size){

	int sum = 0;
	int c = 1;
	int d = size;
	while (d / 10 != 0)
	{
		c++;
		d = d / 10;
	}
	d = size;
	for (int j = c; j <= c && j != 0; j--)
	{
		if (j % 2 != 0)
		{
			int q = 0;
			q = d % 10;
			sum = sum + q;
			d = d / 10;
		}
		else
		{
			d = d / 10;
		}
	}
	return sum;
}

void even_sort(int* mas, int size){

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (sum_chet(mas[i]) > sum_chet(mas[j]))
			{
				int m = mas[j];
				mas[j] = mas[i];
				mas[i] = m;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << endl;
	}
}

void all_sort(int* mas, int size){

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < ((size)-1); j++)
		{
			if (mas[j] % 10 > mas[j + 1] % 10)
			{
				int b = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = b;
			}
		}
	}
	for (int k = 0; k < size; k++)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j > i; j--)
			{
				if (mas[i] % 10 == mas[j] % 10)
				{
					if (mas[j] > mas[i])
					{
						int m = mas[i];
						mas[i] = mas[j];
						mas[j] = m;

					}
				}
			}
		}
	}
	output_m(mas, size);
}

int main(){

	setlocale(LC_ALL, "Russian");
	int choice = 0;
	int size = 0;
	int* mas = new int[size];
	while (true){
		cout << "Что вы хотите выполнить? :: \n"
			<< "1. Ввод массива. \n"
			<< "2. Вывод массива в консоль. \n"
			<< "3. Сортировка по сумме цифр, стоящих на четных местах. \n"
			<< "4. Отсортировать массив вначале по возрастанию последней цифры, а при совпадении последних"
			<< "цифр - по убыванию. \n"
			<< "5. ВЫХОД. \n" << endl;
		cin >> choice;
		switch (choice){

		case 1: {
			input_m(mas, &size);
			break;
		}
		case 2: {
			cout << endl;
			output_m(mas, size);
			break;
			cout << endl;
		}
		case 3: {
			cout << endl;
			even_sort(mas, size);
			break;
			cout << endl;
		}
		case 4: {
			cout << endl;
			all_sort(mas, size);
			break;
			cout << endl;
		}
		case 5: {
			return 0;
		}
		}
	}
}