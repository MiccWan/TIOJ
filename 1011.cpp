#include <iostream>
#include <sstream>
#include <bitset>
using namespace std;
string to_string(bitset<32> i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}
int main()
{
	int x,y;
	cin>>x>>y;
    bitset<32> xx(x);
    bitset<32> yy(y);
    string a=to_string(xx);
    string b=to_string(yy);
    a.erase(0, a.find_first_not_of('0'));
    b.erase(0, b.find_first_not_of('0'));
    int i=0;
    for(;i<min(a.size(),b.size());i++) if(a[i]!=b[i])break;
    int ans=a.length()+b.length()-i-i;
    cout<<ans;
	return 0;
}