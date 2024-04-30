#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 
test:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
*/
TreeNode* buildTreeByPost(vector<int>& postorder, vector<int>& inorder, int postStart, int postEnd, int inStart, int inEnd, unordered_map<int, int>& map) {
    if (postStart > postEnd || inStart > inEnd)
        return nullptr;
    
    int rootValue = postorder[postEnd];
    TreeNode* root = new TreeNode(rootValue);
    
    int rootIndex = map[rootValue];     //根节点在中序遍历中的索引
    int leftNodes = rootIndex - inStart;
    
    root->left = buildTreeByPost(postorder, inorder, postStart, postStart + leftNodes - 1, inStart, rootIndex - 1, map);
    root->right = buildTreeByPost(postorder, inorder, postStart + leftNodes, postEnd - 1, rootIndex + 1, inEnd, map);

    return root;
}

/* 
test:
7
8 6 5 7 10 9 11
5 6 7 8 9 10 11
out:

*/
TreeNode* buildTreeByPre(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int>& map) {
    if (preStart > preEnd || inStart > inEnd)
        return nullptr;
    
    TreeNode* newT = new TreeNode(preorder[preStart]);
    
    int root = map[preorder[preStart]];     //根节点在中序遍历中的索引
    newT->left = buildTreeByPre(preorder, inorder, preStart + 1, preStart + root - inStart, inStart, root - 1, map);
    newT->right = buildTreeByPre(preorder, inorder, preStart + root - inStart + 1, preEnd, root + 1, inEnd, map);
    return newT;
}


//镜像二叉树
void mirror(TreeNode* root) {
    if (!root)
        return;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

//后序遍历
void postOrder(TreeNode* root) {
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val;
    if (root->left || root->right) cout << " ";
}

//中序遍历
void inOrder(TreeNode* root) {
    if (!root)
        return;
    inOrder(root->left);
    cout << root->val;
    if (root->left || root->right) cout << " ";
    inOrder(root->right);
}

//前序遍历
void preOrder(TreeNode* root) {
    if (!root)
        return;
    cout << root->val;
    if (root->left || root->right) cout << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//层序遍历
void levelOrder(TreeNode* root) {
    if (!root)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        if (!q.empty()) cout << " ";
    }
}
int main() {
    int N;
    cin >> N;

    vector<int> order(N);
    vector<int> inorder(N);
    unordered_map<int, int> map;    //存储中序遍历的值和对应的索引

    for (int i = 0; i < N; ++i)
        cin >> order[i];
    for (int i = 0; i < N; ++i){
        cin >> inorder[i];
        map[inorder[i]] = i;
    }

    TreeNode* root = buildTreeByPre(order, inorder, 0, N - 1, 0, N - 1, map); 
    // TreeNode* root = buildTreeByPost(order, inorder, 0, N - 1, 0, N - 1, map);
    mirror(root);
    levelOrder(root);

    system("pause");
    return 0;
}