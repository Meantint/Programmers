#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> solve(int n, vector<vector<string>> relation)
{
    int row = relation.size();
    int col = relation[0].size();
    vector<int> vec;
    for (int i = n; i < col; ++i) {
        vec.push_back(0);
    }
    for (int i = 0; i < n; ++i) {
        vec.push_back(1);
    }

    vector<string> answer;
    map<string, int> m;
    do {
        m.clear();
        bool isTrue = true;
        for (int i = 0; i < row; ++i) {
            string str = "";
            for (int j = 0; j < col; ++j) {
                if (vec[j] == 1) {
                    str += relation[i][j];
                }
            }
            if (m.count(str) == 1) {
                isTrue = false;
                break;
            }
            m[str] = 1;
        }
        if (isTrue) {
            string tmp = "";
            for (int i = 0; i < col; ++i) {
                if (vec[i] == 1) tmp += to_string(i);
            }
            answer.push_back(tmp);
        }
    } while (next_permutation(vec.begin(), vec.end()));

    return answer;
}

int solution(vector<vector<string>> relation)
{
    int answer = 0;

    vector<string> col;
    int size = relation[0].size();
    for (int i = 1; i <= size; ++i) {
        vector<string> v = solve(i, relation);
        int vSize = v.size();
        sort(v.begin(), v.end());
        for (int j = 0; j < vSize; ++j) {
            col.push_back(v[j]);
        }
    }
    int cSize = col.size();
    for (int i = 0; i < cSize; ++i) {
        if (col[i] == "-1") {
            continue;
        }
        for (int j = i + 1; j < cSize; ++j) {
            int idx1 = 0;
            int idx2 = 0;

            while (idx1 < col[i].size() && idx2 < col[j].size()) {
                if (col[i][idx1] < col[j][idx2]) {
                    break;
                }
                else if (col[i][idx1] == col[j][idx2]) {
                    ++idx1, ++idx2;
                }
                else {
                    ++idx2;
                }
            }
            if (idx1 == col[i].size()) {
                col[j] = "-1";
            }
        }
        ++answer;
    }

    return answer;
}