#include <algorithm>
#include <vector>

using namespace std;

int number_of_area = 0;
int max_size_of_one_area = 0;

int M, N;
vector<vector<int>> vec;

int dfs(int val, int x, int y)
{
        if (x >= M || x < 0 || y >= N || y < 0)
                return 0;
        if (vec[x][y] != val)
                return 0;

        int cnt = 1;
        vec[x][y] = 0;

        cnt += dfs(val, x - 1, y);
        cnt += dfs(val, x + 1, y);
        cnt += dfs(val, x, y - 1);
        cnt += dfs(val, x, y + 1);
        return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
        vector<int> answer(2);

        //전역 변수를 함수 내에서 초기화 안하니까 오류남(.....?)
        number_of_area = 0;
        max_size_of_one_area = 0;

        M = m;
        N = n;
        vec = picture;
        for (int i = 0; i < vec.size(); ++i) {
                for (int j = 0; j < vec[0].size(); ++j) {
                        if (vec[i][j] != 0) {
                                int tmp = dfs(vec[i][j], i, j);
                                number_of_area++;
                                max_size_of_one_area = max(max_size_of_one_area, tmp);
                        }
                }
        }

        answer[0] = number_of_area;
        answer[1] = max_size_of_one_area;

        return answer;
}