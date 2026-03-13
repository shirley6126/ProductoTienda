#ifndef REPORTE_H
#define REPORTE_H
// Estas dos líneas evitan que el archivo se incluya más de una vez
// durante la compilación del programa.

#include <iostream>   // Librería para entrada y salida de datos
#include "Producto.h" // Se incluye porque aquí se usa la estructura Producto
using namespace std;


class Reporte{

	public:

	void generarReporte(vector<Producto> &lista){

    cout<<"==============================="<<endl;
    cout<<"        REPORTE FINAL          "<<endl;
    cout<<"==============================="<<endl;

    // Verifica si el vector de productos está vacío
    if(lista.empty()){
        cout<<"No hay productos registrados"<<endl;
        return; 
    }

    // Variable que almacenará el valor total de todo el inventario
    double valorTotal = 0;

    // Guarda el número total de productos registrados
    int totalProductos = lista.size();

    // Variables para encontrar el producto con mayor cantidad
    int mayorCantidad = 0;
    int indiceMayorCantidad = 0;

    // Variables para encontrar el producto más caro
    double mayorPrecio = 0;
    int indiceMayorPrecio = 0;

    cout<<"----- INVENTARIO DE PRODUCTOS -----"<<endl;

    // Recorre todo el vector de productos
    for(int i=0;i<lista.size();i++){

        // Muestra el número del producto
        cout<<i+1<<". Producto"<<endl;

        // Muestra la información almacenada del producto
        cout<<"Nombre: "<<lista[i].nombre<<endl;
        cout<<"Cantidad: "<<lista[i].cant<<endl;
        cout<<"Precio: "<<lista[i].precio<<endl;
        cout<<"Tipo: "<<lista[i].tipo<<endl;

        cout<<"Valor total del producto: "<<lista[i].cant * lista[i].precio<<endl;

        cout<<"---------------------"<<endl;

        
        valorTotal += lista[i].cant * lista[i].precio;

        // Verifica si este producto tiene la mayor cantidad registrada
        if(lista[i].cant > mayorCantidad){
            mayorCantidad = lista[i].cant;
            indiceMayorCantidad = i;
        }

        // Verifica si este producto es el más caro
        if(lista[i].precio > mayorPrecio){
            mayorPrecio = lista[i].precio;
            indiceMayorPrecio = i; 
        }
    }

    cout<<endl;
    cout<<"=============================="<<endl;
    
    // Muestra la cantidad total de productos registrados
    cout<<"Total de productos registrados: "<<totalProductos<<endl;

    // Muestra el valor total del inventario
    cout<<"Valor total del inventario: "<<valorTotal<<endl;

    // Muestra el producto que tiene mayor cantidad
    cout<<"Producto con mayor cantidad: "<<lista[indiceMayorCantidad].nombre<<endl;

    // Muestra el producto con mayor precio
    cout<<"Producto mas caro: "<<lista[indiceMayorPrecio].nombre<<endl;

    cout<<"==============================="<<endl;

}

};
#endif
