#include<iostream>
using namespace std;
int count =0;
int factrec(int n){
    count++;
    if(n<=0){
        count++;
        cout<<"final count be:"<<count<<endl;
        return 1;
    }
    else{
        count++;
        return n*factrec(n-1);
    }
}

int main(){
    int n;
    cout<<"enter the factorial number";
    cin>>n;
    int fact = factrec(n);
    cout<<"the factorial :"<<fact;
}