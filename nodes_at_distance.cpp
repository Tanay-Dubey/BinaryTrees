// Program to find all the nodes at a distance k from a target node

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

void storeParents(Node *head, unordered_map<Node *, Node *> &parentHash, int value, Node* &temp)
{
    queue<Node *> q;  //To store level order traversal
    q.push(head);
    while (!q.empty())
    {
        head = q.front();
        if (head->data == value)
        {
            temp = head;
        }
        if (head->left != NULL)
        {
            q.push(head->left);
            parentHash[head->left] = head;
        }
        if (head->right != NULL)
        {
            q.push(head->right);
            parentHash[head->right] = head;
        }
        q.pop();
    }
}

void getAns()
{
    unordered_map<Node *, Node *> parentHash; // HashMap to store node along with their corresponding parents
    queue<Node *> q;                          // Queue to store nodes as we traverse them
    unordered_map<Node *, bool> visited;      // Map to store nodes when they are visited

    int n, k;
    cout << "Enter the target node\n";
    cin >> n;
    cout << "Enter the distance\n";
    cin >> k;
    Node *head;  //To get the target node
    storeParents(root, parentHash, n, head);

    q.push(head);
    visited[head]=true;
    int curr_distance = 0;  //To count the number of times the loop should execute till it becomes equal to the distance
    while (curr_distance < k)
    {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            head = q.front();
            if (head->left != NULL && !visited[head->left])
            {
                q.push(head->left);
                visited[head->left] = true;
            }
            if (head->right != NULL && !visited[head->right])
            {
                q.push(head->right);
                visited[head->right] = true;
            }
            if (parentHash[head] && !visited[parentHash[head]])
            {
                q.push(parentHash[head]);
                visited[parentHash[head]] = true;
            }
            q.pop();
        }
        curr_distance++;
    }
    while (!q.empty())
    {
        cout << q.front()->data << " ";
        q.pop();
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
        cout << "2.Print the nodes at a distance k from target node\n";
        cout << "3.Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            create();
            break;

        case 2:
        {
            getAns();
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