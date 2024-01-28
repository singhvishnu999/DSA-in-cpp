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
    void preord(Node *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            preord(root->left);
            preord(root->right);
        }
    }
    void inord(Node *root)
    {
        if (root != NULL)
        {
            inord(root->left);
            cout << root->data << " ";
            inord(root->right);
        }
    }
    void postord( Node* root){
       
        if(root!= NULL){
            postord(root->left);
            postord(root->right);
            cout<<root->data<<" ";
        }
    }
};

Node *create(int arr[])
{
    static int idx = -1;
    idx++;
    if (arr[idx] == -1)
    {
        return NULL;
    }
    Node *new_node = new Node{arr[idx]};
    new_node->left = create(arr);
    new_node->right = create(arr);
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
        root->left = insert(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = insert(root->right, val);
    }

    return root;
}
Node *Inordpredeccessor(Node *root)
{

    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Node *Delete(Node *root, int val)
{
    if(root == NULL){
        return NULL;
    }
    if (root->data > val)
    {
        root->left = Delete(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = Delete(root->right, val);
    }
    else
    {
        // case : 1 child node
        if (root->left == NULL && root->right == NULL)
        {
            delete (root);
            return NULL;
        }
        // case : 2 having on child
        if (root->left == NULL)
        {
            delete root;
            return root->right;
        }
        else if (root->right == NULL)
        {
            delete root;
            return root->left;
        }
        // case : 3 root node
        else
        {
            Node *ipre = Inordpredeccessor(root);
            root->data = ipre->data;
            root->left = Delete(root->left, ipre->data);
        }
    }
    return root;
}


Node *createBsorted(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    root->left = createBsorted(arr, start, mid - 1);
    root->right = createBsorted(arr, mid + 1, end);
    return root;
}

bool isBST(Node *root)
{
    static Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && prev->data >= root->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

Node *search(Node *root, int key)
{
    if (root != NULL)
    {
        if (root->data == key)
        {
            cout << root->data<<" is found"<<endl;
            return root;
        }
        else if (root->data > key)
        {
            search(root->left, key);
        }
        else
        {
            search(root->right, key);
        }
    }

}

int main()
{
    int arr[] = {4, 2, 1, -1, -1, 3, -1, -1, 6, 5, -1, -1, 7, -1, -1};
    Node *root = create(arr);
    int arr1[] = {2, 4, 6, 8, 9, 11, 14, 16, 17, 19};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    Node* root2 = createBsorted(arr1, 0,n-1);
    
    root2->inord(root2);
   
    // root->preord(root);
    insert(root2,12);
    cout << endl<<"12 is inserted"<<endl;
    root2->inord(root2);
    cout << endl;

    Delete(root2,17);
    cout<<"17 is deleted"<<endl;
    root2->inord(root2);
    if (isBST(root2))
    {
        cout << "ye BST hai" << endl;
    }
    else{

        cout << "ye BST nahi hai"<<endl;
    }
cout<<endl;
    search(root2, 4);

    // root2->inord(root2);

    return 0;
}