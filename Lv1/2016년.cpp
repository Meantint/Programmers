#include <bits/stdc++.h>

using namespace std;

string solution(int a, int b)
{
        string answer = "";
        vector<string> day = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

        int num = 0;
        switch (a) {
        case 1:
                break;
        case 2:
                num += 31;
                break;
        case 3:
                num += 31 + 29;
                break;
        case 4:
                num = 31 + 29 + 31;
                break;
        case 5:
                num = 31 + 29 + 31 + 30;
                break;
        case 6:
                num = 31 + 29 + 31 + 30 + 31;
                break;
        case 7:
                num = 31 + 29 + 31 + 30 + 31 + 30;
                break;
        case 8:
                num = 31 + 29 + 31 + 30 + 31 + 30 + 31;
                break;
        case 9:
                num = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
                break;
        case 10:
                num = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
                break;
        case 11:
                num = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
                break;
        case 12:
                num = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
                break;
        }
        num += b;
        answer = day[(num + 4) % 7];

        return answer;
}