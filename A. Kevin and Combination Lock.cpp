#include<bits/stdc++.h>
using namespace std;

int main (){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int x;
        cin >> x;
        while(true)
        {
            if(x < 33){
                cout << "NO\n";
                break;
            }
            if(x % 33 == 0){
                cout << "YES\n";
                break;
            }
            string y = to_string(x);
            if(y.find("33")!= y.npos){
                x = stoi(y.erase(y.find("33"), 2));
            }
            else{
                x = x-33;
            }

        }
    }

    return 0;
}
