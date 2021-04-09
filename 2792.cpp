#include<bits/stdc++.h> 
using namespace std;

long long n, m;
long long numarr[300001];
long long result = 1e18;

bool canspread(long long mid) {
    long long num = 0;
    for (int i = 0; i < m; i++) {
        num += numarr[i] / mid;
        if (numarr[i] % mid) num++;
    }
    return n >= num;
}
int main() {
    cin >> n >> m;
    long long left = 1; long long right = 0;
    for (int i = 0; i < m; i++) {
        cin >> numarr[i];
        if (right < numarr[i]) right = numarr[i];
        }
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (canspread(mid)) {
            if (result > mid) result = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << result << "\n";
    return 0;
}