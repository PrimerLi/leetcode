#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node
{
    int value;
    Node * left;
    Node * right;
    Node(int vl) : value(vl), left(NULL), right(NULL) {}
};

Node * bst(Node * root, int value)
{
    if (root == NULL)
    {
        root = new Node(value);
        return root;
    }
    else
    {
        if (value < root->value)
        {
            root->left = bst(root->left, value);
        }
        else
        {
            root->right = bst(root->right, value);
        }
        return root;
    }
}

vector<int> getByLevel(Node * root, int level)
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
        vector<int> resultLeft = getByLevel(root->left, level-1);
        vector<int> resultRight = getByLevel(root->right, level-1);
        for (int i = 0; i < resultLeft.size(); ++i)
        {
            result.push_back(resultLeft[i]);
        }
        for (int i = 0; i < resultRight.size(); ++i)
        {
            result.push_back(resultRight[i]);
        }
        return result;
    }
}

void printVector(const vector<int> &myVector)
{
    for (int i = 0; i < myVector.size(); ++i)
        cout << myVector[i] << ", ";
    cout << endl;
}

int getMaxDepth(Node * root)
{
    if (root == NULL) return 0;
    return 1 + max(getMaxDepth(root->left), getMaxDepth(root->right));
}

int getMinDepth(Node * root)
{
    if (root == NULL) return 0;
    return 1 + min(getMinDepth(root->left), getMinDepth(root->right));
}

void printByLevel(Node * root)
{
    int depth = getMaxDepth(root);
    for (int i = 0; i < depth; ++i)
    {
        vector<int> result = getByLevel(root, i);
        cout << "Level " << i << ": ";
        printVector(result);
    }
}

void printDFS(Node * root)
{
    if (root == NULL) return;
    printDFS(root->left);
    cout << root->value << endl;
    printDFS(root->right);
}

void printInOrder(Node * root)
{
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->value << ", ";
    printInOrder(root->right);
}

