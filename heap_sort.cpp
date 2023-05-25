#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <list>

using namespace std;
using namespace std::chrono;

vector<int> leerArchivo(const string& nombreArchivo) {
    vector<int> listaNumeros;

    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            size_t inicio = linea.find('[') + 1;
            size_t fin = linea.find(']');
            string numerosString = linea.substr(inicio, fin - inicio);
            replace(numerosString.begin(), numerosString.end(), ',', ' ');

            int numero;
            stringstream ss(numerosString);
            while (ss >> numero) {
                listaNumeros.push_back(numero);
            }
        }

        archivo.close();
    }

    return listaNumeros;
}

// Función para realizar el heapify de un subárbol en un arreglo
void heapify(vector<int>& listaNumeros, int n, int i) {
    int largest = i;     // Inicializamos el nodo raíz como el más grande
    int left = 2 * i + 1;    // Índice del hijo izquierdo
    int right = 2 * i + 2;   // Índice del hijo derecho

    // Si el hijo izquierdo es mayor que la raíz
    if (left < n && listaNumeros[left] > listaNumeros[largest]) {
        largest = left;
    }

    // Si el hijo derecho es mayor que el más grande hasta ahora
    if (right < n && listaNumeros[right] > listaNumeros[largest]) {
        largest = right;
    }

    // Si el más grande no es la raíz
    if (largest != i) {
        swap(listaNumeros[i], listaNumeros[largest]);

        // Heapify recursivamente el subárbol afectado
        heapify(listaNumeros, n, largest);
    }
}

// Función principal del Heap Sort
void heapSort(vector<int>& listaNumeros) {
    int n = listaNumeros.size();

    // Construir un heap máximo
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(listaNumeros, n, i);
    }

    // Extraer los elementos uno a uno del heap
    for (int i = n - 1; i >= 0; i--) {
        // Mover la raíz actual al final
        swap(listaNumeros[0], listaNumeros[i]);

        // Llamar a heapify en el subárbol reducido
        heapify(listaNumeros, i, 0);
    }
}

// Función de utilidad para imprimir una lista
void imprimirLista(const vector<int>& listaNumeros) {
    for (int i = 0; i < listaNumeros.size(); i++) {
        cout << listaNumeros[i] << " ";
    }
    cout << endl;
}

