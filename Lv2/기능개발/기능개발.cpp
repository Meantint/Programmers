#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    int relCnt = 0;
    // 한 사이클에 실행되는 작업의 수를 세는 변수
    int pgCnt = 0;

    int pSize = progresses.size();
    // 마지막 작업이 배포되기 전까지 계속
    while (relCnt < pSize) {
        for (int i = 0; i < pSize; ++i) {
            progresses[i] += speeds[i];
        }
        // 작업이 끝났다면
        // relCnt의 바로 뒤부터 작업이 끝나있는 상태일 수 있기 때문에 한 번에 처리해야한다.
        // 그래서 while문 사용!
        while (relCnt < pSize && progresses[relCnt] >= 100) {
            ++pgCnt;
            ++relCnt;
        }
        // while문을 돌고 나온 상태라면
        if (pgCnt != 0) {
            answer.push_back(pgCnt);
            pgCnt = 0;
        }
    }

    return answer;
}