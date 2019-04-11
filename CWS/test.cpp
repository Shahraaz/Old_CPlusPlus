#include<iostream>
using namespace std;
int main()
{
	    int n ,m ,count,j, i,k, l, r, z,answer;
	        bool arr[100000][100000]={false};
		    cin >> n >> m >> k ;
		        while(n--)
				    {
					            cin >> l >> r >> z;
						            while(l<=r)
								                arr[l++][z] = true ;
							        }
			    answer = 1;
			        for(i=1;i<=m;i++)
					    {
						            count = 0;
							            for(j=1;j<=k;j++)
									                if(arr[i][j]) count ++;
								            answer = ( answer * (count%1000003) )%1000003;
									        }
				    cout << answer ;
				        return 0;
}
