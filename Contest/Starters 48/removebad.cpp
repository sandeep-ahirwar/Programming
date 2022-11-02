#include <iostream>
using namespace std;

void execute(){
    int x,i,maxCount,temp;
    cin>>x;

    int arr[x];
    for(i=0; i<x; i++){
        cin>>arr[i];
    }

    maxCount=x;

    for(i=0; i<x; i++){
        temp = 0;
        for(int j=0; j<x; j++){
            if(arr[i] != arr[j]) temp++;
        }
        if(temp<maxCount) maxCount = temp;
    }

    cout<<maxCount<<endl;


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
