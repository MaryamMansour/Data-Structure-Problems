#include <iostream>

using namespace std;
struct Node {
    int val;
    Node *left, *right;
};

                                                    // function to create new Node
Node* newNode(int val)
{
    Node* root = new Node;
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}


bool Foldable( Node* root1,  Node* root2){        //passing a pointer cuz Node(struct) and null which is long long int can't be compared

if( (root1 != NULL && root2 == NULL)  || (root1 == NULL && root2 != NULL) )
    return false;
if((root1 == NULL && root2 == NULL) || (  Foldable(root1->left, root2->right )&& Foldable(root1->right, root2->left )   )  )
    return true;
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(4);               //test case 1
    root->right = newNode(2);
    root->left->right = newNode(5);
    root->right->left = newNode(3);
    root->right->left->left = newNode(3);
    root->right->left->left = newNode(3);
    if(Foldable(root,root)) cout<<"Foldable\n";
    else cout<<"Not Foldable\n";
    //-------------------------------------------------------------
     Node* root1 = newNode(1);
    root1->left = newNode(4);
    root1->right = newNode(2);              //test case 2
    root1->left->right = newNode(5);
    root1->right->left = newNode(3);
    if(Foldable(root1,root1)) cout<<"Foldable\n";
    else cout<<"Not Foldable\n";
    //--------------------------------------------------------------
    Node* root3 = newNode(1);                 //empty tree -  test case 3
    if(Foldable(root3,root3)) cout<<"Foldable\n";
    else cout<<"Not Foldable\n";
    //---------------------------------------------------------------
    Node* root4 = newNode(1);                   //Test case 4
    root4->left = newNode(7);
    if(Foldable(root4,root4)) cout<<"Foldable\n";
    else cout<<"Not Foldable\n";
    //---------------------------------------------------------
    Node* root5 = newNode(8);
    root5->left = newNode(5);
    root5->right = newNode(6);              //test case 5
    root5->left->right = newNode(5);
    root5->right->left = newNode(1);
    root5->left->right->left =newNode(17);
    if(Foldable(root5,root5)) cout<<"Foldable\n";
    else cout<<"Not Foldable\n";
}
