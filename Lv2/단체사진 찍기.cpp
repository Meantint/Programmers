#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
        int answer = 0;

        string str = "ACFJMNRT";

        do {
                bool check = true;
                for (int i = 0; i < n; ++i) {
                        int idx1 = str.find(data[i][0]);
                        int idx2 = str.find(data[i][2]);

                        if (data[i][3] == '=') {
                                if (abs(idx1 - idx2) - 1 == data[i][4] - '0') {
                                }
                                else {
                                        check = false;
                                        break;
                                }
                        }
                        else if (data[i][3] == '>') {
                                if (abs(idx1 - idx2) - 1 > data[i][4] - '0') {
                                }
                                else {
                                        check = false;
                                        break;
                                }
                        }
                        else if (data[i][3] == '<') {
                                if (abs(idx1 - idx2) - 1 < data[i][4] - '0') {
                                }
                                else {
                                        check = false;
                                        break;
                                }
                        }
                }
                if (check == true)
                        answer++;
        } while (next_permutation(str.begin(), str.end())); // next_permutation() -> algorithm header에 있는 함수.
            // 순열을 오름차순으로 보여준다.

        return answer;
}

int main()
{
        vector<string> vec;
        vec.push_back("N~F=0");
        vec.push_back("R~T>2");
        /*vec.push_back("M~C<2");
    vec.push_back("C~M>1");*/
        cout << solution(2, vec) << endl;

        return 0;
}
