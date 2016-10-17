#include<iostream>
using namespace std;
long long m,M;
int main(){
	while(cin>>m>>M){
		if(m!=0){
			if(m>M)swap(m,M);
			cout<<m*(m+1)*(3*M+1-m)/6<<endl;
		}
	}
	return 0;
}