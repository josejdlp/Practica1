/* 
 * File:   main.cpp
 * Author: josej
 *
 * Created on 27 de septiembre de 2014, 17:32
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Vdin.h"
#include "ErrorRango.h"
using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    try{
    
        cout << "hola" << endl;
        
        
        
        
    //operamos con el vector

    //Realizamos borrados

    //mostramos resultados


    }catch(ErrorRango &e){
         cout << e.what() << endl;
    }
    catch(bad_alloc e){
     cout << "No hay memoria suficiente para el objeto dinamico" << endl;
 }
    
 return 0;  

}
   
   

