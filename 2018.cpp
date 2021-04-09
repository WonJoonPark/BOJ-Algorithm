#include<bits/stdc++.h>
using namespace std;

vector<int> tmpsumarr;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int N;

    cin >> N;

    int sindex = 1;
    int eindex = 1;
    int tmpsum = 0;

    int resultcount = 0;
    while (sindex <= eindex && eindex <= N + 1){
        if (tmpsum > N){
            tmpsum -= sindex;
            sindex++;
        }
        else if (tmpsum < N){
            tmpsum += eindex;
            eindex++;
        }
        else if (tmpsum == N){
            resultcount++;
            tmpsum += eindex;
            eindex++;
        }
    }
    cout << resultcount;
    return 0;
}
