#include <bits/stdc++.h>
using namespace std;
bool match(string st)
{ //a*/a*b+
    for (int i = 0; st[i]; i++)
    {
        if (st[i] == 'a' || st[i] == 'b')
        {
            if (st[i] == 'b' && st[i + 1] == 'a')
            {
                return false;
            }
        }else{
            return false;
        }
    }
    return true;
}
int main()
{
    string st;
    cin >> st;
    if(match(st)){
        cout <<"Nice input\n";
    }else cout<<"Oh sorry\n";
}