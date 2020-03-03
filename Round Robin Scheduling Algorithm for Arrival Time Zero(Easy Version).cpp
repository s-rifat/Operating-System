///for arrival time zero
#include<bits/stdc++.h>
using namespace std;
struct node
{
    string process;
    double cputime,initialcputime,arrivaltime,waitingtime,turnaroundtime;
    vector<double>starttime,finishtime;
    int id,index;
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
    ///variable declaration done
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].process>>arr[i].arrivaltime>>arr[i].cputime;
        arr[i].initialcputime = arr[i].cputime;
        arr[i].id = i;
    }
    cin>>timequantum;
    ///input done
    sort(arr,arr+n,compare);///sorting
    for(int i=0;i<n;i++)
    {
        arr[i].index = i;
        q.push(arr[i]); ///pushing all process to queue as arrival time zero
    }
    time = 0;
    while(!q.empty())
    {
        current = q.front();
        q.pop();

        spend= min(current.cputime,timequantum); ///spending time
        current.cputime -= spend;
        arr[current.index].cputime -= spend;

        arr[current.index].starttime.push_back(time);
        arr[current.index].finishtime.push_back(time+spend);
        time+=spend;

        if(current.cputime!=0)
            q.push(current); ///if not finished pushing again
    }


    ///calculating turning and waiting
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

    ///printing..............
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].process<<": Waiting time: "<<arr[i].waitingtime<<" turnaround time: "<<arr[i].turnaroundtime<<endl;
    }
    cout<<"Average waiting time: "<<totalwait/n<<"\nAverage turnaround time: "<<totalturn/n<<endl;
    return 0;
}
/*
4
p1 0 5
p2 0 7
p3 0 9
p4 0 9
3
*/








