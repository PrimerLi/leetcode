#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : value(value), left(NULL), right(NULL){}
};

void printTree(TreeNode* root)
{
    if (root == NULL) return;
    cout << root->value << endl;
    printTree(root->left);
    printTree(root->right);
}

void printTreeByLevel(TreeNode* root, int level)
{
    if (root == NULL) return;
    if (level == 0)
    {
        cout << root->value << "  ";
    }
    else
    {
        printTreeByLevel(root->left, level - 1);
        printTreeByLevel(root->right, level - 1);
    }
}

int getTotalLevel(TreeNode* root)
{
    if (root == NULL) return 0;
    return 1 + max(getTotalLevel(root->left), getTotalLevel(root->right));
}

vector<int> getLevel(TreeNode* root, int level)
{
    vector<int> result;
    if (root == NULL) return result;
    if (level == 0)
    {
        result.push_back(root->value);
        return result;
    }
    else
    {
        vector<int> leftResult = getLevel(root->left, level-1);
        vector<int> rightResult = getLevel(root->right, level-1);
        for (int i = 0; i < leftResult.size(); ++i)
        {
            result.push_back(leftResult[i]);
        }
        for (int i = 0; i < rightResult.size(); ++i)
        {
            result.push_back(rightResult[i]);
        }
        return result;
    }
}

vector< vector<int> > getAllByLevel(TreeNode* root)
{
    int totalNumberOfLevels = getTotalLevel(root);
    cout << "Total number of levels = " << totalNumberOfLevels << endl;
    vector< vector<int> > result;
    for (int i = 0; i < totalNumberOfLevels; ++i)
    {
        vector<int> temp = getLevel(root, i);
        result.push_back(temp);
    }
    return result;
}

bool isSymmetric(TreeNode* left, TreeNode* right)
{
    if (left == NULL && right == NULL) return true;
    if (left != NULL && right == NULL) return false;
    if (left == NULL && right != NULL) return false;
    return ((left->value == right->value) && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left));
}

bool isSymmetric(TreeNode* root)
{
    if (root == NULL) return true;
    return isSymmetric(root->left, root->right);
}

void printVector(vector<int> myVector)
{
    for (int i = 0; i < myVector.size(); ++i)
    {
        cout << myVector[i] << ", ";
    }
    cout << endl;
}

int getMaxDepth(TreeNode * root)
{
    if (root == NULL) return 0;
    return 1 + max(getMaxDepth(root->left), getMaxDepth(root->right));
}

int getMinDepth(TreeNode * root)
{
    if (root == NULL) return 0;
    return 1 + min(getMinDepth(root->left), getMinDepth(root->right));
}


int main()
{
    TreeNode* root;
    root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    /*root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right= new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(3);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(6);
    root->left->left->left = new TreeNode(123);*/
    int totalLevels = getTotalLevel(root);
    printTree(root);
    cout << "Total levels of tree: " << totalLevels << endl;
    int maxDepth = getMaxDepth(root);
    cout << "maxDepth = " << maxDepth << endl;
    int minDepth = getMinDepth(root);
    cout << "minDepth = " << minDepth << endl;
    for (int i = 0; i < totalLevels; ++i)
    {
        cout << "Level = " << i << ": ";
        printTreeByLevel(root, i);
        cout << endl;
    }
    vector< vector<int> > result = getAllByLevel(root);
    for (int i = 0; i < result.size(); ++i)
    {
        printVector(result[i]);
    }
    if(isSymmetric(root))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
