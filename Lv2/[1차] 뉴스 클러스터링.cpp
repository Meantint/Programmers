#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2)
{
    int answer = 0;

    vector<string> vec1, vec2;
    int size = str1.size() - 1;
    for (int i = 0; i < size; ++i) {
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            str1[i] -= 32;
        }
        if (str1[i + 1] >= 'a' && str1[i + 1] <= 'z') {
            str1[i + 1] -= 32;
        }

        if (str1[i] >= 'A' && str1[i] <= 'Z' && str1[i + 1] >= 'A' && str1[i + 1] <= 'Z') {
            vec1.push_back(str1.substr(i, 2));
        }
    }
    size = str2.size() - 1;
    for (int i = 0; i < size; ++i) {
        if (str2[i] >= 'a' && str2[i] <= 'z') {
            str2[i] -= 32;
        }
        if (str2[i + 1] >= 'a' && str2[i + 1] <= 'z') {
            str2[i + 1] -= 32;
        }

        if (str2[i] >= 'A' && str2[i] <= 'Z' && str2[i + 1] >= 'A' && str2[i + 1] <= 'Z') {
            vec2.push_back(str2.substr(i, 2));
        }
    }
    // test
    // for (int i = 0; i < vec1.size(); ++i) {
    //     cout << vec1[i] << ' ';
    // }
    // cout << "\n\n";
    // for (int i = 0; i < vec2.size(); ++i) {
    //     cout << vec2[i] << ' ';
    // }
    // cout << '\n';

    if (vec1.size() == 0 && vec2.size() == 0) {
        return 65536;
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    int idx1, idx2;
    idx1 = idx2 = 0;
    int cnt = 0; // 같은 문자열의 개수를 세는 변수
    while (idx1 < vec1.size() && idx2 < vec2.size()) {
        if (vec1[idx1] == vec2[idx2]) { // 같은 문자열일 때
            ++cnt;
            ++idx1;
            ++idx2;
        }
        else if (vec1[idx1] < vec2[idx2]) { // vec1[idx1]이 vec2[idx2]보다 앞설때(사전순)
            ++idx1;
        }
        else {
            ++idx2;
        }
    }
    answer = (int)((double)65536 * (double)cnt / (double)(vec1.size() + vec2.size() - cnt));

    return answer;
}