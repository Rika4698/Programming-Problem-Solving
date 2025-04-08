#include<iostream>
#include<string>
using namespace std;
int main()
{
    string inputText;
    cin>>inputText;
    int len = inputText.length();
    char max=0,count=0;
    for(int i=0;i<len;i++)
    {
        if(max<inputText[i])
        {
            max=inputText[i];
            count= 1;
        }
        else if(max==inputText[i])
        {
            count++;
        }
    }
    for(int i=0;i<count;i++)
    {
        cout<< max ;
    }
    return 0;
}
