#include <cstring>  // memset
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ALPHA = 26;
int answer = 0;

int charToNum(char ch) { return ch - 'a'; }

struct Trie {
    Trie* children[ALPHA];  // 각 알파벳을 저장할 수 있는 Trie Pointer를 만든다.

    int cnt;        // 이 Node를 몇번 지나가는지
    int depth;      // 이 Node의 깊이
    bool terminal;  // 이 노드에서 종료한다면 true, 아니라면 false
    Trie(int Depth) : cnt(1), depth(Depth + 1)  // 생성자
    {
        terminal = false;
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
            terminal = true;
        }
        else {
            int next = charToNum(*key);

            if (children[next] == NULL) {
                children[next] = new Trie(depth);
            }
            else {
                ++children[next]->cnt;
            }
            children[next]->insert(key + 1);
        }
    }
    // Trie 구조 안을 탐색한다.
    void search()
    {
        for (int i = 0; i < 26; ++i) {
            if (children[i] == NULL) {
                continue;
            }
            else {
                if (children[i]->cnt == 1) {
                    cout << "depth : " << children[i]->depth
                         << ", cnt : " << children[i]->cnt
                         << ", ch : " << char(i + 'a') << '\n';
                    answer += children[i]->depth;
                    continue;
                }
                else if (children[i]->cnt > 1 && children[i]->terminal) {
                    cout << "depth : " << children[i]->depth
                         << ", cnt : " << children[i]->cnt
                         << ", ch : " << char(i + 'a') << '\n';
                    answer += children[i]->depth;
                }
                children[i]->search();
            }
        }
        return;
    }
};

int solution(vector<string> words)
{
    answer = 0;
    Trie* root = new Trie(-1);

    int size = words.size();
    for (int i = 0; i < size; ++i) {
        const char* word = words[i].c_str();
        root->insert(word);
    }

    root->search();

    delete root;

    return answer;
}

int main()
{
    cout << solution({"go", "gone", "guild"}) << '\n';
    cout << solution({"abc", "def", "ghi", "jklm"}) << '\n';
    cout << solution({"word", "war", "warrior", "world"}) << '\n';

    return 0;
}