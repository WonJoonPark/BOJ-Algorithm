#include<bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> tmpsave[2000];
    int len=0;
    string tmps;
    vector<int> tmpi;
    for (int i = 1; i < s.length()-1; i++) { //원소의 집합만 보자
        if (s[i] == '{') {
            len = 1; tmps.clear(); tmpi.clear();
            continue;
        }
        else if (s[i] >= '0' && s[i] <= '9') {
            tmps.push_back(s[i]);
        }
        else if(s[i]==',') { //, 의 경우
            if (s[i - 1] == '}') continue; // 집합사이의 , 일경우 작업  x
            len++;
            tmpi.push_back(stoi(tmps));
            tmps.clear();
        }
        else { // } 인경우
            tmpi.push_back(stoi(tmps));
            tmps.clear();
            tmpsave[len] = tmpi;
        }
    }
    int index = 1;
    while (!tmpsave[index].empty()) {
        for (int i = 0; i < tmpsave[index].size(); i++) {
            bool exi = false;
            for (int j = 0; j < answer.size(); j++) {
                if (tmpsave[index][i] == answer[j]) {
                    exi = true;
                    break;
                }
            }
            if (exi == false) {
                answer.push_back(tmpsave[index][i]);
                break;

            }
      }
        index++;
    }
    return answer;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string tmps;
    cin >> tmps;
    vector<int> output;
    output=solution(tmps);

    return 0;
}