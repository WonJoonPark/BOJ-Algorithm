#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct person {
	int weight;
	int height;
};
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<person> personarr;
	int n;
	cin >> n;
	person tmpperson;
	for(int i=0;i<n;i++) {
		cin >> tmpperson.weight >> tmpperson.height;
		personarr.push_back(tmpperson);
	}
	int counting = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (personarr[i].height < personarr[j].height&&personarr[i].weight < personarr[j].weight) {
				counting++;
			}
		}
		cout <<  counting << ' ';
		counting = 1;
	}
	return 0;
}