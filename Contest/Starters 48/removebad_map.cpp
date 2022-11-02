#include <iostream>
#include <map>
#include <iterator>
using namespace std;

void execute(){
    int x,i,maxCount,temp;
    cin>>x;

    map<int,int> array;

    int arr[x];
    for(i=0; i<x; i++){
        cin>>arr[i];
        array[arr[i]]++;
    }

    maxCount=0;

    for(auto a: array){
        if(a.second > maxCount) maxCount = a.second;
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
