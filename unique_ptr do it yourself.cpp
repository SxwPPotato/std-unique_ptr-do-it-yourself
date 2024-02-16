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

    int operator * ( ) {
        return ptr_[0];

    }

    void operator << (unique_ptr other) {
        std::cout << other;
    }

    unique_ptr release() {
        ptr_ = nullptr;
        return ptr_;

    }

    ~unique_ptr() {
        delete ptr_;
    }


};


int main()
{
    int* ptr = new int[2] {4,6};
    unique_ptr<int> qwe(ptr);
    
    std::cout << "\n";
    std::cout << *qwe;
    qwe.release();

    return 0;
}