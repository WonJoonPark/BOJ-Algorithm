#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    int n = board[0].size();
    int vsize = moves.size();
    for (int i = 0; i < vsize; i++) {
        for (int j = 0; j < n; j++) {
            if (board[j][moves[i]-1] != 0) {
                if (basket.empty()) { basket.push(board[j][moves[i]-1]); }
                else {
                    if (basket.top() == board[j][moves[i]-1]) {
                        answer += 2; basket.pop();
                    }
                    else {
                        basket.push(board[j][moves[i]-1]);
                    }
                }
                board[j][moves[i]-1] = 0;
                break;
            }
            //끝까지 계속 0이면 명령 저절로 무시
        }
    }
    return answer;
}

