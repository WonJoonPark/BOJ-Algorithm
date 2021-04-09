
#include<bits/stdc++.h>
using namespace std;

int vsize=0;
vector<int> casearr;
vector<int> mincasearr;
int resultcount=0;
bool finalsuc = false;

bool uniquekey(vector<vector<string>> &rel,vector<int> &inputarr) {
    vector<vector<string>> tmps;
    for (int i = 0; i < rel.size(); i++) { //���� ����
        for (int k = 0; k < tmps.size(); k++) { //��ġ�°� �ִ��� üũ
            int samecount = 0;
            for (int a = 0; a < inputarr.size(); a++) {
                if (tmps[k][a] == rel[i][inputarr[a]]) { //�򰥸� �� ����
                    samecount++; 
                }
            }
            if (samecount == inputarr.size()) return false;
            //��� �����Ͱ� ������ ���ϼ��� �����
        }
        vector<string> ts;
        for (int j = 0; j < inputarr.size(); j++) { //���Ժ� 
            ts.push_back(rel[i][inputarr[j]]);
        }
        tmps.push_back(ts);
     }
    return true;
}


void makemincase(int cnt, int index,vector<vector<string>>& relation) {
    if (cnt >= casearr.size()) return; //���� ���� ��Ҵ� �����Ѵ�(���ϼ��� ����ϹǷ�)
    if (!mincasearr.empty()) {
        if (uniquekey(relation, mincasearr)) { //������Ҹ� �Ϻ������ߴµ��� ���ϼ��� ������ �ȴٸ�
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


    if (!casearr.empty()&&uniquekey(relation, casearr)) { //���� �䱸���� �����ϴ��� (���ϼ�)
        finalsuc = true;
        makemincase(0, 0,relation);
        if (finalsuc == true) { // (�ּҼ�)
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