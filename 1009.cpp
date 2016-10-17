#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	string input[6];
	getline(cin,input[0],':');
	getline(cin,input[1],':');
	getline(cin,input[2]);
	getline(cin,input[3],':');
	getline(cin,input[4],':');
	getline(cin,input[5]);
	
	stringstream ss;
	int inputInt[6];
	for(int i=0;i<6;i++){
		ss<<input[i];
		ss>>inputInt[i];
		ss.clear();
	}
	
	int ans[3];
	if(inputInt[5]>=inputInt[2])ans[2]=inputInt[5]-inputInt[2];
	else{
		ans[2]=inputInt[5]-inputInt[2]+60;
		inputInt[4]--;
	}
	if(inputInt[4]>=inputInt[1])ans[1]=inputInt[4]-inputInt[1];
	else{
		ans[1]=inputInt[4]-inputInt[1]+60;
		inputInt[3]--;
	}
	if(inputInt[3]>=inputInt[0])ans[0]=inputInt[3]-inputInt[0];
	else{
		ans[0]=inputInt[3]-inputInt[0]+24;
	}
	printf("%02d:%02d:%02d",ans[0],ans[1],ans[2]);
	return 0;
}