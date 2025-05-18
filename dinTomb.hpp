/**
 * @file dinTomb.hpp
 * @brief Dinamikus tömb sablon implementációja
 */

#ifndef DINTOMB_HPP
#define DINTOMB_HPP

#include "memtrace.h"

/**
 * @class DinTomb
 * @brief Dinamikus tömb sablon
 * 
 * Egy sablon osztály, ami egy dinamikus tömböt hoz létre az adott paraméterből
 * 
 * @tparam T paraméter típusait tárolja a tömbben
 */
template <class T>
class DinTomb{
    T* pData;   /**< Pointer a foglalt memóriaterületre */
    size_t cap; /**< A tömb kapacitása */
    size_t siz; /**< Hány elemet tárol éppen a tömb */

    /**
     * @brief A tömb nagyságát növeli új kapacitásra
     * 
     * Új memóriát foglal, átmásolja az elemeket az új területre és törli a régi memóriát
     * 
     * @param nCap Új kapacitás a tömbnek
     */
    void resize(size_t nCap){
        T* newpData = new T[nCap];
        for (size_t i = 0; i < siz; i++){
            newpData[i] = pData[i];
        }
        delete[] pData;
        pData = newpData;
        cap = nCap;
    }
    /**
     * @brief Kikeresi az adott elemet a tömbben
     * 
     * @param val A keresett elem
     * @return size_t Az elem indexe, ha megtalálta
     * @throws std::out_of_range kivételt dob, ha nincs a tömbben
     */
    size_t is_element(const T& val) const{
        for (size_t i = 0; i < siz; i++){
            if (pData[i] == val){
                return i;
            }
        }
        throw std::out_of_range("Nem eleme a tombnek!");
    }

public:
    /**
     * @brief Default konstruktor
     * 
     * Létrehoz egy tömbböt 0 kapacitással
     */
    DinTomb(): pData(nullptr), cap(0), siz(0) {};

    /**
     * @brief Hozzáad egy elemet a tömb végére
     * 
     * Hozzáad egy új elemet a tömbhöz és a méretét és megváltoztatja ha szükséges
     * 
     * @param val elem amit hozzá kell adni a tömbhöz
     */
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
    
    /**
     * @brief Töröl egy elemet a tömbből
     * 
     * @param val elem amit törölni szeretnénk
     */
    void del_element(const T& val){
        size_t idx = 0;
        try{
            idx = is_element(val);
        } catch(std::out_of_range& err){
            throw std::runtime_error("Nem jo index!");
        }
        for (size_t i = idx; i < siz - 1; ++i){
            pData[i] = pData[i + 1];
        }
        pData[siz - 1] = T();
        --siz;
    }

    /**
     * @brief Indexelő operátor (nem konstants)
     * 
     * @param idx az elem indexe
     * @return T& referencia a keresett elemre
     * @throws std::out_of_range kivételt dob, ha rossz az index
     */
    T& operator[](size_t idx){
        if (idx >= siz){
            throw std::out_of_range("Rossz index");
        }
        else{
            return pData[idx];
        }
    }

    /**
     * @brief Indexelő operátor (konstants)
     * 
     * @param idx az elem indexe
     * @return const T& referencia a keresett elemre
     * @throws std::out_of_range kivételt dob, ha rossz az index
     */
    const T& operator[](size_t idx) const{
        if (idx >= siz){
            throw std::out_of_range("Rossz index");
        }
        else{
            return pData[idx];
        }
    }

    /**
     * @brief =operátor
     * 
     * @param rhs Dinamikus tömb amelyből másolni szeretnénk
     * @return DinTomb<T>& referencia this objektumra a művelet után
     */
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

    /**
     * @brief siz getter
     * 
     * @return size_t, visszaadja a tömb méretét
     */
    size_t getSiz() const{
        return siz;
    }

    /**
     * @brief cap getter
     * 
     * @return size_t, visszaadja a tömb kapacitását
     */
    size_t getCap() const{
        return cap;
    }

    /**
     * @brief Törli az elemet és felszabadítja a memóriát
     */
    void clear(){
        delete[] pData;
        pData = nullptr;
        cap = 0;
        siz = 0;
    }

    /**
     * @brief destruktor
     * 
     * Felszabadítja a memóriát
     */
    // destruktor
    ~DinTomb() {
        delete[] pData;
    }

};

#endif // DINTOMB_HPP

