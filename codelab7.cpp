#include <iostream>
#include <queue>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
};

struct Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

void inorder(Node* root){
    if (root == NULL) {
        return;
    }
    else {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }    
}

void preorder(Node* root){
    if (root == NULL) {
        return;
    }
    else {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root){
    if (root == NULL) {
        return;
    }
    else {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void BFS_tree(Node* root){
   queue<Node*> q;
   q.push(root);
   
      while (!q.empty() )
      {
          Node* n = q.front();
          cout << n->data << " ";
          if ( n->left != NULL )
               q.push(n->left);
          if ( n->right != NULL )
               q.push(n->right);
          q.pop();
      }


}


void printArr(int arr[], int n) { 
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void all_root_to_leaves(Node* root, int path[], int pathLen){
    if (root == NULL) {
        return;
    }
    path[pathLen] = root->data;
    pathLen++;
        if (root->left == NULL && root->right == NULL){
            printArr(path, pathLen);
        }
        else {
            all_root_to_leaves(root->left, path, pathLen);
            all_root_to_leaves(root->right, path, pathLen);
        }
}

void path(Node* root) {
    int path[1000];
    all_root_to_leaves(root, path, 0);
}
//This is extra credit. Only turn it in after completing other questions
void printVector(const vector<int>& v, int i)
{
    for (int j=i; j<v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}

void printKPath(Node *root, vector<int>& path,
    int k)
{
if (!root) {
    return;
}
path.push_back(root->data);
printKPath(root->left, path, k);
printKPath(root->right, path, k);
int f = 0;
for (int j=path.size()-1; j>=0; j--)
{
f += path[j];

if (f == k)
printVector(path, j);
}

path.pop_back();
}

void sumPath(Node *root, int k)
{
vector<int> path;
printKPath(root, path, k);
}

int main(){
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
// The calls for the above incomplete functions commented out purposefully. Please uncomment after you have completed all the above methods.
    // cout << "Inorder: ";
    // inorder(root);
    // cout << endl;
    // cout << "Preorder: ";
    // preorder(root);
    // cout << endl;
    // cout << "Postorder: ";
    // postorder(root);
    // cout << endl;
//     cout << "BFS Tree: " << endl;
//    BFS_tree(root);
// cout << "All root to leaves: " << endl;
//    path(root);
sumPath(root, 11);
}


