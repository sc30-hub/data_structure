#include "iostream"
#include "ctime"
#include "cstdlib"
using namespace std;

void Adjust_array(int arr[] , int size){
    //采用双指针的方法把偶数放到左边，奇数放到右边
    int *p = arr;
    int *q = arr + size -1;
    //当p<q的时候进行，如果大于或等于说明执行完毕了
    while(p<q){
        //p->奇数，可以采用位运算来进行奇偶的判别，但是位运算的优先级太低，所以一般都需要加上括号
        if((*p & 0x1) == 0){
            p++;
            continue;
        }
        //q->偶数
        if((*q & 0x1) == 1){
            q--;
            continue;
        }
        //进行奇偶位置交换，通过引入第三变量来进行交换
        int temp = *p;
        *p = *q;
        *q = temp;
    }
}

int main(void){
    //设置随机数种子，并绑定本地时间，保证每次生成的随机数都是不一样的
    srand(time(0));
    int arr[10] = {0};
    for(int i = 0; i<10; i++){
        arr[i] = rand()%100;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    Adjust_array(arr,10);
    for(int i = 0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}