int main(){
	
	std::list<double> miLista;
	
	vector<int> listaNumeros = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_1.txt");
    auto start = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros);
	auto stop = std::chrono::high_resolution_clock::now();
    // Cálculo de la duración en milisegundos
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	// Impresión del tiempo de ejecución con un entero y tres decimales
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration.count());
	//--------------------------------------------------------------------------------------------------------------------------------------
	vector<int> listaNumeros1 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_2.txt");
    auto start1 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros1);
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration1.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration1.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros2 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_3.txt");
    auto start2 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros2);
    auto stop2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(stop2 - start2);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration2.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration2.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros3 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_4.txt");
    auto start3 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros3);
    auto stop3 = std::chrono::high_resolution_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::milliseconds>(stop3 - start3);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration3.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration3.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros4 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_5.txt");
    auto start4 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros4);
    auto stop4 = std::chrono::high_resolution_clock::now();
    auto duration4 = std::chrono::duration_cast<std::chrono::milliseconds>(stop4 - start4);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration4.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration4.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros5 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_6.txt");
    auto start5 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros5);
    auto stop5 = std::chrono::high_resolution_clock::now();
    auto duration5 = std::chrono::duration_cast<std::chrono::milliseconds>(stop5 - start5);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration5.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration5.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros6 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_7.txt");
    auto start6 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros6);
    auto stop6 = std::chrono::high_resolution_clock::now();
    auto duration6 = std::chrono::duration_cast<std::chrono::milliseconds>(stop6 - start6);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration6.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration6.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros7 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_8.txt");
    auto start7 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros7);
    auto stop7 = std::chrono::high_resolution_clock::now();
    auto duration7 = std::chrono::duration_cast<std::chrono::milliseconds>(stop7 - start7);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration7.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration7.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros8 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_9.txt");
    auto start8 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros8);
    auto stop8 = std::chrono::high_resolution_clock::now();
    auto duration8 = std::chrono::duration_cast<std::chrono::milliseconds>(stop8 - start8);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration8.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration8.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros9 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_10.txt");
    auto start9 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros9);
    auto stop9 = std::chrono::high_resolution_clock::now();
    auto duration9 = std::chrono::duration_cast<std::chrono::milliseconds>(stop9 - start9);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration9.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration9.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros10 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_11.txt");
    auto start10 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros10);
    auto stop10 = std::chrono::high_resolution_clock::now();
    auto duration10 = std::chrono::duration_cast<std::chrono::milliseconds>(stop10 - start10);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration10.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration10.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros11 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_12.txt");
    auto start11 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros11);
    auto stop11 = std::chrono::high_resolution_clock::now();
    auto duration11 = std::chrono::duration_cast<std::chrono::milliseconds>(stop11 - start11);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration11.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration11.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros12 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_13.txt");
    auto start12 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros12);
    auto stop12 = std::chrono::high_resolution_clock::now();
    auto duration12 = std::chrono::duration_cast<std::chrono::milliseconds>(stop12 - start12);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration12.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration12.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros13 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_14.txt");
    auto start13 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros13);
    auto stop13 = std::chrono::high_resolution_clock::now();
    auto duration13 = std::chrono::duration_cast<std::chrono::milliseconds>(stop13 - start13);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration13.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration13.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros14 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_15.txt");
    auto start14 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros14);
    auto stop14 = std::chrono::high_resolution_clock::now();
    auto duration14 = std::chrono::duration_cast<std::chrono::milliseconds>(stop14 - start14);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration14.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration14.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros15 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_16.txt");
    auto start15 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros15);
    auto stop15 = std::chrono::high_resolution_clock::now();
    auto duration15 = std::chrono::duration_cast<std::chrono::milliseconds>(stop15 - start15);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration15.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration15.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros16 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_17.txt");
    auto start16 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros16);
    auto stop16 = std::chrono::high_resolution_clock::now();
    auto duration16 = std::chrono::duration_cast<std::chrono::milliseconds>(stop16 - start16);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration16.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration16.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros17 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_18.txt");
    auto start17 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros17);
    auto stop17 = std::chrono::high_resolution_clock::now();
    auto duration17 = std::chrono::duration_cast<std::chrono::milliseconds>(stop17 - start17);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration17.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration17.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros18 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_19.txt");
    auto start18 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros18);
    auto stop18 = std::chrono::high_resolution_clock::now();
    auto duration18 = std::chrono::duration_cast<std::chrono::milliseconds>(stop18 - start18);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration18.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration18.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros19 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_20.txt");
    auto start19 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros19);
    auto stop19 = std::chrono::high_resolution_clock::now();
    auto duration19 = std::chrono::duration_cast<std::chrono::milliseconds>(stop19 - start19);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration19.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration19.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    vector<int> listaNumeros20 = leerArchivo("C:\\Users\\USUARIO\\OneDrive\\Escritorio\\EJERCICIO 1\\archivo_21.txt");
    auto start20 = std::chrono::high_resolution_clock::now();
    heapSort(listaNumeros20);
    auto stop20 = std::chrono::high_resolution_clock::now();
    auto duration20 = std::chrono::duration_cast<std::chrono::milliseconds>(stop20 - start20);
    std::cout << "Tiempo de ejecucion: " << std::fixed << std::setprecision(3) << duration20.count() / 1000.0 << " segundos" << std::endl;
    miLista.push_back(duration20.count());
    //--------------------------------------------------------------------------------------------------------------------------------------
    
    // Recorrer y mostrar los elementos de la lista con tres decimales
    std::cout << std::fixed << std::setprecision(3); // Configurar la precisión decimal
    for (const auto& elemento : miLista) {
        if (elemento >= 0.001) {
            std::cout << elemento/1000 << " ";
        } else {
            std::cout << std::fixed << elemento << " "; // Mostrar en formato decimal
        }
    }
    std::cout << std::endl;
    
    // Crear y abrir el archivo de texto
    std::ofstream archivo("lista_tiempos_heapsort.txt");

    // Verificar si el archivo se abrió correctamente
    if (archivo.is_open()) {
        // Recorrer la lista y escribir los elementos en el archivo
        for (const auto& elemento : miLista) {
            archivo << elemento << "\n";
        }

        // Cerrar el archivo
        archivo.close();
        std::cout << "Archivo guardado correctamente." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo." << std::endl;
    }
    cout << endl;
    
    return 0;
}

