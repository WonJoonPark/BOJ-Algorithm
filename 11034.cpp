#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int a, b, c;
int resultcount;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin>>a>>b>>c) {
		resultcount = 0;
		if (b - a > c - b) resultcount = b-a;
		else resultcount = c-b;
		cout << resultcount - 1<<"\n";
	}
	return 0;
}