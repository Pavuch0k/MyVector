#include <iostream>
#include <vector>
#include <cstdlib> 
using namespace std;

template <typename T>
class MyVector {
private:
    T* arr;
    size_t size_arr;
    size_t capacity;

public:
    MyVector(){
        arr = nullptr;
        size_arr = 0;
        capacity = 1;
    }

    MyVector(const MyVector &p) {

        size_arr = p.size();
        capacity = size_arr;
        arr = new T[size_arr];

        for (size_t i = 0; i < p.size(); i++)
        {
            arr[i] = p[i];
        }

    }
  

    MyVector(MyVector&& p) noexcept {
        size_arr = p.size_arr;
        capacity = p.capacity;
        arr = p.arr;
        p.size_arr = 0;
        p.capacity = 0;
        p.arr = nullptr;
    }

        
    

    MyVector(size_t Size){
        size_arr = Size;
        capacity = size_arr;
        arr = new T[size_arr];
    }

    MyVector(size_t Size, T item) {
        size_arr = Size;
        capacity = size_arr;
        arr = new T[size_arr];
        for (size_t i = 0; i < size_arr; i++)
        {
            arr[i] = item;
        }
    }
    
    ~MyVector() {
        delete[] arr; 
        arr = nullptr;
    }

    void print() {
        for (size_t i = 0; i < size_arr; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout << endl;
    }

    void push_back(T item) {
        if (size_arr >= capacity) {
            increase_capacity();
        }

        arr[size_arr++] = item;
        
    }
    void increase_capacity() {
        if (capacity == 0) {
            capacity = 1;
        }
        else {
            capacity *= 2;
        }
        T* newarr = new T[capacity];
        for (size_t i = 0; i < size_arr; ++i) {
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
    }


    void pop_back() {
        if (size_arr > 0) {
            size_arr--;
        }
    }

    void qSort() {
        if (size_arr < 2) {
            return;
        }
        else {
            MyVector<T> less;
            MyVector<T> equal;
            MyVector<T> greater;
            less.increase_capacity();
            equal.increase_capacity();
            greater.increase_capacity();

            T pivot = arr[0];

            for (size_t i = 0; i < size_arr; i++) {
                if (arr[i] < pivot) {
                    less.push_back(arr[i]);
                }
                else if (arr[i] == pivot) {
                    equal.push_back(arr[i]);
                }
                else {
                    greater.push_back(arr[i]);
                }
            }

            less.qSort();
            greater.qSort();

            size_t index = 0;
            for (size_t i = 0; i < less.size(); ++i) {
                arr[index++] = less[i];
            }
            for (size_t i = 0; i < equal.size(); ++i) {
                arr[index++] = equal[i];
            }
            for (size_t i = 0; i < greater.size(); ++i) {
                arr[index++] = greater[i];
            }
        }
    }


    const size_t size() const {
        return size_arr;
    }
    void clear() {
        if (arr != nullptr) {
            delete[] arr;
            arr = nullptr; 
            size_arr = 0; 
            capacity = 0; 
        }
    }


     T& operator [] (const size_t& index) {
        return arr[index];
    }

     const T& operator [] (const size_t& index)const {
         return arr[index];
     }

     MyVector& operator = (const MyVector& p) {
         if (this != &p) {
             delete[] arr;

             size_arr = p.size();
             capacity = size_arr;

             arr = new T[size_arr];

             for (size_t i = 0; i < p.size(); i++) {
                 arr[i] = p[i];
             }
         }
         return *this;
     }

};

template <typename T>
void swap(MyVector<T>& a, MyVector<T>& b) {
    T* temp = a.arr;
    size_t temp_size = a.size_arr;

    a.arr = b.arr;
    a.size_arr = b.size_arr;

    b.arr = temp;
    b.size_arr = temp_size;
}


int main()
{
    MyVector <int> vec;
    vec.increase_capacity();

    vec.push_back(11);
    vec.push_back(31);
    vec.push_back(-51);
    vec.push_back(61);
    vec.push_back(-10);
    vec.print();

    vec.qSort();
    vec.print();

    for (size_t i = 0; i < vec.size(); i++)
    {
        vec[i] = 228;
    }
    vec.print();

    MyVector <int> vec2;
  
    vec2 = vec;
    vec2.print();
    
    vec2.clear();
    
    for (size_t i = 0; i < 15; i++)
    {

        vec2.push_back(322);
    }
    vec2.print();

    for (size_t i = 0; i < 10; i++)
    {

        vec2.pop_back();
    }
    vec2.print();
    cout << vec.size()<<endl;

    MyVector <double>vec3(5, 0.2);
    vec3.print();
    return 0;
}