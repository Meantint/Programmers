#include <bits/stdc++.h>

using namespace std;

double solution(vector<int> arr)
{
    double answer = 0;

    int rowSize = arr.size();
    for (int i = 0; i < rowSize; ++i)
    {
        answer += arr[i];
    }
    answer /= rowSize;

    return answer;
}