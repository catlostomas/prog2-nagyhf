
#ifndef DINTOMB_HPP
#define DINTOMB_HPP

#include "memtrace.h"

template <class T>
class DinTomb{
    T* pData;
    size_t cap;
    size_t siz;
    // kapacitas novelese, csak belso fuggvenyekkel
    void resize(size_t nCap){
        T* newpData = new T[nCap];
        for (size_t i = 0; i < siz; i++){
            newpData[i] = pData[i];
        }
        delete[] pData;
        pData = newpData;
        cap = nCap;
    }

    size_t is_element(const T& val) const{
        for (size_t i = 0; i < siz; i++){
            if (pData[i] == val){
                return i;
            }
        }
        return static_cast<size_t>(-1);
    }

public:
    //def ctor
    DinTomb(): pData(nullptr), cap(0), siz(0) {};
    // uj elem hozzaadasa
    void push_back(const T& val){
        if (siz == cap){
            if (cap == 0){
                resize(1);
            }
            else{
                resize(cap * 2);
            }
        }
        pData[siz++] = val;
    }
    // elem torlese
    void del_element(const T& val){
        size_t idx = is_element(val);
        if (idx == static_cast<size_t>(-1)){
            throw std::runtime_error("A keresett elem nincs a tombben!");
            return;
        }
        for (size_t i = idx; i < siz - 1; ++i){
            pData[i] = pData[i + 1];
        }
        pData[siz - 1] = T();
        --siz;
    }
    // indexelo operatorok
    T& operator[](size_t idx){
        if (idx >= siz){
            throw std::out_of_range("Rossz index");
        }
        else{
            return pData[idx];
        }
    }
    const T& operator[](size_t idx) const{
        if (idx >= siz){
            throw std::out_of_range("Rossz index");
        }
        else{
            return pData[idx];
        }
    }

    // operator=
    DinTomb<T>& operator=(const DinTomb<T>& rhs){
        if (this != &rhs){
            if (this->pData != nullptr){
                delete[] pData;
            }
            this->cap = rhs.cap;
            this->siz = rhs.siz;
            if (cap > 0){
                this->pData = new T[cap];
                for (size_t i = 0; i < siz; i++){
                    this->pData[i] = rhs.pData[i];
                }
            }
            else{
                this->pData = nullptr;
            }
        }
        return *this;
    }
    // getterek
    size_t getSiz() const{
        return siz;
    }
    size_t getCap() const{
        return cap;
    }
    // ures-e
    bool empty() const {
        return siz == 0;
    }
    // tomb torlese
    void clear(){
        delete[] pData;
        pData = nullptr;
        cap = 0;
        siz = 0;
    }
    // destruktor
    ~DinTomb() {
        delete[] pData;
    }

};

#endif // DINTOMB_HPP

