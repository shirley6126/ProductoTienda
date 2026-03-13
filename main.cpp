#include <iostream>      // Librería para entrada y salida de datos
#include "Producto.h"    // Librería donde está la gestión de productos
#include "Reporte.h"     // Librería donde se genera el reporte final

using namespace std;

int main(){

    // Se crea un objeto de la clase gestionProducto
    // Este objeto será el encargado de manejar el inventario
    gestionProducto tienda;

    // Objeto que generará el reporte final
    Reporte reporte;

    int opcion; // Variable que guardará la opción del menú elegida por el usuario

    do{

        cout << "------------------------" << endl;
        cout << "------TIENDA UTA--------" << endl;
        cout << "------------------------" << endl;
        cout << "1. Registro del producto " << endl;
        cout << "2. Registros realizados " << endl;
        cout << "3. Buscar producto " << endl;
        cout << "4. Modificar registro " << endl;
        cout << "5. Eliminar registro " << endl;
        cout << "6. Generar reporte final " << endl;
        cout << "7. Salir de la tienda  " << endl;

        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion){

            case 1:
                // Llama al método para registrar un nuevo producto
                tienda.registrarProducto();
                break;

            case 2:
                // Muestra todos los productos registrados
                tienda.mostrarProductos();
                break;

            case 3:
                // Permite buscar un producto por su nombre
                tienda.buscarProducto();
                break;

            case 4:
                // Permite modificar los datos de un producto existente
                tienda.modificarProducto();
                break;

            case 5:
                // Permite eliminar un producto del inventario
                tienda.eliminarProducto();
                break;

            case 6:
                // Genera el reporte final usando la lista de productos
                reporte.generarReporte(tienda.obtenerLista());
                break;
        }

    }while (opcion != 7); // El programa se ejecuta mientras la opción sea diferente de 7

    cout << "Saliendo de la tienda..." << endl;

}
