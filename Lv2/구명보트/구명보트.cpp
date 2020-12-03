#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;

    sort(people.begin(), people.end());
    int st = 0, ed = people.size() - 1;
    while (st <= ed) {
        // 두 명 못태우면 몸무게 큰 사람만 태운다
        if (people[st] + people[ed] > limit) {
            ++answer;
            --ed;
        }
        // 둘 다 태울수 있으면 태운다
        else {
            ++answer;
            ++st;
            --ed;
        }
    }
    if (st == ed) {
        ++answer;
    }

    return answer;
}