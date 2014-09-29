/* 
 * File:   Vdin.h
 * Author: josej
 *
 * Created on 29 de septiembre de 2014, 18:25
 */

#ifndef VDIN_H
#define	VDIN_H
#include "ErrorRango.h"
#include <algorithm>
template<class T>
class Vdin {
    unsigned tamal,tamaf;
    T *v;
public:
    Vdin();
    Vdin(const Vdin<T>& orig);
    Vdin<T> &operator=(const Vdin<T> &orig);
    T &operator[](unsigned pos){
        if (pos<0 || pos>=tamal)
                throw ErrorRango();
        return v[pos];
    }
    void escribe(unsigned pos,const T &dato){ v[pos] = dato; }
    void insertar(T &dato, unsigned pos);  //posición dada
    T &borrar(unsigned pos);  //posición dada
    void insertarFinal(T &dato); // Inserción por la derecha
    T &borrarFinal(); // Eliminar dato por la derecha
    unsigned tam(){ return tamal; };
    void ordenar();
    unsigned busca(T &dato);
    unsigned busquedaBin(T &dato);
    ~Vdin(){delete []v;};
};

template<class T>
Vdin<T>::Vdin() {
    tamal = 0;
    v = new T[ tamaf = 1];
}

template <class T>
Vdin<T>::Vdin(const Vdin<T> &orig) {
    v = new T[tamaf = orig.tamaf];
    tamal = orig.tamal;
    for (unsigned i=0; i<tamal; i++) v[i] = orig.v[i];
}

template <class T>
Vdin<T> &Vdin<T>::operator= (const Vdin<T> &orig){
    delete []v;
    v = new T[tamaf = orig.tamaf];
    tamal = orig.tamal;
    for (unsigned i=0; i<tamal; i++) v[i] = orig.v[i];

    return *this;
}

template <class T>
T &Vdin<T>::borrar(unsigned pos){
    if (pos<0 || pos>=tamal) throw ErrorRango();
    T &aux=v[pos];
    for(unsigned i=pos;i<tamal-1;i++){
            v[i]=v[i+1];
    };
    if(tamal*3<tamaf) {
        tamaf=tamaf/2;
        T *vaux = new T[tamaf];
        for(unsigned i=0;i<tamal;i++){
            vaux[i]=v[i];
        };
        delete []v;
        v=vaux;
    }
    tamal--;
    return aux;
}

template <class T>
void Vdin<T>::insertar(T &dato, unsigned pos){
    if(tamal==tamaf) {
        T *vaux;
        vaux= new T[tamaf=tamaf*2];
        for(unsigned i=0;i<tamal;i++)
            vaux[i]=v[i];
        delete []v;
        v=vaux;
    }
    for(unsigned i=tamal-1;i>=pos;i--){
        v[i+1]=v[i];
    };
    v[pos]=dato;
    tamal++;
}

template <class T>
void Vdin<T>::insertarFinal(T &dato){
    if(tamal==tamaf) {
        T *vaux;
        vaux= new T[tamaf=tamaf*2];
        for(unsigned i=0;i<tamal;i++)
            vaux[i]=v[i];
        delete []v;
        v=vaux;
    }
    v[tamal++]=dato;
}

template <class T>
T &Vdin<T>::borrarFinal(){
    if(tamal*3<tamaf) {
        tamaf=tamaf/2;
        T *vaux = new T[tamaf];
        for(unsigned i=0;i<tamal;i++){
            vaux[i]=v[i];
        };
        delete []v;
        v=vaux;
    }
    return v[--tamal];
}

template <class T>
void Vdin<T>::ordenar(){
    sort(v, v+tamal);
}

template <class T>
unsigned Vdin<T>::busca(T &dato){
    for(unsigned j=0; j<tamal; j++)
        if(v[j] == dato) return j;
    return -1;
}

template <class T>
unsigned Vdin<T>::busquedaBin(T &dato){
    unsigned inf = 0;
    unsigned sup = tamal-1;
    unsigned curIn;
    while(true) {
        curIn = (inf + sup) / 2;
        if(v[curIn] == dato)
            return curIn;
        else if(inf > sup) return -1;
            else {
                if(v[curIn] < dato) inf = curIn + 1;
                    else sup = curIn - 1;
                }
    }
}

#endif	/* VDIN_H */

