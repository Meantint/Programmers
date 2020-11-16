#include <string>
#include <vector>

using namespace std;

bool solution(int x)
{
    bool answer = true;

    int cx = x;
    int sum = 0;
    while (cx != 0) {
        sum += cx % 10;
        cx /= 10;
    }
    answer = (x % sum == 0) ? answer = true : answer = false;

    return answer;
}