#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode * left, * right;
    TreeNode(int value) : val(value), left(NULL), right(NULL) {}
};

void flatten(TreeNode * root)
{
    if(!root) return;
    TreeNode * left, * right;
    left = root->left; right = root->right;
    root->left = NULL;
    flatten(left);
    flatten(right);
    root->right = left;
    TreeNode * it = root;
    while(it->right != NULL)
        it = it->right;
    it->right = right;
    return;
}

int getDepth(TreeNode * root)
{
    if (!root) return 0;
    return 1 + max(getDepth(root->left), getDepth(root->right));
}

int countNodes(TreeNode * root)
{
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    flatten(root);
    cout << countNodes(root) << endl;
    cout << getDepth(root) << endl;
    return 0;
}
