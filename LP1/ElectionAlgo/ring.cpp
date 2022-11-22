// #include <bits/stdc++.h>
// patil-gm
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> tocken;

int ring(vector<bool> proc,int n,int start){

    int curr=start;
    while(true){
        for(int i=start;i<n;i++){
            if(proc[i]==1){
                tocken.push_back(i+1);
                cout<<"process "<<curr+1<<" called process "<<i+1<<endl;
                curr=i;
                cout<<"\t\tRecived Tockens : {";
                for(int i=0;i<tocken.size();i++){
                    cout<<tocken[i]<<",";
                }
                cout<<"}"<<endl;
                
            }
        }

        if(start!=0){
            n=start;
            start=0;
        }
        else{
            break;
        }
    }
    if(tocken.size()==0){
        cout<<"there is no process alive to be a co-ordinator\n";
        return -1;}
    return *max_element(tocken.begin(),tocken.end());
}


int main(){
    
    cout<<"enter the no of processes : ";
    int n;cin>>n;
    vector<bool> proc;

    for(int i=0;i<n;i++){
        cout<<"enter the state of process "<<(i+1)<<" (1/0) : ";
        int x;cin>>x;
        proc.push_back(x);
    }

    cout<<"\nEnter the initiater process no : ";
    int start;cin>>start;
    int ans=ring(proc,n,start-1);
    if(ans!=-1)cout<<"\nCurrent process co-ordinator is : "<<ans<<endl;
    
}
