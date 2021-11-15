#include<bits/stdc++.h>
using namespace std;
class Node
{
   public:
   int data;
   Node*right;
   Node*left;

   Node(int val)
   {
      data=val;
      right=NULL;
      left=NULL;

   }
};

class traversal
{
   public:
   Node*preorder(Node*root);
   Node*inorder(Node*root);

};

Node* traversal::preorder(Node*root)
{
   vector<int>ans;
   stack<Node*>st;
   Node*temp;
   st.push(root);
   while(!st.empty())
   {
      temp=st.top();
      st.pop();
      if(temp->right!=NULL) st.push(temp->right);
      if(temp->left!=NULL) st.push(temp->left);
      ans.push_back(temp->data);
   }

   for(auto elemnt:ans)
   {
      cout<<elemnt<<endl;
   }

}

Node* traversal::inorder(Node*root)
{

   vector<int>ans;
   stack<Node*>st;
   Node*temp=root;
   while(true)
   {
      if(temp!=NULL)
      {
         st.push(temp);
         temp=temp->left;
      }

      else
      {
         if(st.empty()==true) break;
         temp=st.top();
         
         st.pop();
         ans.push_back(temp->data);
         temp=temp->right;
      }
   }

   cout<<endl;
   for(auto elemnt:ans)
   {
      cout<<elemnt<<endl;
   }
}

int main()
{
   Node*root=new Node(1);
   root->left=new Node(2);
   root->right=new Node(3);
   root->left->left=new Node(4);
   root->left->right=new Node(5);
   root->right->left=new Node(6);
   root->right->right=new Node(7);

   traversal t;
   t.preorder(root);
   t.inorder(root);
   return 0;
}