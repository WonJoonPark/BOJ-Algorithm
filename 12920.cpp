#include<bits/stdc++.h>
using namespace std;

int N, M; // ��������, �����ִ빫��
int v, c, k; // ����,������,����
int dp[10001]; //�ִ빫�Դ� �ְ��� ������ ����
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
