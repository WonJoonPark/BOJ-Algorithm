#include<bits/stdc++.h>
using namespace std;

int N, M; // 물건종류, 가방최대무게
int v, c, k; // 무게,만족도,개수
int dp[10001]; //최대무게당 최고의 만족도 저장
int uses, binarytmp;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> v >> c >> k;
        binarytmp = 1;
        while (k>0) {
            uses = min(k, binarytmp);
            for (int j = M; j >=v*uses; j--) {
                dp[j] = max(dp[j - v*uses] + c*uses, dp[j]);
            }
            binarytmp *= 2;
            k = k - uses;
        }
    }
    int ans = 0;
    for (int i = 0; i <= M; i++) {
        ans = max(dp[i], ans);
    }
    cout << ans;
    return 0;
}
