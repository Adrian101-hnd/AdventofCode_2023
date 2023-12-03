#include <bits/stdc++.h>

using namespace std;

//Had to press Ctrl + Z to stop the infinte loop, could have cheated a little by just hardcoding it to read
//1000 lines (That is the amount of inputs) but I in the end left it as is.


string checkNum(string num){
    if(num == "one"){
        return "1";
    }
    if(num == "two"){
        return "2";
    }
    if(num == "three"){
        return "3";
    }
    if(num == "four"){
        return "4";
    }
    if(num == "five"){
        return "5";
    }
    if(num == "six"){
        return "6";
    }
    if(num == "seven"){
        return "7";
    }
    if(num == "eight"){
        return "8";
    }
    if(num == "nine"){
        return "9";
    }
    else{
        return "10";
    }
    }


int main(){
    string text;
    int sum = 0;

    int max = 1000;
    while(cin>>text){
        string first_num = "10";
        string last_num;
        string possible_num = "";
        for(int i = 0;i!=text.size();i++){
            if(isdigit(text[i])){
                possible_num = "";
                if(first_num == "10"){
                    first_num = text[i];
                    last_num = text[i];
                }
                else{
                    last_num = text[i];
                }
            }
            else{
                if((text[i] == 'o' || text[i] == 'f' || text[i] == 't' || text[i] == 's' || text[i] == 'e' || text[i] == 'n') && possible_num.size() == 0){
                    possible_num += text[i];
                }
                else if(possible_num.size() != 0){
                    int text_size = possible_num.size();
                    //ONE CASE
                    if(possible_num[0] == 'o'){
                        if(text_size == 1 && text[i] == 'n'){
                            possible_num += text[i];
                        }
                        else if(text_size == 2 && text[i] == 'e'){
                            possible_num += text[i];
                        }
                        else if(text[i] == 'o' || text[i] == 'f' || text[i] == 't' || text[i] == 's' || text[i] == 'e' || text[i] == 'n'){
                            possible_num = text[i];
                        }
                        else{
                            possible_num = "";
                        }
                        
                    }
                    else if(possible_num[0] == 'f'){
                        if(text_size == 1 && (text[i] == 'o' || text[i] == 'i' )){
                            possible_num += text[i];
                        }
                        else if(text_size == 2 && text[i] == 'u' && possible_num[1] == 'o'){
                            possible_num += text[i];
                        }
                        else if(text_size == 2 && text[i] == 'v' && possible_num[1] == 'i'){
                            possible_num += text[i];
                        }
                        else if(text_size == 3 && text[i] == 'r' && possible_num[2] == 'u'){
                            possible_num += text[i];
                        }
                        else if(text_size == 3 && text[i] == 'e' && possible_num[2] == 'v'){
                            possible_num += text[i];
                        }
                        else if(text[i] == 'o' || text[i] == 'f' || text[i] == 't' || text[i] == 's' || text[i] == 'e' || text[i] == 'n'){
                            possible_num = text[i];
                        }
                        else{
                            possible_num = "";
                        }
                        
                    }
                    else if(possible_num[0] == 't'){
                        if(text_size == 1 && (text[i] == 'w' || text[i] == 'h')){
                            possible_num += text[i];
                        }
                        else if(text_size == 2 && ((text[i] == 'o' && possible_num[1] == 'w') || (text[i] == 'r' && possible_num[1] == 'h' ))){
                            possible_num += text[i];
                        }
                        else if(text_size == 3 && text[i] == 'e' && possible_num[2] == 'r'){
                            possible_num += text[i];
                        }
                        else if(text_size == 4 && text[i] == 'e'){
                            possible_num += text[i];
                        }
                        else if(text[i] == 'o' || text[i] == 'f' || text[i] == 't' || text[i] == 's' || text[i] == 'e' || text[i] == 'n'){
                            possible_num = text[i];
                        }
                        else{
                            possible_num = "";
                        }
                        
                    }
                    else if(possible_num[0] == 's'){
                        if(text_size == 1 && (text[i] == 'i' || text[i] == 'e')){
                            possible_num += text[i];
                        }
                        else if(text_size == 2 && ((text[i] == 'x' && possible_num[1] == 'i') || (text[i] == 'v' && possible_num[1] == 'e'))){
                            possible_num += text[i];
                        }
                        else if(text_size == 3 && text[i] == 'e' && possible_num[2] == 'v'){
                            possible_num += text[i];
                        }
                        else if(text_size == 4 && text[i] == 'n'){
                            possible_num += text[i];
                        }
                        else if(text[i] == 'o' || text[i] == 'f' || text[i] == 't' || text[i] == 's' || text[i] == 'e' || text[i] == 'n'){
                            possible_num = text[i];
                        }
                        else{
                            possible_num = "";
                        }
                    }
                    else if(possible_num[0] == 'e'){
                        if(text_size == 1 && text[i] == 'i'){
                             possible_num += text[i];
                        }
                        else if(text_size == 2 && text[i] == 'g'){
                             possible_num += text[i];
                        }
                        else if(text_size == 3 && text[i] == 'h'){
                             possible_num += text[i];
                        }
                        else if(text_size == 4 && text[i] == 't'){
                             possible_num += text[i];
                        }
                        else if(text[i] == 'o' || text[i] == 'f' || text[i] == 't' || text[i] == 's' || text[i] == 'e' || text[i] == 'n'){
                            possible_num = text[i];
                        }
                        else{
                            possible_num = "";
                        }
                    }
                    else if(possible_num[0] == 'n'){
                        if(text_size == 1 && text[i] == 'i'){
                             possible_num += text[i];
                        }
                        else if(text_size == 2 && text[i] == 'n'){
                             possible_num += text[i];
                        }
                        else if(text_size == 3 && text[i] == 'e'){
                             possible_num += text[i];
                        }
                        else if(text[i] == 'o' || text[i] == 'f' || text[i] == 't' || text[i] == 's' || text[i] == 'e' || text[i] == 'n'){
                            possible_num = text[i];
                        }
                        else{
                            possible_num = "";
                        }
                    }
                }
                else{
                    possible_num = "";
                }

                //cout<<possible_num<<"\n";
                string new_num = checkNum(possible_num);
                if(new_num != "10"){
                    //possible_num = "";
                    if(first_num == "10"){
                        first_num = new_num;
                        last_num = new_num;
                        if(text[i] == 'o' || text[i] == 'f' || text[i] == 't' || text[i] == 's' || text[i] == 'e' || text[i] == 'n'){
                            possible_num = possible_num[possible_num.size()-1];
                        }
                        else{
                        possible_num = "";
                        }
                    }
                    else{
                        last_num = new_num;
                        string test =""+ possible_num[possible_num.size()-1];
                        if(text[i] == 'o' || text[i] == 'f' || text[i] == 't' || text[i] == 's' || text[i] == 'e' || text[i] == 'n'){
                            possible_num = possible_num[possible_num.size()-1];
                        }
                        else{
                        possible_num = "";
                        }
                    }
                }
            }
        }
        int num = stoi(first_num + last_num);
        cout<<num<<"\n";
        sum = sum + num;
    }
    cout<<sum;
}

//73four7four92lfqkmgponeightbf