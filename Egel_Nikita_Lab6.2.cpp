#include <iostream>
#include <deque>
using namespace std;
int main() {
	string a;
	cin >> a;
	deque<char> d;
	for (int i = 0; i < a.length(); i++) {
		d.push_back(a[i]);
	}
	while (not d.empty() and d.front() == d.back() and d.size() != 1) {
		d.pop_back();
		d.pop_front();
	}
	if (d.empty() or d.size() == 1) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	char q;
	cin >> q;
	return 0;
}
