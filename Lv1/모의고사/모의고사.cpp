#include <algorithm>
#include <string>
#include <vector>

#define pii pair<int, int>

using namespace std;

int p1[5] = {1, 2, 3, 4, 5};
int p2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int p3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers)
{
    vector<int> answer;

    int c1 = 0, c2 = 0, c3 = 0;
    int aSize = answers.size();
    for (int i = 0; i < aSize; ++i) {
        if (answers[i] == p1[i % 5]) ++c1;
        if (answers[i] == p2[i % 8]) ++c2;
        if (answers[i] == p3[i % 10]) ++c3;
    }
    vector<pii> check = {make_pair(c1, 1), make_pair(c2, 2), make_pair(c3, 3)};

    sort(check.begin(), check.end(), greater<pii>());

    // 가장 많이 맞은 사람의 index = 0이기 때문에 answer에 넣어준다.
    answer.push_back(check[0].second);
    // 두 번째 많이 맞은 사람의 정답 수가 첫 번째 사람이랑 같다면 answer에 넣어준다.
    if (check[0].first == check[1].first) {
        answer.push_back(check[1].second);
        // 세 번째 많이 맞은 사람의 정답 수가 두 번째 사람이랑 같다면 answer에 넣어준다.
        if (check[1].first == check[2].first) {
            answer.push_back(check[2].second);
        }
    }
    // 여러 개 들어간 경우를 대비해 오름차순으로 정렬한다.
    sort(answer.begin(), answer.end());

    return answer;
}