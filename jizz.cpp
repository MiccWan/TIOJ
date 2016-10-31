#include <iostream>
#include <algorithm>
using namespace std;
int T,N,i;
struct work{
	int d,f,pos;
	work(){
		pos=-1;
	}
};
work w[1005];
int getSum(int length){
	int days=0,sum=0;
	for(int i=0;i<length;i++){
		sum+=days*w[i].f;
		days+=w[i].d;
	}
	return sum;
}
int NbyPos(int pos){
	for(int i=0;;i++){
		if(w[i].pos==pos)return i;
	}
}

int main(){
	cin>>T;
	while(T--){
		cin>>N;
		
		for(int i=0;i<N;i++)
			cin>>w[i].d>>w[i].f,w[i].pos=i;
		
		int minSum=getSum(N),curSum=0;;
		for(int i=0;i<N;i++){
			for(int j=NbyPos(i)+1;j<N;j++){
				swap(w[j-1],w[j]);
				curSum=getSum(N);
				if(curSum<minSum) minSum=curSum;
				else{
					swap(w[j-1],w[j]);
					break;
				}
			}
		}
		for(int i=0;i<N-1;i++){
			cout<<w[i].pos+1<<" ";
		}
		cout<<w[N-1].pos+1;
		cout<<"\n";
	}
}