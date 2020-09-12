#include <algorithm>
#include <string>
#include <vector>

#define PSI pair<string, int>

using namespace std;

int solution(string s)
{
    int answer = 2112345678;

    vector<PSI> vec;
    int size = s.size();
    if (size == 1) {
        return 1;
    }
    for (int len = 1; len <= size / 2; ++len) {
        // vec 초기화
        vec.clear();
        // 길이가 len일 때의 압축 처리
        for (int i = 0; i < size; i += len) {
            if (vec.empty()) {
                vec.push_back(make_pair(s.substr(i, len), 1));
            }
            else {
                if (vec.back().first != s.substr(i, len)) {
                    vec.push_back(make_pair(s.substr(i, len), 1));
                }
                else {
                    vec.back().second += 1;
                }
            }
        }
        string tmp = "";
        int vecSize = vec.size();
        for (int i = 0; i < vecSize; ++i) {
            // 반복되는 문자열이 하나라면
            if (vec[i].second == 1) {
                tmp += vec[i].first;
            }
            // 반복되는 문자열이 둘 이상일 때
            else {
                tmp += to_string(vec[i].second) + vec[i].first;
            }
        }
        answer = min(answer, (int)tmp.size());
    }

    return answer;
}