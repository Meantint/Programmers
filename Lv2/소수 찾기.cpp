#include <bits/stdc++.h>

using namespace std;

int solution(string numbers)
{
        int answer = 0;

        vector<int> saveAns;
        int size = numbers.size();
        sort(numbers.begin(), numbers.end());
        do {
                for (int i = 1; i <= size; ++i) {
                        int num = stoi(numbers.substr(0, i));
                        bool check = true;
                        if (num == 0 || num == 1)
                                continue;
                        else {
                                for (int i = 2; i <= sqrt(num); ++i) {
                                        if (num % i == 0) {
                                                check = false;
                                                break;
                                        }
                                }
                        }
                        if (check) {
                                saveAns.push_back(num);
                        }
                }
        } while (next_permutation(numbers.begin(), numbers.end()));

        sort(saveAns.begin(), saveAns.end());
        int ansSize = saveAns.size();

        int prev = saveAns[0];
        ++answer;
        int num;
        for (int i = 1; i < ansSize; ++i) {
                num = saveAns[i];
                if (prev == num)
                        continue;
                else {
                        ++answer;
                        prev = num;
                }
        }

        return answer;
}