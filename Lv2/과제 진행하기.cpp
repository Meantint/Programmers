#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool comp(const vector<int>& n1, const vector<int>& n2) {
    return n1[1] < n2[1];
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<vector<int>> pTable;

    int pSize = plans.size();
    for (int idx = 0; idx < pSize; ++idx) {
        vector<int> plan(3, 0);

        plan[0] = idx;
        plan[1] = stoi(plans[idx][1].substr(0, 2)) * 60 + stoi(plans[idx][1].substr(3));
        plan[2] = stoi(plans[idx][2]);

        pTable.push_back(plan);
    }

    sort(pTable.begin(), pTable.end(), comp);

    int curTime = pTable[0][1];
    stack<vector<int>> st;
    for(int idx = 0; idx < pSize - 1; ++idx) {
        /* 시간내 과제 끝낼수 있는 경우 */
        if (pTable[idx + 1][1] - curTime >= pTable[idx][2]) {
            curTime += pTable[idx][2];
            answer.push_back(plans[pTable[idx][0]][0]);

            /* 남은 시간에 stack 처리 */
            while(!st.empty()) {
                vector<int> curPlan = st.top();
                st.pop();

                /* 시간내 과제 끝낼수 있는 경우 */
                if (pTable[idx + 1][1] - curTime >= curPlan[2]) {
                    curTime += curPlan[2];
                    answer.push_back(plans[curPlan[0]][0]);
                }
                else {
                    curPlan[2] -= (pTable[idx + 1][1] - curTime);
                    st.push(curPlan);

                    break;
                }
            }
        }
        else {
            pTable[idx][2] -= (pTable[idx + 1][1] - curTime);
            st.push(pTable[idx]);
        }

        curTime = pTable[idx + 1][1];
    }
    /* 마지막은 개별 처리 */
    answer.push_back(plans[pTable[pSize - 1][0]][0]);

    /* 스택 남은거 다 처리 */
    while(!st.empty()) {
        answer.push_back(plans[st.top()[0]][0]);
        st.pop();
    }

    return answer;
}