#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <windows.h>

using namespace std;

int main(){
    ifstream infile("1-2.txt");
    int n;
    infile >> n;
    ofstream outfile("1-2_re.txt");
    string s;
    getline(infile, s);
    for (int i=0; i<n; i++){
		string str;
        getline(infile, str);
        int result=0;
        int j;
        LARGE_INTEGER LIB_decOrd;
        LARGE_INTEGER LIE_decOrd;
        LARGE_INTEGER FREQ_decOrd;
        QueryPerformanceFrequency(&FREQ_decOrd);
        QueryPerformanceCounter(&LIB_decOrd);
        for (j=0; j<str.size(); j++){
            result+=pow(26, str.size()-1-j)*(str[j]-'a');
        }
        QueryPerformanceCounter(&LIE_decOrd);
        double time_decOrd=(double)(LIE_decOrd.QuadPart-LIB_decOrd.QuadPart)/((double)FREQ_decOrd.QuadPart);
        outfile << "求解数据规模为" << str.size() << "个字母的字典序结果: " ;
        outfile << result;
        outfile << endl;
        cout << "求解数据规模为" << str.size() << "个字母的字典序所需时间: ";
        cout  << fixed << setprecision(8) << time_decOrd << endl;
    }
    return 0;
}
