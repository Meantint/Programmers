#include <bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
        int answer = 0;

        // skill의 index를 차례대로 읽음
        int skillIdx = 0;
        int size = skill_trees.size();
        for (int i = 0; i < size; ++i) {
                bool isTrue = true;
                int strSize = skill_trees[i].size();
                for (int j = 0; j < strSize; ++j) {
                        if (skill.find(skill_trees[i][j]) == -1)
                                continue;
                        else if (skill.find(skill_trees[i][j]) == skillIdx) {
                                ++skillIdx;
                                continue;
                        }
                        else if (skill.find(skill_trees[i][j]) != skillIdx) {
                                isTrue = false;
                                break;
                        }
                }
                if (isTrue)
                        ++answer;
                skillIdx = 0;
        }

        return answer;
}