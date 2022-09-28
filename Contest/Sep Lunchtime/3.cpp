#include <iostream>
using namespace std;


int main() {
	int t;
	cin>>t;
    while (t>0)
    {
        int a,b,x;
        cin>>a>>b>>x;

        if(a==b) cout<<"YES"<<endl;
        else {
            if(a%2==0 && b%2==0) cout<<"YES"<<endl;
            else if (a%2 != 0 && b%2 != 0) cout<<"YES"<<endl;
            else{
                if(a%2==0 && b%2 != 0) cout<<"NO"<<endl;
                else cout<<"NO"<<endl;
            }
        }




        t--;
    }
    
	return 0;
}
