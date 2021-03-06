#include <algorithm>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

bool comp(const tuple<int, int, int>& t1, const tuple<int, int, int>& t2)
{
    long long n1 = (long long)get<0>(t1) * (long long)get<1>(t2);
    long long n2 = (long long)get<0>(t2) * (long long)get<1>(t1);
    if (n1 == n2) {
        return get<2>(t1) < get<2>(t2);
    }
    return n1 > n2;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;

    vector<int> fail(N + 1, 0);
    vector<int> arrive(N + 1, 0);
    for (auto& stage : stages) {
        ++fail[stage - 1];
        for (int i = 0; i < stage; ++i) {
            ++arrive[i];
        }
    }
    // (fail, arrive, idx)
    vector<tuple<int, int, int>> all(N);
    for (int i = 0; i < N; ++i) {
        all[i] = make_tuple(fail[i], arrive[i], i + 1);
    }
    sort(all.begin(), all.end(), comp);
    for (auto& a : all) {
        answer.push_back(get<2>(a));
    }

    return answer;
}