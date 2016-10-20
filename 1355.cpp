//初階河內塔 遞迴題
#include <stdio.h>
int step=1;
void move(int from,int to,int tmp,int n){
	if(n){
		move(from,tmp,to,n-1);
		printf("#%d : move the dish from #%d to #%d\n",step++,from,to);
		move(tmp,to,from,n-1);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	move(1,3,2,n);
	return 0;
}