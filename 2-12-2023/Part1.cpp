#include <bits/stdc++.h>

using namespace std;

int main(){

    string myText;

    ifstream Myfile("input.txt");

    int sum = 0;

    while(getline(Myfile,myText)){

        string line;
        stringstream text(myText);
        string number_s;
        int red = 0;
        int blue = 0;
        int green = 0;


        getline(text,line,' ');
        getline(text,number_s,':');
        while(getline(text,line,';')){
            string line2;
            stringstream stream_line(line);
            //cout<<"Number:" + number_s<<"\n";
            while(getline(stream_line,line2,',')){
                string line3;
                stringstream stream_line2(line2);
                int num = 0;
                getline(stream_line2,line3,' ');
                        getline(stream_line2,line3,' ');
                        //cout<<"Linea: "+ line3<<"\n";
                        num = stoi(line3);
                        getline(stream_line2,line3,' ');
                        getline(stream_line2,line3,' ');
                        cout<<num<<"\n";
                        cout<<line3<<"\n";
                            if(line3 == "blue"){
                                if(blue < num){
                                    blue = num;
                                }
                            }
                            else if(line3 == "green"){
                                if(green < num){
                                    green = num;
                                }
                            }
                            else if(line3 == "red"){
                                if(red < num){
                                    red = num;
                                }
                            }
                        
                    
            }
        }
        cout<<"Number:" << number_s<<"\n";
        cout<<"red:" << red<<"\n";
        cout<<"green:"<< green<<"\n";
        cout<<"blue:" <<blue<<"\n";

        if(red <= 12 && green <= 13 && blue <= 14){
            sum += stoi(number_s);
        }
        // getline(text,line,',');
        // cout<<line<<"\n";


    }
    cout<<sum<<"\n";

}