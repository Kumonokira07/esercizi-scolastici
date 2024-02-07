#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

struct character {
    string name;
    int level;
    string race;
    string characterClass;
};

void aggiungiPersonaggio( character arrayCharacter[], int posizione) {
    cout << "Andiamo a creare un nuovo personaggio!!\nInserisci le sue informazioni:\nNome:\n";
    cin >> arrayCharacter[posizione].name;
    cout << "Livello:\n";
    cin >> arrayCharacter[posizione].level;
    cout << "Razza:\n";
    cin >> arrayCharacter[posizione].race;
    cout << "Classe:\n";
    cin >> arrayCharacter[posizione].characterClass;
}
void visualizza_registro(character arrayCharacter[], int posizione) {
    cout << "Ben fatto hai " << posizione << "Pokemon!\n";
    for (int i = 1; i <= posizione; i++) {
        cout << "Nome:\n";
        cout << arrayCharacter[i].name << endl << endl;
        cout << "Tipo:\n";
        cout << arrayCharacter[i].level << endl << endl;
        cout << "Punti Lotta:\n";
        cout << arrayCharacter[i].race << endl << endl;
        cout << "Punti esperienza\n";
        cout << arrayCharacter[i].characterClass << endl << endl << endl;
    }

}

void salva_su_file(character arrayCharacter[], int posizione) {
    ofstream outFile("character.txt");

    if (outFile.is_open()) {
        for (int i = 1; i <= posizione; i++) {
            outFile << arrayCharacter[posizione].name << endl;
            outFile << arrayCharacter[posizione].level << endl;
            outFile << arrayCharacter[posizione].race << endl;
            outFile << arrayCharacter[posizione].characterClass << endl;
        }

        cout << "Dati salvati su file 'pokemon.txt'\n";
        outFile.close();
    }
    else {
        cout << "Errore nell'apertura del file.\n";
    }
}

void carica_da_file(character arrayCharacter[], int posizione) {
    ifstream inFile("pokemon.txt");

    if (inFile.is_open()) {
        while (inFile >> arrayCharacter[posizione].name >> arrayCharacter[posizione].level >> arrayCharacter[posizione].race >> arrayCharacter[posizione].characterClass) {
            posizione++;
        }

        cout << "Dati caricati da file 'pokemon.txt'\n";
        inFile.close();
    }
    else {
        cout << "Errore nell'apertura del file.\n";
    }
}
void ordinamento(character arrayCharacter[], int posizione) {
    cout << "Ordinamento alfabetico\n";
        for (int i = 1; i < posizione; i++) {
            for (int j = i + 1; j <= posizione; j++) {
                if (arrayCharacter[i].name > arrayCharacter[j].name) {
                    swap(arrayCharacter[i], arrayCharacter[j]);
                }
            }
        }
}
void ricercaBinaria(character arrayCharacter[], int posizione) {
	string ricerca;
	cout << "Inserisci il nome del personaggio da cercare\n";
	cin >> ricerca;

	int inizio = 1, fine = posizione, centro;
	bool trovato = false;

    while (inizio <= fine && !trovato) {
		centro = (inizio + fine) / 2;
        if (arrayCharacter[centro].name == ricerca) {
			trovato = true;
		}
        else if (arrayCharacter[centro].name < ricerca) {
			inizio = centro + 1;
		}
        else {
			fine = centro - 1;
		}
	}

    if (trovato) {
		cout << "Pokemon trovato!\n";
		cout << "Nome:\n";
		cout << arrayCharacter[centro].name << endl << endl;
		cout << "Tipo:\n";
		cout << arrayCharacter[centro].level << endl << endl;
		cout << "Punti Lotta:\n";
		cout << arrayCharacter[centro].race << endl << endl;
		cout << "Punti esperienza\n";
		cout << arrayCharacter[centro].characterClass << endl << endl << endl;
	}
    else {
		cout << "Pokemon non trovato!\n";
	}
}

int main() {
    const int MAX_ARRAY = 100;
    int posizione = 0, scelta = 1;
    character arrayCharacter[MAX_ARRAY];

    while (scelta > 0 && scelta < 8) {
        cout << "1) Aggiungi un nuovo personaggio\n\n2) Visualizza personaggi\n\n3) Salva su file i personaggi\n\n4) Carica personaggi da file\n\n5) Riordina\n\n7)Ricerca\n\n";
        cin >> scelta;

        switch (scelta) {
        case 1:
            system("cls");
            posizione++;
            aggiungiPersonaggio(arrayCharacter, posizione);
            break;
        case 2:
            system("cls");
            visualizza_registro(arrayCharacter, posizione);
            break;
        case 3:
            system("cls");
            salva_su_file(arrayCharacter, posizione);
            break;
        case 4:
            system("cls");
            posizione = 0;
            carica_da_file(arrayCharacter, posizione);
            break;
        case 5:
            system("cls");
            ordinamento(arrayCharacter, posizione);
            break;
        case 6:
			system("cls");
			ricercaBinaria(arrayCharacter, posizione);
			break;
    }

    return 0;
}