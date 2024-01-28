#include <iostream>
using namespace std;
class Node
{
public:
    char data;
    Node *left;
    Node *right;

    Node(char data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    Node *insertByArr(char arr[])
    {
        static int idx = -1;
        idx++;

        if (arr[idx] == -1)
        {
            return NULL;
        }

        Node *n = new Node(arr[idx]);

        n->left = insertByArr(arr);
        n->right = insertByArr(arr);

        return n;
    }
};

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
int main()
{
    // creating a tree by character array in pre order;
    char arr[] = {'A', 'B', 'D', 'F', -1, -1, -1, 'E', -1, -1, 'C', -1, 'G', 'H', -1, -1, 'I', -1, -1};
    Node *root = root->insertByArr(arr);
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    inOrder(root);
    return 0;
}
