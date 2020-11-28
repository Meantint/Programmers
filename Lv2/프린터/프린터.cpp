#include <algorithm>
#include <queue>
#include <string>
#include <vector>

#define PII pair<int, int>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    vector<int> copy = priorities;
    // 내림차순 정렬
    sort(copy.begin(), copy.end(), greater<int>());
    // copy 배열의 현재 인덱스를 저장하는 변수
    int cpIdx = 0;

    queue<PII> q;
    // (priority, location)
    for (auto& p : priorities) {
        q.push(make_pair(p, &p - &priorities[0]));
    }

    while (1) {
        // 현재의 가장 높은 중요도 값과 현재 탐색하고있는 q.front()의 중요도가 같다면
        if (q.front().first == copy[cpIdx]) {
            ++answer;
            // 이번에 인쇄하는 작업의 인덱스가 우리가 찾는 location이라면
            if (q.front().second == location) {
                break;
            }
            // location이 다르다면 현재 제일 앞에 있는 요청을 제거해준다.
            else {
                ++cpIdx;
                q.pop();
            }
        }
        // 중요도가 다르다면 제일 뒤로 넣어준다.
        else {
            q.push(q.front());
            q.pop();
        }
    }

    return answer;
}