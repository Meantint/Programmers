#include <bits/stdc++.h>

using namespace std;

bool isCheck[50];
int answer;
string gv_begin = "", gv_target = "";
vector<string> gv_words;

void dfs(int cur, string str, int cnt)
{
    if (cur == -1) {
    }
    else if (isCheck[cur]) {
        return;
    }
    if (str == gv_target) {
        answer = min(answer, cnt);
        return;
    }

    isCheck[cur] = true;
    int size = gv_words.size();
    for (int i = 0; i < size; ++i) {
        int diff = 0;
        int wordSize = gv_words[i].size();
        for (int j = 0; j < wordSize; ++j) {
            if (str[j] != gv_words[i][j]) {
                ++diff;
            }
        }
        if (diff == 1) {
            dfs(i, gv_words[i], cnt + 1);
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    memset(isCheck, 0, sizeof(isCheck));
    gv_begin = begin, gv_target = target;
    gv_words = words;
    answer = 2112345678;

    dfs(-1, begin, 0);

    if (answer == 2112345678) {
        answer = 0;
    }
    return answer;
}

int main()
{
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }) << '\n';
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" }) << '\n';
}