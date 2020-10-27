#include<iostream>
#include<vector>
#include<string>
using namespace std;

string arr[14];
int N;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	arr[1] = "baby"; arr[2] = "sukhwan";
	arr[5] = "very"; arr[6] = "cute";
	arr[9] = "in"; arr[10] = "bed";
	arr[13] = "baby"; arr[0] = "sukhwan";
	if (N % 14 == 3 || N % 14 == 4 || N % 14 == 7 || N % 14 == 8 || N % 14 == 11 || N % 14 == 12)
	{
		if (N % 14 == 3 || N % 14 == 7 || N % 14 == 11) {
			if ((N / 14 + 2) >= 5) {
				cout << "tu+";
				cout << "ru*" << N / 14 + 2;
			}
			else {
				cout << "tu";
				for (int i = 0; i < N / 14 + 2; i++) {
					cout << "ru";
				}
			}
		}
		else {
			if ((N / 14 + 1) >= 5)
			{	cout << "tu+";
				cout << "ru*" << N / 14 + 1;}
			else {
				cout << "tu";
				for (int i = 0; i < N / 14 + 1; i++) {
					cout << "ru";
				}
			}
		}
	}
	else {
		cout << arr[N % 14] << '\n';
	}
	return 0;
}