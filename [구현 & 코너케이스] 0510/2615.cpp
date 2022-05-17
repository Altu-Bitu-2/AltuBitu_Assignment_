#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19;  // 바둑판 크기

//범위와 돌의 종류가 유효한지 확인
bool promising(int r, int c, int stone, vector<vector<int>>& board) {
    return r >= 0 && r < SIZE&& c >= 0 && c < SIZE&& board[r][c] == stone;
}

bool validDir(int r, int c, int d, int stone, vector<vector<int>>& board) {
    //가로, 세로, 우하향 대각선, 우상향 대각선
    int dr[4] = { 0, 1, 1, -1 };  // 세로, 우하향 대각선, 우상향 대각선
    int dc[4] = { 1, 0, 1, 1 };  // 가로, 우하향 대각선, 우상향 대각선

    //(r, c) 이전에 위치한 이어지는 돌이 있나?
    if (promising(r - dr[d], c - dc[d], stone, board)) {  // (r, c) 이전에 위치한 이어지는 돌이 있으면
        return false;  // false 리턴
    }
    int cnt = 0;  // 이어지는 바둑알 개수 0으로 초기화
    while (cnt < 6 && promising(r, c, stone, board)) { //(r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수
        cnt++;  // 바둑알 개수 하나 증가
        r += dr[d];  // 행 증가
        c += dc[d];  // 열 증가
    }
    return cnt == 5;  // 이어지는 바둑알 개수가 5면 true 리턴 
}

bool isEnd(int r, int c, vector<vector<int>>& board) {  // 누가 이겼는지 확인
    for (int i = 0; i < 4; i++) { //가로, 세로, 우하향 대각선, 우상향 대각선
        if (validDir(r, c, i, board[r][c], board)) {  // 돌이 유효하면 
            return true;  // true 리턴
        }
    }
    return false;  // 유효하지 않으면 false 리턴
}

/**
 * [오목]
 *
 * 1. 특정 좌표(r, c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
 *    가능한 모든 배치 :  오른쪽, 아래, 우하향, 우상향
 * 2. (주의) 육목이상이 되는지 확인해야 함
 *
 */

int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));  // 바둑판 선언

    //입력
    for (int i = 0; i < SIZE; i++) {  // 바둑판 행 크기 만큼 반복
        for (int j = 0; j < SIZE; j++) {  // 바둑판 열 크기 만큼 반복
            cin >> board[i][j];  // 바둑판 상태 입력
        }
    }

    //연산 & 출력
    for (int i = 0; i < SIZE; i++) {   // 바둑판 행 크기 만큼 반복
        for (int j = 0; j < SIZE; j++) {  // 바둑판 열 크기 만큼 반복
            if (!board[i][j]) { //돌이 없음
                continue;
            }
            if (isEnd(i, j, board)) { //누군가 이겼나?
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1;
                // 연속된 다섯 개의 바둑알 중에서 가장 왼쪽에 있는 바둑알(세로의 경우, 가장 위)의 가로줄 번호와 세로줄 번호 출력
                return 0;
            }
        }
    }
    cout << 0;  // 승부가 결정되지 않았을 경우 0 출력 
    return 0;
}