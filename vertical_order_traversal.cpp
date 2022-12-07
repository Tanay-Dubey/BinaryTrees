// Program to find vertical order traversal of a binary tree

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

map<int, multiset<int>> m;  //Data structures to store verticals along with their values

void verticalTraversal(Node *head)  
{
    int vertical = 0, level = 0;  //Initialize vertical and level
    queue<pair<Node *, pair<int, int>>> q;  //Queue to store level order traversal along with their verticals and levels
    q.push({head, {0, 0}});
    while (!q.empty())
    {
        m[vertical].insert(head->data);  //Insert value into the map
        if (head->left != NULL)
        {
            q.push({head->left, {vertical-1, level+1}});
        }
        if (head->right != NULL)
        {
            q.push({head->right, {vertical+1, level+1}});
        }
        q.pop();
        head = q.front().first;
        vertical=q.front().second.first;
        level=q.front().second.second;
    }
}

void printTraversal()
{
    verticalTraversal(root);
    for (auto i : m)
    {
        cout<<i.first<<": ";   
        for(auto j:i.second)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
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
        cout << "2.Print the vertical order traversal of the tree\n";
        cout << "3.Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            create();
            break;

        case 2:
        {
            printTraversal();
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