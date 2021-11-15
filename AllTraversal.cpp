#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int val;
   Node *left;
   Node *right;

   Node(int data)
   {
      val = data;
      left == NULL;
      right == NULL;
   }
};

void function(Node *root)
{
   stack<pair<Node*,int >>p;
   vector<int> pre;
   vector<int> in;
   vector<int>post;
   p.push(root, 1);

   while (!p.empty())
   {
      auto it = p.top();
      p.pop();

      if (it.second == 1)
      {
         pre.push_back(it.first->val);

         it.second++;
         p.push(it);

         if (it.first->left != NULL)
         {
            p.push(it->left, 1);
         }
      }

      else if(it.second==2)
      {
         in.push_back(it.first->val);
         it.second++;
         p.push(it);

         if(it.second!=NULL)
         {
            p.push(it.second->left,1);
         }
      }
      else
      {
         post.push_back(it.first->val);
      }
   }
}
int main()
{

   Node *root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   root->left->left = new Node(4);
   root->left->right = new Node(5);
   root->right->left = new Node(6);
   root->right->right = new Node(7);



   return 0;
}
