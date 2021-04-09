#include<bits/stdc++.h>
using namespace std;

const int MAX = 30; //최대 추의개수
int N, M;
int choo[MAX];
int goosle[7];
bool dp[MAX + 1][MAX * 500 + 1];
 //추 하나당 최대 무게 500

void makedp(int cnt, int Result)
{
    if (cnt > N) return;
    if (dp[cnt][Result] == true) return;

    dp[cnt][Result] = true;

    makedp(cnt + 1, Result + choo[cnt]);
    makedp(cnt + 1, Result);
    makedp(cnt + 1, abs(Result - choo[cnt]));
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> choo[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> goosle[i];
    }

    makedp(0, 0);
    for (int i = 0; i < M; i++)
    {
        if (goosle[i] > MAX * 500) cout << "N ";
        else if (dp[N][goosle[i]] == true) cout << "Y ";
        else cout << "N ";
    }
    cout << endl;


    return 0;
}