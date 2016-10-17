#include<iostream>
using namespace std;
long long ans[100];
int main(){
	int n,m;
	cin>>n>>m;
	ans[0]=1;
	ans[1]=1;
	int i=2;
	if(m>n){
		for(;i<n+1;i++){
			ans[i]=ans[i-1]*2;
		}
		for(;i<m+2;i++){
			int start=i-n-1;
			for(int j=0;j<n+1;j++){
				ans[i]+=ans[start+j];
			}
		}
		cout<<ans[m+1]<<endl;
		return 0;
	}
	else{
		int ans=1;
		while(m--){
			ans*=2;
		}
		cout<<ans<<endl;
	}
}