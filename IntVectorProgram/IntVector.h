#ifndef I_H
#define I_H
using namespace std;

class IntVector {
    private: 
        unsigned sz;
        unsigned cap;
        int *data ; //: stores the address of the dynamically-allocated array of integers
        void expand();
        void expand(unsigned);
        
        
    public: 
        
        IntVector();
        IntVector(unsigned size, int value = 0);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        int & at(unsigned index);
        const int & front() const;
        int & front();
        const int & back() const;
        int & back();
        void insert(unsigned index, int value);
        void erase(unsigned index);
        void assign(unsigned n, int value);
        void push_back(int value);
        void pop_back();
        void clear();
        void resize(unsigned size, int value = 0);
        void reserve(unsigned n);
        
};


#endif