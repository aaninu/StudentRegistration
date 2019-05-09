#include <iostream>
#include <cstdlib>
#include <fstream>

#include "Facultate.h"
#include "Informatii.h"
#include "Student.h"

using namespace std;

Facultate Facul;
Student Stu;

Informatii Info(Facul);
Informatii Info2(Stu);

int run = 1;

void WriteInformation(){
    ofstream f;
    f.open("studenti.txt");
    f << Stu.AllInfo();
    f.close();
}

void WriteInformationFacultate(){
    ofstream f;
    f.open("facultati.txt");
    f << Facul.All_Info_Facultate();
    f.close();
}

void WriteInformationSectii(){
    ofstream f;
    f.open("sectii.txt");
    f << Facul.All_Info_FacultateSectii();
    f.close();
}

void WriteInformationSectiiCursuri(){
    ofstream f;
    f.open("cursuri.txt");
    f << Facul.All_Info_FacultateSectiiCursuri();
    f.close();
}

void program_option(){
    cout << " Din acest program puteti face urmatoarele:     - " << endl;
    cout << " 1. Vezi lista facultatilor;                    - " << endl;
    cout << " 2. Vezi lista studentilor inregistrati;        - " << endl;
    cout << endl;
    cout << " 4. Adauga un student nou;                      - " << endl;
    cout << " 5. Adauga o facultate noua;                    - " << endl;
    cout << " 6. Adauga o sectie noua la o facultate;        - " << endl;
    cout << " 7. Adauga un curs nou la o sectie;             - " << endl;
    cout << endl;
    cout << " 9. Inchide programul.                          - " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << " Ce vrei sa faci?                               - " << endl;
}

void program_show_fac(){
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << " Ai ales sa vezi lista facultatilor:            - " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    Facul.Show_Facultate();
    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    program_option();
}

void program_show_stu(){
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << " Ai ales sa vezi lista studentilor:             - " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    Stu.Afisare();
    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    program_option();
}

void program_add_stu(){
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << " Ai ales sa adaugi un student nou               - " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << " Completati informatiile cu atentie             - " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    std::string nume, prenume, save;
    int facultate, sectia, anul, semestrul;
    cout << " Nume: ";
    cin.sync();
    getline(cin, nume);
    cout << " Prenume: ";
    cin.sync();
    getline(cin, prenume);
    cout << " Anul: (1)" << endl; anul = 1;
    cout << " Semestrul: (1)" << endl; semestrul = 1;
    if(Facul.isEmptyFacultate())
        facultate = -1;
    else{
        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
        cout << " Mai jos aveti lista facultatilor:              - " << endl;
        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
        Facul.Show_Facultate();
        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
        do{
            cout << " Introduceti ID-ul facultatii dorite: "; cin >> facultate;
            if(!Facul.ExistFac(facultate))
                cout << " ID-ul introdus nu este valid!" << endl;
        }while(!Facul.ExistFac(facultate));
    }
    if(facultate != -1){
        ListaSectii Facu;
        Facu = Facul.ReturnSectii(facultate);
        if(Facul.isEmptySect(Facu))
            sectia = -1;
        else{
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            cout << " Ai ales: " << Facul.Nume_Facultate(facultate) << endl;
            cout << " Mai jos aveti lista sectiilor:                 - " << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            Facul.Show_Facultate_Secti(facultate);
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            do{
                cout << " Introduceti ID-ul sectiei dorite: "; cin >> sectia;
                if(!Facul.ExistSec(Facu, sectia))
                    cout << " ID-ul introdus nu este valid!" << endl;
            }while(!Facul.ExistSec(Facu, sectia));
        }
    }else{
        sectia = -1;
    }
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    if(facultate > -1)
        cout << " Ai ales: " << Facul.Nume_Facultate(facultate) << endl;
    else
        cout << " Nu sunt facultati disponibile! " << endl;
    if(sectia > -1)
        cout << " Sectia: " << Facul.Nume_Sectie_Fac(facultate, sectia) << endl;
    else
        cout << " Nu sunt sectii disponibile! " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    if(facultate > -1 && sectia > -1){
        cout << " Lista cursurilor disponibile: " << endl;
        ListaCursuri Cur;
        Cur = Facul.ReturnCursuri(facultate, sectia);
        if(Facul.isEmptyCurs(Cur))
            cout << "Nu sunt cursuri disponibile " << endl;
        else
            Facul.Show_Cursuri(Cur);
    }else
        cout << "Nu sunt cursuri disponibile " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl << endl;
    cout << " Vrei sa salvezi datele introduse? (Y/N) "; cin >> save;
    if(save == "Y" || save == "y"){
        Stu.Addaugare(nume, prenume, facultate, sectia, anul, semestrul);
        WriteInformation();
        cout << " Datele au fost inregistrate cu succes! " << endl << endl;
        program_option();
    }else{
        cout << " Ai ales sa nu salvezi datele. " << endl << endl;
        program_option();
    }
}

