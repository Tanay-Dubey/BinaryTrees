// Program to create a binary tree from the given inorder and preorder sequence

#include <bits/stdc++.h>
using namespace std;

struct Node // A structure data type to resemble a node in a binary tree
{
    int data;
    Node *left;
    Node *right;
};

Node *root = NULL;
int size;

Node *createTree(vector<int> inorder, int instart, int inend, vector<int> preorder, int prestart, int preend, map<int, int> inMap) // Function to create tree
{
    if (instart > inend || prestart > preend)
        return NULL;
    Node *head = new Node;
    head->data = preorder[prestart];
    int index = inMap[head->data];
    head->left = createTree(inorder, instart, index - 1, preorder, prestart + 1, preend, inMap);
    head->right = createTree(inorder, index + 1, inend, preorder, prestart + 2, preend, inMap);
    return head;
}

Node *getOrders() // Function to receive inorder and preorder sequences
{
    int n;
    map<int, int> inMap; // Map to store data with their indices
    cout << "Enter the number of nodes\n";
    cin >> n;
    vector<int> inorder(n), preorder(n); // Sequences to store inorder and preorder
    cout << "Enter the inorder sequence\n";
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }
    cout << "Enter the preorder sequence\n";
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }
    for (int i = 0; i < inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }
    Node *head = createTree(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1, inMap);
    return head;
}

int main()
{
    while (true)
    {
        int n;
        cout << "\n1.Create a binary tree from preorder and inorder\n";
        cout << "2.Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            root = getOrders();
            break;

        case 2:
            exit(0);

        default:
            cout << "Incorrect choice\n";
            break;
        }
    }
    return 0;
}