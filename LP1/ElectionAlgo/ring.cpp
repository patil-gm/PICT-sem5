// #include <bits/stdc++.h>
// patil-gm
#include<iostream>

using namespace std;
class Ring
{
    int token[100];
    int l = 0;

public:
    void print()
    {
        cout << "\t ___ Token received : "<< endl;
        for (int i = 0; i < l; i++)
            cout << token[i] << ", ";
        cout << endl;
    }

    Ring()
    {
        int winner, max = -1;

        cout << "Enter the Total Number of processes = "<< endl;
        int n;
        cin >> n;
        winner = n;
        int processes[n + 1];
        int status[n + 1];
        cout << "Enter the status of processes (1/0) ....."<< endl;
        for (int i = 0; i < n; i++)
        {
            processes[i] = i;
            cout << "Enter the status of process " << i << " = "<< endl;
            cin >> status[i];
        }
        cout << "Enter the process initiator = "<< endl;
        int x;
        cin >> x;

        int i = x;
        while (i < n)
        {
            if (status[i] == 1)
            {
                int next = i + 1;
                while (next < n)
                {
                    if (status[next] == 1)
                    {
                        cout << "Election message is sent from " << i << " to " << next<< endl;
                        token[l] = i;
                        l++;
                        print();
                        winner = next;
                        break;
                    }
                    else
                    {
                        next++;
                    }
                }
            }
            i++;
        }

        cout << "Election message is sent from " << winner << " to 0"<< endl;
        token[l] = winner;
        l++;
        print();
        i = 0;
        while (i < x)
        {
            if (status[i] == 1)
            {
                int next = i + 1;
                while (next < n)
                {
                    if (status[next] == 1)
                    {
                        cout << "Election message is sent from " << i << " to " << next<< endl;
                        token[l] = i;
                        l++;
                        print();
                        break;
                    }
                    else
                    {
                        next++;
                    }
                }
            }
            i++;
        }

        for (int j = 0; j < l; j++)
        {
            if (token[j] > max)
                max = token[j];
        }
        cout << "Co-ordinator is " << max<< endl;
    }
};
int main()
{   
    Ring r;
    return 0;
}