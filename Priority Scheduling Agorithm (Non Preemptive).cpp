#include<bits/stdc++.h>
using namespace std;
struct node
{
    string process;
    double arrivaltime,cputime,priority,waitingtime,turnaroundtime,starttime,finishtime;
    int id,index,pushed;
} arr[50];
bool compare(node a, node b)
{
    if(a.arrivaltime== b.arrivaltime)
        return a.id<b.id;
    return a.arrivaltime<b.arrivaltime;
}
bool operator<(const node& a, const node& b) {
    if(a.priority == b.priority)
        return a.id > b.id;
  return a.priority > b.priority;
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
    for(int i=0;i<n;i++)
    {
        arr[i].index = i;
    }
    priority_queue<node > q;
    q.push(arr[0]);
    arr[0].pushed = 1;
    double time = arr[0].arrivaltime;
    while(!q.empty())
    {
        node current = q.top();
        q.pop();
        time = max(time,current.arrivaltime);
        arr[current.index].starttime = time;
        arr[current.index].finishtime = time+current.cputime;
        time+=current.cputime;
        for(int i=0;i<n;i++)
        {
            if(arr[i].arrivaltime<=time && arr[i].pushed ==0)
            {
                q.push(arr[i]);
                arr[i].pushed = 1;
            }
        }
    }
    double totalwait = 0, totalturn = 0;
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        arr[i].waitingtime = arr[i].starttime-arr[i].arrivaltime;
        totalwait+=arr[i].waitingtime;
        arr[i].turnaroundtime = arr[i].waitingtime+arr[i].cputime;
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
p1 4 5 0
p2 0 7 2
p3 2 9 1
*/

