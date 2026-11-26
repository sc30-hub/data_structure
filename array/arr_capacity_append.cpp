#include "iostream"
#include "cstring"
#include "ctime"
#include "cstdlib"

using namespace std;

class Array {
    public:
    //构造函数
    Array(int size = 10):mcap(size),mcur(0){
        mparr = new int[size]();
    }
    ~Array(){
        delete [] mparr;
        mparr = nullptr;
    };
    
    //末尾增添元素
    void push_back(int val){
        if(mcur == mcap){
            expand(2*mcap);
        }
        mparr[mcur] = val;
        mcur++;
    }
    //末尾删减元素
    void pop_back(){
        if(mcur <=0){
            return;
        }
        mcur--;
    }
    //按位置插入元素
    void insert(int pos , int val){
        if(pos < 0 || pos >mcap){
            return;
        }
        if(mcur = mcap){
            expand(2*mcap);
        }
        for(int i=mcur-1; i>=pos; i--){
            mparr[i+1] = mparr[i];
        }
    }
    //按位置删除元素
    void erase(int pos){
        if(pos <0 || pos >=mcur){
            return;
        }
        for(int i=pos;i<mcur;i++){
            mparr[i] = mparr[i+1];
        }
        mcur--;
    }
    //查询元素
    //因为下现在是无序数组，所以使用线性搜索，复杂度是O(n)，但是如果是有序数组，那么就可以使用二分搜素，此时复杂度是O(logn)
    int find(int val){
        for(int i=0; i<mcur; i++){
            if(val == mparr[i]){
                return i;
            }
        }
        return -1;
    }
    //遍历输出数组元素
    void show() const{
        for(int i =0; i<mcur; i++){
            cout<<mparr[i]<<" ";
        }
        cout<<endl;
    }
    
    private:
    int *mparr;
    int mcap;
    int mcur;
    //动态扩容
    void expand(int size){
        int *p = new int[size];
        memcpy(p,mparr,sizeof(int)*mcap);
        delete [] mparr;
        mparr = p;
        mcap = size;
    }
};

int main(void){
    Array array;
    srand(time(0));
    for(int i=0; i<10; i++){
        array.push_back(rand()%100+1);
    }
    array.show();
    array.insert(10,130);
    array.show();
    array.pop_back();
    array.show();
    int num = array.find(60);
    if(num!=-1){
        cout<<"pos is"<<num<<endl;
    }
    else{
        cerr<<"not found"<<endl;
    }
    return 0;
}