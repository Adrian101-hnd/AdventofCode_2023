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

void delete_numbers(map<int,int>& numbers,int position){
    int number_size = to_string(numbers[position]).length();
    numbers.erase(position);
    //Delete adjacent number
    if(number_size == 2){
        if(numbers.find(position - 1) == numbers.end()){
            numbers.erase(position + 1);
        }
        else{
           numbers.erase(position - 1); 
        }
    }
    else if(number_size == 3){
        if(numbers.find(position - 1) != numbers.end() && numbers.find(position - 2) != numbers.end()){

            numbers.erase(position - 1);
            numbers.erase(position - 2);
        }
        else if(numbers.find(position + 1) != numbers.end() && numbers.find(position + 2) != numbers.end()){
            numbers.erase(position + 1);
            numbers.erase(position + 2);
        }
        else{
            numbers.erase(position + 1);
            numbers.erase(position - 1);
        }
    }

}


int main(){
    int sum = 0;
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
                    //cout<<"Number saved at: "<< x+i <<"\n";
                }
                x += line2.size();

            }
            else{
                //cout<<line2<<"\n";
                if(line2.size() > 1){
                    string possible_num = "";
                    for(int i = 0;i!=line2.size();i++){
                        if(isdigit(line2[i])){
                            possible_num += line2[i];
                        }
                        else{
                            if(possible_num.size() != 0){
                                for(int j = 0;j!=possible_num.size();j++){
                                numbers[x + j] = stoi(possible_num);
                                //cout<<"Number saved at: "<< x+i <<"\n";
                            }
                                x += possible_num.size();
                                symbols[x] = line2[i];
                                //cout<<"Symbol saved at: "<< x <<"\n";
                                x += 1;
                                possible_num = "";
                            }
                            else{
                                possible_num = "";
                                symbols[x] = line2[i];
                                //cout<<"Symbol saved at: "<< x <<"\n";
                                x += 1;
                            }
                        }
                    }
                    if(possible_num != ""){
                                for(int j = 0;j!=possible_num.size();j++){
                                numbers[x + j] = stoi(possible_num);
                                //cout<<"Number saved at: "<< x+i <<"\n";
                            }
                                x += possible_num.size();
                    }
                }
                else{
                    symbols[x] = line2;
                    //cout<<"Symbol saved at: "<< x <<"\n";
                    x += 1;
                }
              
            }
            }
        }

        //HACER COMPARACION AQUI HORIZONTAL
        
        for (auto it = symbols.begin(); it != symbols.end(); ++it) {
        int position = it->first;
        if(numbers.find(position-1) != numbers.end()){
            cout<<"Se agrego: "<<numbers[position-1]<<"Por estar al lado de: " + it->second<<"\n";
            sum += numbers[position-1];
            delete_numbers(numbers,position);
        }
        if(numbers.find(position+1) != numbers.end()){
            cout<<"Se agrego: "<<numbers[position+1]<<"Por estar al lado de: " + it->second<<"\n";
            sum += numbers[position+1];
            delete_numbers(numbers,position);
        }

        //std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        }   
        if(y){
            for (auto it = symbols.begin(); it != symbols.end(); ++it) {

                //MATCH BOTTOM UP
                int position = it->first;
                if(numbers_prev.find(position) != numbers_prev.end()){
                    cout<<"Se agrego: "<<numbers_prev[position]<<"Por estar al lado de: " + it->second<<"\n";
                    sum += numbers_prev[position];
                    delete_numbers(numbers_prev,position);
                }
                if(numbers_prev.find(position -1) != numbers_prev.end()){
                    cout<<"Se agrego: "<<numbers_prev[position-1]<<"Por estar al lado de: " + it->second<<"\n";
                    sum += numbers_prev[position-1];
                    delete_numbers(numbers_prev,position);
                }
                if(numbers_prev.find(position + 1) != numbers_prev.end()){
                    cout<<"Se agrego: "<<numbers_prev[position + 1]<<"Por estar al lado de: " + it->second<<"\n";
                    sum += numbers_prev[position+1];
                    delete_numbers(numbers_prev,position);
                }
            }

            //MATCH TOP DOWN
            for (auto it = symbols_prev.begin(); it != symbols_prev.end(); ++it) {

                //MATCH BOTTOM UP
                int position = it->first;
                if(numbers.find(position) != numbers.end()){
                    sum += numbers[position];
                    delete_numbers(numbers,position);
                }
                if(numbers.find(position -1) != numbers.end()){
                    sum += numbers[position-1];
                    delete_numbers(numbers,position);
                }
                if(numbers.find(position + 1) != numbers.end()){
                    sum += numbers[position+1];
                    delete_numbers(numbers,position);
                }
            }
        }
        else{
            y =!y;
        }
        numbers_prev = numbers;
        symbols_prev = symbols;
        numbers.clear();
        symbols.clear();
        
    }
    cout<<"Sum: "<<sum<<"\n";
}