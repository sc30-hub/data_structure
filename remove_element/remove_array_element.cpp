#include "iostream"

using namespace std;

int remove_element(int arr [] , int size , int val){
    int *p = arr;
    int *q = arr + size - 1;
    while(p <= q){
        if(*q == val){
            q--;
        }
        if(*p == val){
            *p = *q;
            q--;
        }
        p++;
    }
    return p-arr;
}
int main(void){
    int arr[10] = {1,3,2,3,3,2,1,2,3,1};
    int arr1[4] = {3,2,3,2};
    int len = remove_element(arr,10,3);
    int len1 = remove_element(arr1,4,3);
    for(int i=0; i<len ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<len1 ; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    return 0;
}