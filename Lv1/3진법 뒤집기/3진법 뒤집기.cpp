#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    string str = "";

    while (n != 0) {
        str += to_string(n % 3);
        n /= 3;
    }
    // 뒤집어 준다.
    reverse(str.begin(), str.end());

    int sSize = str.size();
    for (int i = 0; i < sSize; ++i) {
        answer += (str[i] - '0') * pow(3, i);
    }

    return answer;
}