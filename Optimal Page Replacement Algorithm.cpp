/*
Syed Rifat
170104026
*/
#include<bits/stdc++.h>
using namespace std;

int Find_Replace_Index(int i,int nPageFrame, int nRef, int* pageFrame, int* Ref)
{
    int maax = INT_MIN;
    int I = 0;

    for(int j = 0;j<nPageFrame;j++)
    {
        if(pageFrame[j]==-1)
            return j;

        int ix = INT_MAX;
        for(int k = i+1;k<nRef;k++)
        {
            if(Ref[k]==pageFrame[j])
            {
                ix = k;
                break;
            }
        }

        if(ix>maax)
        {
            maax = ix;
            I = j;
        }
    }
    return I;
}
double rate(double pageFault, double nRef)
{
    return (pageFault*100.00)/nRef;
}
int main()
{
    cout<<"Number of pages: ";
    int nPage;
    cin>>nPage;

    cout<<"Number of Page References: ";
    int nRef;
    cin>>nRef;


    cout<<"Reference: ";
    int Ref[nRef];
    for(int i=0;i<nRef;i++)
        cin>>Ref[i];

    cout<<"Number of Memory Page Frame: ";
    int nPageFrame;
    cin>>nPageFrame;

    int pageFrame[nPageFrame];
    map<int,int> mp;

    for(int i=0;i<nPageFrame;i++)
        pageFrame[i] = -1; //-1 means empty

    int Replace = 0;
    int pageFault = 0;
    for(int i=0;i<nRef;i++)
    {
        if(mp[Ref[i]]==0)
        {
            int Replace = Find_Replace_Index(i,nPageFrame,nRef,pageFrame,Ref);
            mp[pageFrame[Replace]] = 0;
            pageFrame[Replace] = Ref[i];
            mp[Ref[i]] = 1;
            pageFault++;
        }
    }

    cout<<"Number of page fault using Optimal Page replacement Algorithm: "<<pageFault<<endl;
    cout<<"Page Fault Rate: "<<rate(pageFault,nRef)<<"%"<<endl;

    return 0;
}
/*
8
22
7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
3
*/

