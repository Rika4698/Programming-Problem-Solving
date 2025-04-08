
 #include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int x1=x;
        vector<int>value;
        vector<int>arr(n+1,0);
        for(int i=2;i<=sqrt(x)+1;i++){
               // cout<<"haha "<<x<<" "<<i<<endl;
            while(x%i==0){
                value.push_back(i);
                x/=i;
            }
        }
        if(x>1)value.push_back(x);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(value.begin(),value.end());
        int age=0;
        int pt=0;
        vector<pair<int,int>>vv;
        for(int i=0;i<value.size();i++){
            if(pt==0)pt=value[i];
            if(pt==value[i])++age;
            else{
                vv.push_back({pt,age});
                pt=value[i];
                age=1;
            }
        }
        if(pt>0)
        vv.push_back({pt,age});
        //for(int i=0;i<vv.size();i++)cout<<vv[i].first<<" "<<vv[i].second<<endl;
        vector<vector<int>>sum(vv.size()+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
                int kk=arr[i];
            for(int j=0;j<vv.size();j++){
                while(kk%vv[j].first==0){
                        sum[j][i]++;
                     kk/=vv[j].first;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<vv.size();j++){
                    sum[j][i]+=sum[j][i-1];
                   // cout<<sum[j][i]<<" ";
            }
           // cout<<endl;
        }
        vector<int>akn(n+1,INT_MAX);
        for(int i=0;i<n;i++){
            int low=i,high=n-1;
            vector<int>biyok(vv.size(),0);
            if(i!=0){
                for(int j=0;j<vv.size();j++)biyok[j]=sum[j][i-1];
            }
            int ans=INT_MAX;
            while(high>=low){
                int mid=(high+low)/2;
                int flag=0;
                for(int j=0;j<vv.size();j++){
                    if(sum[j][mid]-biyok[j]<vv[j].second)flag=1;
                }
                if(!flag){
                    ans=mid;
                    high=mid-1;
                }else low=mid+1;

            }
           // cout<<ans<<endl;
            akn[i]=ans;
        }
        for(int i=n-2;i>=0;i--){
               // cout<<akn[i]<<endl;
            akn[i]=min(akn[i],akn[i+1]);
        }
        int q;
        cin>>q;
        while(q--){
            int a,b;
            cin>>a>>b;
           // cout<<akn[a-1]<<" "<<b-1<<endl;
            if(x1==1){
                cout<<"Yes"<<endl;
            }else{
                if(akn[a-1]<=b-1)cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }

        }

    }
}
