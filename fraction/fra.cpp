#include <bits/stdc++.h>
using namespace std;

int f[1000002];
int why=-1;
vector<int>d;
string s="";

int nwd(int x, int y)
{
    int t;
    while(y != 0)
    {
        t = x % y;
        x = y;
        y = t;
    }
    return x;
}

string div(string a)
{
    for (int i=0; i<d.size(); i++)
    {
        if(i==why) {a+="(";}
        a+=to_string(d[i]);
    }
    if(why>=0) {a+=")";}
    return a;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int x, y;
    cin>>x>>y;
    if(x%y==0) { cout<<x/y; return 0;}
    s=to_string(x/y)+".";
    int a=x/nwd(x,y);
    int b=y/nwd(x,y);
    a=a%b;
    int i=1;
    while (a!=0) {
        if (f[a]!=0) {why=f[a]-1; break;}
        f[a]=i;
        a*=10;
        d.push_back(a/b);
        a%=b;
        i+=1;
    }
    cout<<div(s);
    return 0;
}
