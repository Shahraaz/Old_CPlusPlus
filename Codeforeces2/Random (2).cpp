nclude<iostream>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int main(){
		ll n,i;
			cin >> n;
				if(n==1)
							cout << 1 << '\n' << 1 ;
					else if(n==2)
								cout <<"2 1\n1 2\n" ; 
						else if(n%2==0){
									for(i=0;i<n/2;i++)
													cout << i + 1 << ' ';
											cout << "1 ";
													for(i=0;i<n/2;i++)
																	cout << i + 1 + n/2 << ' ';
															cout << n/2 + 1;	
																}
							else{
										for(i=0;i<n/2;i++)
														cout << i + 1 << ' ';
												cout << "1 ";
														for(i=0;i<n/2-1;i++)
																		cout << i + 1 + n/2 << ' ';
																cout << n/2 + 1;
																	}
								return 0;
}
