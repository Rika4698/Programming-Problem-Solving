#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    map<int,int>required_digit={{0,3},{1,1},{2,2},{3,1},{5,1}};

    while(t--)
    {
        int n;
        cin>>n;

        vector<int>digits(n);

        for(int i=0;i<n;i++)
        {
            cin>> digits[i];
        }
        map<int, int>current_count;

        int result=0;

        for(int i=0;i<n;i++)
        {
            current_count[digits[i]]++;

            bool form_date = true;

            for(const auto&[digit, count]: required_digit){
                if(current_count[digit]< count){
                    form_date = false;
                    break;
                }
            }
            if(form_date)
            {
                result = i+1;
                break;
            }
        }

        cout<<result<<endl;

    }
    return 0;
}
