#include <bits/stdc++.h>

using namespace std;

int solution(int n)
{
        int answer = 0;

        vector<bool> prime(n + 1, true);
        int primeSize = prime.size();
        for (int i = 2; i < primeSize; ++i) {
                for (int j = i * 2; j < primeSize; j += i) {
                        prime[j] = false;
                }
        }
        for (int i = 2; i < primeSize; ++i) {
                if (prime[i] == true)
                        ++answer;
        }

        return answer;
}