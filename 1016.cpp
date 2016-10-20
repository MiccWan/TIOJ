//暴力解baseball game
#include <iostream>
#include <string>
using namespace std;
int base[8];
int score[2];
int turn=0;
int out=0;
int len=0;
string rec;
void run(int a){
	base[0]=1;
	for(int j=3;j>=0;j--){
		if(base[j]){
			base[j]=0;
			base[j+a]=1;
		}
	}
	for(int j=7;j>3;j--){
		if(base[j]){
			score[turn]++;
			base[j]=0;
		}
	}
}
int main() {
    while(cin>>rec){
    	for(int i=0;i<8;i++) base[i]=0;
		score[0]=0,score[1]=0;
		turn=0;
		out=0;
		len=rec.size();
		for(int i=0;i<len;i++){
			switch(rec[i]){
				case 'K':
					out++;
					if(out==3){
						out=0;
						turn=(turn)?0:1;
						for(int i=0;i<8;i++) base[i]=0;
					}
					break;
				case 'O':
					out++;
					if(out==3){
						out=0;
						turn=(turn)?0:1;
						for(int i=0;i<8;i++) base[i]=0;
					}
					break;
				case 'S':
					run(1);
					break;
				case 'D':
					run(2);
					break;
				case 'T':
					run(3);
					break;
				case 'H':
					run(4);
					break;
				case 'W':
					if(base[1]){
						if(base[2]){
							if(base[3]){
								score[turn]++;
							}
							base[3]=1;
						}
						base[2]=1;
					}
					base[1]=1;
					break;
			}
		}
		cout<<score[0]<<' '<<score[1]<<"\n";
    }
}