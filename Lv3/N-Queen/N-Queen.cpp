#include <string>
#include <vector>

using namespace std;

vector<bool> col;
vector<int> row;
int answer, global_n;

void dfs(int r)
{
    if (r == global_n) {
        ++answer;
        return;
    }

    for (int i = 0; i < global_n; ++i) {
        bool isPos = true;

        for (int j = 0; j < r; ++j) {
            int y = j - r;
            int x = row[j] - i;

            if (y - x == 0 || y + x == 0) {
                isPos = false;

                break;
            }
        }

        if (!col[i] && isPos) {
            col[i] = true;
            row[r] = i;
            dfs(r + 1);
            row[r] = -1;
            col[i] = false;
        }
    }
}

void solve()
{
    answer = 0;
    for (int i = 0; i < global_n; ++i) {
        col[i] = true;
        row[0] = i;
        dfs(1);
        row[0] = -1;
        col[i] = false;
    }
}

int solution(int n)
{
    global_n = n;
    col.resize(n, false);
    row.resize(n, -1);

    solve();

    return answer;
}