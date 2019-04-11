#include<iostream>
#include<algorithm>
using namespace std;
int a
void permute(char *a, int l, int r) 
{ 
   int i; 
   if (l == r){

   } 
   else
   { 
       for (i = l; i <= r; i++) 
       { 
          swap((a+l), (a+i)); 
          permute(a, l+1, r); 
          swap((a+l), (a+i)); 
       } 
   } 
} 
int main() 
{ 
    char str[] = "ABCDE"; 
    int n = strlen(str); 
    permute(str, 0, n-1); 
    return 0; 
}