#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int x, y;
    int num;
    Node* left;
    Node* right;
};

int node_size;
vector<Node> tree;
vector<vector<int>> answer(2);
Node* snode;

bool compare(const Node &a, const Node &b) {
    if(a.y == b.y)
        return a.x < b.x;
    return a.y > b.y;
}

void makeTree(Node* root, Node* node) {
    if(root -> x > node -> x) { //왼쪽 자식
        if(root -> left == NULL) {
            root -> left = node;
            return;
        }
        makeTree(root -> left, node);
    }else {
        if(root -> right == NULL) {
            root -> right = node;
            return;
        }
        makeTree(root -> right, node);
    }
}

void preorder(Node * root) {
    answer[0].push_back(root -> num);
    if(root -> left != NULL) preorder(root -> left);
    if(root -> right != NULL) preorder(root -> right);
}

void postorder(Node * root) {
    if(root -> left != NULL) postorder(root -> left);
    if(root -> right != NULL) postorder(root -> right);
    answer[1].push_back(root -> num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    node_size = nodeinfo.size();
    
    for(int i = 0; i < node_size; i++) {
        tree.push_back({nodeinfo[i][0], nodeinfo[i][1], i + 1, NULL, NULL});
    }
    
    sort(tree.begin(), tree.end(), compare);
    
    snode = &tree[0];
    for(int i = 1; i < node_size; i++) {
        makeTree(snode, &tree[i]);
    }
    
    preorder(snode);
    postorder(snode);
    return answer;
}
