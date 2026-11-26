#include "iostream"
#include "cstring"
using namespace std;

void reverse(char arr[], int size){
    char *p = arr;
    char *q = arr + size -1;
    while(p < q){
        char middle  = *p;
        *p = *q;
        *q = middle;
        p++;
        q--;
    }
}
int main(void){
    char arr[] = {"hello world"};
    reverse(arr,strlen(arr));
    cout<<arr<<endl;
    return 0;
}