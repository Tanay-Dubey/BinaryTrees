// Program to find path of a node from the root

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

bool findPath(Node *head, int value)  //To find the path
{
    if (head == NULL)  //If null node then return false
        return false;

    if (head->data == value)  //If node data is equal to value then print data and return true
    {
        cout << head->data << " ";
        return true;
    }

    if (findPath(head->left, value) || findPath(head->right, value))  //If either of the two branches return true then print the data
    {
        cout << head->data << " ";
    }
}

void printPath()
{
    int n;
    cout << "Enter a node\n";
    cin >> n;
    cout << "The path to the given node is: ";
    findPath(root, n);
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
        cout << "2.Print the path from root to the node\n";
        cout << "3.Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            create();
            break;

        case 2:
        {
            printPath();
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