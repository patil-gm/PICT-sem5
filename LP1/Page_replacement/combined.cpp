#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<vector>
// patil_gm
using namespace std;



int fifo(int n,vector<int> &pages,int capacity){
	unordered_set<int> s;
	queue<int> q;
	int pf=0,size=0;
	for(int i=0;i<n;i++){
		if(size<capacity){
			if(s.find(pages[i])==s.end()){
				s.insert(pages[i]);
				q.push(pages[i]);
				pf++;
				size++;
			}
		
		}
		else{
		if(s.find(pages[i])==s.end()){
			s.erase(q.front());
			q.pop();
			s.insert(pages[i]);
			q.push(pages[i]);
			pf++;
		}
		}
	}
	return pf;
}

int lru(int n,vector<int> &pages,int capacity){
	unordered_set<int> s;
	unordered_map<int,int> map;
	int pf=0,size=0;

	for(int i=0;i<n;i++){
		map[pages[i]]=i;

		if(size<capacity){
			if(s.find(pages[i])==s.end()){
				s.insert(pages[i]);
				pf++;
				size++;
			}
		
		}
		else{
		if(s.find(pages[i])==s.end()){
			int lru=INT_MAX,val=-1;
			for(auto it:s){
				lru=min(lru,map[it]);
				val=pages[lru];
			}
			s.erase(pages[val]);
			s.insert(pages[i]);
			pf++;

		}
		}
	}

	return pf;
}

int getpos(int start,int find,int n,vector<int> &pages){
	for(int i=start;i<n;i++){
		if(pages[i]==find)return i;
	}
	return INT_MAX;
}

int optimal(int n,vector<int> &pages,int capacity){
	unordered_set<int> s;
	int pf=0,size=0;
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
			
			int pos=-1,val;
			for(auto it:s){
				int temp=getpos(i,it,n,pages);
				pos=max(pos,temp);
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









int main(){
	cout<<"enter the no of pages : ";
	int n;cin>>n;
	vector<int> pages;
	for(int i=0;i<n;i++){
		cout<<"enter the size of "<<i+1<<"th page : ";
		int x;cin>>x;
		pages.push_back(x);
	}
	cout<<"\nEnter the frame size : ";
	int fr;cin>>fr;
	cout<<"\n\nthe page fault for FIFO is : "<<fifo(n,pages,fr)<<endl;
	cout<<"the page fault for LRU is : "<<lru(n,pages,fr)<<endl;
	cout<<"the page fault for OPTIMAL is : "<<optimal(n,pages,fr)<<endl;
}

