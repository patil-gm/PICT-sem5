// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Bully
{

    int n;
    int pro[100];
    int sta[100];
    int co;

public:
    void elect(int ele)
    {   co=ele;
        ele--;
      
        for (int i = 0; i < n; i++)
        {
            if (pro[ele] < pro[i])
            {
                cout << "\n\t Election message is sent from " << (ele + 1) << " to " << (i + 1) << endl;
                if (sta[i] == 1)
                    elect(i + 1);
            }
        }
    }
    void getInput()
    {
        cout << "Enter total number of processes:" << endl;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter the sta of process " << i + 1 << ":(0/1)";
            cin >> sta[i];
            cout << endl;
            cout << "Enter priority:";
            cin >> pro[i];
        }
        cout << "Which process will initiate the election?: ";
        int ele;
        cin >> ele;
        elect(ele);
        cout << "Final co-ordinator is:" << co << endl;
    }
};

int main()
{
    Bully b;
    b.getInput();
    return 0;
}
