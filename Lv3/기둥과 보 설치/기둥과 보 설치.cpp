#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<pair<int, int>, int>> vec;
vector<vector<bool>> gidung;
vector<vector<bool>> bo;

bool check()
{
    for (int i = 0; i < gidung.size(); ++i) {
        for (int j = 0; j < gidung[0].size() - 1; ++j) {
            // 기둥이 있다면
            if (gidung[i][j]) {
                if (j == 0 || bo[i][j])
                    continue;
                else if (j - 1 >= 0 && gidung[i][j - 1])
                    continue;
                else if (i - 1 >= 0 && bo[i - 1][j])
                    continue;
                // 기둥의 조건을 만족하지 못하면 false를 반환
                else
                    return false;
            }
        }
    }
    for (int i = 0; i < bo.size() - 1; ++i) {
        for (int j = 0; j < bo[0].size(); ++j) {
            // 보가 있다면
            if (bo[i][j]) {
                if (j - 1 >= 0 && gidung[i][j - 1])
                    continue;
                else if (j - 1 >= 0 && gidung[i + 1][j - 1])
                    continue;
                else if (i - 1 >= 0 && bo[i - 1][j] && bo[i + 1][j])
                    continue;
                // 기둥의 조건을 만족하지 못하면 false를 반환
                else
                    return false;
            }
        }
    }
    // 모든 것이 이상 없으면 true 반환
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;

    // 기둥과 보의 사이즈 설정
    gidung.resize(n + 1, vector<bool>(n + 1, 0));
    bo.resize(n + 1, vector<bool>(n + 1, 0));

    int buildSize = build_frame.size();
    for (int i = 0; i < buildSize; ++i) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        // 설치
        if (b == 1) {
            // 기둥
            if (a == 0) {
                // 조건을 만족하면
                if (y == 0) {
                    gidung[x][y] = true;
                }
                else if (y - 1 >= 0 && gidung[x][y - 1]) {
                    gidung[x][y] = true;
                }
                else if (bo[x][y]) {
                    gidung[x][y] = true;
                }
                else if (x - 1 >= 0 && bo[x - 1][y]) {
                    gidung[x][y] = true;
                }
            }
            // 보
            else if (a == 1) {
                // 조건을 만족하면
                if (y != 0) {
                    if (y - 1 >= 0 && gidung[x][y - 1]) {
                        bo[x][y] = true;
                    }
                    else if (y - 1 >= 0 && gidung[x + 1][y - 1]) {
                        bo[x][y] = true;
                    }
                    else if (x - 1 >= 0 && bo[x - 1][y] && bo[x + 1][y]) {
                        bo[x][y] = true;
                    }
                }
            }
        }
        // 삭제
        else {
            // 기둥
            if (a == 0) {
                gidung[x][y] = false;
                if (!check()) {
                    gidung[x][y] = true;
                }
            }
            // 보
            if (a == 1) {
                bo[x][y] = false;
                if (!check()) {
                    bo[x][y] = true;
                }
            }
            // }
        }
    }
    // test
    // cout << "gidung\n";
    // for (int i = 0; i < bo.size(); ++i) {
    //     for (int j = 0; j < bo[0].size(); ++j) {
    //         cout << gidung[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "bo\n";
    // for (int i = 0; i < bo.size(); ++i) {
    //     for (int j = 0; j < bo[0].size(); ++j) {
    //         cout << bo[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int i = 0; i < bo.size() - 1; ++i) {
        for (int j = 0; j < bo[0].size(); ++j) {
            if (bo[i][j]) {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(1);
                answer.push_back(tmp);
                bo[i][j] = false;
            }
        }
    }
    for (int i = 0; i < gidung.size(); ++i) {
        for (int j = 0; j < gidung[0].size() - 1; ++j) {
            if (gidung[i][j]) {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(0);
                answer.push_back(tmp);
                gidung[i][j] = false;
            }
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}

// int main()
// {
// vector<vector<int>> vec = solution(5, {{1, 0, 0, 1},
//                                        {1, 1, 1, 1},
//                                        {2, 1, 0, 1},
//                                        {2, 2, 1, 1},
//                                        {5, 0, 0, 1},
//                                        {5, 1, 0, 1},
//                                        {4, 2, 1, 1},
//                                        {3, 2, 1, 1}});
//
//     vector<vector<int>> vec = solution(5, {{0, 0, 0, 1},
//                                            {2, 0, 0, 1},
//                                            {4, 0, 0, 1},
//                                            {0, 1, 1, 1},
//                                            {1, 1, 1, 1},
//                                            {2, 1, 1, 1},
//                                            {3, 1, 1, 1},
//                                            {2, 0, 0, 0},
//                                            {1, 1, 1, 0},
//                                            {2, 2, 0, 1}});

//     return 0;
// }