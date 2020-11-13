#include <string>
#include <vector>

using namespace std;

int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

string solution(int a, int b)
{
    string answer = "";

    // 2016년 1월 1일을 금요일로 설정해 놓는다. (day[5] = "FRI")
    int base = 5;
    for (int i = a - 2; i >= 0; --i) {
        base += month[i];
    }
    base += (b - 1);
    answer = day[base % 7];

    return answer;
}