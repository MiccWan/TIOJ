//線段相交 數學題
#include <iostream>
using namespace std;
struct Point{
	double x,y;
};
int N,pos=0,neg=0,ans=0;
double Ax,Ay,Bx,By,V;
Point pt[360];

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>pt[i].x>>pt[i].y;
	}
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			Ax=pt[j].x-pt[i].x;
			Ay=pt[j].y-pt[i].y;
			for(int k=0;k<N;k++){
				if(k!=i&&k!=j){
					Bx=pt[k].x-pt[i].x;
					By=pt[k].y-pt[i].y;
					V=Ax*By-Ay*Bx;
					if(V>0)pos++;
					else if(V<0)neg++;
				}
			}
			ans+=pos*neg;
			pos=0;
			neg=0;
		}
	}
	cout<<ans<<"\n";
	return 0;
}