#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    while(n>0){
        int zero;
        int one;
        cin>>zero;
        cin>>one;

        if((zero == 1) && (one == 1)) {
            cout<<"No"<<endl;
        }
         
        else if((zero == 1 && one != 1) || (zero !=1 && one == 1)){
            cout<<"No"<<endl;
        }

        else if((zero%2 == 0) && (one%2 == 0)){
            cout<<"Yes"<<endl;
        }
        
        else if(((zero%2 == 0) && (one%2 !=0)) || ((zero%2 != 0) && (one%2 ==0))){
            cout<<"Yes"<<endl;
        }

        else{
            cout<<"No"<<endl;
        }

        
        n--;
    }

    return 0;
}