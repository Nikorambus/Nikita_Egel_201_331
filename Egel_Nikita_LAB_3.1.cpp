/*�������� ��������� � ����, ������� �� ������� ������������ ��������� ���� �� ��������� ��������
1.��������� �������� ������ (����� �� ����� 1000) �� ����������� �� ��������� ����������� ����������.
���� ���������� �������� ��������� ��������. ������, ��������� ������������� ���������� � ������� ����������.
2.��������� ���������� ������ (����� a-z) (����� �� ����� 1000) �� ����������� �� ��������� ���������� ���������.
���� ���������� �������� ��������� ��������.
������, ��������� ������������� ���������� � ������� ����������.
3.��������� �������� ������ (����� �� ����� 1000) �� ����������� �� ��������� ���������� ��������.
���� ���������� �������� ��������� ��������. ������, ��������� ������������� ���������� � ������� ����������.
*/

#include <iostream>
#include <stdio.h>

using namespace std;

void bubble(int arr[], const int k)
{
	int x;

	for (int i = 1; i < k; i++)
	{
		for (int j = 0; j < (k - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				x = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = x;
			}
		}
	}
}

void count(char* a, const int k)
{
	const int EDC = 26;
	int c[EDC] = { 0 };
	int j = 0, i;

	for (i = 0; i < k; i++)
	{
		j = int(a[i] - 'a');
		c[j]++;
	}
	i = 0;
	j = 0;
	while (j <= EDC)
	{
		if (c[j] > 0)
		{
			a[i] = char(int('a') + j);
			i++;
			c[j]--;
		}
		else {
			j++;
		}
	}
}

void merger(int* a, int l, int r)
{
	int lcur = l;
	int rcur = (l + r) / 2 + 1;

	int res[1000] = { 0 };

	for (int i = l; i < r + 1; i++) {

		if ((lcur < (r + l) / 2 + 1) && (rcur < r + 1)) {

			if (a[lcur] < a[rcur]) {
				res[i] = a[lcur];
				lcur++;
			}
			else {
				res[i] = a[rcur];
				rcur++;
			}
		}
		else {

			if (lcur < (r + l) / 2 + 1) {
				res[i] = a[lcur];
				lcur++;
			}
			else {
				res[i] = a[rcur];
				rcur++;
			}
		}
	}
	for (int i = l; i < r + 1; i++) {
		a[i] = res[i];
	}
}

void print(const int* a, const int length) {
	for (int i = 0; i < length; i++) {
		cout << a[i] << " ";
	}
}

void merge(int* a, int l, int r)
{
	cout << "l = " << l << " r = " << r << " || ";
	print(a, r + 1);
	cout << endl;

	if (r - l > 1) {
		merge(a, l, (l + r) / 2);
		merge(a, (l + r) / 2 + 1, r);
		merger(a, l, r);
	}
	else {
		if (l == r) return;
		else {
			if (a[r] < a[l]) {
				int tmp = a[r];
				a[r] = a[l];
				a[l] = tmp;
			}
		}
	}
	cout << "l = " << l << " r = " << r << " || ";
	print(a, r + 1);
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, c;
	char arrB[1000];
	int arrA[1000], arrC[1000];
	int choice = 0;

	while (true)
	{
		cout << "��� �� ������ �������? \n"
			<< "1. ���������� ���������  \n"
			<< "2. ���������� ��������� \n"
			<< "3. ���������� �������� \n"
			<< "4. ����� \n" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "\n������� ������ �������" << endl;
			cin >> a;
			cout << "\n������� ��-�� �������" << endl;

			for (int i = 0; i < a; i++)
			{
				cin >> arrA[i];
			}
			cout << "\n" << endl;

			bubble(arrA, a);

			for (int i = 0; i < a; i++)
			{
				cout << arrA[i] << endl;
			}
			cout << "\n" << endl;

			break;
		}
		case 2:
		{
			cout << "\n������� ������ �������" << endl;
			cin >> b;
			cout << "\n������� ��-�� �������" << endl;

			for (int i = 0; i < b; i++)
			{
				cin >> arrB[i];
			}
			cout << "\n" << endl;

			count(arrB, b);

			for (int i = 0; i < b; i++)
			{
				cout << arrB[i] << endl;
			}
			cout << "\n" << endl;

			break;
		}
		case 3:
		{
			cout << "\n������� ������ �������" << endl;
			cin >> c;
			cout << "\n������� ��-�� �������" << endl;

			for (int i = 0; i < c; i++)
			{
				cin >> arrC[i];
			}
			cout << "\n" << endl;

			merge(arrC, 0, c - 1);

			for (int i = 0; i < c; i++)
			{
				cout << arrC[i] << endl;
			}
			cout << "\n" << endl;

			break;
		}
		case 4:
		{
			return 0;
		}
		}
	}
}
