#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int array[5]={0, 1, 45, 16, 8};
    make_heap(array, array+5);
    for(int i=0; i<5; i++){
        cout << array[i] << ' ';
    }
    cout << endl;
    pop_heap(array, array+5);
    for(int i=0; i<5; i++){
        cout << array[i] << ' ';
    }
    cout << endl;    
    return 0;
}