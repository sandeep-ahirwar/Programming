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
    temp=0;
    for(auto a: array){
        if(a.second > 2 ) {
            if(a.second%2!=0){
                maxCount= maxCount + (a.second%2); 
                temp = a.second%2;
            }
            else{
            maxCount= maxCount + (a.second%2); 
            }
        }
        else if(a.second == 2) temp ++;
    }

    if(temp%2!=0) cout<<maxCount+(temp/2) + 1<<endl;
    else cout<<maxCount + (temp/2)<<endl;

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
