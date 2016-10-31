#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

struct M{
	int ID;
	int rLvl;
	int wLvl;
};
int n;
map<string,M> skill;
bool G[35][35];
string N[35];

int getSkID(string &s){
	auto id=skill.find(s);
	if(id==skill.end()){
		skill[s].ID=skill.size()-1;
	}
	return skill[s].ID;
}
void setPreSkill(string skName,int &w,string* N){
	for(auto &iter:skill){
		if(G[getSkID(skName)][iter.second.ID] && iter.second.wLvl==0){
			iter.second.wLvl=1;
			N[w]=iter.first;
			w++;
		}
	}
}

int main(){
	while(cin>>n,n){
		skill.clear();
		for(int i=0;i<n;i++){
			string skName;cin>>skName;
			getSkID(skName);
			cin>>skill[skName].rLvl;
			int preSkil;cin>>preSkil;
			
			while(preSkil--){
				string preSkName;cin>>preSkName;
				G[getSkID(skName)][getSkID(preSkName)]=true;
			}
		}
		int w;cin>>w;
		int cnt=0;
		for(int i=0;i<w;i++){
			string wSkName;cin>>wSkName;
			cin>>skill[wSkName].wLvl;
			N[cnt++]=wSkName;
		}

		for(int i=0;i<w;i++){
			setPreSkill(N[i],w,N);
		}
		
		int ans=1;
		int point=0;
		for(int i=0;i<w;i++){
			skill[N[i]].rLvl+=skill[N[i]].wLvl-1;
			while(ans<skill[N[i]].rLvl||point<skill[N[i]].wLvl){
				ans++,point++;
			}
			point-=skill[N[i]].wLvl;
		}
		if(ans>99)cout<<"IMPOSSIBLE"<<endl;
		else cout<<ans<<endl;
	}
}