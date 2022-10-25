// Stack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>

template<typename T>
    class stack {
    int top;
    size_t memSize;
    T* pMem;
    public:
    //stack(T val):top(-1),memSize((sizeof T)*val),pMem(new T[memSize]){};
    stack(size_t _memSize) :top(-1), memSize(_memSize), pMem(new T[memSize]) {};
    ~stack()                    {delete[] pMem;pMem=nullptr; }
    size_t size()               const {return top+1;}
    bool IsEmpty()              const {return top==-1;}
    bool IsFull()               const{return top==memSize-1;}
    T Pop()                     {return pMem[top--];}
    void Push (const T& val){
        if (top == memSize - 1) {
            T* tmpMem=new T[memSize*2];
            std::copy(pMem,pMem+memSize,tmpMem);
            delete[] pMem;
            pMem=tmpMem;
            memSize*=2;
        }
        
        pMem[++top]=val; 
    }
    void Print(){
        for(int i = 0; i <= top; i++) {
            std::cout<<pMem[i]<<' ';
        }
    }
};

int main()
{
    //std::cout << "Enter 10 numbers\n";
    stack<int> st(10);
    for (int i = 0; i < 10; i++) {
        st.Push(i);
    }
    st.Print();
    std::cout << std::endl << "size "<< st.size();
    std::cout << std::endl << "Is Full? " << st.IsFull();
    std::cout << std::endl << "Is Empty? " << st.IsEmpty();
    std::cout << std::endl << "Pop " << st.Pop();
    std::cout << std::endl << "size " << st.size();
    std::cout << std::endl << "Is Full? " << st.IsFull();
    std::cout << std::endl << "Is Empty? " << st.IsEmpty();
}

