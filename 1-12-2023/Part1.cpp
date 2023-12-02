#include <bits/stdc++.h>

using namespace std;


int main(){
    string text;
    int sum = 0;

    while(cin>>text){
        string first_num = "10";
        string last_num;
        for(int i = 0;i!=text.size();i++){
            if(isdigit(text[i])){
                if(first_num == "10"){
                    first_num = text[i];
                    last_num = text[i];
                }
                else{
                    last_num = text[i];
                }
            }
        }
        int num = stoi(first_num + last_num);
        sum += num;
    }
    cout<<sum;
}