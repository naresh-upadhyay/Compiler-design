#include<bits/stdc++.h>
#define MPCV map<char,vector<string>>
#define MPCS map<char,set<string>>
using namespace std;
MPCS mpfirst;//my null is small z;
void firstvalues(MPCV mp,char start){
    char temp= start;
    while(1){
        if(((mp[temp])[0]).size()==1){
            if(islower(((mp[temp])[0])[0])){
                string st(1,((mp[temp])[0])[0]);
                mpfirst[temp].insert(st);
            }else{
                for(int i=0; i<((mp[temp])[0]).size();i++){
                    firstvalues(mp,(((mp[temp])[0])[i]));
                    set<string> vt = mpfirst[(((mp[temp])[0])[i])];
                    for(auto it = vt.begin(); it!= vt.end(); it++){
                        mpfirst[temp].insert(*it);
                    }
                }                
            }
        }else{
            if(islower(((mp[temp])[0])[0])){
                string st(1,((mp[temp])[0])[0]);
                mpfirst[temp].insert(st);
            }            
            if(islower(((mp[temp])[1])[0])){
                string st(1,((mp[temp])[1])[0]);
                mpfirst[temp].insert(st);
            }
        }
    }
}
int main(){
    int num_of_prod;
    cin >> num_of_prod;
    MPCV mp;
    string start;
    cout <<"Assume 'z' as epsilon\n";
    for(int i=0; i<num_of_prod; i++){
        char left_side;
        string right_side;
        cin >>left_side>>right_side;
        mp[left_side].push_back(right_side);
    }
    for(auto it = mp.begin(); it != mp.end(); it++){
        firstvalues(mp,it->first);
    }
    cout <<"Enter start symbol:";
    cin >>start;
    for(auto it = mpfirst.begin(); it!= mpfirst.end();it++){
        cout <<it->first<<"  {";
        for(auto itr = (it->second).begin(); itr!= (it->second).end();itr++){
            cout <<*itr<<", ";
        }cout<<"}"<<endl;
    }
}