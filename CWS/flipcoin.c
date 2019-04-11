#include<stdio.h>
#include<stdbool.h>
int st[1<<18]={0};
bool lazy[1<<18]={0};
void pushdown(int node,int left, int right)
{
    if(lazy[node])
    {
        if(left!=right)
        {
            lazy[2*node] = !lazy[2*node];
            lazy[2*node+1] = !lazy[2*node+1];
        }
        st[node] = right - left + 1 - st[node];
        lazy[node] = false;
    }
}
void updater(int node,int segstart,int segend,int querystart,int queryend)
{
    pushdown(node,segstart,segend);
    if(segstart>segend | segstart > queryend | segend < querystart)
        return ;
    if(querystart<=segstart & segend<=queryend)
    {
        lazy[node] = true;
        pushdown(node,segstart,segend);
        return ;
    }
    int mid = (segstart+segend)/2;
    updater(2*node,segstart,mid,querystart,queryend);
    updater(2*node+1,mid+1,segend,querystart,queryend);
    st[node] = st[node*2] + st[node*2+1];
}
int count(int node,int segstart,int segend,int querystart,int queryend)
{
    pushdown(node,segstart,segend);
    if(segstart>segend | segstart > queryend | segend < querystart)
        return 0;
    if(querystart<=segstart & segend<=queryend)
        return st[node];
    int mid = (segstart+segend)/2;
    return count(2*node,segstart,mid,querystart,queryend)+count(2*node+1,mid+1,segend,querystart,queryend);
}
int main()
{
    int n,q,sel,a,b;
    scanf("%d %d",&n,&q);
    while(q--)
    {
        scanf("%d %d %d",&sel,&a,&b);
        if(sel)
            printf("%d\n",count(1,1,n,a+1,b+1));
        else updater(1,1,n,a+1,b+1);
    }    
    return 0;
}