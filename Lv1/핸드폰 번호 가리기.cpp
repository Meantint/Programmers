#include <bits/stdc++.h>

using namespace std;

string solution(string phone_number)
{
        string answer = "";

        int size = phone_number.size();
        for (int i = 0; i < size; ++i) {
                if (i < size - 4)
                        answer.push_back('*');
                else
                        answer.push_back(phone_number[i]);
        }

        return answer;
}