#include "IntVector.h"
#include <stdexcept>
#include <iostream>

using namespace std;

        IntVector::IntVector() {
            sz = 0;
            cap = 0;
            data = 0;
            
        }
        
        IntVector::IntVector(unsigned size, int value) {
            sz = size;
            cap = size;
            data = new int[cap];
            
            for (unsigned int i = 0; i < sz; i++) {
                data[i] = value;
            }
            
        }
        
        IntVector::~IntVector() {
            
            delete data;
            
            
        }
        unsigned IntVector::size() const {
            return sz;
        }
        
        unsigned IntVector::capacity() const {
            return cap;
        }
        
        bool IntVector::empty() const  {
            if (sz == 0) {
                return true;
            }
            return false;
        }
        
        const int & IntVector::at(unsigned index) const {
            if (index >= sz) {
                throw out_of_range("IntVector::at_range_check");
            }
            else {
                return data[index];
            }
        }
        
        int & IntVector::at(unsigned index) {
            if (index >= sz) {
                throw out_of_range("IntVector::at_range_check");
            }
            else {
                return data[index];
            }
        }
        
        
        const int & IntVector::front() const {
            return data[0];
        }
        
        int & IntVector::front() {
            return data[0];
        }
        
        const int & IntVector::back() const {
            return data[sz - 1];
        }
        
        int & IntVector::back() {
            return data[sz - 1];
        }
        
        
        void IntVector::insert(unsigned index, int value) {
            if (index > sz) {
                throw out_of_range("IntVector::insert_range_check");
            }
              
                sz = sz + 1;
                
                if (cap < sz) {
                    expand();
                   
                }
               
                for (unsigned int i = sz - 1; i > index; i--) {

                        data[i] = data[i-1];
                }
                data[index] = value; 

            
        }
        
        void IntVector::erase(unsigned index) {
            if (index >= sz) {
                throw out_of_range("IntVector::erase_range_check");
            }
            for (unsigned int i = index; i+1 < sz; i++) {
                
                data[i] = data[i+1];
            }
            sz -= 1;
        }

        void IntVector::assign(unsigned n, int value) {
            if (n <= cap) {
                sz = n;
                for (unsigned int i = 0; i < sz; i ++) {
                    data[i] = value;
                }
            } 
            
            if (n > (2*cap)) {
                expand(n);
                sz = n;
                for (unsigned int i = 0; i < sz; i ++) {
                    data[i] = value;
                }
                
            }
            else if (n > cap){
                expand();
                sz = n;
                for (unsigned int i = 0; i < sz; i ++) {
                    data[i] = value;
                }
            }
            
        }
        
        void IntVector::push_back(int value) {
            if (sz >= cap) {
                expand();
            }
            sz += 1;

            data[sz-1] = value;
        }
        
        void IntVector::pop_back() {
            
            sz = sz - 1;
        }
        
        
        void IntVector::clear() {
            
            sz = 0;
        }

        void IntVector::resize(unsigned size, int value) {
                //cout << "1" << endl;
                if (size < sz) {
                   // cout << "2" << endl;
                  sz = size;
                 // cout << "3" << endl;
                }
                
                if (size > sz) {
                    //cout << "4" << endl;
                    unsigned temp = sz;
                    sz = size;
                    //cout << "5" << endl;
                    if (sz > (2*cap)) {
                        expand(sz);
                    }
                    else if (size > cap){
                         cout << "6" << endl;
                        expand();
                    }
                    
                    for (unsigned int i = temp; i < sz; i++) {
                        data[i] = value;
                        cout << data[i] << endl;
                    }
                }
            
        }
        
        void IntVector::reserve(unsigned n) {
            // if (cap < n) {
            //     cap = n;
            //}
            if (n > (2*cap)) {
                expand(n);
            }
            else if (n > cap) {
                expand();
            }
            
        }
        
        void IntVector::expand() {
                int * temp = data;
                
                cap *= 2;
                if (cap ==  0) {
                    cap = 1;
                    data = new int[cap];
                }
                else {
                    data = new int[cap];
                    for (unsigned int i = 0; i < sz; i++) {
                        data[i] = temp[i];
                    }
                }
            
        }
        
        void IntVector::expand(unsigned x) {
            
        
            int * temp = data;
            if (cap == 0) {
                cap = x;
                
                data = new int[cap];
            }
            else {
                cap = x;
                
                data = new int[cap];
                for (unsigned int i = 0; i < sz; i++) {
                    data[i] = temp[i];
                }
            }
            
                        
            

        }