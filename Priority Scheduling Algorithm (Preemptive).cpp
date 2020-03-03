#include<bits/stdc++.h>
using namespace std;
struct node
{
    string process;
    double arrivaltime,initialcputime,cputime,priority,waitingtime,turnaroundtime;
    vector<double> starttime,finishtime;
    int id,index,pushed,responed;
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
        arr[i].initialcputime = arr[i].cputime;
    }
    sort(arr,arr+n,compare);
    for(int i=0;i<n;i++)
    {
        arr[i].index = i;
    }
    priority_queue<node > q;
    q.push(arr[0]);
    arr[0].pushed = 1;
    arr[0].responed = 1;
    double time = arr[0].arrivaltime;
    int cnt = 1;
    int x = 1;
    while(!q.empty())
    {
        node current = q.top();
        q.pop();
        time = max(time,current.arrivaltime);
        if(cnt==n)
        {
            x = current.cputime;
        }
        current.cputime-=x;
        current.pushed = 0;
        arr[current.index].pushed = 0;
        arr[current.index].cputime-=x;
        arr[current.index].starttime.push_back(time);
        arr[current.index].finishtime.push_back(time+x);
        time+=x;
        if(cnt!=n)
        {
            for(int i=0;i<n;i++)
            {
                if(arr[i].arrivaltime<=time && arr[i].pushed ==0 && arr[i].cputime!=0)
                {
                    q.push(arr[i]);
                    arr[i].pushed = 1;
                    if(arr[i].responed ==0)
                    {
                         arr[i].responed = 1;
                         cnt++;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].process<<" ";
        for(int j=0;j<arr[i].starttime.size();j++)
        {
            cout<<" "<<arr[i].starttime[j]<<" "<<arr[i].finishtime[j]<<endl;
        }
        cout<<endl;
    }
    double totalwait = 0, totalturn = 0;
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
3
p1 4 5 0
p2 0 7 2
p3 2 9 1
*/

/*
7
p1 0 8 3
p2 1 2 4
p3 3 4 4
p4 4 1 5
p5 5 6 2
p6 6 5 6
p7 10 1 1
*/


