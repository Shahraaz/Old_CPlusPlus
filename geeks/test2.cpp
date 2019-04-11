#include<iostream>
using namespace std;

int fun(int &x)
{
		return x;
}
int main()
{
		cout << fun(10);
			return 0;
}
