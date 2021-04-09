#include<bits/stdc++.h>

using namespace std;

bool comp(pair<long long, long long>& lhs, pair<long long, long long>& rhs) {
    if (lhs.second < rhs.second) return true;
    else return false;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector <pair<long long,long long>> sortnum; //first = 원하는 방 번호 second=고객번호 
    vector <pair<long long, long long>> tmpanswer;
    vector<long long> answer;
    int rsize = room_number.size();
    for (int i = 1; i <= rsize; i++) {
        sortnum.push_back({ room_number[i-1],i });
    }
    sort(sortnum.begin(), sortnum.end()); // 원하는 방 번호를 기준으로 정렬
    for (int i = 0; i < rsize; i++) {
        cout << sortnum[i].first << " ";
    }
    cout << "\n";
    for (int i = 0; i < rsize; i++) {
        cout << sortnum[i].second << " ";
    }
    cout << "\n";
    for (int i = 0; i < rsize; i++) {
        bool c = false;
        if (tmpanswer.empty()) {
            tmpanswer.push_back({ sortnum[i].first,sortnum[i].second }); cout << tmpanswer[i].first; continue;
        }
        if (tmpanswer[i - 1].first >= sortnum[i].first) { //이미 손님이 있다
            tmpanswer.push_back({ tmpanswer[i-1].first + 1,sortnum[i].second });
        }
        else {
            tmpanswer.push_back({ sortnum[i].first,sortnum[i].second });
        }
        cout << tmpanswer[i].first;
    }
    sort(tmpanswer.begin(), tmpanswer.end(), comp);
    for (int i = 0; i < rsize; i++) {
        answer.push_back(tmpanswer[i].first);
    }

    return answer;
}

int main() {

    //	10, [1, 3, 4, 1, 3, 1]

    long long tmpk;
    vector<long long> s;
    s.push_back(1); s.push_back(3);
    s.push_back(4); s.push_back(1);
    s.push_back(3); s.push_back(1);
    solution(10, s);

    return 0;
}