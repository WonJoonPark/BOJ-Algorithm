
#include<bits/stdc++.h>
using namespace std;

int vsize=0;
vector<int> casearr;
vector<int> mincasearr;
int resultcount=0;
bool finalsuc = false;

bool uniquekey(vector<vector<string>> &rel,vector<int> &inputarr) {
    vector<vector<string>> tmps;
    for (int i = 0; i < rel.size(); i++) { //행을 본다
        for (int k = 0; k < tmps.size(); k++) { //겹치는게 있는지 체크
            int samecount = 0;
            for (int a = 0; a < inputarr.size(); a++) {
                if (tmps[k][a] == rel[i][inputarr[a]]) { //헷갈릴 수 있음
                    samecount++; 
                }
            }
            if (samecount == inputarr.size()) return false;
            //모든 데이터가 같으면 유일성이 사라짐
        }
        vector<string> ts;
        for (int j = 0; j < inputarr.size(); j++) { //삽입부 
            ts.push_back(rel[i][inputarr[j]]);
        }
        tmps.push_back(ts);
     }
    return true;
}


void makemincase(int cnt, int index,vector<vector<string>>& relation) {
    if (cnt >= casearr.size()) return; //완전 같은 요소는 제외한다(유일성을 통과하므로)
    if (!mincasearr.empty()) {
        if (uniquekey(relation, mincasearr)) { //구성요소를 일부제외했는데도 유일성이 유지가 된다면
            finalsuc = false;
            return;
        }
    }
    for (int i = index; i < casearr.size(); i++) {
        mincasearr.push_back(casearr[i]);
        makemincase(cnt + 1, i + 1,relation);
        mincasearr.pop_back();
    }
}


void makecase(int cnt,int index, vector<vector<string>> &relation) {
    if (cnt > vsize) return;


    if (!casearr.empty()&&uniquekey(relation, casearr)) { //문제 요구조건 만족하는지 (유일성)
        finalsuc = true;
        makemincase(0, 0,relation);
        if (finalsuc == true) { // (최소성)
            resultcount++; }
    }


    for (int i = index; i < vsize; i++) {
        casearr.push_back(i);
        makecase(cnt + 1, i + 1,relation);
        casearr.pop_back();
    }
}


int solution(vector<vector<string>> relation) {
    vsize = relation[0].size();
    makecase(0,0,relation);
    return resultcount;
}
/*
int main() {
    vector<vector<string>> tmpr = { {"100","ryan","music","2"},
        {"200","apeach","math","2"},{"300","tube","computer","3"}
    ,{"400","con","computer","4"},{"500","muzi","music","3"}
    ,{"600","apeach","music","2"} };


    cout<<solution(tmpr);
    return 0;
}*/