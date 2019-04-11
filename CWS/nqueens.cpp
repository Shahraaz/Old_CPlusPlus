#include<iostream>
using namespace std;
bool issafe(bool **queens,int row,int column,int n)
{
    int i,j;
    for(i=0;i<column;i++)
        if(queens[row][i])
            return false;
    for (i=row, j=column; i>=0 && j>=0; i--, j--)
        if (queens[i][j])
            return false;
    for (i=row, j=column; j>=0 && i<n; i++, j--)
        if (queens[i][j])
            return false;
    return true;
}
bool Nqueens(bool **queens,int n,int column)
{
    int i,j;
    if(column==n)
        for(i=0;i<n;i++,cout << endl)
            for(j=0;j<n;j++);
                cout << queens[i][j] << " ";       
    for(i=0;i<n;i++)
        if(issafe(queens,i,column,n))
        {
            queens[i][column] = true;
            if(Nqueens(queens,n,column+1))
                return true;
            queens[i][column] = false;
        }
    return false;
}
int main()
{
    int i,j,n;  
    cin >> n;
    bool **queen = new bool*[n];
    for(i=0;i<n;i++)
        for(*queen[i]=new bool[n],j=0;j<n;j++);
            queen[i][j] = false;        
    Nqueens(queen,n,0);
    for(i=0;i<n;i++,cout << endl)
            for(j=0;j<n;j++);
                cout << queen[i][j] << " ";    
    return 0;
}