#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t>0){
	    int k,l,s;
	    cin>>l>>k;
    
        if(l%k == 0) cout<<"0"<<endl;
        else cout<<k<<endl;

	    t--;
	}
	return 0;
}
