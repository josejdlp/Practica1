/* 
 * File:   ErrorRango.h
 * Author: josej
 *
 * Created on 29 de septiembre de 2014, 18:23
 */

#ifndef ERRORRANGO_H
#define	ERRORRANGO_H
#include <exception>

using namespace std;

class ErrorRango {
public:
    const char* what() const throw()
    {
        return "\nError: Direccion de la matriz fuera de rango";
    }
private:

};

#endif	/* ERRORRANGO_H */

