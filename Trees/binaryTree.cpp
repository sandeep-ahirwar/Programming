#include <iostream>
#include <queue>
using namespace std;

class Node
{
    // structure for binary tree
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete ho chuka hai
            cout << endl;

            // queue still has some child nodes
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void buildFromLevelOrder(Node* &root){
    queue<Node*> q;
    cout<<"Enter data for root: ";
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter the left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData; 
        
        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter the right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        
        if(rightData != -1){
            temp->right  = new Node(rightData);
            q.push(temp->right);
        }

    }
}

void inorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }

    //L
    inorder(root->left);
    ///N
    cout<<root->data<<" ";
    //R
    inorder(root->right);
}

void preorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }

    //N
    cout<<root->data<<" ";
    //L
    preorder(root->left);
    //R
    preorder(root->right);
}

void postorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }

    //L
    postorder(root->left);
    //R
    postorder(root->right);
    //N
    cout<<root->data<<" ";
}


void inorderTraversal(Node* root){
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);


}

int main()
{
    Node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // root = buildTree(root);

    buildFromLevelOrder(root);

    cout<<endl;
    cout<<"Preorder Traversal: "<<endl;
    preorder(root);


    // //level order traversal
    // cout<<"Printing the level order traversal output"<<endl;
    // levelOrderTraversal(root);
    // cout<<endl;

    // //Inorder Traversal
    // cout<<"Inorder Traversal: ";
    // inorder(root);
    // cout<<endl;

    // //Preorder Traversal
    // cout<<endl;
    // cout<<"Preorder Traversal: "<<endl;
    // preorder(root);

    // //Postorder Traversal
    // cout<<endl;
    // cout<<"Postorder Traversal: "<<endl;
    // postorder(root);

    return 0;
}