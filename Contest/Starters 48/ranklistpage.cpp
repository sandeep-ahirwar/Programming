#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    while(n>0){

        int x;
        cin>>x;
        if (x%25 == 0 ) cout<<x/25<<endl;
        else cout<<(x/25) + 1<<endl;
        n--;
    }
    return 0;
}