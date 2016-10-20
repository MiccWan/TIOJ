//誰先晚餐
#include <iostream>
#include <algorithm>
using namespace std;
struct jizz{
	int c,e;
};
// bool operator<(const jizz& a)
int main(){
	int N;
	while(cin>>N){
		if(!N)break;
		jizz arr[10000];
		for(int i=0;i<N;i++){
			cin>>arr[i].c>>arr[i].e;
		}
		sort(arr, arr+N, [](const jizz& a, const jizz& b) -> bool {return a.e==b.e ? a.c > b.c : a.e > b.e;});
		int timeC=0,ans=0;
		for(int i=0;i<N;i++){
			timeC+=arr[i].c;
			ans= max(ans,timeC+arr[i].e);
		}
		cout<<ans<<endl;
	}
}