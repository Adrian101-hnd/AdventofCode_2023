#include <bits/stdc++.h>

using namespace std;

bool check_num(string num){
    for(int i = 0;i!=num.size();i++){
        if(!isdigit(num[i])){
            return false;
        }
    }
    return true;
}


int main(){
    ifstream Myfile("input.txt");
    string line1;
    bool y = false;
    map<int,int> numbers;
    map<int,string> symbols;
    map<int,int> numbers_prev;
    map<int,string> symbols_prev;
    while(getline(Myfile,line1)){
        int x = -1;
        string line2;
        stringstream string_line(line1);
        while(getline(string_line,line2,'.')){
            x += 1; 
            //cout<<line2<<"\n";
            if(line2 != "." && line2.size() != 0){
            bool a = check_num(line2);
            if(a){
                for(int i = 0;i!=line2.size();i++){
                    numbers[x + i] = stoi(line2);
                    cout<<"Number saved at: "<< x+i <<"\n";
                }
                x += line2.size();

            }
            else{
              symbols[x] = line2;
              cout<<"Symbol saved at: "<< x <<"\n";
              x += 1;
            }
            }
        }
        //HACER COMPARACION AQUI HORIZONTAL

        if(y){
            //HACER COMPARACION AQUI VERTICAL Y DIAGONAL
        }
        else{
            y =!y;
        }
        numbers_prev = numbers;
        symbols_prev = symbols;
        numbers.clear();
        symbols.clear();
        
    }
}