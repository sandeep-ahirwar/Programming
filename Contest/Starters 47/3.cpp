#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    while(n>0){
        int m;
        cin>>m;
        int arr[m];
        int mul;
        for(int i=0; i<m; i++) cin>>arr[i];

        int countN=0;
        int zero = 0;

        for(int i=0; i<m; i++){
            if(arr[i] < 0) countN++;
            if(arr[i] == 0) zero++;
        }  

        if (zero>0) cout<<"0"<<endl;
        else if(countN % 2 == 0) cout<<"0"<<endl;
        else cout<<"1"<<endl;

        n--;
    }

    return 0;
}