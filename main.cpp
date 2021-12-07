#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#define LIMITE_PECES 2211046

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

    for (int i = 0; i < lista_peces->size(); ++i) {
        ss2.str("");
        ss2<<lista_peces->at(i);
        cadena+=ss2.str();
        if (i<lista_peces->size()-1){
            cadena+=", ";
        }
    }
    std::ofstream fichero(nombre, std::ios::ate);
    fichero << cadena;
    fichero.close();
}

// acualiza los peces con valor 7 y devuelve los peces excedenes que se deben agregar
int actualizarPoblacionPeces(std::vector<int> *lista_peces, int &peces_excedentes){
    int size = lista_peces->size();
    int numero_nuevo_peces_excedentes = 0;
    for (int i = 0; i < size; ++i) {
        if(lista_peces->at(i) == 0){
            lista_peces->at(i) = 6;//7;
            if(lista_peces->size()<LIMITE_PECES)
            {
                lista_peces->push_back(8);//(9);
            }else{
                numero_nuevo_peces_excedentes++;
            }
        }else{
            lista_peces->at(i)-=1;
        }
    }
    if(numero_nuevo_peces_excedentes == 0 && peces_excedentes>0){
        int size = peces_excedentes;
        for (int i = 0; i < size; ++i) {
            lista_peces->push_back(8);
            peces_excedentes-=1;
            if(lista_peces->size()==LIMITE_PECES){
                break;
            }
        }
    }else{
        peces_excedentes+=numero_nuevo_peces_excedentes;
    }
    //while(lista_peces->size()<LIMITE_PECES)
    return numero_nuevo_peces_excedentes;
}
int main() {
    int limite_peces = 1000;
    std::vector<int> lista_peces;
    //cargarListaPeces("../Lanternfish.txt", &lista_peces);

    cargarListaPeces("../Lanternfish.txt", &lista_peces);
    guardarListaPeces("part_1_0", &lista_peces);
    std::vector<std::string> archivos_particionados  {"part_1_0"};
    lista_peces.clear();
    //printf("Terminar de cargar el archivo\n");
    //------------------------------------------------------------------------------------------------------------------
    //archivos_particionados
    int peces_excedentes = 0;
    int cantidad_peces = 0;
    for (int dia = 0; dia <256; ++dia) {
        //if(dia > 0){
            peces_excedentes = 0;
            cantidad_peces = 0;
            int cantidad_ultimo_archivo = 0;
            for (int indice_file = 0; indice_file < archivos_particionados.size(); ++indice_file) {
                cargarListaPeces(archivos_particionados[indice_file], &lista_peces);
                actualizarPoblacionPeces(&lista_peces, peces_excedentes);
                guardarListaPeces(archivos_particionados[indice_file], &lista_peces);
                cantidad_ultimo_archivo = lista_peces.size();
                cantidad_peces+=lista_peces.size();
                lista_peces.clear();

            }
            cantidad_peces+=peces_excedentes;
            if(peces_excedentes>0){
                printf("peces de exceso: %d\n", peces_excedentes);
                std::string nombre_ = "part_"+std::to_string(dia)+"_"
                                      +std::to_string(archivos_particionados.size()+1);
                archivos_particionados.push_back(nombre_);
                for (int i = 0; i < peces_excedentes; ++i) {
                    lista_peces.push_back(8);
                }
                guardarListaPeces(nombre_, &lista_peces);
                lista_peces.clear();
            }

        printf("dia %d y tam-peces %d\n",dia, cantidad_peces);
    }
    printf("tam lista peces %d\n", lista_peces.size());

    return 0;
}
