#include <iostream>

template<class T>
class unique_ptr {
private:
    T* ptr_;
public:

    unique_ptr(T* ptr): ptr_(ptr) {
        
    }

    unique_ptr(T other) = delete;

    T operator= (T other) = delete;

    T& operator * ( ) {
        return ptr_[0];

    }

    void operator << (unique_ptr other) {
        std::cout << other;
    }

    unique_ptr release() {
        T * tmp = ptr_;
        ptr_ = nullptr;
        return tmp;

    }

    ~unique_ptr() {
        delete ptr_;
    }


};


int main()
{
    int* ptr = new int (4);
    unique_ptr<int> uniq_ptr(ptr);
    
    std::cout << *uniq_ptr;
    uniq_ptr.release();
    
    return 0;
}