#include<bits/stdc++.h>
using namespace std;

struct info {
    int x, y, dir;        //dir=-1: 죽은 물고기
};
info tmp;
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
info fish[17];
int result = 0;
int arr[4][4];      //1~16: 물고기, 0: Shark, -1: 죽은 물고기

void move_fish() {
    for (int i = 1; i < 17; i++) {
        int cx = fish[i].x;
        int cy = fish[i].y;
        int cd = fish[i].dir;
        if (cd == -1) continue;       //죽은 물고기
        int nx, ny;
        int nd = cd;
        for (int j = 0; j < 8; j++) {
            nx = cx + dx[nd];
            ny = cy + dy[nd];
            if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
                int idx = arr[ny][nx];
                if (idx == 0) {     //shark
                    nd = (nd + 1) % 8;
                    continue;
                }
                //물고기 자리 교환
                arr[ny][nx] = i;
                fish[i].x = nx;
                fish[i].y = ny;
                fish[i].dir = nd;

                arr[cy][cx] = idx;
                fish[idx].x = cx;
                fish[idx].y = cy;
                break;
            }
            nd = (nd + 1) % 8;
        }
    }
}

void dfs(int y, int x, int dir, int sum) {
    info fdup[17];
    int dup[4][4];
    //복사
    for (int i = 1; i < 17; i++)
        fdup[i] = fish[i];
    memcpy(dup, arr, sizeof(dup));

    //물고기 이동
    move_fish();

    //상어 이동
    int nx = x;
    int ny = y;
    while (1) {
        nx += dx[dir];
        ny += dy[dir];
        if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
            int idx = arr[ny][nx];
            if (idx == -1)   continue;     //물고기가 없어서 이동 불가
            //물고기
            int fd = fish[idx].dir;
            //죽임 처리 + 상어 자리이동
            fish[idx].dir = -1;
            arr[y][x] = -1;
            arr[ny][nx] = 0;
            dfs(ny, nx, fd, sum + idx);
            //원복
            fish[idx].dir = fd;
            arr[y][x] = 0;
            arr[ny][nx] = idx;
        }
        else break;
    }
    result = max(result, sum);

    //원복
    memcpy(arr, dup, sizeof(dup));
    for (int i = 1; i < 17; i++)
        fish[i] = fdup[i];
    return;
}

int main() {
    int a, b, val;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            cin >> a >> b;
            arr[i][j] = a;
            fish[a].x = j;
            fish[a].y = i;
            fish[a].dir = b - 1;
        }
    val = arr[0][0];
    int sd = fish[val].dir; //0,0의 물고기를 먹은 상어 (방향, 결과값)
    fish[val].dir = -1;
    arr[0][0] = 0;
    dfs(0, 0, sd, val);
    cout << result;
    return 0;
}