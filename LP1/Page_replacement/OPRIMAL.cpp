// Page replcement algorithm OPTIMAL
// patil_gm
#include<iostream>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace std;


bool search(int key, vector<int>& fr)
{
	for (int i = 0; i < fr.size(); i++)
		if (fr[i] == key)
			return true;
	return false;
}

int predict(vector<int> pg, vector<int>& fr, int pn, int index)
{
	int res = -1, farthest = index;
	for (int i = 0; i < fr.size(); i++) {
		int j;
		for (j = index; j < pn; j++) {
			if (fr[i] == pg[j]) {
				if (j > farthest) {
					farthest = j;
					res = i;
				}
				break;
			}
		}

		if (j == pn)
			return i;
	}

	return (res == -1) ? 0 : res;
}

void optimalPage(vector<int> pg, int pn, int fn)
{
	vector<int> fr;

	int hit = 0;
	for (int i = 0; i < pn; i++) {

		if (search(pg[i], fr)) {
			hit++;
			continue;
		}

		if (fr.size() < fn)
			fr.push_back(pg[i]);

		else {
			int j = predict(pg, fr, pn, i + 1);
			fr[j] = pg[i];
		}
	}
	cout << "No. of hits = " << hit << endl;
	cout << "No. of misses = " << pn - hit << endl;
}

int main()
{   cout<<"enter the no of pages : ";
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
	optimalPage(pg, n, fn);
	return 0;
}

// 13
// 7 0 1 2 0 3 0 4 2 3 0 3 2 
// 4