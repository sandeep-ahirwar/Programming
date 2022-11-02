#include <iostream>
using namespace std;

void execute(){
    int x,y;
    cin>>x>>y;
    cout<<x-y<<endl;

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
