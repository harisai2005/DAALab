#include <iostream>
using namespace std;
int count=0;
int gcd(int a , int b){
    count++;
    if(a%min(a,b)==0 && b%min(a,b)==0){
        count++;
        return min(a,b);
    }
    else 
    count++;
    return gcd(max(a,b),min(a,b)-1);
}

int main(){
    int a,b;
    cin>>a>>b;
    int result = min(a,b);
    int ans=gcd(a,b);
    cout<<ans<<endl;
    cout<<count;
}

