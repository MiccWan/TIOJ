#include <iostream>
#include<cmath>
using namespace std;

int GCD(int a,int b)
{
   int temp;
   while(a%b){
        temp=a;
        a=b;
        b=temp%a;
    }
   return b;
}

int main() {
	cout.precision(6);
	while(true){
		int a;
		cin>>a;
		if(a==0)break;
		int b [a];
		int k=0;
		for(int i=0;i<a;i++){
			cin>>b[i];
		}
		for(int i=0;i<a;i++){
			for(int j=i+1;j<a;j++){
				if(GCD(b[i],b[j])==1)k++;
			}
		}
		if(k!=0){
			double pi=sqrt((double)3*(double)a*(double)(a-1)/(double)k);
			cout<<fixed<<pi<<endl;
		}
		else cout<<"No estimate for this data set."<<endl;
	}
    return 0;
}