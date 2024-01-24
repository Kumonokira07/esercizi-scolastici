#include <iostream>
#include <fstream>
#include <windows.h>
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
        cout << arrayPokedex[i].nome << endl << endl;
        cout << "Tipo:\n";
        cout << arrayPokedex[i].tipo << endl << endl;
        cout << "Punti Lotta:\n";
        cout << arrayPokedex[i].punti_lotta << endl << endl;
        cout << "Punti esperienza\n";
        cout << arrayPokedex[i].esperienza << endl << endl << endl;
    }

}
void esplodi_pokemon(pokemon arrayPokedex[], int posizione) {
    int scelta;
    cout << "Quale pokemon vuoi esplodere ?\n";
    cin >> scelta;
    for (int i = scelta; i <= posizione; i++) {
        arrayPokedex[i].nome = arrayPokedex[i + 1].nome;
        arrayPokedex[i].tipo = arrayPokedex[i + 1].tipo;
        arrayPokedex[i].punti_lotta = arrayPokedex[i + 1].punti_lotta;
        arrayPokedex[i].esperienza = arrayPokedex[i + 1].esperienza;
    }
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

void carica_da_file(pokemon arrayPokedex[], int posizione) {
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
void bubbleSort(pokemon arrayPokedex[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arrayPokedex[j].nome > arrayPokedex[j + 1].nome) {
                pokemon temp = arrayPokedex[j];
                arrayPokedex[j] = arrayPokedex[j + 1];
                arrayPokedex[j + 1] = temp;
            }
        }
    }
}
void cerca_pokemon(pokemon arrayPokedex[], int posizione) {
    string searchValue;
    int searchValue1;
    int scelta;

    cout << "Scegli il criterio di ricerca:\n";
    cout << "1. Nome\n";
    cout << "2. Tipo\n";
    cout << "3. Punti Lotta\n";
    cout << "4. Esperienza\n";
    cin >> scelta;

    if (scelta == 1 || scelta == 2) {
        cout << "Inserisci il valore di ricerca:\n";
        cin >> searchValue;
    }
    else if (scelta == 3 || scelta == 4) {
        cout << "Inserisci il valore di ricerca:\n";
        cin >> searchValue1;
    }
    bool found = false;

    switch (scelta) {
    case 1:
        for (int i = 1; i <= posizione; i++) {
            if (arrayPokedex[i].nome == searchValue) {
                cout << "Nome:\n" << arrayPokedex[i].nome << endl;
                cout << "Tipo:\n" << arrayPokedex[i].tipo << endl;
                cout << "Punti Lotta:\n" << arrayPokedex[i].punti_lotta << endl;
                cout << "Punti esperienza:\n" << arrayPokedex[i].esperienza << endl;
                found = true;
            }
        }
        break;
    case 2:
        for (int i = 1; i <= posizione; i++) {
            if (arrayPokedex[i].tipo == searchValue) {
                cout << "Nome:\n" << arrayPokedex[i].nome << endl;
                cout << "Tipo:\n" << arrayPokedex[i].tipo << endl;
                cout << "Punti Lotta:\n" << arrayPokedex[i].punti_lotta << endl;
                cout << "Punti esperienza:\n" << arrayPokedex[i].esperienza << endl;
                found = true;
            }
        }
        break;
    case 3:
        for (int i = 1; i <= posizione; i++) {
            if (arrayPokedex[i].punti_lotta == searchValue1) {
                cout << "Nome:\n" << arrayPokedex[i].nome << endl;
                cout << "Tipo:\n" << arrayPokedex[i].tipo << endl;
                cout << "Punti Lotta:\n" << arrayPokedex[i].punti_lotta << endl;
                cout << "Punti esperienza:\n" << arrayPokedex[i].esperienza << endl;
                found = true;
            }
        }
        break;
    case 4:
        for (int i = 1; i <= posizione; i++) {
            if (arrayPokedex[i].esperienza == searchValue1) {
                cout << "Nome:\n" << arrayPokedex[i].nome << endl;
                cout << "Tipo:\n" << arrayPokedex[i].tipo << endl;
                cout << "Punti Lotta:\n" << arrayPokedex[i].punti_lotta << endl;
                cout << "Punti esperienza:\n" << arrayPokedex[i].esperienza << endl;
                found = true;
            }
        }
        break;
    default:
        cout << "Scelta non valida.\n";
        return;
    }

    if (!found) {
        cout << "Nessun Pokemon trovato con il criterio di ricerca selezionato.\n";
    }
}

int main() {
    const int MAX_ARRAY = 10;
    int posizione = 0, scelta = 1;
    pokemon arrayPokedex[MAX_ARRAY];

    while (scelta > 0 && scelta < 8) {
        cout << "1) Aggiungi un nuovo pokemon\n\n2) Visualizza pokemon catturati\n\n3) Salva su file i pokemon catturati\n\n4) Carica pokemon da file\n\n5) Esplodi pokemon a tua scelta\n\n6) Riordina\n\n7)Ricerca\n\n";
        cin >> scelta;

        switch (scelta) {
        case 1:
            system("cls");
            posizione++;
            cattura_pokemon(arrayPokedex, posizione);
            Sleep(6000);
            system("cls");
            break;
        case 2:
            system("cls");
            visualizza_registro(arrayPokedex, posizione);
            Sleep(6000);
            system("cls");
            break;
        case 3:
            system("cls");
            salva_su_file(arrayPokedex, posizione);
            Sleep(6000);
            system("cls");
            break;
        case 4:
            system("cls");
            posizione = 0;
            carica_da_file(arrayPokedex, posizione);
            Sleep(6000);
            system("cls");
            break;
        case 5:
            system("cls");
            esplodi_pokemon(arrayPokedex, posizione);
            posizione--;
            Sleep(6000);
            system("cls");
            break;
        case 6:
            system("cls");
            bubbleSort(arrayPokedex, posizione);
            Sleep(6000);
            system("cls");
            break;
        }
    }

    return 0;
