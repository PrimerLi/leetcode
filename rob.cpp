#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode * left, *right;
    TreeNode(int value) : val(value), left(NULL), right(NULL) {

    }
};

TreeNode * addToBST(TreeNode *root, int value)
{
    if (root == NULL)
    {
        root = new TreeNode(value);
        return root;
    }
    else
    {
        if (value < root->val)
        {
            root->left = addToBST(root->left, value);
        }
        else
        {
            root->right = addToBST(root->right, value);
        }
        return root;
    }
}

TreeNode * createBST(const vector<int> &numbers)
{
    TreeNode * root = NULL;
    for (int i = 0; i < numbers.size(); ++i)
    {
        root = addToBST(root, numbers[i]);
    }
    return root;
}

int getDepth(TreeNode * root)
{
    if (root == NULL) return 0;
    return 1 + max(getDepth(root->left), getDepth(root->right));
}

vector<TreeNode *> getNodesByLevel(TreeNode * root, int level)
{
    vector<TreeNode *> result;
    if (root == NULL) return result;
    if (level == 1)
    {
        result.push_back(root);
        return result;
    }
    else
    {
        vector<TreeNode *> leftResult = getNodesByLevel(root->left, level-1);
        vector<TreeNode *> rightResult = getNodesByLevel(root->right, level-1);
        result.insert(result.end(), leftResult.begin(), leftResult.end());
        result.insert(result.end(), rightResult.begin(), rightResult.end());
        return result;
    }
}

int rob(TreeNode * root)
{
    if (root == NULL) return 0;
    int h = getDepth(root);
    if (h == 1) return root->val;
    if (h == 2) return max(root->val, rob(root->left) + rob(root->right));
    vector<TreeNode *> nodes = getNodesByLevel(root, 3);
    assert(nodes.size() > 0);
    int sum = 0;
    for (int i = 0; i < nodes.size(); ++i)
    {
        sum = sum + rob(nodes[i]);
    }
    return max(root->val + sum, rob(root->left) + rob(root->right));
}

void printVector(const vector<int> &numbers)
{
    for (int i = 0; i < numbers.size(); ++i)
    {
        cout << numbers[i] << "  ";
    }
    cout << endl;
}

vector<int> getByLevel(TreeNode * root, int level)
{
    vector<int> result;
    if (root == NULL) return result;
    if (level == 1)
    {
        result.push_back(root->val);
        return result;
    }
    else
    {
        vector<int> leftResult = getByLevel(root->left, level-1);
        vector<int> rightResult = getByLevel(root->right, level-1);
        result.insert(result.end(), leftResult.begin(), leftResult.end());
        result.insert(result.end(), rightResult.begin(), rightResult.end());
        return result;
    }
}

void printByLevel(TreeNode * root)
{
    int h = getDepth(root);
    cout << "Total height of tree is " << h << endl;
    for (int i = 1; i <= h; ++i)
    {
        cout << "i = " << i << ": ";
        /*vector<TreeNode *> nodes = getNodesByLevel(root, i);
        for (int j = 0; j < nodes.size(); ++j)
        {
            cout << nodes[i]->val << "  ";
        }
        cout << endl;*/
        vector<int> values = getByLevel(root, i);
        printVector(values);
    }
}

int main()
{
    int len = 10;
    int mod = len*2;
    vector<int> numbers;
    for (int i = 0; i < len; ++i)
    {
        numbers.push_back(rand()%mod);
    }
    printVector(numbers);
    TreeNode * root = createBST(numbers);
    cout << getDepth(root) << endl;
    printByLevel(root);
    cout << rob(root) << endl;
    return 0;
}
