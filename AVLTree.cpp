#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int max(int a, int b)
{
    return (a>b)? a:b;
}

int get_height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
   return root->height;
}

int balancefactor(Node *root)
{
    if(root == NULL){
        return 0;
    }
    return get_height(root->left) - get_height(root->right);
}

Node *rightrotation(Node *x)
{
    Node *y = x->left;
    Node *z = y->right;

    y->right = x;
    x->left = z;

    x->height = max(get_height(x->left),get_height(x->right))+1;
    y->height = max(get_height(y->left),get_height(y->right))+1;
    return y;
}

Node *leftrotation(Node *y)
{
    Node *x = y->right;
    Node *z = x->left;

    x->left = y;
    y->right = z;

    x->height = max(get_height(x->left),get_height(x->right))+1;
    y->height = max(get_height(y->left),get_height(y->right))+1;
    return x;
}

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    if (root->data > val)
    {
        root -> left = insert(root->left, val);
    }
    else if (root->data < val)
    {
        root -> right =  insert(root->right, val);
    }

    root->height = max(get_height(root->left),get_height(root->right))+1;
    int bf = balancefactor(root);
    if (bf > 1 && val < root->left->data){
       return rightrotation(root);
    }
    if (bf < -1 && val > root->right->data){
        return leftrotation(root);
    }
    if (bf > 1 && val > root->left->data){
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
    if (bf < -1 && val < root->left->data){
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }

        return root;
}

void preord(Node *root)
{
    if (root != NULL)
    {
         cout << root->data << " ";
        preord(root->left);
       
        preord(root->right);
    }
}

void inord(Node* root){
    if(root!=NULL){
        inord(root->left);
        cout<<root->data<<" ";
        inord(root->right);
    }
}

int main()
{

    int arr[] = {2, 4, 6, 9, 7, 11, 5, 13, 21, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = NULL;
    root = insert(root, 13);
    for(int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    // root = insert(root, 3);
    // root = insert(root, 2);
    // root = insert(root, 5);
    // root = insert(root, 9);
    // root = insert(root, 1);
    // root = insert(root, 4);

    preord(root);
    cout << endl;
    cout << get_height(root);
    return 0;
}