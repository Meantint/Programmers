#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<char, int> m;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;

    for (auto& s : skill) {
        m[s] = &s - &skill[0];
    }

    for (auto& skill_tree : skill_trees) {
        // 올바른 스킬트리인지 확인하는 bool 타입 변수
        bool isGood = true;
        int curPos = 0;
        // cout << skill_tree << endl;
        for (auto& st : skill_tree) {
            auto it = m.find(st);
            // cout << it->first << ", " << m.end()->first << endl;

            // find에 실패했을시 map 컨테이너의 end()를 리턴하는 것을 이용한다.
            // skill 순서안에 포함된다면
            if (it != m.end()) {
                // 스킬트리 순서를 따른다면
                if (st == skill[curPos]) {
                    ++curPos;
                }
                // 순서가 잘못된 스킬트리라면
                else {
                    isGood = false;
                    break;
                }
            }
        }
        // 스킬트리가 올바르다면
        if (isGood) {
            ++answer;
        }
    }

    return answer;
}