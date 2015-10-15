#include<bits/stdc++.h>
using namespace std;
struct tree{
  int val;
  tree *left;
  tree *right;
};
tree *head;
void insert(int data)
{
    tree *ptr=new tree;
    ptr->val=data;
    ptr->left=NULL;
    ptr->right=NULL;
    vector<tree *> vt;
    if(head==NULL)
    {  cout<<"first element:"<<ptr->val<<endl;
          head=ptr;
          return;
    }
    vt.push_back(head);
    while(!vt.empty())
    {tree *temp=vt.front();
      vt.erase(vt.begin());
      if(temp->left!=NULL)
            vt.push_back(temp->left);
      else
      {cout<<"element"<<ptr->val<<"inserted"<<endl;
            temp->left=ptr;
            return;
      }
      if(temp->right!=NULL)
           vt.push_back(temp->right);
      else
      {cout<<"element"<<ptr->val<<"inserted"<<endl;
            temp->right=ptr;
            return;
      }
    }
}
void print(tree *ptr)
{
    if(ptr!=NULL)
    {
       cout<<ptr->val;
       print(ptr->left);
       print(ptr->right);
    }
}
void lot()
{
    queue<tree *> q;
    q.push(head);
    while(!q.empty())
    {
        tree *temp=q.front();
        cout<<temp->val<<" ";
        q.pop();
        if(temp->left!=NULL)
              q.push(temp->left);
        if(temp->right!=NULL)
              q.push(temp->right);
    }
}
int main()
{
     head=NULL;
     insert(1);
     insert(2);
     insert(3);
     insert(4);
     insert(5);
     lot();
     //print(head);
    return 0;
}
