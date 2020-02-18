#include<bits/stdc++.h>
using namespace std;

bool valid_word(string word){
    for(int i =0; word[i] ; i++){
        if(ispunct(word[i]) && word[i] != '_'){
            return false;
        }
    }
    if(isdigit(word[0]))
    return false;
    else
    return true;
}

int main(){
    ifstream ifile;
    string file_name;
    cin >>file_name;
    if(valid_word(file_name))
        cout <<"Good Choice\n";
    else cout <<"Sorry\n";
    ifile.open(file_name);
    string words,line;
    /*while(ifile >> line){
        stringstream strstream(line);
        while()
    }*/
    /*    ifstream ifile;
    string file_name;
    cin >>file_name;
    ifile.open(file_name);
    string complete_code,line;
    while(getline(ifile,line)){
        find_comment(line);
    }
*/
}
/*
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
*/