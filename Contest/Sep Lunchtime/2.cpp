#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	while(n>0){
	    int x,y;
	    cin>>x;
        cin>>y;

        if (x==y) cout<<"0"<<endl;
        else if(x == 0 || y==0) cout<<"0"<<endl;
        else{
            if (x<2*y) cout<< x-y <<endl;
            else {
                if (x>y) cout<< y <<endl;
                else cout<< y <<endl;
            }
        }
	    n--;
	}
	return 0;
}
