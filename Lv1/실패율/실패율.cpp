#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool comp(pair<pair<long long, long long>, long long> p1, pair<pair<long long, long long>, long long> p2)
{
    long long num1 = p1.first.first * p2.first.second;
    long long num2 = p1.first.second * p2.first.first;

    if (num1 == num2)
        return p1.second < p2.second;
    return num1 > num2;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;

    vector<int> suc(N + 2, 0);
    vector<int> arrive(N + 2, 0);
    int size = stages.size();
    for (int i = 0; i < size; ++i) {
        for (int j = stages[i]; j > 0; --j) {
            ++suc[j];
            ++arrive[j];
        }
        --suc[stages[i]];
    }
    vector<pair<pair<long long, long long>, long long>> per(N);
    int pSize = per.size();
    for (int i = 0; i < pSize; ++i) {
        if (arrive[i + 1] == 0) {
            per[i].first.first = 0;
            per[i].first.second = 1000000;
        }
        else {
            // 분자
            per[i].first.first = arrive[i + 1] - suc[i + 1];
            // 분모
            per[i].first.second = arrive[i + 1];
        }
        // 번호
        per[i].second = i + 1;
    }

    sort(per.begin(), per.end(), comp);
    for (int i = 0; i < pSize; ++i) {
        answer.push_back(per[i].second);
    }

    return answer;
}