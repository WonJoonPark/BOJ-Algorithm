#include<iostream>
#include<vector>
using namespace std;
int n;
bool arr1[180];
void func(int tmp) {
	if (tmp < 180000) {
		arr1[tmp] = true;
	}
	else {
		tmp = tmp - 180000;
		arr1[tmp] = true;
	}
}
int func2(int tmp) {
	if (tmp < 180000) {
		if (arr1[tmp] == true) {
			arr1[tmp] = false;
		}
		else { return 1; }
	}
	else {
		tmp = tmp - 180000;
		if (arr1[tmp] == true) {
			arr1[tmp] = false;
		}
		else { return 1; }
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	/*cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		func(tmp);
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (func2(tmp) == 1) {
			cout << "impossible" << '\n'; return 0;;
		}
	}
	cout << "possible" << '\n';*/
	cout << 270000 % 180 << endl;
	return 0;
}