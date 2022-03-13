// To test your understanding, implement:
// 1) insert()
// 2) search()
// 3) findHeight()
// 4) preorder()
// 5) inorder()
// 6) postorder()
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

struct Node 
{
    Node* left;
    Node* right;
    int data;
};

Node* createNewNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    return newNode;
}

Node* insert(Node* root, int data)
{
    if (root == NULL)
    {
        root = createNewNode(data);
        return root;
    }
    else if (data <= root->data) 
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root; 
}

bool search(Node* root, int target)
{
    if (root == NULL) return false;
    else if (target == root->data) return true;
    else if (target < root->data) return search(root->left, target);
    else return search(root->right, target);
}

int findHeight(Node* root)
{
    if (root == NULL) return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int findMax(Node* root)
{
    if (root == NULL)
    {
        cout << "Error: tree is empty." << endl;
        return -1;
    }
    else if (root->right == NULL) return root->data;
    return findMax(root->right);
}

int findMin(Node* root)
{
    if (root == NULL)
    {
        cout << "Error: tree is empty." << endl;
        return -1;
    }
    else if (root->left == NULL) return root->data;
    return findMin(root->left);
}

void levelOrder(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* current = q.front();
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
        cout << current->data << " ";
        q.pop();
    }
    return;
}

void preorder(Node* root) // root left right
{
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) // left root right
{
    if (root == NULL) return;
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}

void postorder(Node* root) // right left root
{
    if (root == NULL) return;
    preorder(root->left);
    preorder(root->right);
    cout << root->data << " ";
}

bool isBSTHelper(Node* root, int minValue, int maxValue)
{
    if (root == NULL) return true;
    if (root->data > minValue && root->data < maxValue
        && isBSTHelper(root->left, minValue, root->data)
        && isBSTHelper(root->right, root->data, maxValue))
    {
        return true;
    }
    else return false;
}

bool isBST(Node*root)
{
    return isBSTHelper(root, INT_MIN, INT_MAX);
}


int main()
{
    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);

    search(root, 7) ? cout << "Found" << endl : cout << "Not found" << endl;

    cout << "Height of tree: " << findHeight(root) << endl;

    cout << "Max value: " << findMax(root) << endl;

    cout << "Min value: " << findMin(root) << endl;

    cout << "Level order traversal: ";
    levelOrder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    cout << "Is a binary search tree: ";
    isBST(root) ? cout << "True" : cout << "False";
    cout << endl;
}