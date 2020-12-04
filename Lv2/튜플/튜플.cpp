#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool comp(const vector<int> &v1, const vector<int> &v2)
{
    return v1.size() < v2.size();
}

int diff(const vector<int> &v1, const vector<int> &v2)
{
    int v1Size = v1.size();
    for (int i = 0; i < v1Size; ++i) {
        if (v1[i] != v2[i]) {
            return v2[i];
        }
    }
    return v2.back();
}

vector<int> solution(string s)
{
    vector<int> answer;
    vector<vector<int>> v;

    int size = s.size();
    for (int i = 1; i < size; ++i) {
        if (s[i] == '{') {
            int idx = i + 1;
            int num = 0;
            vector<int> tmp;
            while (s[idx] != '}') {
                if (s[idx] == ',') {
                    tmp.push_back(num);
                    num = 0;
                }
                else {
                    num *= 10;
                    num += (s[idx] - '0');
                }
                ++idx;
            }
            tmp.push_back(num);
            sort(tmp.begin(), tmp.end());
            v.push_back(tmp);

            i = idx;
        }
    }
    sort(v.begin(), v.end(), comp);
    answer.push_back(v[0][0]);

    int vSize = v.size();
    for (int i = 1; i < vSize; ++i) {
        answer.push_back(diff(v[i - 1], v[i]));
    }

    return answer;
}