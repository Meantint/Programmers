#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p)
{
        string answer = "";

        int cnt = 0; // 구한 개수가 t와 같으면 종료
        int order = p - 1; // 나머지가 p - 1일 때의 숫자 저장
        int cycle = 0;

        if (cycle == order) {
                answer.push_back('0');
                ++cnt;
                if (cnt == t)
                        return answer;
        }
        ++cycle;
        for (int i = 1;; ++i) {
                int cp = i; // copy value

                string base10 = "";
                while (cp != 0) {
                        if (cp % n >= 10) { // 10 이상이면 알파벳 표현
                                base10.push_back('A' + (cp % n - 10));
                        }
                        else {
                                base10.push_back('0' + cp % n);
                        }
                        cp /= n;
                }

                // reverse 안쓰고 for(int i = base10.size() - 1; i >= 0; --i) 쓰는게 더 빠름(귀찮아서)
                reverse(base10.begin(), base10.end());
                for (int i = 0; i < base10.size(); ++i) {
                        if (cycle == order) {
                                answer.push_back(base10[i]);
                                cnt++;
                        }
                        if (cnt == t) {
                                return answer;
                        }
                        ++cycle;
                        cycle %= m;
                }
        }

        return answer;
}

int main()
{
        cout << solution(2, 4, 2, 1) << endl;

        return 0;
}