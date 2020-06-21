#include <bits/stdc++.h>

using namespace std;

string solution(int n)
{
        string answer = "";

        while (n != 0) {
                if (n % 3 == 0) {
                        answer = '4' + answer;
                        n -= 3;
                        n /= 3;
                }
                else {
                        answer = to_string(n % 3) + answer;
                        n /= 3;
                }
        }

        return answer;
}

int main()
{
        for (int i = 0; i < 60; ++i)
                cout << i << " : " << solution(i) << endl;

        return 0;
}