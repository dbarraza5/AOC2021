#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#define LIMITE_PECES 1000

void cargarListaPeces(std::string nombre, std::vector<int> *lista_peces) {
    std::ifstream in(nombre);

    if (in) {
        std::string line;
        while (getline(in, line)) {
            std::stringstream sep(line);
            std::string field;
            while (getline(sep, field, ',')) {
                lista_peces->push_back(atof(field.c_str()));
            }
        }
        in.close();
    }
}

void guardarListaPeces(std::string nombre, std::vector<int> *lista_peces){
    std::string cadena;
    std::stringstream ss2;

    ss2.str("");
    for (int i = 0; i < lista_peces->size(); ++i) {
        ss2<<lista_peces->at(i);
        cadena+=ss2.str()+", ";
    }
}

// acualiza los peces con valor 7 y devuelve los peces excedenes que se deben agregar
int actualizarPoblacionPeces(std::vector<int> *lista_peces){
    int size = lista_peces->size();
    int numero_nuevo_peces_excedentes = 0;
    for (int i = 0; i < size; ++i) {
        if(lista_peces->at(i) == 0){
            lista_peces->at(i) = 7;
            if(lista_peces->size()<LIMITE_PECES)
            {
                lista_peces->push_back(9);
            }else{
                numero_nuevo_peces_excedentes++;
            }
        }
    }
    return numero_nuevo_peces_excedentes;
}
int main() {
    int limite_peces = 1000;
    std::vector<int> lista_peces;
    //cargarListaPeces("../Lanternfish.txt", &lista_peces);

    std::vector<std::string> archivos_particionados  {"../Lanternfish.txt"};
    //printf("Terminar de cargar el archivo\n");
    //------------------------------------------------------------------------------------------------------------------
    //archivos_particionados
    int peces_excedentes = 0;
    for (int dia = 0; dia <256 ; ++dia) {
        if(dia > 0){
            for (int indice_file = 0; indice_file < archivos_particionados.size(); ++indice_file) {
                cargarListaPeces(archivos_particionados[indice_file], &lista_peces);
            }
            peces_excedentes = actualizarPoblacionPeces(&lista_peces);
            if(peces_excedentes>0){
                archivos_particionados.push_back("part_"+std::to_string(dia)+"_"
                    +std::to_string(archivos_particionados.size()+1));
                for (int i = 0; i < peces_excedentes; ++i) {

                }
            }
        }
        for (int i = 0; i < lista_peces.size(); ++i) {
            lista_peces[i]-=1;
        }
        printf("dia %d y tam-peces %d\n",dia, lista_peces.size());
    }
    printf("tam lista peces %d\n", lista_peces.size());

    return 0;
}
