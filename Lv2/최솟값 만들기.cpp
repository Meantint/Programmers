#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    int size = A.size();
    for (int i = 0; i < size; ++i) {
        answer += A[i] * B[i];
    }

    return answer;
}