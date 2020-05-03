
#include <iostream>
#include <string>
 
bool isNum(char c){
    bool result = true;
    if( !(c >= '0' && c <= '9') ){
        result = false;
    }
    return result;
}
 
bool isNumberType(std::string s){
    bool result = true;
    for( int i = s.size() - 1; i >= 0; i-- ){
        if(!isNum(s[i])){
            result = false;
            break;
        }
    }
    return result;
}
 
bool isPhoneType(std::string s){
    bool result = true;
    if( s.size() != 11 ){
        result = false;
    }
    else{
        if( s[0] != '1' ){
            result = false;
        }
        else{
            if( s[1] != '3' && s[1] != '5' && s[1] != '8' ){
                result = false;
            }
        }
    }
    return result;
}
 
 
void findType(std::string s, int& cntNum, int& cntPhn){
    if( isNumberType(s) ){
        cntNum++;
    }
    if( isPhoneType(s) ){
        cntPhn++;
    }
 
}
 
int main(){
    int cntNum = 0;
    int cntPhn = 0;
    std::string s;
    while( std::cin >> s ){
        findType(s, cntNum, cntPhn);
        if( s[0] == '*' ){
            break;
        }
    }
    std::cout << "The count of Number Type Code is: " << cntNum << std::endl;
    std::cout << "The count of Phone Type Code is: " << cntPhn << std::endl;
    return 0;
}
