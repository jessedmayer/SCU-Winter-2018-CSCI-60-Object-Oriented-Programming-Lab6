#include <iostream>

using namespace std;


template <typename T1, typename T2>
int count_exact(T1 a[], T2 size, T1 find){
int count=0;
    for (T2 i=0; i<size; i++){
        if(a[i]==find){
            count++;
        }
    }
return count;
}

template <typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high){  //Can only deal with types that can use '=','<','>'
int count =0;
    for (T2 i=0; i<size; i++){
        if(a[i]>=low&&a[i]<=high){
            count++;
        }
    }
    return count;
}

template <typename T>
class Point {
public:
    Point();
    Point(int size);
    Point(T b[], int size);
    T GetItem(int item);
    int GetSize();
    void operator =(T b);
    
private:
    T a[10];
    int dim;
    
};    

template <typename T>
Point<T>::Point(){
}

template <typename T>
Point<T>::Point(int size){
   dim=size;
}

template <typename T>
Point<T>::Point(T b[10], int size){
    dim=size;
    for(int i=0; i<size; i++){
        a[i]=b[i];
    }
}

template <typename T>
T Point<T>::GetItem(int item){
    return a[item];
}

template <typename T>
int Point<T>::GetSize(){
    return dim;
}

template <typename T>
void Point<T>::operator =(T b[]){
    for(int i=0; i<b.size; i++){
        a[i]=b[i];
    }
}

template <typename T>
Point<T> operator +(Point<T> a, Point<T> b){
    T c[10];
    for(int i=0; i<b.GetSize(); i++){
        c[i]=a.GetItem(i)+b.GetItem(i);
    }
    return Point<T>(c,b.GetSize());
}

template <typename T>
bool operator ==(Point<T> a, Point<T> b){
    if(a.GetSize()!=b.GetSize()){
        return 0;
    }
    for(int i=0; i<b.GetSize; i++){
        if(a.GetItem(i)!==b.GetItem(i)){
            return 0;
        }
    }
        return 1;
}

int main(){
int a[5]={3,6,5,2,3};
int d[5]={3,6,5,2,3};
char c[4]={'a','b','c','d'};
char e[4]={'a','b','c','f'};
string b[3]={"Bob","Dogs","Bob"};
string str="Bob";
//cout << count_exact(a,5,3) <<endl;
//cout << count_exact(b,3,str) <<endl;



//cout << count_range(a,5,3,5) <<endl;
//cout << count_range(c,4,'b','d') <<endl;

Point<int>p1(a,5);

Point<char>p2(c,4);
//cout << p1.GetItem(3) <<endl;
//cout << p1.GetSize() <<endl;
//cout << p2.GetItem(3) <<endl;
//cout << p2.GetSize() <<endl;

Point<int>p3(d,5);
Point<char>p4(e,4);

cout << (p3==p1) <<endl;
p1=(p1+p3);
cout << p1.GetItem(0) <<endl;
cout << (p2==p4) <<endl;



return 0;
}