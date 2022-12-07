#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *root = NULL;
int size;

void levelorder(Node *head)
{
    queue<Node *> a;
    a.push(head);
    for (int i = 0; i < size; i++)
    {
        if (head->left != NULL)
            a.push(head->left);
        if (head->right != NULL)
            a.push(head->right);
        cout << a.front()->data << " ";
        a.pop();
        if (a.size() != 0)
            head = a.front();
    }
}

void postorder(Node *head)
{
    stack<Node *> s;
    s.push(head);
    while (head != NULL && !s.empty())
    {
        if (head != NULL)
        {
            s.push(head);
            head = head->left;
        }
        else
        {
            Node *temp = s.top()->right;
            if (temp == NULL)
            {
                temp = s.top();
                s.pop();
                cout << temp->data << " ";
                while (!s.empty() && temp == s.top()->right)
                {
                    temp = s.top();
                    s.pop();
                    cout << temp->data << " ";
                }
            }
            else
            head=temp;
        }
    }
}

void inorder(Node *head)
{
    stack<Node *> s;
    s.push(head);
    while (true)
    {
        if (head != NULL)
        {
            s.push(head);
            head = head->left;
        }
        else
        {
            if (s.empty())
                break;
            head = s.top();
            s.pop();
            cout << head->data << " ";
            head = head->right;
        }
    }
}

void preorder(Node *head)
{
    stack<Node *> s;
    s.push(head);
    for (int i = 0; i < size; i++)
    {
        head = s.top();
        s.pop();
        cout << head->data << " ";
        if (head->right != NULL)
            s.push(head->right);
        if (head->left != NULL)
            s.push(head->left);
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
        cout << "2.Print in preorder\n";
        cout << "3.Print in postorder\n";
        cout << "4.Print in inorder\n";
        cout << "5.Print in level order\n";
        cout << "6.Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            create();
            break;

        case 2:
            preorder(root);
            break;

        case 3:
            postorder(root);
            break;

        case 4:
            inorder(root);
            break;

        case 5:
            levelorder(root);
            break;

        case 6:
            exit(0);

        default:
            cout << "Incorrect choice\n";
            break;
        }
    }
    return 0;
}