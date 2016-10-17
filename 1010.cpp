#include <iostream>
using namespace std;

int main() {
  string a,b;
  cin >> a >> b;
  int lenA=a.length();
  int lenB=b.length();
  bool jizz=true;
  if(lenA>=lenB){
    int i=lenB;
    for(;i>=0;i--){
      int front_b=lenB-i;
      jizz=true;
      for(int j=0;j<i;j++){
        if(a[j]==b[front_b+j]);
        else{
          jizz=false;
          break;
        }
      }
      if(jizz)break;
    }
    cout<<i<<endl;
  }
  else{
    int i=lenA;
    for(;i>=0;i--){
      int front_b=lenB-i;
      jizz=true;
      for(int j=0;j<i;j++){
        if(a[j]==b[front_b+j]);
        else{
          jizz=false;
          break;
        }
      }
      if(jizz)break;
    }
    cout<<i<<endl;
  }
}

