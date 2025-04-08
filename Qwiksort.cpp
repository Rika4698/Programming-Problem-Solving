#include<bits/stdc++.h>
using namespace std;

void applySort(vector<int>&arr, int l, int r)
{
    sort(arr.begin()+l-1, arr.begin()+r);
}

bool isSorted(const vector<int>&arr)
{
    for(int i=1; i<arr.size(); i++)
    {
        if(arr[i-1]>arr[i])
            return false;
    }
    return true;
}


void solveSort(int caseNumber, int n, vector<int>&arr)
{
    vector<pair<int, int>> operate;

    for(int i=0; i<10; i++)
    {
        if(isSorted(arr))
            break;

        operate.push_back({1,n});
        applySort(arr, 1, n);
        if(isSorted(arr))
            break;

        operate.push_back({n+1, 2*n});
        applySort(arr, n+1, 2*n );
        if(isSorted(arr))
            break;
        if(n>1)
        {
            operate.push_back({(n/2)+1, (n/2)+n});
            applySort(arr, (n/2)+1, (n/2)+n);
            if(isSorted(arr))
                break;
        }
    }
    cout<< "Case "<<caseNumber<<": "<<operate.size()<<"\n";
    for(const auto& output:operate)
    {
        cout<<output.first<<" "<<output.second<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;

    for(int t=1; t<=T; t++)
    {
        int n;
        cin>>n;
        vector<int>arr(2*n);

        for(int i=0; i<2*n; i++)
        {
            cin>>arr[i];
        }
        solveSort(t, n, arr);
    }

    return 0;
}



