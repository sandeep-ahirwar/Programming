#include <iostream>
using namespace std;

void execute(){
    int x,i,even=0,odd=0;
    cin>>x;

    int arr[x];
    for(i=0; i<x; i++){
        cin>>arr[i];
        if(arr[i]%2==0) even++;
        else odd++;
    }
}

int main(){

    int n;
    cin>>n;
    while(n>0){
        execute();
        n--;
    }

    return 0;
}
