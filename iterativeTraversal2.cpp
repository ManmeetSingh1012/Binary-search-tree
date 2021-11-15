#include<bits/stdc++.h>
using namespace std;
class Node
{
   public:
   Node*left;
   Node*right;
   int data;

   Node(int val)
   {
      data=val;
      left=NULL;
      right=NULL;
   }
};

class Postorder_traversal
{
   public:
   Node* traversal(Node*root); // using two stack 
   Node*traversal2(Node*root); // using single stack
};

Node*Postorder_traversal::traversal(Node*root)
{
   stack<Node*>st1;
   stack<int>st2;
   Node*temp;

   st1.push(root);

   while(!st1.empty())
   {
      temp=st1.top();
      st1.pop();
      st2.push(temp->data);

      if(temp->left!=NULL) st1.push(temp->left);
      if(temp->right!=NULL) st1.push(temp->right);



   }

   while(!st2.empty())
   {
      cout<<st2.top()<<endl;
      st2.pop();
   }
   return 0;
}

Node*Postorder_traversal::traversal2(Node*root)
{
   stack<Node*>st;
   vector<int>ans;
   Node*temp;
   Node*curr=root;

   while(!st.empty() )
   {
      if(curr!=NULL)
      {
         st.push(curr);
         curr=curr->left;
         
      }

      else{
         temp=st.top()->right;
         if(temp==NULL)
         {
            temp=st.top();
            st.pop();
            ans.push_back(temp->data);
            while(!st.empty() and temp==st.top()->right);
            {
               temp=st.top();
               st.pop();
               ans.push_back(temp->data);
            }

         }

         else{
            curr=temp;
         }
      }
   }

   for(auto elment : ans)
   {
      cout<<elment<<endl;
   }
   return 0;
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

   Postorder_traversal t;
   //t.traversal(root);
   t.traversal2(root);
   return 0;
}
