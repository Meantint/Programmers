#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> v1, vector<int> v2)
{
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes)
{
    int answer = 0;

    vector<vector<int>> r1 = routes;
    vector<bool> isCheck(routes.size(), false);
    sort(routes.begin(), routes.end(), cmp);
    sort(r1.begin(), r1.end());

    int idx = 0;
    int size = routes.size();
    for (int i = 0; i < size; ++i) {
        if (!isCheck[i]) {
            isCheck[i] = true;
            ++answer;

            for (; idx < size; ++idx) {
                if (isCheck[idx]) {
                    continue;
                }
                if (routes[i][1] >= routes[idx][0] && routes[i][1] <= routes[idx][1]) { // 자른 부분이 다음 경로 안에 포함된다면
                    isCheck[idx] = true;
                    continue;
                }
                break;
            }
        }
    }

    return answer;
}

int main()
{
    cout << solution({ { -20, 15 }, { -14, -5 }, { -18, -13 }, { -5, -3 } }) << '\n';

    return 0;
}