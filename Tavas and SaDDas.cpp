#include<bits/stdc++.h>

using namespace std;

int main()
{
    string n;
    cin>>n;
    int l = n.size();
    int index = 0;
    for(int i=1; i<l; i++)
    {
       index= index+(1<<i);
    }
    for(int s=0; s<l; s++)
        {
            if(n[s]=='7')
            {
                index = index + (1<<(l - s - 1));
            }
        }
        cout<<index+1<<"\n";
        return 0;
}
