#include <iostream>
#include <fstream>
using namespace std;

struct pokemon {
    string nome;
    string tipo;
    int punti_lotta;
    int esperienza;
};

void cattura_pokemon(pokemon arrayPokedex[], int posizione) {
    cout << "Ben fatto hai catturato un nuovo pokemon!!\nInserisci le sue informazioni:\nNome:\n";
    cin >> arrayPokedex[posizione].nome;
    cout << "Tipo:\n";
    cin >> arrayPokedex[posizione].tipo;
    cout << "Punti Lotta:\n";
    cin >> arrayPokedex[posizione].punti_lotta;
    cout << "Punti esperienza\n";
    cin >> arrayPokedex[posizione].esperienza;
}
void visualizza_registro(pokemon arrayPokedex[], int posizione) {
    cout << "Ben fatto hai " << posizione << "Pokemon!\n";
    for (int i = 1; i <= posizione; i++) {
        cout << "Nome:\n";
        cout << arrayPokedex[i].nome << endl;
        cout << "Tipo:\n";
        cout << arrayPokedex[i].tipo << endl;
        cout << "Punti Lotta:\n";
        cout << arrayPokedex[i].punti_lotta << endl;
        cout << "Punti esperienza\n";
        cout << arrayPokedex[i].esperienza << endl;
    }

}
void esplodi_pokemon(pokemon arrayPokedex[], int posizione) {

}
void salva_su_file(pokemon arrayPokedex[], int posizione) {
    ofstream outFile("pokemon.txt");

    if (outFile.is_open()) {
        for (int i = 1; i <= posizione; i++) {
            outFile << arrayPokedex[i].nome << endl;
            outFile << arrayPokedex[i].tipo << endl;
            outFile << arrayPokedex[i].punti_lotta << endl;
            outFile << arrayPokedex[i].esperienza << endl;
        }

        cout << "Dati salvati su file 'pokemon.txt'\n";
        outFile.close();
    }
    else {
        cout << "Errore nell'apertura del file.\n";
    }
}

void carica_da_file(pokemon arrayPokedex[], int& posizione) {
    ifstream inFile("pokemon.txt");

    if (inFile.is_open()) {
        while (inFile >> arrayPokedex[posizione].nome >> arrayPokedex[posizione].tipo >> arrayPokedex[posizione].punti_lotta >> arrayPokedex[posizione].esperienza) {
            posizione++;
        }

        cout << "Dati caricati da file 'pokemon.txt'\n";
        inFile.close();
    }
    else {
        cout << "Errore nell'apertura del file.\n";
    }
}

int main() {
    const int MAX_ARRAY = 10;
    int posizione = 0, scelta = 1;
    pokemon arrayPokedex[MAX_ARRAY];

    while (scelta > 0 && scelta < 6) {
        cout << "1) Aggiungi un nuovo pokemon\n2) Visualizza pokemon catturati\n3) Salva su file i pokemon catturati\n4) Carica pokemon da file\n5) Esplodi pokemon a tua scelta\n";
        cin >> scelta;

        switch (scelta) {
        case 1:
            posizione++;
            cattura_pokemon(arrayPokedex, posizione);
            break;
        case 2:
            visualizza_registro(arrayPokedex, posizione);
            break;
        case 3:
            salva_su_file(arrayPokedex, posizione);
            break;
        case 4:
            posizione = 0;
            carica_da_file(arrayPokedex, posizione);
            break;
        case 5:
            esplodi_pokemon(arrayPokedex, posizione);
            posizione--;
            break;
        }
    }

    return 0;
}
