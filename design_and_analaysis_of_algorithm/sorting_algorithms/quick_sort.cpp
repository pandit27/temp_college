#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class quick{
    public:
        void sort(vector<int> &v, int n);
        void printArray(vector<int> &v, int n);
};

int main(){
    vector<int>v;
    int n, x;
    
    // taking size of the array
    cout<<"Enter the size of the array: ";
    cin>>n;
    
    // taking elements in the array
    for(int i = 0; i < n; i++){
        cout<<"Enter element "<<(i + 1)<<": ";
        cin>>x;
        v.push_back(x);
    }
    
}

/*
    DRY RUN
    4 2 9 8 50 14
    
    1st pass
    
    4 2 9 8 50 14
*/

void quick::sort(vector<int> &v, int n){
    
}

void quick::sort(vector<int> &v, int n){
    
}
