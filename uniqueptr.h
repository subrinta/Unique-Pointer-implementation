#pragma once
template <typename T>
class uniqueptr
{
    private:
        T * ptr {nullptr};
    public:
        uniqueptr();
        uniqueptr(T* _ptr) : ptr(_ptr) { std::cout << "Constructor 1" <<std::endl; }
        uniqueptr(const uniqueptr<T> & up) = delete;
        uniqueptr(uniqueptr<T>&& up) : ptr(up.ptr) 
        { 
            up.ptr = nullptr;
            std::cout << "Move Constructor " << std::endl;
        }
        uniqueptr& operator= (const uniqueptr<T> & up) = delete;
        uniqueptr& operator= (uniqueptr<T> && up)
        {
            if(this == &up)
                return *this;
            if(ptr)
                delete ptr;
            ptr = up.ptr;
            up.ptr = nullptr;
            std::cout << "Move assignment operator" <<std::endl;
            return *this;
        }
        T * operator-> () { return ptr; }
        T & operator* () {return *ptr; }
        void reset(T * _ptr = nullptr)
        {
            delete ptr;
            ptr = _ptr;
        }
        ~uniqueptr()
        {
            delete ptr;
        }
        const T * get() const { return ptr; }
};