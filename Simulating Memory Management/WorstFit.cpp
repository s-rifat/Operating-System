#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Number of memory holes: ";
    int nHole;
    cin>>nHole;

    int hole[100];
    cout<<"Memory holes: ";
    for(int i=0;i<nHole;i++)
        cin>>hole[i];

    cout<<"Number of memory requests: ";
    int nReq;
    cin>>nReq;

    int req[100];
    cout<<"Memory requests: ";
    for(int i=0;i<nReq;i++)
        cin>>req[i];

    int output[100][100];
    memset(output,-1,sizeof(output));
    for(int i = 0;i<nReq;i++)
        output[0][i] = req[i];

    int exfrag= 0;

    for(int i=0;i<nReq;i++)
    {
        int mx = INT_MIN;
        int ix = -1;

        for(int j = 0;j<nHole;j++)
        {
            if(hole[j]>=req[i] && hole[j]>mx)
            {
                mx = hole[j];
                ix = j;
            }
        }

        if(ix==-1)
        {
             for(int j = 0;j<nHole;j++)
                exfrag+=hole[j];
             if(exfrag<req[i])
                exfrag = 0;
             break;
        }

        hole[ix]-=req[i];

        for(int j = 0;j<nHole;j++)
            output[j+1][i] = hole[j];
    }

    cout<<"\nWorst Fit\nStep by step memory allocation situation in Worst Fit\n"<<endl;
    for(int i=0;i<=nHole;i++)
    {
        for(int j=0;j<nReq;j++)
        {
            cout<<output[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nExternal Fragmentation: "<<exfrag<<endl;

    return 0;
}
/*
5
50 200 70 115 15
10
100 10 35 15 23 6 25 55 88 40
*/

