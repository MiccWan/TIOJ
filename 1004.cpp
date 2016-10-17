#include <iostream>
#include <vector>
using namespace std;
int main() {
	int a;
	cin>>a;
	vector<int> b;
	for(int i=0;i<a;i++){
		b.push_back(i);
	}
	bool flag=false;
	for(int i=0;i<2*a-2;i++){
		if(!flag){
			b.push_back(b.front());
		}
		b.erase(b.begin());
		flag=(flag)?false:true;
	}
	cout<<b[0]+1<<endl;
    return 0;
}