#include <algorithm>
#include <cstring>  // memset
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ALPHA = 26;

int charToNum(char ch) { return ch - 'a'; }

struct Trie {
    Trie* children[ALPHA];  // 각 알파벳을 저장할 수 있는 Trie Pointer를 만든다.

    int cnt;         // 이 Trie를 지나는 총 개수
    Trie() : cnt(1)  // 생성자
    {
        memset(children, 0, sizeof(children));
    }
    ~Trie()  // 소멸자
    {
        for (int i = 0; i < ALPHA; ++i) {
            if (children[i]) {
                delete children[i];
            }
        }
    }
    // Trie 구조 안에 문자열을 넣는다.
    void insert(const char* key)
    {
        if (*key == 0) {
            return;
        }
        else {
            int next = charToNum(*key);

            // children[next]가 없다면 만들어준다.
            if (children[next] == NULL) {
                children[next] = new Trie();
            }
            // children[next]가 있다면 children[next]의 cnt를 증가시킨다.
            else {
                children[next]->cnt++;
            }
            children[next]->insert(key + 1);
        }
    }
    int find(const char* key)
    {
        int next = charToNum(*key);
        // 다음 key가 '?'라면
        if (*key == '?') {
            int tmp = 0;
            // 모든 자식 노드의 cnt를 tmp에 더해준다.
            for (int i = 0; i < 26; ++i) {
                if (children[i] != NULL) tmp += children[i]->cnt;
            }
            // 모두 더한 후 tmp를 리턴한다.
            return tmp;
        }

        if (children[next] == NULL) return 0;
        if (*(key + 1) == '?') return children[next]->cnt;
        return children[next]->find(key + 1);
    }
};
Trie* root[10010];
Trie* rv_root[10010];

vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<int> answer;

    int wordsSize = words.size();
    for (int i = 0; i < wordsSize; ++i) {
        int wordSize = words[i].size();
        if (root[wordSize] == NULL) {
            root[wordSize] = new Trie();
        }
        root[wordSize]->insert(words[i].c_str());

        if (rv_root[wordSize] == NULL) {
            rv_root[wordSize] = new Trie();
        }
        reverse(words[i].begin(), words[i].end());
        rv_root[wordSize]->insert(words[i].c_str());
    }
    int queriesSize = queries.size();
    for (int i = 0; i < queriesSize; ++i) {
        int querySize = queries[i].size();
        // 앞이 '?'라면
        if (queries[i][0] == '?') {
            if (rv_root[querySize] == NULL)
                answer.push_back(0);
            else {
                reverse(queries[i].begin(), queries[i].end());
                answer.push_back(rv_root[querySize]->find(queries[i].c_str()));
            }
        }
        else {
            if (root[querySize] == NULL)
                answer.push_back(0);
            else
                answer.push_back(root[querySize]->find(queries[i].c_str()));
        }
    }

    return answer;
}