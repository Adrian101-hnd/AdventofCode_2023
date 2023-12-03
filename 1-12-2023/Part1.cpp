#include <bits/stdc++.h>

using namespace std;

//Had to press Ctrl + Z to stop the infinte loop, could have cheated a little by just hardcoding it to read
//1000 lines (That is the amount of inputs) but I in the end left it as is.
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