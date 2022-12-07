#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *root = NULL;
int size;

int height(Node *head)
{
    if (head == NULL)
        return 0;
    int count = 1 + height(head->left);
    count = max(count, height(head->right)+1);
    return count;
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
        cout << "2.Print the height of the tree\n";
        cout << "3.Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            create();
            break;

        case 2:
            cout << "Height of the tree is " << height(root);
            break;

        case 3:
            exit(0);

        default:
            cout << "Incorrect choice\n";
            break;
        }
    }
    return 0;
}