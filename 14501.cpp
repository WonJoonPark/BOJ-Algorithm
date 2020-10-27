#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct schedule {
	int cstime;
	int salary;
};

int N;
queue<schedule> firstq;
queue<schedule> secondq;
vector<schedule> arr;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	schedule tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp.cstime;
		cin >> tmp.salary;
		arr.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		firstq.push(arr[i]);
		int j = arr[i].cstime - 1;
		
	}
	
	return 0;
}