#include <bits/stdc++.h>

class Solution {
public:
    int romanToInt(string s) {
        // stack<char> str;
        int result=0;
        // for (int i=0; i<s.size(); i++){
        //     str.push(s[i]);
        // }
        char tempch='0';
        for (int i=s.size()-1; i>=0; i--){
            char ch=s[i];
            if(ch=='V'){
                tempch='V';
                result+=5;
            }
            if(ch=='L'){
                tempch='L';
                result+=50;
            }
            if(ch=='D'){
                tempch='D';
                result+=500;
            }
            if(ch=='M'){
                tempch='M';
                result+=1000;
            }
            if(ch=='I'){
                if(tempch=='V'||tempch=='X'){
                    result--;
                }
                else{
                    result++;
                }
                tempch='I';
            }
            if(ch=='X'){
                if(tempch=='L'||tempch=='C'){
                    result-=10;
                }
                else{
                    result+=10;
                }
                tempch='X';
            }
            if(ch=='C'){
                if(tempch=='D'||tempch=='M'){
                    result-=100;
                }
                else{
                    result+=100;
                }
                tempch='C';
            }
        }
        return result;
    }
};