void program_add_fac(){
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << " Ai ales sa adaugi o facultate noua in lista    - " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << " Completati informatiile cu atentie             - " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    string nume = "", save;
	do{
        cout << " Introduceti numele facultatii noi: " << endl << " ";
		cin.sync();
		getline(cin, nume);
		if(nume == "")
			std::cout << " Trebuie sa introduceti un nume!" << endl;
		if(Facul.ExistFac(nume))
			std::cout << " Numele introdus exista in lista actuala!" << endl;
	}while(nume == "" || Facul.ExistFac(nume));
    cout << " Ai introdus: " << nume << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl << endl;
    cout << " Vrei sa salvezi datele introduse? (Y/N) "; cin >> save;
    if(save == "Y" || save == "y"){
        Facul.Add_Facultate(nume);
        WriteInformationFacultate();
        cout << " Datele au fost inregistrate cu succes! " << endl << endl;
        program_option();
    }else{
        cout << " Ai ales sa nu salvezi datele. " << endl << endl;
        program_option();
    }
}

void program_add_sec(){
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << " Ai ales sa adaugi o sectie noua                - " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << " Completati informatiile cu atentie             - " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	string nume = "", save;
	int facultate;
	if(!Facul.isEmptyFacultate()){
        cout << " Mai jos aveti lista facultatilor:              - " << endl;
        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
        Facul.Show_Facultate();
        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
        do{
            cout << " Introduceti ID-ul facultatii dorite: "; cin >> facultate;
            if(!Facul.ExistFac(facultate))
                cout << " ID-ul introdus nu este valid!" << endl;
        }while(!Facul.ExistFac(facultate));
		do{
			cout << " Introduceti numele sectiei: " << endl << " ";
			cin.sync();
			getline(cin, nume);
			if(nume == "")
				std::cout << " Trebuie sa introduceti un nume!" << endl;
		}while(nume == "");
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
		cout << " Facultatea: " << Facul.Nume_Facultate(facultate) << endl;
		cout << " Sectia: " << nume << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl << endl;
		cout << " Vrei sa salvezi datele introduse? (Y/N) "; cin >> save;
		if(save == "Y" || save == "y"){
			Facul.Add_Secti(facultate, nume);
			WriteInformationSectii();
			cout << " Datele au fost inregistrate cu succes! " << endl << endl;
			program_option();
		}else{
			cout << " Ai ales sa nu salvezi datele. " << endl << endl;
			program_option();
		}
	}else{
		cout << " Nu exista facultati disponibile! " << endl << endl;
		program_option();
	}
}

