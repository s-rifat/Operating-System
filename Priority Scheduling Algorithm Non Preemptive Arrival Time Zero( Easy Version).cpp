///for Arrival time zero
#include<bits/stdc++.h>
using namespace std;
struct node
{
    string process;
    double arrivaltime,cputime,priority,waitingtime,turnaroundtime,starttime,finishtime;
    int id;
} arr[50];
bool compare(node a, node b)
{
    if(a.priority== b.priority)
        return a.id<b.id;
    return a.priority<b.priority;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].process>>arr[i].arrivaltime>>arr[i].cputime>>arr[i].priority;
        arr[i].id = i;
    }
    sort(arr,arr+n,compare);
    arr[0].turnaroundtime = arr[0].cputime;
    arr[0].finishtime = arr[0].cputime;
    double totalwait = 0, totalturn = arr[0].turnaroundtime;
    for(int i=1;i<n;i++)
    {
        arr[i].starttime =arr[i-1].finishtime;
        arr[i].finishtime = arr[i].starttime+arr[i].cputime;
        arr[i].waitingtime = arr[i].starttime;
        arr[i].turnaroundtime = arr[i].waitingtime+arr[i].cputime;
        totalwait+=arr[i].waitingtime;
        totalturn+= arr[i].turnaroundtime;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].process<<": waiting time: "<<arr[i].waitingtime<<" turnaround time:"<<arr[i].turnaroundtime<<endl;
    }
    cout<<"\nAverage wait: "<<totalwait/n<<" Average turn: "<<totalturn/n<<endl;
    return 0;
}

/*
3
p1 0 5 0
p2 0 7 2
p3 0 9 1
*/

