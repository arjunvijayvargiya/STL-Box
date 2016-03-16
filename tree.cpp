#include<bits/stdc++.h>
using namespace std;
struct node{
 int val;
 node *left;
 node *right;
};
struct stringnode{
 string str;
 stringnode *left;
 stringnode *right;
};
map<int,int> mp;
string alphabet[]={"", "a", "b", "c", "d", "e",
        "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
        "s", "t", "u", "v", "w", "x", "v", "z"};
node *newnode(int x)
{
    node* ptr=new node;
    ptr->val=x;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}
void insert(node **root,int x)
{
  if(*root==NULL)
  {
    *root=newnode(x);
  }
  else
  {
      queue<node*> q;
      q.push(*root);
      while(!q.empty())
      {
        node *temp=q.front();
        q.pop();
        if(temp->left!=NULL)
          q.push(temp->left);
        else
        {
          temp->left=newnode(x);
          return;
        }
        if(temp->right!=NULL)
          q.push(temp->right);
        else
        {
          temp->right=newnode(x);
          return;
        }
      }
  }
}
void preordertraversal(node **root)
{
  if(*root!=NULL)
  {
    cout<<(*root)->val<<" ";
    preordertraversal(&((*root)->left));
    preordertraversal(&((*root)->right));
  }
}
void inordertraversal(node **root)
{
  if(*root!=NULL)
  {

    preordertraversal(&((*root)->left));
    cout<<(*root)->val<<" ";
    preordertraversal(&((*root)->right));
  }
}
void postordertraversal(node **root)
{
  if(*root!=NULL)
  {

    preordertraversal(&((*root)->left));
    preordertraversal(&((*root)->right));
    cout<<(*root)->val<<" ";
  }
}
node *searchtreeComplex(node **root,int x)
{
  if(*root==NULL)
    return NULL;
  else
  {
     if((*root)->val==x)
        return (*root);
     else
     {
      if(searchtreeComplex(&((*root)->left),x)!=NULL)
        return *root;
      else
        return searchtreeComplex(&((*root)->right),x);
     }
  }
}
int height(node **root)
{
    if(*root==NULL)
      return 0;
    else
    {
        int lh=height(&((*root)->left));
        int rh=height(&((*root)->right));
        if(lh>rh)
          return (lh+1);
        else
          return (rh+1);
    }
}
int maxelement(node **root)
{int maxx;
    if(*root==NULL)
      return 0;
    else
    {
        int lh=maxelement(&((*root)->left));
        int rh=maxelement(&((*root)->right));
        if(lh>rh)
          maxx=lh;
        else
          maxx=rh;
        if((*root)->val>maxx)
          maxx=(*root)->val;
        return maxx;
    }
}
int levels(node **root)
{
    int cnt=0;
    if(*root==NULL)
  {
    return 0;
  }
  else
  {
      queue<node*> q;
      q.push(*root);
      q.push(NULL);
      while(!q.empty())
      {
        node *temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cnt++;
            if(!q.empty())
              q.push(NULL);
        }
        else
        {
        if(temp->left!=NULL)
          q.push(temp->left);
        if(temp->right!=NULL)
          q.push(temp->right);
        }
      }
  }
  return cnt;
}
int levelsum(node **root)
{
  int summax=0;
  if(*root==NULL)
  {
    return -1;
  }
  else
  {
      queue<node*> q;
      q.push(*root);
      q.push(NULL);
      int sum=0;
      while(!q.empty())
      {
        node *temp=q.front();
        q.pop();
        if(temp!=NULL)
          sum=sum+temp->val;
        if(temp==NULL)
        {
            if(sum>summax)
              summax=sum;
            sum=0;
            if(!q.empty())
              q.push(NULL);
        }
        else
        {
        if(temp->left!=NULL)
          q.push(temp->left);
        if(temp->right!=NULL)
          q.push(temp->right);
        }
      }
  }
  return summax;
}
void printpath(vector<int> vec)
{
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i];
    }
    cout<<endl;
}
void printrecurpath(node **root,vector<int> vec)
{
    if(*root==NULL)
       return;
    vec.push_back((*root)->val);
    if((*root)->left==NULL && (*root)->right==NULL)
      printpath(vec);
    else
    {
        printrecurpath(&((*root)->left),vec);
        printrecurpath(&((*root)->right),vec);
    }
}
node *LCA(node **root,int a,int b)
{
    if(*root==NULL)
        return NULL;
    if((*root)->val==a || (*root)->val==b)
        return *root;
    node *lefty=LCA(&((*root)->left),a,b);
    node *righty=LCA(&((*root)->right),a,b);
    if(lefty!=NULL && right!=NULL)
        return *root;
    else if(lefty!=NULL)
        return lefty;
    else
        return righty;
}
void verticalcolumnsum(node **root,int col)
{
   if(*root!=NULL)
   {
       verticalcolumnsum(&((*root)->left),col-1);
       mp[col]+=(*root)->val;
       verticalcolumnsum(&((*root)->left),col+1);
   }
}
void printspiralorder(node **root,int level,bool f)
{
   if(*root==NULL)
      return;
   if(level==1)
   {
       cout<<(*root)->val;
       return;
   }
   else if(level>1)
   {
       if(f)
       {
          printspiralorder(&((*root)->left),level-1,f);
          printspiralorder(&((*root)->right),level-1,f);
       }
       else
       {
          printspiralorder(&((*root)->right),level-1,f);
          printspiralorder(&((*root)->left),level-1,f);
       }
   }
}
void spiralsetter(node **root)
{
    int h=height(root);
    bool ltr=true;
    for(int i=1;i<=h;i++)
    {
        printspiralorder(root,i,ltr);
        ltr=!ltr;
        cout<<endl;
    }
}
int childsumproperty(node **root)
{
    int ld=0;
    int rd=0;
    if(*root==NULL || ((*root)->left==NULL && (*root)->right==NULL ))
        return 1;
    else
    {
        if((*root)->left!=NULL)
            ld=((*root)->left)->val;
        if((*root)->right!=NULL)
            rd=((*root)->right)->val;
        if((ld+rd)==(*root)->val && childsumproperty(&((*root)->left)) && childsumproperty(&((*root)->right)))
            return 1;
        else
            return 0;
    }
}
void doubletree(node **root)
{
    if(*root!=NULL)
    {
      doubletree(&((*root)->left));
      doubletree(&((*root)->right));
      node *oldleft=(*root)->left;
      (*root)->left=newnode(((*root)->val));
      ((*root)->left)->left=oldleft;
    }
}
bool printancestors(node **root,int target)
{
    if(*root==NULL)
      return false;
    if((*root)->val==target)
      return true;
    if(printancestors(&((*root)->left),target) || printancestors(&((*root)->right),target))
    {
        cout<<(*root)->val<<",";
        return true;
    }
    return false;
}
int sumtreeconvert(node **root)
{
    if(*root==NULL)
        return 0;
    int oldval=(*root)->val;
    (*root)->val=sumtreeconvert(&((*root)->left))+sumtreeconvert(&((*root)->right));
    return oldval+(*root)->val;
}
node *buildspecialtree(int arr[],int start,int endd)
{
  if(start>endd)
    return NULL;
  int index=start;
  for(int i=start+1;i<endd;i++)
  {
      if(arr[i]>arr[index])
        index=i;
  }
  node *ptr=newnode(arr[index]);
  ptr->left=buildspecialtree(arr,start,index-1);
  ptr->right=buildspecialtree(arr,index+1,endd);
  return ptr;
}
void checkcompletetree(node **root)
{
  if(*root==NULL)
  {
    cout<<"Tree is a complete tree";
  }
  else
  {
      queue<node*> q;
      q.push(*root);
      bool flag=false;
      while(!q.empty())
      {
        node *temp=q.front();
        q.pop();
        cout<<temp->val;
        if(temp->left!=NULL)
        {
          if(flag==true)
          {
              cout<<"not a complete tree";
              return;
          }
          q.push(temp->left);
        }
        else
        {
          flag=true;
        }
        if(temp->right!=NULL)
        {
          if(flag==true)
          {
              cout<<"not a complete tree";
              return;
          }
          q.push(temp->right);
        }
        else
        {
          flag=true;
        }
      }
  }
  cout<<"A complete tree";
}
node *buildtreefromlist(list<int> l)
{
    queue<node*> q;
    node *root=NULL;
    int p=l.front();
    l.pop_front();
    root=newnode(p);
    q.push(root);
    while(!q.empty())
    {
        node *temp=q.front();
        q.pop();
        if(!l.empty())
        {
           temp->left=newnode(l.front());
           l.pop_front();
           q.push(temp->left);
        }
        if(!l.empty())
        {
           temp->right=newnode(l.front());
           l.pop_front();
           q.push(temp->right);
        }
    }
    return root;
}
stringnode *intrepret(stringnode **root,int data,string pstring,vector<int> vec)
{
   if(data>26)
      return NULL;
   (*root)=new stringnode;
   string cstring=pstring.append(alphabet[data]);
   cout<<cstring<<endl;
   (*root)->str=cstring;
   if(!vec.empty())
   {
       data=vec[0];
       vector<int> nvec=vec;
       nvec.erase(nvec.begin());
       (*root)->left=intrepret( &((*root)->left),data,pstring,nvec);
   }
   if(vec.size()>1)
   {
       data=vec[0]*10+vec[1];
       vector<int> nvec=vec;
       nvec.erase(nvec.begin());
       nvec.erase(nvec.begin());
       (*root)->right=intrepret( &((*root)->right),data,pstring,nvec);
   }
   return (*root);
}
void traversestringnode(stringnode **root)
{
    if((*root)!=NULL)
    {
        cout<<(*root)->str;
        cout<<endl;
        traversestringnode(&((*root)->left));
        traversestringnode(&((*root)->right));
    }
}
int main()
{
 stringnode *root=NULL;
 vector<int> vec;
 vec.push_back(1);
 vec.push_back(1);
 vec.push_back(3);
 vec.push_back(4);
 string str="";
 root=intrepret(&root,0,str,vec);
 traversestringnode(&root);
 return 0;
}
