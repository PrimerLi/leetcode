#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left, * right;
    TreeNode(int value) : val(value), left(NULL), right(NULL){}
};

TreeNode * addToBST(TreeNode * root, int value)
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
    int size = numbers.size();
    if (size == 0) return NULL;
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

vector<int> getByLevel(TreeNode * root, int level)
{
    vector<int> result;
    if (root == NULL) return result;
    if (level == 0)
    {
        result.push_back(root->val);
        return result;
    }
    else
    {
        vector<int> leftReesult = getByLevel(root->left, level-1);
        vector<int> rightResult = getByLevel(root->right, level-1);
        result.insert(result.end(), leftReesult.begin(), leftReesult.end());
        result.insert(result.end(), rightResult.begin(), rightResult.end());
        return result;
    }
}

void printVector(const vector<int> &numbers)
{
    for (int i = 0; i < numbers.size(); ++i)
    {
        cout << numbers[i] << ", ";
    }
    cout << endl;
}

void printByLevel(TreeNode * root)
{
    int h = getDepth(root);
    for (int i = 0; i < h; ++i)
    {
        cout << "Level " << i << " : ";
        printVector(getByLevel(root, i));
    }
}

vector<int> inorder(TreeNode * root)
{
    vector<int> result;
    if (root == NULL) return result;
    vector<int> leftResult = inorder(root->left);
    vector<int> rightResult = inorder(root->right);
    result.insert(result.end(), leftResult.begin(), leftResult.end());
    result.push_back(root->val);
    result.insert(result.end(), rightResult.begin(), rightResult.end());
    return result;
}

bool isSorted(const vector<int> &numbers)
{
    for (int i = 0; i < numbers.size()-1; ++i)
    {
        if(numbers[i] > numbers[i+1]) return false;
    }
    return true;
}

bool isBST(TreeNode * root)
{
    return isSorted(inorder(root));
}

int findMin(TreeNode * root)
{
    if (root == NULL) return 0;
    TreeNode * it = root;
    while(it->left != NULL)
    {
        it = it->left;
    }
    return it->val;
}

TreeNode * deleteNode(TreeNode * root, int value)
{
    if (root == NULL) return NULL;
    if (root->val == value)
    {
        if (root->right != NULL)
        {
            root->val = findMin(root->right);
            root->right = deleteNode(root->right, root->val);
            return root;
        }
        else
        {
            root = root->left;
            return root;
        }
    }
    else if (value < root->val)
    {
        root->left = deleteNode(root->left, value);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, value);
        return root;
    }
}

int sumOfNodes(TreeNode * root)
{
    if (root == NULL) return 0;
    return root->val + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int rob(TreeNode * root)
{
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->val;
    if (root->left != NULL && root->right != NULL)
    {
        TreeNode * left = root->left;
        TreeNode * right = root->right;
        return max(root->val + rob(left->left) + rob(left->right) + rob(right->left) + rob(right->right), rob(left) + rob(right));
    }
    else if (root->left != NULL)
    {
        TreeNode * left = root->left;
        return max(root->val + rob(left->left) + rob(left->right), rob(left));
    }
    else
    {
        TreeNode * right = root->right;
        return max(root->val + rob(right->left) + rob(right->right), rob(right));
    }
}

int main()
{
    vector<int> numbers;
    int len = 5;
    for (int i = 0; i < len; ++i)
    {
        //numbers.push_back(rand()%(12*len));
        numbers.push_back(i+1);
    }
    printVector(numbers);
    TreeNode * root = createBST(numbers);
    printByLevel(root);
    cout << rob(root) << endl;
    return 0;
}
