#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int answer = 0;
// bool isCheck[8];
vector<vector<int>> save;

void solve(int colSize, vector<vector<string>> relation)
{
    int rowSize = relation.size();
    int realColSize = relation[0].size();

    vector<int> vec;
    for (int i = 0; i < colSize; ++i) {
        vec.push_back(1);
    }
    for (int i = colSize; i < realColSize; ++i) {
        vec.push_back(0);
    }
    do {
        map<string, int> m;
        bool check = true;
        for (int i = 0; i < rowSize; ++i) {
            string str = "";
            bool alreadyCheck = false;
            for (int j = 0; j < realColSize; ++j) {
                if (vec[j] == 1) {
                    // if (isCheck[j]) {
                    //     alreadyCheck = true;
                    //     check = false;
                    //     break;
                    // }
                    str += relation[i][j];
                }
            }
            if (alreadyCheck) {
                break;
            }
            int cnt = m.count(str);
            if (cnt == 0) {
                m[str] = 1;
            }
            else if (cnt == 1) {
                check = false;
                break;
            }
        }
        if (check) {
            // ++answer;
            vector<int> tmp;
            // cout << "colSize : " << colSize << '\n';
            for (int i = 0; i < realColSize; ++i) {
                if (vec[i] == 1) {
                    // cout << "index i : " << i << '\n';
                    tmp.push_back(i);
                }
            }
            // cout << '\n';
            save.push_back(tmp);
        }
    } while (prev_permutation(vec.begin(), vec.end()));

    return;
}

int solution(vector<vector<string>> relation)
{
    // memset(isCheck, 0, sizeof(isCheck));
    int rowSize = relation.size();
    int colSize = relation[0].size();
    for (int i = 1; i <= colSize; ++i) {
        solve(i, relation);
    }
    // for (int i = 0; i < save.size(); ++i) {
    //     for (int j = 0; j < save[i].size(); ++j) {
    //         cout << save[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    vector<bool> isCheck(save.size(), 0);
    for (int i = 0; i < save.size(); ++i) {
        if (isCheck[i]) {
            continue;
        }
        else {
            for (int j = i + 1; j < save.size(); ++j) {
                if (isCheck[j]) {
                    continue;
                }
                else {
                    int idx1 = 0;
                    int idx2 = 0;
                    int cnt = 0;
                    while (idx1 < save[i].size() && idx2 < save[j].size()) {
                        if (save[i][idx1] == save[j][idx2]) {
                            ++cnt;
                            ++idx1;
                            ++idx2;
                        }
                        else if (save[i][idx1] > save[j][idx2]) {
                            ++idx2;
                        }
                        else {
                            ++idx1;
                        }
                    }
                    if (cnt == save[i].size()) {
                        isCheck[j] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < isCheck.size(); ++i) {
        if (!isCheck[i]) {
            // for (int j = 0; j < save[i].size(); ++j) {
            //     cout << save[i][j] << ' ';
            // }
            // cout << '\n';
            ++answer;
        }
    }

    return answer;
}

int main()
{
    // cout << solution({{"100", "ryan", "music", "2"},
    //                   {"200", "apeach", "math", "2"},
    //                   {"300", "tube", "computer", "3"},
    //                   {"400", "con", "computer", "4"},
    //                   {"500", "muzi", "music", "3"},
    //                   {"600", "apeach", "music", "2"}})
    //      << '\n';
    cout << solution({{"0", "0", "0", "2"},
                      {"1", "1", "1", "2"},
                      {"2", "2", "2", "3"},
                      {"3", "3", "3", "4"},
                      {"4", "4", "4", "3"},
                      {"5", "5", "5", "2"}})
         << '\n';
    return 0;
}