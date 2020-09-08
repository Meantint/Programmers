#include <bits/stdc++.h>

#define PSI pair<string, int>

using namespace std;

int solution(string s)
{
    if (s.size() == 1) {
        return 1;
    }
    unsigned long answer = 10000;

    int size = s.size();
    for (int i = 1; i <= size / 2; ++i) {
        vector<PSI> vec;
        vec.push_back(make_pair(s.substr(0, i), 1));
        for (int j = i; j < size; j += i) {
            if (j + i - 1 >= size) {
                vec.push_back(make_pair(s.substr(j), 1));
            }
            else if (vec.back().first == s.substr(j, i)) {
                ++vec.back().second;
            }
            else {
                vec.push_back(make_pair(s.substr(j, i), 1));
            }
        }
        string test = "";
        int vecSize = vec.size();
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i].second > 1) {
                test += to_string(vec[i].second);
                test += vec[i].first;
            }
            else
                test += vec[i].first;
        }
        // cout << test << endl;
        answer = min(answer, (unsigned long)test.size());
    }

    return answer;
}