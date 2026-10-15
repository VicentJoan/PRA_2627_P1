#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;                         
    int max;                        
    int n;                          
    static const int MINSIZE = 2;   

    // Método privado para redimensionar el array
    void resize(int new_size) {
        T* new_arr = new T[new_size];      
        for (int i = 0; i < n; ++i) {
            new_arr[i] = arr[i];            
        }
        delete[] arr;                       
        arr = new_arr;                      
        max = new_size;                     
    }

public:
    // Constructor sin argumentos
    ListArray() {
        arr = new T[MINSIZE];
        max = MINSIZE;
        n = 0;
    }

    
    ~ListArray() override {
        delete[] arr;
    }

    
    T operator[](int pos) {
        if (pos < 0 || pos >= n) { // size() es igual a n
            throw std::out_of_range("Posición fuera de rango");
        }
        return arr[pos];
    }

    // Sobrecarga del operador << para imprimir la lista
    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
        out << "[";
        for (int i = 0; i < list.n; ++i) {
            out << list.arr[i];
            if (i < list.n - 1) out << ", ";
        }
        out << "]";
        return out;
    }

    // --- MÉTODOS HEREDADOS DE List<T> (Sobrescritos) ---
    
    void insert(int pos, T e) override {
        // TODO: Lógica de la siguiente actividad
    }

    void append(T e) override {
        // TODO: Lógica de la siguiente actividad
    }

    void prepend(T e) override {
        // TODO: Lógica de la siguiente actividad
    }

    T remove(int pos) override {
        // TODO: Lógica de la siguiente actividad
        return T(); 
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Fuera de rango");
        return arr[pos];
    }

    int search(T e) override {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e) return i;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }
};

#endif
