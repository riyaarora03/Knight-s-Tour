#include<iostream>
#include<queue>
using namespace std;
int arr[8][8]={0};



class node
{
    public:
    int x; 
    int y;
    int dist;
    int count;
    node *child[8]={};
    node(int x1,int y1)
    {
        x=x1;
        y=y1;
       dist=0;        
        
    }
};


queue<node*> q;



bool valid(int x, int y)
{
    if (x < 0 || y < 0 || x >= 7 || y >= 7)
        return false;
 
    return true;
}



class tree
{
    public:
    int x,y;
    int counttree(node *src,node *dest)
    {
        q.push(src);
        while (!q.empty())
        {
        
            node *root=q.front();
            q.pop();
            int x = root->x;
            int y = root->y;
            int dist = root->dist;
            root->count=-1;
            // if destination is reached, return distance
            if (x == dest->x && y == dest->y)
                return dist;


        
            if(valid(root->x-2,root->y-1))
            {
                if(arr[root->x-2][root->y-1]!=1)
                {
                    (root->count)++;
                    root->child[root->count]=new node(root->x-2,root->y-1);
                    arr[root->x-2][root->y-1]=1;
                    root->child[root->count]->dist=root->dist+1;
                    q.push(root->child[root->count]);
                   
                }
            }


            
            if(valid(root->x-1,root->y-2))
            {
                if(arr[root->x-1][root->y-2]!=1)
                {
                    (root->count)++;
                    root->child[root->count]=new node(root->x-1,root->y-2);
                    arr[root->x-1][root->y-2]=1;
                    root->child[root->count]->dist=root->dist+1;
                    q.push(root->child[root->count]);
                                      
                }
            }


            
            if(valid(root->x+2,root->y+1))
            {
                if(arr[root->x+2][root->y+1]!=1)
                {
                    (root->count)++;
                    root->child[root->count]=new node(root->x+2,root->y+1);
                    arr[root->x+2][root->y+1]=1;
                    root->child[root->count]->dist=root->dist+1;
                    q.push(root->child[root->count]);
                      
                }
                
            }


            
            if(valid(root->x+1,root->y+2))
            {
                if(arr[root->x+1][root->y+2]!=1)
                {
                    (root->count)++;
                    root->child[root->count]=new node(root->x+1,root->y+2);
                    arr[root->x+1][root->y+2]=1;  
                    root->child[root->count]->dist=root->dist+1;
                   q.push(root->child[root->count]);
                   
                }
                 
            }


            
            
            if(valid(root->x-2,root->y+1))
            {
                if(arr[root->x-2][root->y+1]!=1)
                 {
                      (root->count)++;
                    root->child[root->count]=new node(root->x-2,root->y+1);
                    arr[root->x-2][root->y+1]=1;
                 root->child[root->count]->dist=root->dist+1;
                 q.push(root->child[root->count]);
                  
                 }
            }


            
            
            if(valid(root->x+1,root->y-2))
            {
                 if(arr[root->x+1][root->y-2]!=1)
                {
                     (root->count)++;
                    root->child[root->count]=new node(root->x+1,root->y-2);
                    arr[root->x+1][root->y-2]=1;
                 root->child[root->count]->dist=root->dist+1;
                 q.push(root->child[root->count]);
                  
                }
            }


            
            if(valid(root->x-1,root->y+2))
            {
                if(arr[root->x-1][root->y+2]!=1)
                 {
                      (root->count)++;
                     root->child[root->count]=new node(root->x-1,root->y+2);
                    arr[root->x-1][root->y+2]=1;
                  root->child[root->count]->dist=root->dist+1;             
                 q.push(root->child[root->count]);
                  
                 }
            }


            
            
            if(valid(root->x+2,root->y-1))
             {
                if(arr[root->x+2][root->y-1]!=1)
                 {
                      (root->count)++;
                     root->child[root->count]=new node(root->x+2,root->y-1);
                    arr[root->x+2][root->y-1]=1;
                 root->child[root->count]->dist=root->dist+1;
                 q.push(root->child[root->count]);
                  
                 }
            }


        
        }       
    
    return INT32_MAX;
    }


};





bool hasPath(node *root, vector<node*>& arr, int x,int y) 
{ 
    if (!root) 
        return false; 
       
    arr.push_back(root);     
    
    if (root->x == x && root->y==y)     
        return true; 
       
    
    for(int i=0;i<7;i++)
    {
        if (hasPath(root->child[i], arr, x,y) || hasPath(root->child[7], arr, x,y)) 
        return true; 
    }       
    arr.pop_back(); 
        return false;             
} 
  


void printPath(node *root, int x,int y)
{ 
   
    vector<node*> arr; 
      
    
    if (hasPath(root, arr, x,y)) 
    { 
        for (int i=0; i<arr.size()-1; i++)     
            cout<<"["<<arr[i]->x<<","<<arr[i]->y<<"]"<<" -> "; 
        cout<<"["<<x<<","<<y<<"]";     
    } 
      
    
    else
        cout << "No Path"; 
}

int main()
{
    cout<<"\n-*-*-*-*-*-*-WELCOME TO THE CHESS BOARD GAME ARRANGED BY ASHISH SHIVANK AND TAIYAB -*-*-*-*-*-*-*\n\n";
    int a;
    int b,c,d;
    cout<<"\n enter the initial coordinates of knight";
    
    cout<<"\n\n enter x coordinate:  ";
    cin>>a;
    cout<<"\n enter y coordinate:  ";
    cin>>b;
    
    node *src=new node(a,b);


    cout<<"\n\n enter the final position";
    
    cout<<"\n\n enter the x coordinate:  ";
    cin>>c;
    cout<<"\n enter the y coordinate:  ";
    cin>>d;
    
    node *dest=new node(c,d);
    arr[a][b]=1;
    tree t;
    
    cout<<"\n\nTHE LENGTH OF SHORTEST PATH IS ->"<<t.counttree(src,dest);
    cout<<"\n";
    cout<<"\n\n THE PATH OF KNIGHT IS -> ";
    printPath(src,c,d);
    cout<<"\n\n\t\t\t\t\t\tTHANK YOU";


}

