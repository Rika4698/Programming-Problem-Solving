#include <bits/stdc++.h>

using namespace std;

bool isRXCY(const string& coord)
{
    if(coord.size() < 4) return false;
    if(coord[0] != 'R' || !isdigit(coord[1])) return false;
    size_t posC = coord.find('C');
    if(posC == string::npos || posC == 1)return false;
    for(size_t i=2; i<posC; i++)
    {
        if(!isdigit(coord[i]))return false;

    }
    for(size_t i= posC + 1; i< coord.size(); i++)
    {
        if(!isdigit(coord[i])) return false;

    }
    return true;
}

string RXCYtoExcel(const string& coord)
{
    int posC = coord.find('C');
    int row = stoi(coord.substr(1,posC-1));
    int col = stoi(coord.substr(posC+1));
    string excel="";
    while(col>0)
    {
        int rem = (col-1)%26;
        excel = char('A'+ rem)+excel;
        col=(col-rem -1 )/ 26;

    }
    excel+= to_string(row);
    return excel;

}

string ExceltoRXCY(const string& coord)
{
    string row="", col="";
    for(char c : coord)
    {
        if(isdigit(c))row+=c;
        else col+=c;
    }
    int colNum = 0;
    for(char c : col)
    {
        colNum = colNum * 26 +(c - 'A' + 1);
    }
    return "R" + row + "C" + to_string(colNum);
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++)
    {
        string coord;
        getline(cin,coord);
        if(isRXCY(coord))
        {
            cout<< RXCYtoExcel(coord) << endl;
        }
        else cout<< ExceltoRXCY(coord) << endl;
    }
    return 0;
}
