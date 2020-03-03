#include<bits/stdc++.h>
using namespace std;
struct node
{
    string process;
    double cputime,initialcputime,arrivaltime,waitingtime,turnaroundtime;
    vector<double>starttime,finishtime;
    int id,index,pushed;
} arr[50];
bool compare(node a, node b)
{
    if(a.arrivaltime==b.arrivaltime)
        return a.id<b.id;
    return a.arrivaltime<b.arrivaltime;
}
int main()
{
    int n;
    double timequantum,time,spend, totalwait = 0, totalturn = 0;
    node current;
    queue<node>q;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].process>>arr[i].arrivaltime>>arr[i].cputime;
        arr[i].initialcputime = arr[i].cputime;
        arr[i].id = i;
    }
    cin>>timequantum;
    sort(arr,arr+n,compare);
    for(int i=0;i<n;i++)
    {
        arr[i].index = i;
    }
    arr[0].pushed = 1;
    q.push(arr[0]);
    time = arr[0].arrivaltime;
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        current.pushed = 0;
        arr[current.index].pushed = 0;

        spend= min(current.cputime,timequantum);
        current.cputime -= spend;
        arr[current.index].cputime -= spend;

        time = max(current.arrivaltime,time);
        arr[current.index].starttime.push_back(time);
        arr[current.index].finishtime.push_back(time+spend);
        time+=spend;

        if(current.cputime==0)
        {
            for(int i=0;i<n;i++)
            {
                if(arr[i].cputime!=0 && arr[i].pushed==0)
                {
                    q.push(arr[i]);
                    arr[i].pushed = 1;
                    break;
                }
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(arr[i].cputime!=0 && arr[i].arrivaltime<=time && arr[i].pushed==0 && i!=current.index )
                {
                    q.push(arr[i]);
                    arr[i].pushed = 1;
                }
            }
            q.push(current);
            arr[current.index].pushed = 1;
        }
    }
    for(int i=0;i<n;i++)
    {
        arr[i].waitingtime = arr[i].starttime[0] - arr[i].arrivaltime;
        for(int j=1;j<arr[i].starttime.size();j++)
        {
             arr[i].waitingtime += arr[i].starttime[j]-arr[i].finishtime[j-1];
        }
        arr[i].turnaroundtime = arr[i].waitingtime + arr[i].initialcputime;
        totalwait+= arr[i].waitingtime;
        totalturn+= arr[i].turnaroundtime;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].process<<": Waiting time: "<<arr[i].waitingtime<<" turnaround time: "<<arr[i].turnaroundtime<<endl;
    }
    cout<<"Average waiting time: "<<totalwait/n<<"\nAverage turnaround time: "<<totalturn/n<<endl;
    return 0;
}

/*
4
p1 4 5
p2 0 7
p3 6 9
p4 10 9
3
*/







