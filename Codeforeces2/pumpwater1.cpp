#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007

void buildTree(pair<int,int> *tree,int *a,int index,int s,int e)
{
	if(s>e)
		return;
	if(s==e)
	{
		tree[index]=make_pair(a[s],s);
		return ;
	}

	int m = (s+e)/2;
	buildTree(tree,a,2*index,s,m);
	buildTree(tree,a,2*index+1,m+1,e);
	tree[index]= max(tree[2*index],tree[2*index+1]);
	return;
}

pair<int,int> query(pair<int,int> *tree,int index,int s,int e,int qs,int qe)
{
	if(qs>e || s>qe)
		return make_pair(INT_MIN,-1);

	if(s>=qs && e<=qe)
		return tree[index];

	int m = (s+e)/2;
	return max(query(tree,2*index,s,m,qs,qe),query(tree,2*index+1,m+1,e,qs,qe));
}



int ans(int start,int end,int n,pair<int,int> *tree){

    if(start>end)
        return 0;

    pair<int,int> m=query(tree,1,0,n-1,start,end);
    int temp1 = ans(start,m.second-1,n,tree),temp2 = ans(m.second+1,end,n,tree); 
    return min(temp1,temp2)+1;
}


int main()
{
    FIO;
    int t,n,k,i,j;
    cin >> t;
    while(t--)
    {
        cin >> n ;
        int a[n];

        for(i=0;i<n;i++)
            cin >> a[i];

        pair<int,int> *tree = new pair<int,int> [4*n+1];

        buildTree(tree,a,1,0,n-1);

        cout << ans(0,n-1,n,tree) << endl;

    }


	return 0;
}
