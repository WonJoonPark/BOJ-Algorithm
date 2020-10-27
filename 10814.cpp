#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct agewithname {
	int age;
	string name;
	int whenin;
};
bool cmpage(agewithname a, agewithname b) {
	if (a.age < b.age) { return true; }
	else if (a.age == b.age) {
		if (a.whenin < b.whenin) return true;
		else return false;
	}
	else { return false; }
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;

	cin >> N;
	vector<agewithname> peoplearr;
	agewithname tmp;
	for(int i=0;i<N;i++) {
		cin >> tmp.age >> tmp.name;
		tmp.whenin = i;
		peoplearr.push_back(tmp);

	}
	sort(peoplearr.begin(), peoplearr.end(), cmpage);
	for (int i = 0; i < peoplearr.size(); i++) {
		cout << peoplearr[i].age << " " << peoplearr[i].name << '\n';
	}
	return 0;
}