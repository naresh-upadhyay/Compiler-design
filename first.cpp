#include<bits/stdc++.h>
#define MCS map<char,set<char>>
#define VC vector<char>
#define VVC vector<string>
#define MVVC map<char,VVC>
#define MCII map<char,int>
#define SET set<char>
using namespace std;

MCS mapset;
MVVC initialmap;

void printset(SET st){
    for(auto it = st.begin(); it != st.end(); it++){
        cout<<*it<<" ";
    }cout<<endl;
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
    for(auto it=initialmap.begin(); it!=initialmap.end(); it++){
        cout<<(it->first)<<"->";
        SET stv = findfirst(it->first,mpflag);
        for(auto iter = stv.begin(); iter!= stv.end(); iter++){
            cout<<*iter<<" ";
        }cout<<endl;
    }
}