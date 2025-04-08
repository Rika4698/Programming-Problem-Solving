#include<bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin>>t;
    vector<tuple<int, int, int>>outcomes;

    for(int AB=0; AB<3; AB++)
    {
        for(int BC=0; BC<3; BC++)
        {
            for(int CA=0; CA<3; CA++)
            {
                int pointA=0, pointB=0, pointC=0;
                if(AB==0)
                    pointA+=3;
                else if(AB==1)
                    pointB+=3;
                else{pointA+=1; pointB+=1;}

                if(BC==0)
                    pointB+=3;
                else if(BC==1)
                    pointC+=3;
                else{pointB+=1; pointC+=1;}


                if(CA==0)
                    pointC+=3;
                else if(CA==1)
                    pointA+=3;
                else{pointC+=1; pointA+=1;}

                outcomes.push_back({pointA, pointB, pointC});
            }
        }
    }



    for(int n=1; n<=t; n++)
    {
        int A, B, C;
        cin>>A>>B>>C;

        bool isvalid=false;

        for(const auto&output: outcomes)
        {
            int p, q, r;
            tie(p,q, r)= output;
            if(A==p && B==q && C==r){
                isvalid=true;
                break;
            }

        }
        cout<<"Case " << n <<": "<< (isvalid?"perfectus" : "invalidum") <<endl;
    }


    return 0;
}
