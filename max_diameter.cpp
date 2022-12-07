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

int diameter(Node *head, int &maxd)
{
    if (head == NULL)
        return 0;
    int lh = diameter(head->left, maxd);
    int rh = diameter(head->right, maxd);
    maxd = max(maxd, lh + rh + 1);
    return 1 + max(lh, rh);
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
        cout << "2.Print the maximum diameter of the tree\n";
        cout << "3.Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            create();
            break;

        case 2:
        {
            int value = 0;
            diameter(root, value);
            cout << "Maximum diameter of the tree is " << value;
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