#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define MAXN 100001

int least_prime[MAXN];

void leastPrimeFactor_Sieve(int n)
{
	least_prime[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(least_prime[i]==0)
		{
			least_prime[i]=i;
			for(int j=2*i;j<=n;j+=i)
			{
				if(least_prime[j]==0)
				   least_prime[j]=i;
			}
		}
	}
}

vector<int> getFactorization(int x)
{
	vector<int>res;
	while(x!=1)
	{
		res.push_back(least_prime[x]);
		x=x/least_prime[x];
	}
	return res;
}

int main()
{
	int x = 12246; 
	leastPrimeFactor_Sieve(x);
    cout << "prime factorization for " << x << " : "; 
  
    // calling getFactorization function 
    vector <int> p = getFactorization(x); 
  
    for (int i=0; i<p.size(); i++) 
        cout << p[i] << " "; 
    cout << endl; 
    return 0; 
}
