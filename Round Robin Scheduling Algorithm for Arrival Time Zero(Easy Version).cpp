///for arrival time zero
#include<bits/stdc++.h>
using namespace std;
struct node
{
    string process;
    double cputime,arrivaltime,waitingtime,turnaroundtime;
} arr[50];
int main()
{
    int n;
    double timequantum,time,spend, totalwait = 0, totalturn = 0;
    vector<string> v;
    ///variable declaration done
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].process>>arr[i].arrivaltime>>arr[i].cputime;
        arr[i].turnaroundtime = arr[i].cputime;
    }
    cin>>timequantum;
    ///input done
    time = 0;
    int died = 0;
    while(died<n)
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i].cputime!=0)
            {
                v.push_back(arr[i].process);
                spend= min(arr[i].cputime,timequantum);
                arr[i].cputime -= spend;
                arr[i].waitingtime+=time-arr[i].arrivaltime;
                time+=spend;
                arr[i].arrivaltime = time;
                if(arr[i].cputime==0)
                    died++;
            }
        }
    }
    ///calculating turning and waiting
    for(int i=0;i<n;i++)
    {
        arr[i].turnaroundtime+=arr[i].waitingtime;
        totalwait+=arr[i].waitingtime;
        totalturn+=arr[i].turnaroundtime;
    }
    ///printing..............
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].process<<": Waiting time: "<<arr[i].waitingtime<<" turnaround time: "<<arr[i].turnaroundtime<<endl;
    }
    cout<<"Average waiting time: "<<totalwait/n<<"\nAverage turnaround time: "<<totalturn/n<<endl;
    return 0;
}
/*
4
p1 0 4
p2 0 7
p3 0 2
p4 0 2
3
*/








