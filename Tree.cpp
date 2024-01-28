#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    Node *create(int data)
    {
        Node *n = new Node(data);
        n->left = NULL;
        n->right = NULL;
        return n;
    }

    Node *insertByArr(int arr[])
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
        // Node *n = new Node(7);
        // Node *n1 = n1->create(8);
        // Node *n2 = n2->create(9);
        // n-> left = n1;
        // n-> right = n2;
        // preOrder(n);

        // create a node by array in pre order
        int arr[] = {2, 3, 4, -1, -1, 45, -1, -1, 3, -1, 9, -1, -1};
       
        Node *root = root->insertByArr(arr);
        preOrder(root);
        cout << endl;
        postOrder(root);
        cout << endl;
        inOrder(root);
        return 0;
        
    }