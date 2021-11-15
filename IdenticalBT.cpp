#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
   int data;
   Node *left;
   Node *right;

   Node(int val)
   {
      data = val;
      left = NULL;
      right = NULL;
   }
};

bool Preorder_traversal(Node*p,Node*q)
{
  if(p==NULL || q==NULL) return true;

  if(p->data !=q->data)
  {
     return false;
  }
  Preorder_traversal(p->left,p->right);
  Preorder_traversal(p->right,q->right);
}

int main()
{
   Node *root1 = new Node(1);
   root1->left = new Node(2);
   root1->right = new Node(3);

   Node*root2=new Node(1);
   root2->left = new Node(2);
   root2->right = new Node(3);
   
   cout<<Preorder_traversal(root1,root2);

   return 0;
}