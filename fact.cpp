#include<iostream>
using namespace std;
int fact_iter(int n){
    int count = 1;
    int fact = 1;
    count++;
    for(int i = 1; i <= n; i++){
        count+=2;
        fact = fact*i;
    }
    cout<<"factorial value:"<<fact<<endl;
    count++;
    return count;
}

int main(){
    int n;
    cout<<"enter the factorial number";
    cin>>n;
    int count = fact_iter(n);
    cout<<"the count on iternative factorial is :"<<count;
}