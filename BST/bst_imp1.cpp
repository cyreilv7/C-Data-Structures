#include <iostream>
using namespace std;
#include <cstdlib> // exit()

// typedef struct BstNode;
struct BstNode
{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* createNewNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    return newNode;
}

// recursive insert
void insert(BstNode** root, int x)
{
    if (*root == NULL)
    {
        BstNode* newNode = createNewNode(x);
        *root = newNode;
    }
    else if ((*root)->data <= x)
        insert(&(*root)->right, x);
    else
        insert(&(*root)->left, x);
    return;
}

bool search(BstNode** root, int target)
{
    if (*root == NULL) return false;
    else if ((*root)->data == target) return true;
    else if ((*root)->data < target) return search(&(*root)->right, target);
    else return search(&(*root)->left, target);
}

int findMax(BstNode** root) 
{
    if (root == NULL) exit(0); // if tree is empty
    if ((*root)->right == NULL) return (*root)->data;
    int max = findMax(&(*root)->right);
    return max;
}

int findMin(BstNode** root) 
{
    if (root == NULL) exit(0); // if tree is empty
    if ((*root)->left == NULL) return (*root)->data;
    return findMax(&(*root)->left);
}

int findHeight(BstNode** root)
{
    if (*root == NULL) return -1;
    int leftHeight = findHeight(&(*root)->left);
    int rightHeight = findHeight(&(*root)->right);
    return max(leftHeight, rightHeight) + 1;
}

// TODO: iterative insert


int main()
{
    BstNode* root = NULL;
    insert(&root, 5);
    insert(&root, 10);
    insert(&root, 20);
    cout << root->data << endl; // expected: 5
    cout << root->right->data << endl; // expected: 10
    cout << root->right->right->data << endl; // expected: 20

    // testing search()
    search(&root, 20) ? cout << "Found!" << endl : cout << "Not found." << endl; // expected: found

    // testing findMax()
    insert(&root, 100);
    cout << findMax(&root) << endl; // expected: 100

    // testing findMin()
    cout << findMin(&root) << endl; // expected: root value (i.e., 5)
    insert(&root, -1); 
    cout << findMin(&root) << endl; // expected: -20

    cout << findHeight(&root) << endl; // expected: 3

    return 0;
}
