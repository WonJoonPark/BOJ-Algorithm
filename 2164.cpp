#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	queue<int> carddec;
	for (int i = 1; i <= N; i++) {
		carddec.push(i);
	}
	int tmp;
	int result;
	while (1) {
		if (carddec.size() == 1) {
		result = carddec.front();
		carddec.pop(); break;
		}
		carddec.pop();
		tmp = carddec.front();
		carddec.pop();
		carddec.push(tmp);
	}
	cout << result << '\n';
	return 0;
}