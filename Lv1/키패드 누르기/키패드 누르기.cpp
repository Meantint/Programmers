#include <string>
#include <vector>

#define PII pair<int, int>

using namespace std;

// 순서대로 0, 1, 2, 3, 4, 5, 6, 7, 8, 9의 (x, y) 좌표를 나타냄.
vector<PII> phone = {
    make_pair(3, 1),
    make_pair(0, 0),
    make_pair(0, 1),
    make_pair(0, 2),
    make_pair(1, 0),
    make_pair(1, 1),
    make_pair(1, 2),
    make_pair(2, 0),
    make_pair(2, 1),
    make_pair(2, 2),
};

// 초기 위치
PII left = make_pair(3, 0);
PII right = make_pair(3, 2);
bool isRight;  // 오른손잡이라면 true, 왼손잡이라면 false

// 움직이는 거리를 구하는 함수
int dist(PII p1, PII p2)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

string solution(vector<int> numbers, string hand)
{
    string answer = "";

    if (hand == "right") {
        isRight = true;
    }
    else {
        isRight = false;
    }
    for (auto& num : numbers) {
        // 왼손을 움직여야 하는 숫자들
        if (num == 1 || num == 4 || num == 7) {
            // 왼손의 위치를 바꿔준다.
            left = phone[num];
            answer += 'L';
        }
        // 오른손을 움직여야 하는 숫자들
        else if (num == 3 || num == 6 || num == 9) {
            // 오른손의 위치를 바꿔준다.
            right = phone[num];
            answer += 'R';
        }
        // 나머지는 거리와 isRight에 따라 바뀜(2, 5, 8, 0)
        else {
            int leftDist = dist(phone[num], left);
            int rightDist = dist(phone[num], right);
            // 왼손과 오른손의 거리가 같다면
            if (leftDist == rightDist) {
                // 오른손잡이라면
                if (isRight) {
                    // 오른손의 위치를 바꿔준다.
                    right = phone[num];
                    answer += 'R';
                }
                // 왼손잡이라면
                else {
                    // 왼손의 위치를 바꿔준다.
                    left = phone[num];
                    answer += 'L';
                }
            }
            // 오른손이 더 가깝다면
            else if (leftDist > rightDist) {
                // 오른손의 위치를 바꿔준다.
                right = phone[num];
                answer += 'R';
            }
            // 왼손이 더 가깝다면
            else {
                // 왼손의 위치를 바꿔준다.
                left = phone[num];
                answer += 'L';
            }
        }
    }

    return answer;
}