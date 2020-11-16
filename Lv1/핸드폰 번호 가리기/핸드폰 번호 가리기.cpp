#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number)
{
    string answer = "";

    reverse(phone_number.begin(), phone_number.end());
    for (int i = 4; i < phone_number.size(); ++i) {
        phone_number[i] = '*';
    }
    reverse(phone_number.begin(), phone_number.end());
    answer = phone_number;

    return answer;
}