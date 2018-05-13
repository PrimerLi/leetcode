#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        TreeNode * it = root;
        while(it->val != key)
        {
            if (key < it->val) it = it->left;
            else it = it->right;
        }
        //cout << it->val << endl;
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode * temp = s.top();
            //cout << temp->val << endl;
            if (temp->val == key) break;
            s.pop();
            if (temp->right) s.push(temp->right);
            if (temp->left) s.push(temp->left);
        }
        TreeNode * target = s.top();
        s.pop();
        TreeNode * parent = s.top();
        //cout << target->val << endl;
        //cout << parent->val << endl;
        bool isLeft = true;
        if (parent->right == target) isLeft = false;
        if (isLeft)
        {
            //cout << "left" << endl;
            if (target->left == NULL && target->right == NULL)
            {
                cout<< "Double null. " << endl;
                parent->left = NULL;
                return root;
            }
            else if (target->left == NULL && target->right != NULL)
            {
                cout << "left null." << endl;
                parent->left = target->right;
            }
            else if (target->left != NULL && target->right == NULL)
            {
                cout << "right null " << endl;
                parent->left = target->left;
            }
            else
            {
                cout << "None null. " << endl;
                parent->left = target->left;
                parent->left->right = target->right;
            }
        }
        else
        {
            cout << "right" << endl;
            if (target->left == NULL && target->right == NULL)
            {
                parent->right = NULL;
            }
            else if (target->left != NULL && target->right == NULL)
            {
                parent->right = target->left;
            }
            else if (target->left == NULL && target->right != NULL)
            {
                parent->right = target->right;
            }
            else
            {
                parent->right = target->right;
                parent->right->left = target->left;
            }
        }
        return root;
    }
};

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
        vector<int> leftResult = getByLevel(root->left, level-1);
        vector<int> rightResult = getByLevel(root->right, level-1);
        result.insert(result.end(), leftResult.begin(), leftResult.end());
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

int main()
{
    TreeNode * root = new TreeNode(0);
    root->left = new TreeNode(-1);
    root->right = new TreeNode(2);
    Solution s;
    root = s.deleteNode(root, -1);
    //cout << root->left->val << endl;
    //cout << getDepth(root) << endl;
    printVector(getByLevel(root, 0));
    printVector(getByLevel(root, 1));
    return 0;
}