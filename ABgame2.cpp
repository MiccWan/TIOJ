#include <iostream>
#include <utility>
#include <cstring>
#include <assert.h>
using namespace std;
bool ans[10000];
bool lis[10000];
int lef;
int gst;
int target,res[4][4],Max,oldMax;
pair<int,int> input,result,resPair;


void initial(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				for(int l=0;l<10;l++){
					if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l){
						ans[1000*i+100*j+10*k+l]=true;
						lis[1000*i+100*j+10*k+l]=true;
					}
					else ans[1000*i+100*j+10*k+l]=false;
				}
			}
		}
	}
	lef=5040;
}

pair<int,int> test(int A,int B){
	int tA=0,tB=0;
	int a[4]={ A/1000, A%1000/100, A%100/10, A%10 };
	int b[4]={ B/1000, B%1000/100, B%100/10, B%10 };

	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			if(a[i]==b[j]){
				if(i==j)tA++;
				else tB++;
			}
		}
	return pair<int,int>(tA,tB);
}

void inp(){
	while(cin>>input.first>>input.second){
		if(input.first>=0 && input.first<5 && input.second>=0 && input.second<5)break;
		else cout<<"Input Error\n";
	}
}

void renewLef(int g){
	for(int i=0;i<10000;i++){
		if(ans[i]){
			result=test(i,g);
			if( result.first != input.first || result.second != input.second ) ans[i] = false;
		}
	}
	lef=0;
	for(int i=0;i<10000;i++)
		if(ans[i])lef++;
}

int guess(){ //return guess number
	target=123;
	oldMax=9999;
	if(lef>1){
		for(int i=123;i<9877;i++){
			if(lis[i]){
				Max=0;
				memset(res,0,sizeof(res));
				for(int j=123;j<9877;j++){
					if(ans[j]){
						resPair=test(i,j);
						res[resPair.first][resPair.second]++;
					}
				}
				for(int m=0;m<4;m++){
					for(int n=0;n<4;n++){
						Max=max(Max,res[m][n]);
					}
				}
				if(Max<oldMax){
					oldMax=Max;
					target=i;
				}
			}
		}
		return target;
	}
	else for(int i=1;i<10000;i++)if(ans[i])return i;
}

bool chkEnd(){
	if(lef==0){
		cout<<"你確定沒給錯AB嗎?\n";
		return true;
	}
	else if(lef==1){
		for(int i=0;i<10000;i++)
			if(ans[i])printf("答案是 %04d ?\n",i);
		return true;
	}
	return false;
}

int main(){
		initial();
		cout<<"I guess : 0123"<<endl;
		inp();
		renewLef(123);
		if(!chkEnd())
			while(true){
				gst=guess();
				printf("I guess : %04d\n",gst);
				inp();
				renewLef(gst);
				if(chkEnd())break;
			}
}
