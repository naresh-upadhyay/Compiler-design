#include<bits/stdc++.h>
#define MCS map<char,set<char>>
#define VC vector<char>
#define VVC vector<string>
// #define VVS vector<VVC>
#define MVVC map<char,VVC>
#define MCII map<char,int>
#define SET set<char>
using namespace std;
SET findfirst(char ch,MCII mpflag);
SET findFollow(char ch,MCII mpflag);
void printset(SET st);
MCS mapset;
MCS mapsetfollow;
MVVC initialmap;
MVVC table;
int main(){
    char ch;
    int numprod,numblock;
    cout <<"Enter the number of productions \n";
    cin >>numprod;
    MCII mpflag;
    for(int i=0; i<numprod; i++){
        cout<<"Enter left had variable and no. of block right side :";
        cin>>ch>>numblock;
        mpflag[ch] = 0;
        cout<<"Enter right hand # as epislon:";
        for(int j=0; j<numblock; j++){
            string str;
            cin >>str;
            initialmap[ch].push_back(str);
        }
    }
    //finding first
    cout <<"Printing first"<<endl;
    for(auto iterate : initialmap){
        cout<<iterate.first<<"->";
        SET st= findfirst(iterate.first,mpflag);
        printset(st);
    }
    cout <<"Printing follow"<<endl;
    //finding follow
    for(auto iterate : initialmap){
        cout<<iterate.first<<"->";
        SET st= findFollow(iterate.first,mpflag);
        printset(st);
    }
    //table filling
    for(auto iterate2 : initialmap){
        SET stfirst = mapset[iterate2.first];
        VVC vctstr;
        vctstr.resize(4);
        for(int i=0; i<3; i++){//fill by first
            if(stfirst.find('a'+i)!= stfirst.end()){
                vctstr[i] = iterate2.second[0];
            }
            else vctstr[i] = "";
        }
        if(stfirst.find('#') != stfirst.end()){
            SET stfollow = mapsetfollow[iterate2.first];
            for(int i=0; i<3; i++){//fill by follow
                if(stfollow.find('a'+i)!= stfollow.end()){
                    vctstr[i] = '#';
                }
            }
            //fill dollar
            if(stfollow.find('$')!= stfollow.end()){
                vctstr[3] = '#';
            }

        }
        table[iterate2.first] = vctstr;
    }
    //printing parsing table
    cout<<"Printing parsing table\n";
    for(auto it2 : table){
        cout<<it2.first<<"\t";
        VVC vcts = it2.second;
        for(int i=0; i<vcts.size(); i++){
            cout<<vcts[i]<<"\t";
        }cout<<endl;
    }
}

void printset(SET st){
    for(auto it = st.begin(); it != st.end(); it++){
        cout<<*it<<" ";
    }cout<<endl;
}


SET findFollow(char ch,MCII mpflag){
    if(mapsetfollow[ch].size() || mpflag[ch]){
        return mapsetfollow[ch];
    }
    SET follow;
    if(ch == 'E'){
        follow.insert('$');
    }
    for(auto it :initialmap){
        VVC vct = it.second;
        for(int i=0; i<vct.size(); i++){
            string str = vct[i];
            mpflag[ch] =1;
            char tch = ch;
            for(int j = 0; str[j]; j++){//find first of next variable
                SET temp;
                if(str[j] == tch && j+1<str.size()){
                    if(str[j+1]>='A' && str[j+1]<='Z'){
                        temp = mapset[str[j+1]];
                    }else if(str[j+1]>='a' && str[j+1]<='z'){
                        temp.insert(str[j+1]);
                    }  
                    if(temp.find('#') != temp.end()){
                        //again fill follow of ch
                        tch = str[j+1];
                        temp.erase(temp.find('#'));
                    }else{
                        follow.insert(temp.begin(),temp.end());
                        break;
                    }                  
                }
                else if(str[j] == tch && j+1 == str.size()){
                    temp = findFollow(it.first,mpflag);
                }
                follow.insert(temp.begin(),temp.end());
            }
            mpflag[ch] =0;
        }
    }
    mapsetfollow[ch] = follow;
    return follow;

}


SET findfirst(char ch,MCII mpflag){
    if(mapset[ch].size() || mpflag[ch]){
        return mapset[ch];
    }
    SET stch,newst;
    VVC vct = initialmap[ch];
    mpflag[ch] = 1;
    for(int i=0;i<vct.size();i++){//2d arrary 
    // what about sigma
        if(vct[i][0] >= 'a' && vct[i][0] <= 'z' || vct[i][0]=='#'){
            stch.insert(vct[i][0]);
        }else{
            int k=0;
            newst = findfirst(vct[i][k],mpflag);
            while(newst.find('#') != newst.end() && k<(vct[i].size()-1)){
                k++;
                if(vct[i][k] >= 'a' && vct[i][k] <= 'z'){
                    stch.insert(vct[i][k]);
                    break;
                }else{
                    stch.insert(newst.begin(),newst.end());
                    stch.erase(stch.find('#'));
                    newst = findfirst(vct[i][k],mpflag);
                }

            }            
            stch.insert(newst.begin(),newst.end());
        }
    }
    mpflag[ch] = 0;
    mapset[ch] = stch;
    return stch;
}
