#include <stack>
#include <string>
#include <vector>

#define PII pair<int, int>

using namespace std;

stack<PII> st;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size(), -1);

    for (auto& price : prices) {
        int curIdx = &price - &prices[0];
        // 비어 있을 경우
        if (st.empty()) {
            st.push(make_pair(price, curIdx));
        }
        else {
            // 스택의 가장 큰 값보다 price가 더 크거나 같을 경우
            if (st.top().first <= price) {
                st.push(make_pair(price, curIdx));
            }
            // st.top()이 더 클 경우는 빼줘야한다.
            else {
                // 몇 개가 있을지 모르기 때문에 while문 사용
                while (!st.empty() && st.top().first > price) {
                    answer[st.top().second] = curIdx - st.top().second;
                    st.pop();
                }
                // price보다 더 큰 stack의 요소들을 제거한 후 stack에 넣어준다.
                st.push(make_pair(price, curIdx));
            }
        }
    }

    // stack에 남아있는 나머지 요소들을 answer에 넣어준 후 빼준다.
    int topIdx = st.top().second;
    while (!st.empty()) {
        answer[st.top().second] = topIdx - st.top().second;
        st.pop();
    }

    return answer;
}