void program_add_cur(){
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << " Ai ales sa adaugi un curs nou                  - " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << " Completati informatiile cu atentie             - " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	string save, nume = "", exam = "", prof = "";
	int facultate = 0, sectia = 0, an = 0, sem = 0, cred = 0;
    if(!Facul.isEmptyFacultate()){
        cout << " Mai jos aveti lista facultatilor:              - " << endl;
        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
        Facul.Show_Facultate();
        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
        do{
            cout << " Introduceti ID-ul facultatii dorite: "; cin >> facultate;
            if(!Facul.ExistFac(facultate))
                cout << " ID-ul introdus nu este valid!" << endl;
        }while(!Facul.ExistFac(facultate));
        ListaSectii Facu = Facul.ReturnSectii(facultate);
        if(!Facul.isEmptySect(Facu)){
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            cout << " Ai ales: " << Facul.Nume_Facultate(facultate) << endl;
            cout << " Mai jos aveti lista sectiilor:                 - " << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            Facul.Show_Facultate_Secti(facultate);
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            do{
                cout << " Introduceti ID-ul sectiei dorite: "; cin >> sectia;
                if(!Facul.ExistSec(Facu, sectia))
                    cout << " ID-ul introdus nu este valid!" << endl;
            }while(!Facul.ExistSec(Facu, sectia));
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            do{
                cout << " Introduceti anul de studiu (1, 2, 3 ,...): " << endl << " ";
                cin >> an;
                if(an < 1)
                    cout << " Valoarea introdusa nu este valida!" << endl;
            }while(an < 1);
            do{
                cout << " Introduceti semestrul: " << endl << " ";
                cin >> sem;
                if(sem < 1)
                    cout << " Valoarea introdusa nu este valida!" << endl;
            }while(sem < 1);
            do{
                cout << " Introduceti numele cursului: " << endl << " ";
                cin.sync();
                getline(cin, nume);
                if(nume == "")
                    cout << " Valoarea introdusa nu este valida!" << endl;
            }while(nume == "");
            do{
                cout << " Introduceti tipul examenului: " << endl << " ";
                cin.sync();
                getline(cin, exam);
                if(exam == "")
                    cout << " Valoarea introdusa nu este valida!" << endl;
            }while(exam == "");
            do{
                cout << " Introduceti numarul de credite: " << endl << " ";
                cin >> cred;
                if(cred < 1)
                    cout << " Valoarea introdusa nu este valida!" << endl;
            }while(cred < 1);
            do{
                cout << " Introduceti numele profesorului: " << endl << " ";
                cin.sync();
                getline(cin, prof);
                if(prof == "")
                    cout << " Valoarea introdusa nu este valida!" << endl;
            }while(prof == "");
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl << endl;
            cout << " Ai introdus: " << endl;
            cout << " Facultatea:       " << Facul.Nume_Facultate(facultate) << endl;
            cout << " Sectia:           " << Facul.Nume_Sectie_Fac(facultate, sectia) << endl;
            cout << " Anul:             " << an << endl;
            cout << " Semestrul:        " << sem << endl;
            cout << " Denumirea:        " << nume << endl;
            cout << " Tipul examenului: " << exam << endl;
            cout << " Numar de credite: " << cred << endl;
            cout << " Numele profesor : " << prof << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl << endl;
            cout << " Vrei sa salvezi datele introduse? (Y/N) "; cin >> save;
            if(save == "Y" || save == "y"){
                Facul.Add_Cursuri(facultate, sectia, an, sem, nume, exam, cred, prof);
                WriteInformationSectiiCursuri();
                cout << " Datele au fost inregistrate cu succes! " << endl << endl;
                program_option();
            }else{
                cout << " Ai ales sa nu salvezi datele. " << endl << endl;
                program_option();
            }
        }else{
            cout << " Facultatea selectata nu are sectii! " << endl << endl;
            program_option();
        }
	}else{
		cout << " Nu exista facultati disponibile! " << endl << endl;
		program_option();
	}
}

void program_exit(){
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << " Ai ales sa inchizi programul!                  - " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << endl << endl;
}

void program(){
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << " Bine ai venit!                                 - " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    program_option();
    string work;
    while(run){
        cin >> work;
        system("cls");
        if(work == "1")
            program_show_fac();
        else if(work == "2")
            program_show_stu();
        else if(work == "4")
            program_add_stu();
        else if(work == "5")
            program_add_fac();
        else if(work == "6")
            program_add_sec();
        else if(work == "7")
            program_add_cur();
        else if(work == "9"){
            run = 0;
            break;
        }else
            program();
    }
}

int main(){
    program();
    program_exit();
    return 0;
}