void printPreOrder(Node * root)
{
    if (root == NULL) return;
    cout << root->value << ", ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(Node * root)
{
    if (root == NULL) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->value << ", ";
}

Node * createBST(const vector<int> &myVector)
{
    Node * root = NULL;
    if (myVector.size() == 0) return NULL;
    for (int i = 0; i < myVector.size(); ++i)
    {
        root = bst(root, myVector[i]);
    }
    return root;
}

vector<int> DFS(Node * root)
{
    vector<int> result;
    if (root == NULL) return result;
    vector<int> resultLeft = DFS(root->left);
    vector<int> resultRight = DFS(root->right);
    for (int i = 0; i < resultLeft.size(); ++i)
    {
        result.push_back(resultLeft[i]);
    }
    result.push_back(root->value);
    for (int i = 0; i < resultRight.size(); ++i)
    {
        result.push_back(resultRight[i]);
    }
    return result;
}

vector<int> preorderTraversal(Node * root)
{
    vector<int> result;
    if (root == NULL) return result;
    stack<Node *> myStack;
    Node * p = root;
    myStack.push(p);
    while(!myStack.empty())
    {
        p = myStack.top();
        myStack.pop();
        result.push_back(p->value);
        if (p->right != NULL) myStack.push(p->right);
        if (p->left != NULL) myStack.push(p->left);
    }
    return result;
}

vector<int> preorderTraversalRecursive(Node * root)
{
    vector<int> result;
    if (root == NULL) return result;
    result.push_back(root->value);
    vector<int> leftResult = preorderTraversalRecursive(root->left);
    vector<int> rightResult = preorderTraversalRecursive(root->right);
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

vector<int> inorderTraversal(Node * root)
{
    vector<int> result;
    Node * p = root;
    stack<Node *> myStack;
    while(!myStack.empty() || p != NULL)
    {
        if (p != NULL)
        {
            myStack.push(p);
            p = p->left;
        }
        else
        {
            p = myStack.top();
            myStack.pop();
            result.push_back(p->value);
            p = p->right;
        }
    }
    return result;
}

vector<int> inorderTraversalRecursive(Node * root)
{
    vector<int> result;
    if (root == NULL) return result;
    vector<int> leftResult = inorderTraversalRecursive(root->left);
    vector<int> rightResult = inorderTraversalRecursive(root->right);
    for (int i = 0; i < leftResult.size(); ++i)
    {
        result.push_back(leftResult[i]);
    }
    result.push_back(root->value);
    for (int i = 0; i < rightResult.size(); ++i)
    {
        result.push_back(rightResult[i]);
    }
    return result;
}

vector<int> postorderTraversal(Node * root)
{
    vector<int> result;
    if (root == NULL) return result;
    Node * p, *q;
    p = root;
    stack<Node *> myStack;
    do{
        while(p != NULL)
        {
            myStack.push(p);
            p = p->left;
        }
        q = NULL;
        while(!myStack.empty())
        {
            p = myStack.top();
            myStack.pop();
            if (p->right == q)
            {
                result.push_back(p->value);
                q = p;
            }
            else
            {
                myStack.push(p);
                p = p->right;
                break;
            }
        }
    }while(!myStack.empty());
    return result;
}

bool isBalanced(Node * root)
{
    if (root == NULL) return true;
    int leftDepth = getMaxDepth(root->left);
    int rightDepth = getMaxDepth(root->right);
    return (abs(leftDepth - rightDepth) <= 1 && isBalanced(root->left) && isBalanced(root->right));
}

bool isIdentical(Node * root1, Node * root2)
{
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL && root2 != NULL) return false;
    if (root1 != NULL && root2 == NULL) return false;
    return (root1->value == root2->value)&&isIdentical(root1->left, root2->left)&&isIdentical(root1->right, root2->right);
}

bool isBST(Node * root, int lower, int upper)
{
    if (root == NULL) return true;
    //if (root->left == NULL && root->right == NULL) return true;
    return (root->value < upper && root->value > lower)&&(isBST(root->left, lower, root->value))&&(isBST(root->right, root->value, upper));
}

bool isBST(Node * root)
{
    return isBST(root, INT_MIN, INT_MAX);
}

vector< vector<int> > insertIntoVector(const vector<int> &myVector, int value)
{
    vector<vector<int> > result;
    if (myVector.size() == 0)
    {
        vector<int> element(value, 1);
        result.push_back(element);
        return result;
    }
    for (int i = 0; i <= myVector.size(); ++i)
    {
        vector<int> temp(myVector.begin(), myVector.end());
        temp.insert(temp.begin()+i, value);
        result.push_back(temp);
    }
    return result;
}

vector<vector<int> > getPermutations(const vector<int> &myVector)
{
    vector< vector<int> > result;
    if (myVector.size() == 0) return result;
    if (myVector.size() == 1)
    {
        result.push_back(myVector);
        return result;
    }
    vector<int> tail(myVector.begin()+1, myVector.end());
    vector< vector<int> > previous = getPermutations(tail);
    for (int i = 0; i < previous.size(); ++i)
    {
        vector<vector<int> > temp = insertIntoVector(previous[i], myVector[0]);
        for (int j = 0; j < temp.size(); ++j)
        {
            result.push_back(temp[j]);
        }
    }
    return result;
}

void addToSet(vector<Node *> &myVector, Node * root)
{
    if (myVector.size() == 0)
        myVector.push_back(root);
    else
    {
        for (int i = 0; i < myVector.size(); ++i)
        {
            if (isIdentical(myVector[i], root)) return;
        }
        myVector.push_back(root);
    }
}

vector<Node *> generateTrees(int n)
{
    vector<int> myVector;
    for (int i = 0; i < n; ++i)
    {
        myVector.push_back(i+1);
    }
    vector<Node *> result;
    vector< vector<int> > permutations = getPermutations(myVector);
    for (int i = 0; i < permutations.size(); ++i)
    {
        Node * root = createBST(permutations[i]);
        addToSet(result, root);
    }
    return result;
}

int numTrees(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 1;
    int *g = new int [n+1];
    g[0] = 1;
    g[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        int s = 0;
        for (int j = 1; j <= i; ++j)
        {
            s = s + g[j-1]*g[i-j];
        }
        g[i] = s;
    }
    for (int i = 0; i < n+1; ++i)
        cout << "i = " << i << ", " << g[i] << endl;
    return g[n];
}

Node * flatten(Node * root, Node * tail)
{
    if (root == NULL) return tail;
    root->right = flatten(root->left, flatten(root->right, tail));
    root->left = NULL;
    return root;
}

void flatten(Node * root)
{
    flatten(root, nullptr);
}

Node * sortedArrayToBST(const vector<int> &myVector)
{
    Node * root = NULL;
    if (myVector.size() == 0) return root;
    if (myVector.size() == 1)
    {
        root = new Node(myVector[0]);
    }
    int size = myVector.size();
    int mid_index = size/2;
    root = new Node(myVector[mid_index]);
    vector<int> leftVector(myVector.begin(), myVector.begin() + mid_index);
    vector<int> rightVector(myVector.begin() + mid_index + 1, myVector.end());
    root->left = sortedArrayToBST(leftVector);
    root->right = sortedArrayToBST(rightVector);
    return root;
}

int minDepth(Node * root)
{
    if (root == NULL) return 0;
    if (root->left == NULL) return 1 + minDepth(root->right);
    if (root->right == NULL) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int maxDepth(Node * root)
{
    if (root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

bool hasPathSum(Node * root, int sum)
{
    if (root == NULL) return false;
    int diff = sum - root->value;
    if (root->left == NULL && root->right == NULL) return (root->value == sum);
    if (root->left == NULL) return hasPathSum(root->right, diff);
    if (root->right == NULL) return hasPathSum(root->left, diff);
    return hasPathSum(root->left, diff) || hasPathSum(root->right, diff);
}

vector<vector<int> > pathSum(Node * root, int sum)
{
    vector<vector<int> > result;
    if (root == NULL) return result;
    if (root->left == NULL && root->right == NULL)
    {
        if (root->value == sum)
        {
            vector<int> temp;
            temp.push_back(root->value);
            result.push_back(temp);
            return result;
        }
        else
            return result;
    }
    int diff = sum - root->value;
    vector<vector<int> > leftResult = pathSum(root->left, diff);
    vector<vector<int> > rightResult = pathSum(root->right, diff);
    for (int i = 0; i < leftResult.size(); ++i)
    {
        leftResult[i].insert(leftResult[i].begin(), root->value);
        result.push_back(leftResult[i]);
    }
    for (int i = 0; i < rightResult.size(); ++i)
    {
        rightResult[i].insert(rightResult[i].begin(), root->value);
        result.push_back(rightResult[i]);
    }
    return result;
}

int numOfPaths(Node * root)
{
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    //if (root->left == NULL) return numOfPaths(root->right);
    //if (root->right == NULL) return numOfPaths(root->left);
    return numOfPaths(root->left) + numOfPaths(root->right);
}

vector<vector<int> > paths(Node * root)
{
    vector<vector<int> > result;
    if (root == NULL) return result;
    if (root->left == NULL && root->right == NULL)
    {
        vector<int> temp;
        temp.push_back(root->value);
        result.push_back(temp);
        return result;
    }
    vector<vector<int> > leftResult = paths(root->left);
    vector<vector<int> > rightResult = paths(root->right);
    for (int i = 0; i < leftResult.size(); ++i)
    {
        leftResult[i].insert(leftResult[i].begin(), root->value);
        result.push_back(leftResult[i]);
    }
    for (int i = 0; i < rightResult.size(); ++i)
    {
        rightResult[i].insert(rightResult[i].begin(), root->value);
        result.push_back(rightResult[i]);
    }
    return result;
}

int sumOfVector(const vector<int> &myVector)
{
    int s = 0;
    for (int i = 0; i < myVector.size(); ++i)
    {
        s = s + myVector[i];
    }
    return s;
}

struct data
{
    int sum;
    int index;
    data(int s, int i) : sum(s), index(i) {}
};

vector<int> maxFromRoot(Node * root)
{
    vector<vector<int> > allPaths = paths(root);
    data maxResult(0, 0);
    for (int i = 0; i < allPaths.size(); ++i)
    {
        int sum = sumOfVector(allPaths[i]);
        if (sum > maxResult.sum)
        {
            maxResult.sum = sum;
            maxResult.index = i;
        }
    }
    return allPaths[maxResult.index];
}

int maxPathSumFromRoot(Node * root)
{
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->value;
    int leftMax = maxPathSumFromRoot(root->left);
    int rightMax = maxPathSumFromRoot(root->right);
    return max(root->value + leftMax, root->value + rightMax);
}

int maxPathSumWithRoot(Node * root)
{
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->value;
    int leftMax = maxPathSumFromRoot(root->left);
    int rightMax = maxPathSumFromRoot(root->right);
    int maxWithRoot = leftMax + root->value + rightMax;
    return maxWithRoot;
}

int maxPathSum(Node * root)
{
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->value;
    int maxWithRoot = maxPathSumWithRoot(root);
    int maxWithLeftRoot = maxPathSumWithRoot(root->left);
    int maxWithRightRoot = maxPathSumWithRoot(root->right);
    int result = maxWithRoot;
    result = max(result, maxWithLeftRoot);
    result = max(result, maxWithRightRoot);
    return result;
}

struct TreeLinkNode
{
    int val;
    TreeLinkNode * left, *right, *next;
    TreeLinkNode(int value) : val(value), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode * root, TreeLinkNode * sibling)
{
    if (root == NULL) return;
    root->next = sibling;
    if (sibling == NULL)
    {
        connect(root->left, root->right);
        connect(root->right, NULL);
    }
    else
    {
        connect(root->left, root->right);
        connect(root->right, sibling->left);
    }
}

void connect(TreeLinkNode * root)
{
    connect(root, NULL);
}

int power(int a, int n)
{
    int p = 1;
    for (int i = 0; i < n; ++i)
        p = p*a;
    return p;
}

int convertToNumber(const vector<int> &myVector)
{
    int s = 0;
    int size = myVector.size();
    for (int i = 0; i < size; ++i)
    {
        s = s + myVector[i]*power(10, size-i-1);
    }
    return s;
}

int sumNumbers(Node * root)
{
    if (root == NULL) return 0;
    vector<vector<int> > result = paths(root);
    int sum = 0;
    for (int i = 0; i < result.size(); ++i)
    {
        int s = convertToNumber(result[i]);
        sum = sum + s;
    }
    return sum;
}

string tree2str(Node * root)
{
    if (root == NULL) return "()";
    if (root->left == NULL && root->right == NULL)
        return to_string(root->value);
    string result = to_string(root->value);
    string leftResult = tree2str(root->left);
    string rightResult = tree2str(root->right);
    if (root->right == NULL)
        result = result + "(" + leftResult + ")";
    else
        result = result + "(" + leftResult + rightResult + ")";
    return result;
}

int findBottomLeftValue(Node * root)
{
    int maxDepth = getMaxDepth(root);
    vector<int> result = getByLevel(root, maxDepth-1);
    return result[0];
}

int maxLengthFromRoot(Node * root)
{
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    int leftLength = getMaxDepth(root->left);
    int rightLength = getMaxDepth(root->right);
    return 1 + leftLength + rightLength;
}

int diameterOfBinaryTree(Node * root)
{
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    int lengthWithRoot = maxLengthFromRoot(root);
    int leftLength = maxLengthFromRoot(root->left);
    int rightLength = maxLengthFromRoot(root->right);
    int result = lengthWithRoot;
    result = max(result, leftLength);
    result = max(result, rightLength);
    return result;
}

void find(Node * root, unordered_map<int, int> &map)
{
    if (root == nullptr) return;
    stack<Node *> s;
    Node * p = root;
    s.push(p);
    while(!s.empty())
    {
        p = s.top();
        s.pop();
        map[p->value]++;
        if (p->left != nullptr) s.push(p->left);
        if (p->right != NULL) s.push(p->right);
    }
    unordered_map<int, int>:: iterator it;
    for (it = map.begin(); it != map.end(); ++it)
    {
        cout << it->first << "  " << it->second << endl;
    }
}

vector<int> findMode(Node * root)
{
    vector<int> result;
    if (root == NULL) return result;
    unordered_map<int, int> map;
    find(root, map);
    unordered_map<int, int>::iterator it = map.begin();
    int maxValue = it->second;
    for (it = map.begin(); it != map.end(); ++it)
    {
        maxValue = max(maxValue, it->second);
    }
    for (it = map.begin(); it != map.end(); ++it)
    {
        if (it->second == maxValue) result.push_back(it->first);
    }
    return result;
}

vector<int> bfs(Node * root)
{
    vector<int> result;
    queue<Node *> q;
    if (root == NULL) return result;
    q.push(root);
    while(!q.empty())
    {
        Node * temp = q.front();
        q.pop();
        result.push_back(temp->value);
        if (temp->left != NULL) q.push(temp->left);
        if (temp->right != NULL) q.push(temp->right);
    }
    return result;
}

vector<int> dfs(Node * root)
{
    vector<int> result;
    stack<Node *> s;
    if (!root) return result;
    s.push(root);
    while(!s.empty())
    {
        Node * temp = s.top();
        s.pop();
        result.push_back(temp->value);
        if (temp->right) s.push(temp->right);
        if (temp->left) s.push(temp->left);
    }
    return result;
}


int main()
{
    vector<int> numbers;
    int len = 6;
    for (int i = 0; i < len; ++i)
    {
        numbers.push_back(rand()%(4*len));
    }
    printVector(numbers);
    Node * root = createBST(numbers);
    printByLevel(root);
    printVector(postorderTraversal(root));
    return 0;
}
