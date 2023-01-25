#include <iostream>
#include <vector>
using namespace std;

int main(){
    int e, n, arr[n];
    bool flag = false;
    
    // taking size of the array
    cout<<"Enter the size of the array: ";
    cin>>n;
    
    // taking elements in the array
    for(int i = 0; i < n; i++){
        cout<<"Enter element "<<(i + 1)<<": ";
        cin>>arr[i];
    }
    
    // taking element that we have to search
    cout<<"Enter the element you want to search: ";
    cin>>e;
    
    // searching the element in the array
    for(int i = 0; i < n; i++){
        if(e == arr[i]){
            cout<<"Element found at index "<<i<<endl;
            flag = true;
            break;
        }
    }
    
    if(flag == false){
        cout<<"Element not found \n";
    }
    
    cout<<"excuted successfully \n";
    
    return 0;
}
