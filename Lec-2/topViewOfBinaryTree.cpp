//! Breadth First Search (BFS)

#include <iostream>
#include <algorithm>
#include <Queue>
#include <unordered_map>
#include <climits>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *construct(int arr[], int n)
{
    queue<Node *> q;
    Node *root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;

    while (q.size() > 0 && i < n)
    {
        Node *temp = q.front();
        q.pop();

        Node *l;
        Node *r;

        if (arr[i] != INT_MIN)

            l = new Node(arr[i]);

        else
            l = NULL;

        if (arr[j] != INT_MIN && j != n)

            r = new Node(arr[j]);

        else
            r = NULL;

        temp->left = l;
        temp->right = r;

        if (l != NULL)
            q.push(l);
        if (r != NULL)
            q.push(r);

        i += 2;
        j += 2;
    }

    return root;
}

int levels(Node *root)
{
    if (root == NULL)
        return 0;
    int answer = 1 + max(levels(root->right), levels(root->left));
    return answer;
}

void displayPreOpt(Node *root, int current, int target)
{
    if (root == NULL)
        return;
    if (current == target)
    {
        cout << root->val << " ";
        return;
    }

    displayPreOpt(root->left, current + 1, target);
    displayPreOpt(root->right, current + 1, target);
}

void topView(Node *root)
{
    unordered_map<int, int> m; //* < level, root->val > --> < int , int >
    queue<pair<Node *, int>> q;
    pair<Node *, int> r;
    r.first = root;
    r.second = 0;
    q.push(r);
 

    //! Following procedure is to check and fill only those root and values which are needed

    while (q.size() > 0)
    {
        Node *temp = (q.front()).first;
        int level = (q.front()).second;
        q.pop();
        if (m.find(level) == m.end())
            m[level] = temp->val;

        if (temp->left != NULL)
        {
            pair<Node *, int> p;
            p.first = temp->left;
            p.second = level - 1;
            q.push(p);
        }

        if (temp->right != NULL)
        {
            pair<Node *, int> p;
            p.first = temp->right;
            p.second = level + 1;
            q.push(p);
        }
    }

    //! To calculate the maximum and minimum level
    int minLevel = INT_MAX;
    int maxLevel = INT_MIN;

    for (auto x : m)
    {
        int level = x.first;
        minLevel = min(minLevel, level);
        maxLevel = max(maxLevel, level);
    }

    //! To print all the values through their respective levels which are already present in our map.

    for (int i = minLevel; i <= maxLevel; i++)
        cout << m[i] << " ";
    cout << endl;

    return;
}

int main()
{
    //! construct
    int arr[] = {1, 2, 3, 4, 5, 6, INT_MIN, INT_MIN, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = construct(arr, n);

    //! Level Order Traversal
    // for (int i = 1; i <= levels(root); i++)
    // {
    //     displayPreOpt(root, 1, i);
    //     cout << endl;
    // }
    cout << endl;
    //! Calculating And printing only top view elemnts of the given binary tree
    topView(root);
    //* 4,2,1,3,6

    return 0;
}