#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N;
int B, C;
long long resultcount = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	vector<int> examarea(N);
	for (int i = 0; i < N; i++) cin>>examarea[i];
	cin >> B >> C;

		for (int i = 0; i < N; i++) {
			resultcount++;
			examarea[i] -= B;
			if (examarea[i] <= 0) continue; //ÃÑ °¨µ¶°ü È¥ÀÚ °¨½Ã °¡´É
			else { 
				if (examarea[i] % C == 0) resultcount += (examarea[i] / C);
				else resultcount += ((examarea[i] / C) + 1); }
		}

	cout << resultcount << "\n";
	return 0;
}