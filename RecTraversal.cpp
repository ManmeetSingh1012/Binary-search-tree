// recursive traversal of the tree by there methods 
#include <bits/stdc++.h>
using namespace std;

class Node
{
   public:
   int data;
   Node*left;
   Node*right;

   Node(int val)
   {
      data=val;
      left=NULL;
      right=NULL;
   }
};

void Preorder_traversal(Node*root)
{
  if(root==NULL) return;

  cout<<root->data<<" ";
  Preorder_traversal(root->left);
  Preorder_traversal(root->right);
}


void Inoreder_traversal(Node*root)
{
  if(root==NULL) return;

  Inoreder_traversal(root->left);
  cout<<root->data<<" ";
  Inoreder_traversal(root->right);
}

void Postorder_traversal(Node*root)
{
  if(root==NULL) return;

  Postorder_traversal(root->left);
  Postorder_traversal(root->right);
  cout<<root->data<<" ";
}
int main()
{
    // creating the tree
   Node*root=new Node(1);
   root->left=new Node(2);
   root->right=new Node(3);
   root->left->left=new Node(4);
   root->left->right=new Node(5);
   root->right->left=new Node(6);
   root->right->right=new Node(7);

   /*
            1
          /   \
        2       3
      /  \     /  \

    4     5   6     7

*/

// traversing through Preorder_traversal
Preorder_traversal(root);

cout<<endl;

// traversing through Inoreder_traversal
Inoreder_traversal(root);

cout<<endl;

//traversing through Postorder_traversal
Postorder_traversal(root);



   return 0;

}
