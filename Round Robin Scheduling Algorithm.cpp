#include<bits/stdc++.h>
using namespace std;
struct node
{
    string process;
    double cputime,ct,arrivaltime,At,waitingtime,turnaroundtime;
    int id,index,pushed;
} arr[50];
struct node2
{
    string process;
    int starttime,finishtime;
};
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
    vector<node2>v;
    node2 temp;
    int current;
    queue<int>q;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].process>>arr[i].arrivaltime>>arr[i].cputime;
        arr[i].ct = arr[i].cputime;
        arr[i].At = arr[i].arrivaltime;
        arr[i].turnaroundtime = arr[i].cputime;
        arr[i].id = i;
    }
    cin>>timequantum;
    sort(arr,arr+n,compare);
    for(int i=0;i<n;i++)
    {
        arr[i].index = i;
    }
    arr[0].pushed = 1;
    q.push(arr[0].index);
    time = arr[0].arrivaltime;
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        arr[current].pushed = 0;

        spend= min(arr[current].cputime,timequantum);
        arr[current].cputime -= spend;

        time = max(arr[current].arrivaltime,time);
        temp.starttime = time;
        arr[current].waitingtime+=time-arr[current].At;
        time+=spend;
        temp.finishtime = time;
        arr[current].At = time;

        temp.process = arr[current].process;
        v.push_back(temp);

        if(arr[current].cputime==0)
        {
            for(int i=0;i<n;i++)
            {
                if(arr[i].cputime!=0 && arr[i].pushed==0)
                {
                    q.push(arr[i].index);
                    arr[i].pushed = 1;
                    break;
                }
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(arr[i].cputime!=0 && arr[i].arrivaltime<=time && arr[i].pushed==0 && i!=current )
                {
                    q.push(arr[i].index);
                    arr[i].pushed = 1;
                }
            }
            q.push(arr[current].index);
            arr[current].pushed = 1;
        }
    }
    for(int i=0;i<n;i++)
    {
        arr[i].turnaroundtime+=arr[i].waitingtime;
        totalwait+= arr[i].waitingtime;
        totalturn+= arr[i].turnaroundtime;
    }
    cout<<"chart:"<<endl;
    for(int i=0;i<v.size();i++)
    {
       cout<<v[i].starttime<<" "<<v[i].process<<" "<<v[i].finishtime<<endl;
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
p1 4 5
p2 0 7
p3 6 9
p4 10 9
3
*/









