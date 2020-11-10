#include<bits/stdc++.h>
using namespace std;
int solve(int *arr, int i, string& str, int p){
    if(p>str.size()+1)return 0;
    if(p==str.size()+1)return arr[i];
    int ans=0;
    if(str[p]=='L')ans+=solve(arr, (i*2)+1, str, p+5);
    else if(str[p]=='R' and str[p+1]=='i')ans+=solve(arr, (i*2)+2, str, p+6);
    else if(str[p]=='R' and str[p+1]=='a')ans+=solve(arr, i, str, p+5);
    else ans+=(solve(arr, (i*2)+1, str, p+4)+solve(arr, (i*2)+2, str, p+4)+solve(arr, i, str, p+4));
    return ans;
}
int main()
{
    int *arr = new int[100000];
    for(int i=0; i<100000; i++)arr[i]=i+1;
    string str;
    cin>>str;
    cout<<solve(arr, 0, str, 0);
}
