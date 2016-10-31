#include <iostream>
using namespace std;
bool ans[10000];
int lef;
int lis[4];
int lastGst[4];
int ti;

void init(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				for(int l=0;l<10;l++){
					if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l)
						ans[1000*i+100*j+10*k+l]=true;
				}
			}
		}
	}
}
void printLef(){
	lef=0;
	for(int i=0;i<10000;i++)
		if(ans[i])
			lef++;
	ti=0;
	for(int i=0;i<10000;i++){
		if(ans[i])ti++;
		if(ti==(lef/2+1)){
			lastGst[0]=i/1000;
			lastGst[1]=i%1000/100;
			lastGst[2]=i%100/10;
			lastGst[3]=i%10;
			break;
		}
	}
	
	if(lef>1){
		cout<<"我猜:"<<lastGst[0]<<lastGst[1]<<lastGst[2]<<lastGst[3]<<'\n';
	}
}
void test(int A,int B){
	for(int i=0;i<10000;i++){
		int tA=0,tB=0;
		lis[0]=i/1000;
		lis[1]=i%1000/100;
		lis[2]=i%100/10;
		lis[3]=i%10;
		for(int k=0;k<4;k++){
			for(int j=0;j<4;j++){
				if(lis[j]==lastGst[k]){
					if(j==k)tA++;
					else tB++;
				}
			}
		}
		if(tA!=A||tB!=B)ans[i]=false;
	}
	printLef();
}
int main(){
	init();
	int a,b;
	printLef();
	while(cin>>a>>b){
		if(a<5&&a>=0&&b<5&&b>=0){
			test(a,b);
			if(lef==1){
				for(int i=0;i<10000;i++){
					if(ans[i]){
						cout<<"答案是 "<<i<<" ?\n";
						break;
					}
				}
				break;
			}
			if(lef==0){
				cout<<"你確定沒給錯AB嗎?\n";
				break;
			}
		}
		else{
			cout<<"你在輸入啥阿\n";
		}
	}
}