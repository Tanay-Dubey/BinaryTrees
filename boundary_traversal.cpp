//Program to find boundary traversal of a binary tree

#include <bits/stdc++.h>
using namespace std;

struct Node  //A structure data type to resemble a node in a binary tree
{
    int data;
    Node *left;
    Node *right;
};

Node *root = NULL;
int size;

void leftTraversal(Node *head)  //To traverse the left boundary of the tree
{
    if(head->left==NULL && head->right==NULL)  //To skip the leaf nodes
        return;
    cout<<head->data<<" ";  //To print the data as we go down the left boundary
    if (head->left==NULL)
        leftTraversal(head->right);  //If no left branch only then go to right branch
    else
        leftTraversal(head->left);  //Otherwise always go to right branch
}

void leafTraversal(Node *head)  //To traverse the bottom boundary of the tree
{
    if(head->left==NULL && head->right==NULL)  //If leaf nodes only then print the data
    {
        cout<<head->data<<" ";
        return;
    }
    leafTraversal(head->left);
    leafTraversal(head->right);
    
}

void rightTraversal(Node *head)  //To traverse the right boundary of the tree
{
    if(head->left==NULL && head->right==NULL)  //To skip the leaf nodes
    {
        return;
    }
    if(head->right==NULL)  //If no right branch only then go to left branch
    rightTraversal(head->left);
    else 
    rightTraversal(head->right);
    cout<<head->data<<" ";  //To print the data as we go up the right boundary via the return statement
}

void boundaryTraversal()
{
    leftTraversal(root);  //First traverse the left boundary
    leafTraversal(root);  //Then traverse the bottom boundary
    rightTraversal(root);  //Then traverse the right boundary
}

Node *appendNode(Node *head, int value)
{
    if (head == NULL)
    {
        head = new Node;
        head->data = value;
        head->left = NULL;
        head->right = NULL;
        return head;
    }

    if (value < head->data)
    {
        head->left = appendNode(head->left, value);
    }
    else if (value >= head->data)
    {
        head->right = appendNode(head->right, value);
    }
}

void create()
{
    int n;
    cout << "Enter the number of nodes\n";
    cin >> n;
    size = n;
    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Enter the data inside the node\n";
        cin >> value;
        root = appendNode(root, value);
    }
}

int main()
{
    while (true)
    {
        int n;
        cout << "\n1.Create a binary search tree\n";
        cout << "2.Print the boundary traversal of the tree\n";
        cout << "3.Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            create();
            break;

        case 2:
        {
            boundaryTraversal();
            break;
        }

        case 3:
            exit(0);

        default:
            cout << "Incorrect choice\n";
            break;
        }
    }
    return 0;
}