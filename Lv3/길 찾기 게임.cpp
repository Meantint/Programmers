#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> pre;
vector<int> post;

struct Tree {
    Tree* left = NULL;
    Tree* right = NULL;
    int x, y, num;

    Tree(int X, int Y, int Num) : x(X), y(Y), num(Num){};
    void input(int cx, int cy, int cnum)
    {
        if (cy < y) {      // 자식 혹은 자손 노드이고
            if (cx < x) {  // 부모 노드의 왼쪽 노드라면
                if (this->left != NULL) {  // 이미 왼쪽 노드가 존재한다면
                    this->left->input(cx, cy, cnum);
                }
                else {  // 왼쪽 노드가 존재하지 않는다면
                    Tree* node = new Tree(cx, cy, cnum);
                    this->left = node;
                }
            }
            else {  // 부모 노드의 오른쪽 노드라면
                if (this->right != NULL) {  // 이미 오른쪽 노드가 존재한다면
                    this->right->input(cx, cy, cnum);
                }
                else {  // 오른쪽 노드가 존재하지 않는다면
                    Tree* node = new Tree(cx, cy, cnum);
                    this->right = node;
                }
            }
        }
    }

    void preorder(Tree* tree)
    {
        if (tree == NULL) {
            return;
        }
        pre.push_back(tree->num);
        preorder(tree->left);
        preorder(tree->right);
    }
    void postorder(Tree* tree)
    {
        if (tree == NULL) {
            return;
        }
        postorder(tree->left);
        postorder(tree->right);
        post.push_back(tree->num);
    }
};

bool comp(const vector<int> v1, const vector<int> v2)
{
    if (v1[1] == v2[1]) {  // y 값이 같다면
        return v1[0] < v2[0];
    }
    return v1[1] > v2[1];
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;

    vector<vector<int>> realNodeinfo;
    int size = nodeinfo.size();
    for (int i = 0; i < size; ++i) {
        realNodeinfo.push_back(nodeinfo[i]);
        realNodeinfo[i].push_back(i + 1);
    }
    sort(realNodeinfo.begin(), realNodeinfo.end(), comp);
    // test
    // for (int i = 0; i < realNodeinfo.size(); ++i) {
    //     for (int j = 0; j < realNodeinfo[0].size(); ++j) {
    //         cout << realNodeinfo[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    Tree* root =
        new Tree(realNodeinfo[0][0], realNodeinfo[0][1], realNodeinfo[0][2]);
    for (int i = 1; i < size; ++i) {
        root->input(realNodeinfo[i][0], realNodeinfo[i][1], realNodeinfo[i][2]);
    }
    root->preorder(root);
    root->postorder(root);
    answer.push_back(pre);
    answer.push_back(post);

    return answer;
}

int main()
{
    vector<vector<int>> ans = solution({{5, 3},
                                        {11, 5},
                                        {13, 3},
                                        {3, 5},
                                        {6, 1},
                                        {1, 3},
                                        {8, 6},
                                        {7, 2},
                                        {2, 2}});
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[0].size(); ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}