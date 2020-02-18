
// Sample code to perform I/O:

#include <bits/stdc++.h>
typedef long long int ll;
#define flp(i,a,n) for(int i=a; i*i <= n ; i++)
#define fl(i,a,n) for(int i=a; i<n; i++)
#define flk(i,a,n,k) for(int  i=a; i<n ; i+=k)
#define VII vector<int>
#define VVII vector<VII>
#define VLL vector<ll>
#define pb push_back
const ll maxval = 5*(1e5)+1;
const ll MOD = 1e9+7;
using namespace std;
VII vct(maxval,0);
VII primes(maxval,1);
VVII primefact;
void sieve(){
    primefact.resize(maxval+1);
    fl(i,0,maxval+1){
        primes[i] = i;
    }
    primes[0] = 0;
    primes[1] = 0;
    flp(i,2,maxval){
        if(primes[i] == i){
            primefact[i].pb(i);
            flk(j,i*i,maxval,i){
                primefact[j].pb(i);
            }
        }
    }
}
ll EulerTotient(ll n){
    ll sum = n,t = 0;
    for(int i=0; i<primefact[n].size(); i++){
        t = primefact[n][i];
        sum = ll((sum*1.0/t*1.0)*(t-1))%MOD;
    }
    return sum;
}
ll function(ll n){
    ll temp = 0;
    for(ll i = 1; i*i <= n; i++){
        while(n%i == 0){
            if(n/i == i){
                temp += (i*EulerTotient(i));
            }else{
                temp += ((i)*EulerTotient(i));
                temp += ((i)*EulerTotient(n/i));
            }
        }
    }
    
}
ll Ctype(VII vct,int x,int y){
    ll sum = 0;
    fl(i,x,y+1){
        sum += EulerTotient(vct[i])%MOD;
    }
    return sum;
}
int main() {
    sieve();
	int num,Q;
	cin >> num;	
	VII vct;
	vct.resize(num);
	fl(i,0,num){
	    cin >> vct[i];
	}
	cin >>Q;
	char ch;
	int x,y;
	fl(i,0,Q){
	    cin >>ch>>x>>y;
	    if(ch == 'C'){
	        cout <<Ctype(vct,x-1,y-1)<<"\n";
	    }else{
	        vct[x-1] = y;
	    }
	}
    
}
