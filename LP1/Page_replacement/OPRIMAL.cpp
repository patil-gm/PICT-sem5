// Page replcement algorithm OPTIMAL
// patil_gm
#include<iostream>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int getpos(int idx,int find,int n,vector<int> &pages){
    for(int i=idx;i<n;i++){
        if(pages[i]==find)return i;
    }
    return INT_MAX;
}


int pageFaults(vector<int> &pages, int n, int capacity)
{	int pf=0,size=0;
    unordered_set<int> s;

    for(int i=0;i<n;i++){
        if(size<capacity){
            if(s.find(pages[i])==s.end()){
                s.insert(pages[i]);
                pf++;
                size++;
            }
           
        }
        else{
             if(s.find(pages[i])==s.end()){
                int pos=-1;
                int val=0;
                for(auto it:s){
                    int temp=getpos(i,it,n,pages);
                    pos = max(pos,temp);
                    if(pos==INT_MAX){
                        val=it;
                        break;
                    }
                }
                if(pos!=INT_MAX){
                    val=pages[pos];
                }
                s.erase(val);
                s.insert(pages[i]);
                pf++;

            }
        }
    }
  

	return pf;
}

int main()
{
	cout<<"enter the no of pages : ";
    int n; cin>>n;
    vector<int> pg;
    for(int i=0;i<n;i++){
        cout<<"enter the size of "<<(i+1)<<"th page : ";
        int x;cin>>x;
        pg.push_back(x);
    }

	int fn;
    cout<<"enter the frame no's :";
    cin>>fn;
	cout<<"the no of page fault's is : "<<pageFaults(pg, n, fn)<<endl;
	return 0;
}

// 13
// 7 0 1 2 0 3 0 4 2 3 0 3 2 
// 4

// 20
// 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
// 4
