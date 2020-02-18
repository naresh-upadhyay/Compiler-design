#include<bits/stdc++.h>
using namespace std;
void find_comment(string &st){
    int count =0;
    for(int i=0; st[i]; i++){
        if(st[i] == '/' && st[i+1] == '/'){
            st  = st.substr(i);
            cout <<st<<"\n";
            break;
        }else if(st[i] == '/' && st[i+1] == '*'){
            st = st.substr(i);
            count++;
            continue;
        }else if(st[i] == '*' && st[i+1] == '/'){
            string strtemp = st.substr(i+2);
            st = st.substr(0,i+2);
            cout <<st<<"\n";
            st = strtemp;
            count--;
        }
    }
    if(count > 0)
    cout <<st<<"\n";
}
int main(){
    string line;
    cout <<"Enter line text :";
    getline(cin,line);
    find_comment(line);
}