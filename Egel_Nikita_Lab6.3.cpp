#include <iostream>
#include <queue>
using namespace std;
int main() {
	queue<int> q;
	int n;
	cin >> n;
	int a, b;
	for (int i = 2; i <= n; i++) {     //0 и 1 не подходят 
		b = i;
		while (b % 2 == 0) {
			b /= 2;
		}
		while (b % 3 == 0) {
			b /= 3;
		}
		while (b % 5 == 0) {
			b /= 5;
		}
		if (b == 1) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}/*Напечатать в порядке возрастания первые n натуральных чисел, в разложение которых на простые множители входят только 2, 3 и 5.	*/