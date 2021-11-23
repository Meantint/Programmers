#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;

    int width = 0, height = 0;
    int size = sizes.size();
    for (int i = 0; i < size; ++i) {
        if (sizes[i][0] < sizes[i][1]) {
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
        if (height < sizes[i][0]) {
            height = sizes[i][0];
        }
        if (width < sizes[i][1]) {
            width = sizes[i][1];
        }
    }

    answer = width * height;

    return answer;
}