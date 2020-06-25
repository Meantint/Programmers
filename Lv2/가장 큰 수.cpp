#include <bits/stdc++.h>

using namespace std;

bool compare(const int n1, const int n2)
{
        string str1 = to_string(n1);
        string str2 = to_string(n2);

        int size = (str1.size() > str2.size()) ? str1.size() : str2.size();
        for (int i = 0; i < size; ++i) {
                if (str1[i % str1.size()] == str2[i % str2.size()])
                        continue;
                return str1[i % str1.size()] > str2[i % str2.size()];
        }

        int newStr1 = stoi(str1 + str2);
        int newStr2 = stoi(str2 + str1);
        return newStr1 > newStr2;
}

string solution(vector<int> numbers)
{
        string answer = "";

        sort(numbers.begin(), numbers.end(), compare);
        int size = numbers.size();
        for (int i = 0; i < size; ++i) {
                answer += to_string(numbers[i]);
        }

        if (answer[0] == '0')
                return "0";
        return answer;
}