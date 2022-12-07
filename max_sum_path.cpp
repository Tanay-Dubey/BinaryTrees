//Program to find path in a binary tree with maximum sum.

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

int findMaxSum(Node *head, int &maxSum)  //Takes reference variable to store value permanently
{
    if (head == NULL)
        return 0;
    int lsum = findMaxSum(head->left, maxSum);//Finds the maximum sum obtained by the left subtree
    int rsum = findMaxSum(head->right, maxSum);//Finds the maximum sum obtained by the right subtree
    maxSum = max(maxSum, head->data + lsum + rsum);//Updates maxSum if a greater sum is obtained by adding root,leftsubtree and rightsubtree
    return max(lsum, rsum) + head->data; //Returns the maximum sum to the parent node
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
        cout << "2.Print the maximum sum path of the tree\n";
        cout << "3.Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            create();
            break;

        case 2:
        {
            int value = INT_MIN;
            findMaxSum(root, value);
            cout << "Maximum sum path of the tree is " << value;
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