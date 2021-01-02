#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
	int n;
	int id;
	string answer;
	cin >> n;
	unordered_set<int> u;
	for (int i = 0; i < n; i++) {
		cin >> id >> answer;
		if (u.count(id) != 1) {
			u.insert(id);
			cout << "The answer is counted" << endl;
		}
		else {
			cout << "The answer isn't counted" << endl;
		}
	}

	return 0;
}/*Преподаватель на экзамене дал студентам тест. Один из студентов решил узнать правильные ответы.
 Для этого он отправлял тест много раз с нескольких аккаунтов. Преподаватель решил это пресечь.
 Для этого преподаватель не стал засчитывать результаты теста, отправленного повторно с одного и того же аккаунта.
 Нужно автоматизировать этот процесс. */