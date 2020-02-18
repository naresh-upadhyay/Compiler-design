#include<bits/stdc++.h>
#define VST vector<string>
using namespace std;
string st = "";
bool E(VST vct,int &i);
bool F(VST vct,int &i){
    st = '(';
    if(vct[i] == st){
        i++;//todo
        if(E(vct,i)){
            st = ')';
            if(vct[i] == st){
                i++;
                return true;
            }
        }
        return false;
    }else if(vct[i] >= "0" && vct[i] <= "9"){
        cout <<vct[i]<<endl;
        i++;
        return true;
    }return true;
}
bool T1(VST vct,int &i){
    if(vct[i] == "*"){
        i++;
        if(F(vct,i)){
            if(T1(vct,i)){
                return true;
            }
        }
        return false;
    }else return true;
}
bool T(VST vct,int &i){
    if(F(vct,i)){
        if(T1(vct,i)){
            return true;
        }
    }
    return false;
}
bool E1(VST vct,int &i){
    if(vct[i] == "+"){
        i++;
        if(T(vct,i)){
            if(E1(vct,i)){
                return true;
            }
        }
        return false;
    }else return true;
}
bool E(VST vct,int &i){
    if(T(vct,i)){
        if(E1(vct,i)){
            return true;
        }
    }
    return false;
}
int main(){
    string str="";
    VST vct;
    char ch;
    while(cin >> ch){
        if(ispunct(ch) && ch != '_'){
            vct.push_back(str);
            str = "";
            str = ch;
            vct.push_back(str);
            str = "";
        }
        str += ch;
    }
    int i=0;
    if(E(vct,i)){
        cout <<"Good job\n";
    }




    // chcurrent = getchar();
    // if(E()){
    //     if(chcurrent != ' ')
    //     chcurrent = getchar();
    //     if(chcurrent == '$'){
    //         cout <<"Done"<<endl;
    //     }
    // }else{
    //     cout <<"OH no"<<endl;
    // }
}