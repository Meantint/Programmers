#include <string>
#include <vector>

using namespace std;

int check[16] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
        vector<string> answer;

        for (int i = 0; i < n; ++i) {
                string partAns = "";
                for (int j = n - 1; j >= 0; --j) {
                        int cnt = 0;
                        if (arr1[i] - check[j] >= 0) {
                                arr1[i] -= check[j];
                                partAns += "#";
                                ++cnt;
                        }
                        if (arr2[i] - check[j] >= 0) {
                                arr2[i] -= check[j];
                                if (cnt == 0) {
                                        partAns += "#";
                                        ++cnt;
                                }
                        }
                        if (cnt == 0)
                                partAns += " ";
                }
                answer.push_back(partAns);
        }
        return answer;
}
