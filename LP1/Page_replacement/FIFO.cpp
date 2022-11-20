// Page replcement algorithm FIFO
// patil_gm
#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;

int pageFaults(vector<int> pages, int n, int capacity)
{
	unordered_set<int> s;
	queue<int> indexes;
	int page_faults = 0;
	for (int i=0; i<n; i++)
	{

		if (s.size() < capacity)
		{
			if (s.find(pages[i])==s.end())
			{
				s.insert(pages[i]);
				page_faults++;
				indexes.push(pages[i]);
			}
		}
		else
		{
			if (s.find(pages[i]) == s.end())
			{
				int val = indexes.front();
				indexes.pop();
				s.erase(val);
				s.insert(pages[i]);
				indexes.push(pages[i]);
				page_faults++;
			}
		}
	}

	return page_faults;
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