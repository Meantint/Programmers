#include <bits/stdc++.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
        vector<string> answer;

        int rowSize = arr1.size();
        for (int i = 0; i < rowSize; ++i) {
                // arr1, arr2 각각의 값을 row단위로 검사하고 하나로 묶어서 answer에 넣음
                string str1 = "";
                string str2 = "";
                int val = arr1[i];
                while (val != 0) {
                        if (val % 2 == 0) {
                                str1 = ' ' + str1;
                        }
                        else {
                                str1 = '#' + str1;
                        }
                        val /= 2;
                }
                while (str1.size() != n) {
                        str1 = ' ' + str1;
                }
                val = arr2[i];
                while (val != 0) {
                        if (val % 2 == 0) {
                                str2 = ' ' + str2;
                        }
                        else {
                                str2 = '#' + str2;
                        }
                        val /= 2;
                }
                while (str2.size() != n) {
                        str2 = ' ' + str2;
                }
                string str;
                for (int i = 0; i < rowSize; ++i) {
                        if (str1[i] == ' ' && str2[i] == ' ')
                                str.push_back(' ');
                        else
                                str.push_back('#');
                }
                answer.push_back(str);
        }

        return answer;
}