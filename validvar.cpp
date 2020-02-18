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
    string file_name;
    cin >>file_name;
    if(valid_word(file_name))
        cout <<"Good Choice\n";
    else cout <<"Sorry\n";
}