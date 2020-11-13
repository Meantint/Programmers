#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N;

bool comp(const string &s1, const string &s2)
{
    if (s1[N] == s2[N]) {
        return s1 < s2;
    }
    return s1[N] < s2[N];
}

vector<string> solution(vector<string> strings, int n)
{
    vector<string> answer;

    N = n;
    sort(strings.begin(), strings.end(), comp);
    answer = strings;

    return answer;
}