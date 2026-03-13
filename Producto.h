#ifndef PRODUCTO_H
#define PRODUCTO_H
// Estas líneas evitan que el archivo se incluya más de una vez en el programa

#include <vector>      // Librería para usar vectores
#include <iostream>    // Librería para entrada y salida de datos
using namespace std;

// ===============================
// ESTRUCTURA PRODUCTO
// ===============================
	struct Producto {

    string nombre;   // Nombre del producto
    int cant;        // Cantidad disponible
    double precio;   // Precio unitario del producto
    string tipo;     // Tipo o categoría del producto

};

// ===============================
// CLASE GESTION PRODUCTO
// ===============================
	class gestionProducto{

	private:

    // Vector que almacenará todos los productos registrados
    vector<Producto> lista;

	public:
		
	gestionProducto(){

    lista.push_back({"Pan",6,0.50,"Comestible"});
    lista.push_back({"Leche",8,1.00,"Lacteo"});
    lista.push_back({"Arroz",20,1.20,"Grano"});
    lista.push_back({"Azucar",15,0.90,"Grano"});
    lista.push_back({"Detergente",5,2.50,"Limpieza"});
    lista.push_back({"Jabon",12,1.30,"Limpieza"});
    lista.push_back({"Galletas",7,0.80,"Golosina"});
    lista.push_back({"Cereal",6,2.00,"Desayuno"});
    lista.push_back({"Aceite",9,3.50,"Cocina"});
    lista.push_back({"Sal",2,0.40,"Condimento"});

}

// ===============================
// REGISTRAR PRODUCTO
// ===============================
	void registrarProducto(){

    Producto p; // Variable temporal para guardar los datos ingresados

    cout<<"------REGISTRO DE PRODUCTO-----"<<endl;

    cout<<"Nombre: ";
    cin>>p.nombre;

    cout<<"Cantidad: ";
    cin>>p.cant;

    cout<<"Precio: ";
    cin>>p.precio;

    cout<<"Tipo: ";
    cin>>p.tipo;

    // push_back agrega el producto al final del vector
    lista.push_back(p);

    cout<<"Producto registrado con exito"<<endl;
}

// ===============================
// MOSTRAR PRODUCTOS
// ===============================
// Muestra todos los productos registrados en el sistema
	void mostrarProductos(){

    // Verifica si el vector está vacío
    if(lista.empty()){
        cout<<"No hay productos registrados"<<endl;
        return;
    }

    cout<<"---------PRODUCTOS REGISTRADOS-------"<<endl;

    for(int i=0;i<lista.size();i++){

        cout<<i+1<<". Producto:"<<endl;
        cout<<"Nombre: "<<lista[i].nombre<<endl;
        cout<<"Cantidad: "<<lista[i].cant<<endl;
        cout<<"Precio: "<<lista[i].precio<<endl;
        cout<<"Tipo: "<<lista[i].tipo<<endl;

        cout<<"---------------------"<<endl;
    }

}

// ===============================
// BUSCAR PRODUCTO
// ===============================
// Permite buscar un producto por su nombre
	void buscarProducto(){

    string nombre;

    cout<<"---------BUSQUEDA DE PRODUCTO--------"<<endl;
    cout<<"Escriba el nombre del producto buscado: ";
    cin>>nombre;

  
    for(int i=0;i<lista.size();i++){

        if(lista[i].nombre == nombre){

            cout<<"Producto encontrado:"<<endl;

            cout<<"Nombre: "<<lista[i].nombre<<endl;
            cout<<"Cantidad: "<<lista[i].cant<<endl;
            cout<<"Precio: "<<lista[i].precio<<endl;
            cout<<"Tipo: "<<lista[i].tipo<<endl;

            return;
        }

    }

    cout<<"Producto no encontrado"<<endl;
}

// ===============================
// MODIFICAR PRODUCTO
// ===============================

	void modificarProducto(){

    if(lista.empty()){
        cout<<"No hay productos para modificar"<<endl;
        return;
    }

    // Primero se muestran los productos disponibles
    mostrarProductos();

    int opcion;

    cout<<"----------MODIFICAR PRODUCTO--------"<<endl;
    cout<<"Seleccione el producto a modificar: ";
    cin>>opcion;

    // Validación para evitar errores
    if(opcion<1 || opcion>lista.size()){
        cout<<"Opcion invalida"<<endl;
        return;
    }

    // Se modifican los datos del producto seleccionado
    cout<<"Nuevo nombre: ";
    cin>>lista[opcion-1].nombre;

    cout<<"Nueva cantidad: ";
    cin>>lista[opcion-1].cant;

    cout<<"Nuevo precio: ";
    cin>>lista[opcion-1].precio;

    cout<<"Nuevo tipo: ";
    cin>>lista[opcion-1].tipo;

    cout<<"Producto modificado correctamente"<<endl;

}

// ===============================
// ELIMINAR PRODUCTO
// ===============================

	void eliminarProducto(){

    if(lista.empty()){
        cout<<"No hay productos para eliminar"<<endl;
        return;
    }

    // Mostrar productos antes de eliminar
    mostrarProductos();

    int opcion;

    cout<<"---------ELIMINAR EL PRODUCTO--------"<<endl;
    cout<<"Seleccione el producto a eliminar: ";
    cin>>opcion;

    if(opcion<1 || opcion>lista.size()){
        cout<<"Opcion invalida"<<endl;
        return;
    }

    // erase elimina el elemento seleccionado del vector
    lista.erase(lista.begin()+(opcion-1));

    cout<<"Producto eliminado correctamente"<<endl;

}

// ===============================
// OBTENER LISTA DE PRODUCTOS
// ===============================
// Permite que otras clases (como Reporte) accedan al vector
	vector<Producto>& obtenerLista(){

    return lista;

}

};

#endif
