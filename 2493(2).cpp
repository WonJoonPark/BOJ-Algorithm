#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int N;
struct building {
	int height;
	int index;
};
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	stack<building> bb;
	building tmp;
	for(int i=0;i<N;i++) {
		cin >> tmp.height;
		tmp.index = i+1;
		while (1) {
			if (bb.empty() == true) { cout << "0 "; bb.push(tmp); break; }
			if (bb.top().height < tmp.height) {
				bb.pop();
			}
			else{
				cout << bb.top().index << " ";
				bb.push(tmp);
				break;
			}
		}
	}
	return 0;
}