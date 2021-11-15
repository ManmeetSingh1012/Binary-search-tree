/// here we have find the binary tree is balanced is not ** It is optimized soln with complexity equal to O(n)-Using recursion
// Binary tree balnced means if the left hight and right hight of curr nodes absolute difference is equal or less than 1

#include<bits/stdc++.h>
using namespace std;

class Node
{
   public:
   int val;
   Node*left;
   Node*right;

   Node(int data)
   {
      val=data;
      left=right=NULL;
   }
};

class BalancedBT
{
   public:
   int balanced(Node*root)
   {
      if(root==NULL) return 0;

      int lt=balanced(root->left);
      int rh=balanced(root->right);
      if(abs(lt-rh)>1) return -1;

      return 1+max(lt,rh);
   }
};
int main()
{
   Node*root=new Node(1);
   root->left=new Node(2);
   root->right=new Node(3);
   root->right->right=new Node(4);
   root->right->left=new Node(5);

   BalancedBT b;


   int ans=b.balanced(root);

   if(ans==-1) cout<<"Not Balanced";
   else cout<<"Balanced";
   return 0;


}