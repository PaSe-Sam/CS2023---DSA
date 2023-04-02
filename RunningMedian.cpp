#include <bits/stdc++.h>
using namespace std;

void median(int* arr, int size){
    double val;
    if (size % 2 ==0){
        val= (arr[size/2-1] + arr[size/2])*1.0/2;
    }

    else{
        val= (arr[(size-1)/2])*1.0;
    }
    cout<< fixed << setprecision(1)<<val;
    
}

int insert(int n, int* arr, int size){
    if (size ==0){
        int arr[]={n};
    }
    else{
          
        int i= size-1;
        while(i>=0 && n <= arr[i])  
        {  
            arr[i+1] = arr[i];   
            i = i-1;  
        }  
        arr[i+1] = n;
    }

    for (int n = 0; n < size; n++) {
        if (n<size-1){
            cout << arr[n] << ",";
        }
        else{
            cout << arr[n];
        }
    }
    
    return 0;
}



int main(){

    int sz;
    cin>>sz;
    int randArray[sz];
    for(int i=0;i<sz;i++){
      randArray[i]=rand()%500;  //Generate number between 0 to 499
	}
    //int array[]= {7,4,6,3,2};

    int length = sizeof(randArray) / sizeof(int);
    int newarray[]={randArray[0]};

    for (int i=0; i< length; i++){
        cout<<"[";
        insert(randArray[i], newarray, i+1);
        cout<<"]"<<"   ";
        median(newarray,i+1);
        cout<<"\n";
    }
    return 0;
}
