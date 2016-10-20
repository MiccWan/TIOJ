//建立質數表&查詢 演算法題
#include <iostream>
using namespace std;
int N;
bool prime[10000010];
int ans[10000010];
int cnt=0,req;
int main(){
	prime[0]=true;
	prime[1]=true;
	for(int i=2;i<3200;i++){
		if(!prime[i]){
			for (int k=(10000010-1)/i, j=i*k; k>=i; k--, j-=i){
				if (!prime[k]){
					prime[j] = true;
				}
			}
		}
	}
	for(int i=0;i<10000010;i++){
		if(!prime[i]){
			cnt++;
		}
		ans[i]=cnt;
	}
	cin>>N;
	while(N--){
		cin>>req;
		cout<<ans[req]<<"\n";
	}
}