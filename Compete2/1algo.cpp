long long gcd(long long a,long long b){
    return b==0 ? a : gcd(b,a%b);
}

long long pow(long long base,long long index,long long MOD){
    if(index==0) return 1;
    long long temp = pow(base,index/2,MOD);
    temp = (temp*temp)%MOD;
    if(index&1) return (temp*base)%MOD;
    return temp;
}

vector<long long> prime;
void Seive(){
    vector<bool> seive(1000000,true);
    seive[0]=seive[1]=false;
    int i;
    for(i=3;i<1000;i+=2)
        if(seive[i])
            for(int j=i*i;j<1000000;j+=i)
                seive[j] = false;
    prime.push_back(2);
    for(i=3;i<1000000;i+=2)
        if(seive[i]) prime.push_back(i);
}
ll MAT[2][2];
void fun1(){
    ll a = ((MAT[0][0]*MAT[0][0])%mod + (MAT[0][1]*MAT[1][0])%mod)%mod;
    ll b = ((MAT[0][0]*MAT[0][1])%mod + (MAT[0][1]*MAT[1][1])%mod)%mod;
    ll c = ((MAT[1][0]*MAT[0][0])%mod + (MAT[1][1]*MAT[1][0])%mod)%mod;
    ll d = ((MAT[1][0]*MAT[0][1])%mod + (MAT[1][1]*MAT[1][1])%mod)%mod; 
    MAT[0][0] = a;MAT[0][1] = b;
    MAT[1][0] = c;MAT[1][1] = d;
}
void fun2(){
    ll a = (MAT[0][0] + MAT[0][1])%mod;
    ll b = MAT[0][0] ;
    ll c = (MAT[1][0] + MAT[1][1])%mod;
    ll d = MAT[1][0]; 
    MAT[0][0] = a;MAT[0][1] = b;
    MAT[1][0] = c;MAT[1][1] = d;
}
void power(ll index){
    if(index==0){
        MAT[0][0] = 1;MAT[1][0] = 0;
        MAT[1][0] = 0;MAT[1][1] = 1; 
    }
    else{
        power(index/2);
        fun1();
        
/*    cout << "MAtrix " << index << '\n';
    cout << MAT[0][0] << ' ' << MAT[0][1] << '\n';
    cout << MAT[1][0] << ' ' << MAT[1][1] << '\n';
*/        if(index&1) fun2();
    }
/*    cout << "MAtrix " << index << '\n';
    cout << MAT[0][0] << ' ' << MAT[0][1] << '\n';
    cout << MAT[1][0] << ' ' << MAT[1][1] << '\n';*/
}

int ri () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
// akikaze's template
struct matrix {
	vector<vector<ll>> A;

	matrix() {}

	matrix(ll n, ll m) {
		A.resize(n, vector<i64>(m, 0));
	}

	matrix(ll n, ll m, vector<ll> input) {
		A.resize(n, vector<ll>(m, 0));
		for (ll i=0; i<input.size(); i++) {
			A[i/m][i%m] = input[i];
		}
	}

	matrix(ll n, ll m, vector<vector<ll>> input) {
		A.resize(n, vector<i64>(m, 0));
		for (ll i=0; i<input.size(); i++) {
			if (i >= n) break;
			for (ll j=0; j<input[0].size(); j++) {
				if (j >= m) break;
				A[i][j] = input[i][j];
			}
		}
	}

	matrix(vector<vector<ll>> input) {
		for (ll i=0; i<input.size(); i++) {
			vector<ll> tmp;
			for (ll j=0; j<input[0].size(); j++) {
				tmp.pub(input[i][j]);
			}
			A.pub(tmp);
		}
	}

	matrix operator* (matrix b) {
		if (this->A[0].size() != b.A.size()) return matrix(0, 0);
		ll n = this->A.size(), m = b.A[0].size();
		matrix result(n, m);
		for (ll i=0; i<n; i++) {
			for (ll j=0; j<m; j++) {
				result.A[i][j] = 0;
				for (ll k=0; k<b.A.size(); k++) result.A[i][j] += this->A[i][k] * b.A[k][j];
			}
		}
		return result;
	}

	ostream& operator<< (ostream& os) {
		for (ll i=0; i<this->A.size(); i++) {
			for (ll j=0; j<this->A[0].size(); j++) {
				os << this->A[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}
};

matrix unitmat(matrix z) {
	matrix res = matrix(z.A.size(), z.A[0].size());
	for (ll i=0; i<z.A.size(); i++) {
		res.A[i][i] = 1;
	}
	return res;
}

matrix modMul(matrix a, matrix b) {
	if (a.A[0].size() != b.A.size()) return matrix(0, 0);
	ll n = a.A.size(), m = b.A[0].size();
	matrix result(n, m);
	for (ll i=0; i<n; i++) {
		for (ll j=0; j<m; j++) {
			result.A[i][j] = 0;
			for (ll k=0; k<b.A.size(); k++) result.A[i][j] = (result.A[i][j] + a.A[i][k] * b.A[k][j]) % MOD;
		}
	}
	return result;
}

matrix matPow(matrix a, ll b) {
	if (b == 0) return unitmat(a);
	if (b == 1) return a;
	matrix tmp = matPow(a, b/2);
	if (b % 2 == 0) return modMul(tmp, tmp);
	return modMul(modMul(tmp, tmp), a);
}


ll modPow(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	ll tmp = modPow(a, b/2);
	if (b % 2 == 0) return ((tmp * tmp) % MOD);
	return ((((tmp * tmp) % MOD) * a) % MOD);
}


ll divPow(ll a, ll b) {
	return ((a * modPow(b, MOD-2)) % MOD);
}
// chestnutrice's template
struct M{
  ll A[4][4];
  
  M operator*(const M&m){
    M r;
    for(int i=0;i<4;i++)
      for(int j=0;j<4;j++){
	r.A[i][j]=0;
	for(int k=0;k<4;k++)
	  r.A[i][j] = (r.A[i][j] + (A[i][k]*m.A[k][j])%MOD)%MOD;
      }
    return r;
  };

  M operator^(ll y){
    M r,x=*this;
    for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
	r.A[i][j]=((i==j)?1:0);
    while(y){
      if(y&1)
	r=(r*x);
      x=(x*x);y>>=1;
    }
    return r;
  };

};

// raja1999's template
ll res[5][5];
 int matimut(ll a[5][5],ll b[5][5])
 {
 	int i,j,k;
 	ll c[5][5]= { 0 } ;
 	for(i=0;i<2;i++)
 		 {
 		 	for(j=0;j<2;j++)
 		 	{
 		 		for(k=0;k<2;k++)
 		 		{
 		 			c[i][j]+=a[i][k]*b[k][j];
 		 			c[i][j]%= mod ;
 		 		}
 		 	}
 		 }
 		 for(i=0;i<2;i++)
 		 {
 		 	for( j=0 ;j<2; j++) 
 		 		a[i][j]=c[i][j];
 		 }
 }
int matrixexp(ll a[5][5],int n)
{
	res[0][0]=1;
	res[0][1]=0;
	res[1][0]=0;
	res[1][1]=1;
	while(n>0)
	{
		 if(n%2==1)
		 {
		 	matimut(res,a);
		 }
		 matimut(a,a);
		 n/=2;
	}
}