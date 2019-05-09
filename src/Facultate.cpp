#include "Facultate.h"

#include <iostream>
#include <sstream>

Facultate::Facultate(){
    Lista.first = nullptr;
    Lista.last = nullptr;
}

Facultate::~Facultate(){
    Faculta *aux = Lista.first, *temp;
    Sectie *aux_sectie, *temp_sectie;
    Curs *aux_curs, *temp_curs;
    while(aux != nullptr){
        temp = aux;
        aux_sectie = aux->Sectii.first;
        while(aux_sectie != nullptr){
            temp_sectie = aux_sectie;
            aux_curs = aux_sectie->Cursuri.first;
            while(aux_curs != nullptr){
                temp_curs = aux_curs;
                aux_curs = aux_curs->next;
                delete temp_curs;
            }
            aux_sectie = aux_sectie->next;
            delete temp_sectie;
        }
        aux = aux->next;
        delete temp;
    }
    Lista.first = Lista.last = nullptr;
    Lista.total_facultati = 0;
}

// Functii pentru facultate
bool Facultate::isEmptyFacultate() const {
    return Lista.first == nullptr;
}

void Facultate::Add_Facultate(std::string nume){
    if(isEmptyFacultate()){
        Lista.first = new Faculta;
        Lista.first->id = Lista.total_facultati;
        Lista.first->nume = nume;
        Lista.first->next = nullptr;
        Lista.last = Lista.first;
    }else{
        Faculta* nod = new Faculta;
        nod->id = Lista.total_facultati;
        nod->nume = nume;
        nod->next = nullptr;
        Lista.last->next = nod;
        Lista.last = nod;
    }
    Lista.total_facultati += 1;
}

void Facultate::Add_Facultate(int id, std::string nume){
    Lista.total_facultati += 1;
    if(isEmptyFacultate()){
        Lista.first = new Faculta;
        Lista.first->id = id;
        Lista.first->nume = nume;
        Lista.first->next = nullptr;
        Lista.last = Lista.first;
    }else{
        Faculta* nod = new Faculta;
        nod->id = id;
        nod->nume = nume;
        nod->next = nullptr;
        Lista.last->next = nod;
        Lista.last = nod;
    }
}

void Facultate::Add_Facultate(std::string nume, ListaSectii Sectiile){
    if(isEmptyFacultate()){
        Lista.first = new Faculta;
        Lista.first->id = Lista.total_facultati;
        Lista.first->nume = nume;
        Lista.first->Sectii = Sectiile;
        Lista.first->next = nullptr;
        Lista.last = Lista.first;
    }else{
        Faculta* nod = new Faculta;
        nod->id = Lista.total_facultati;
        nod->nume = nume;
        nod->Sectii = Sectiile;
        nod->next = nullptr;
        Lista.last->next = nod;
        Lista.last = nod;
    }
    Lista.total_facultati += 1;
}

void Facultate::Add_Facultate(int id, std::string nume, ListaSectii Sectiile){
    Lista.total_facultati += 1;
    if(isEmptyFacultate()){
        Lista.first = new Faculta;
        Lista.first->id = id;
        Lista.first->nume = nume;
        Lista.first->Sectii = Sectiile;
        Lista.first->next = nullptr;
        Lista.last = Lista.first;
    }else{
        Faculta* nod = new Faculta;
        nod->id = id;
        nod->nume = nume;
        nod->Sectii = Sectiile;
        nod->next = nullptr;
        Lista.last->next = nod;
        Lista.last = nod;
    }
}

void Facultate::Show_Facultate(){
    if(isEmptyFacultate())
        std::cout << "Lista este goala" << std::endl;
    else{
        int i = 0;
        Faculta* nod = Lista.first;
        std::cout << "ID\tNume" << std::endl;
        while (nod != nullptr){
            std::cout << i << "\t" << nod->nume << std::endl;
            nod = nod->next;
            i++;
        }
    }
}

int Facultate::ExistFac(int pozitie){
    if(isEmptyFacultate())
        return 0;
    else{
        int i = 0;
        Faculta* nod = Lista.first;
        while (nod != nullptr && i < pozitie){
            nod = nod->next;
            i++;
        }
        if (i == pozitie && nod != nullptr)
            return 1;
        else
            return 0;
    }
}

int Facultate::ExistFac(std::string nume){
    if(isEmptyFacultate())
        return 0;
    else{
		int ok = 0;
        Faculta* nod = Lista.first;
		while (nod != nullptr){
            if(nod->nume == nume){
				ok = 1;
				break;
			}
            nod = nod->next;
        }
		if(ok)
			return 1;
		else
			return 0;
    }
}

std::string Facultate::Nume_Facultate(int pozitie){
    if(isEmptyFacultate())
        return "Lista este goala";
    else{
        int i = 0;
        Faculta* nod = Lista.first;
        while (nod != nullptr && i < pozitie){
            nod = nod->next;
            i++;
        }
        if (i == pozitie && nod != nullptr)
            return nod->nume;
        else{
            std::ostringstream text;
            text << "Nu s-a gasit pozitia data (" << pozitie << ")";
            return text.str();
        }
    }
}

void Facultate::Show_Facultate_Secti(int pozitie){
    if(isEmptyFacultate())
        std::cout << "Lista facultatilor este goala!";
    else{
        int i = 0;
        Faculta* nod = Lista.first;
        while (nod != nullptr && i < pozitie){
            nod = nod->next;
            i++;
        }
        if (i == pozitie && nod != nullptr){
            return Show_Secti(nod->Sectii);
        }else{
            std::cout << "Nu s-a gasit pozitia data (" << pozitie << ")";
        }
    }
}

std::string Facultate::Nume_Sectie_Fac(int PozFac, int PozSec){
    if(isEmptyFacultate())
        return "Lista este goala";
    else{
        int i = 0;
        Faculta* nod = Lista.first;
        while (nod != nullptr && i < PozFac){
            nod = nod->next;
            i++;
        }
        if (i == PozFac && nod != nullptr)
            return Nume_Sectie(nod->Sectii, PozSec);
        else{
            std::ostringstream text;
            text << "Nu s-a gasit pozitia data (" << PozFac << ")";
            return text.str();
        }
    }
}

ListaCursuri Facultate::ReturnCursuri(int PozFac, int PozSec){
    if(isEmptyFacultate())
        std::cout <<  "Lista este goala";
    else{
        int i = 0;
        Faculta* nod = Lista.first;
        while (nod != nullptr && i < PozFac){
            nod = nod->next;
            i++;
        }
        if (i == PozFac && nod != nullptr)
            return PointerCurs(nod->Sectii, PozSec);
        else{
            std::cout << "Nu s-a gasit pozitia data (" << PozFac << ")";
        }
    }
}

std::string Facultate::Nume_Curs_Fac_Sec(int PozFac, int PozSec, int PozCur){
    if(isEmptyFacultate())
        return "Lista este goala";
    else{
        int i = 0;
        Faculta* nod = Lista.first;
        while (nod != nullptr && i < PozFac){
            nod = nod->next;
            i++;
        }
        if (i == PozFac && nod != nullptr)
            return Nume_Sectie(nod->Sectii, PozSec, PozCur);
        else{
            std::ostringstream text;
            text << "Nu s-a gasit pozitia data (" << PozFac << ")";
            return text.str();
        }
    }
}

ListaSectii Facultate::ReturnSectii(int pozitie){
    if(isEmptyFacultate())
        std::cout << "Lista facultatilor este goala!";
    else{
        int i = 0;
        Faculta* nod = Lista.first;
        while (nod != nullptr && i < pozitie){
            nod = nod->next;
            i++;
        }
        if (i == pozitie && nod != nullptr){
            return nod->Sectii;
        }else{
            std::cout << "Nu s-a gasit pozitia data (" << pozitie << ")";
        }
    }
}

std::string Facultate::All_Info_Facultate(){
    std::ostringstream text;
    text << "";
    if(isEmptyFacultate())
        return text.str();
    else{
        Faculta* nod = Lista.first;
        while (nod != nullptr){
            text << nod->id << "\t" << nod->nume << "\n";
            nod = nod->next;
        }
        return text.str();
    }
}

std::string Facultate::All_Info_Sectia(ListaSectii L, int fac){
    std::ostringstream text;
    text << "";
    if(isEmptySect(L))
        return text.str();
    else{
        Sectie* nod = L.first;
        while (nod != nullptr){
            text << fac << "\t" << nod->id << "\t" << nod->nume << std::endl;
            nod = nod->next;
        }
        return text.str();
    }
}

std::string Facultate::All_Info_FacultateSectii(){
    std::ostringstream text;
    text << "";
    if(isEmptyFacultate())
        return text.str();
    else{
        Faculta* nod = Lista.first;
        while (nod != nullptr){
            text << All_Info_Sectia(nod->Sectii, nod->id);
            nod = nod->next;
        }
        return text.str();
    }
}

std::string Facultate::All_Info_Curs(ListaCursuri C, int fac, int sec){
    std::ostringstream text;
    text << "";
    if(isEmptyCurs(C))
        return text.str();
    else{
        Curs* nod = C.first;
        while (nod != nullptr){
            text << fac << "\t" << sec << "\t" << nod->id << "\t" << nod->anul << "\t" << nod->semestrul << "\t" << nod->nume << "\t" << nod->examen << "\t" << nod->credite << "\t" << nod->profesor << std::endl;
            nod = nod->next;
        }
        return text.str();
    }
}

std::string Facultate::All_Info_SectiaCurs(ListaSectii L, int fac){
    std::ostringstream text;
    text << "";
    if(isEmptySect(L))
        return text.str();
    else{
        int i = 0;
        Sectie* nod = L.first;
        while (nod != nullptr){
            text << All_Info_Curs(nod->Cursuri, fac, nod->id);
            nod = nod->next;
            i++;
        }
        return text.str();
    }
}

std::string Facultate::All_Info_FacultateSectiiCursuri(){
    std::ostringstream text;
    text << "";
    if(isEmptyFacultate())
        return text.str();
    else{
        Faculta* nod = Lista.first;
        while (nod != nullptr){
            text << All_Info_SectiaCurs(nod->Sectii, nod->id);
            nod = nod->next;
        }
        return text.str();
    }
}

// Functii pentru sectii
bool Facultate::isEmptySect(ListaSectii L) const {
    return L.first == nullptr;
}

void Facultate::Add_Secti(int fac, std::string nume){
    if(isEmptyFacultate())
        std::cout << "Lista este goala";
    else{
        int i = 0;
        Faculta* nod = Lista.first;
        while (nod != nullptr && i < fac){
            nod = nod->next;
            i++;
        }
        if (i == fac && nod != nullptr){
            if(isEmptySect(nod->Sectii)){
                nod->Sectii.first = new Sectie;
                nod->Sectii.first->id = nod->Sectii.total_sectii;
                nod->Sectii.first->nume = nume;
                nod->Sectii.first->next = nullptr;
                nod->Sectii.last = nod->Sectii.first;
            }else{
                Sectie* nod_aux = new Sectie;
                nod_aux->id = nod->Sectii.total_sectii;
                nod_aux->nume = nume;
                nod_aux->next = nullptr;
                nod->Sectii.last->next = nod_aux;
                nod->Sectii.last = nod_aux;
            }
            nod->Sectii.total_sectii += 1;
        }else{
            std::cout << "Nu s-a gasit pozitia data (" << fac << ")";
        }
    }
}

void Facultate::Add_Secti(int fac, int id, std::string nume){
    if(isEmptyFacultate())
        std::cout << "Lista este goala";
    else{
        int i = 0;
        Faculta* nod = Lista.first;
        while (nod != nullptr && i < fac){
            nod = nod->next;
            i++;
        }
        if (i == fac && nod != nullptr){
            if(isEmptySect(nod->Sectii)){
                nod->Sectii.first = new Sectie;
                nod->Sectii.first->id = id;
                nod->Sectii.first->nume = nume;
                nod->Sectii.first->next = nullptr;
                nod->Sectii.last = nod->Sectii.first;
                nod->Sectii.total_sectii += 1;
            }else{
                Sectie* nod_aux = new Sectie;
                nod_aux->id = id;
                nod_aux->nume = nume;
                nod_aux->next = nullptr;
                nod->Sectii.last->next = nod_aux;
                nod->Sectii.last = nod_aux;
                nod->Sectii.total_sectii += 1;
            }
        }else{
            std::cout << "Nu s-a gasit pozitia data (" << fac << ")";
        }
    }
}

void Facultate::Add_Secti(ListaSectii& L, std::string nume, ListaCursuri C){
    if(isEmptySect(L)){
        L.first = new Sectie;
        L.first->nume = nume;
        L.first->Cursuri = C;
        L.first->next = nullptr;
        L.last = L.first;
        L.total_sectii += 1;
    }else{
        Sectie* nod = new Sectie;
        nod->nume = nume;
        nod->Cursuri = C;
        nod->next = nullptr;
        L.last->next = nod;
        L.last = nod;
        L.total_sectii += 1;
    }
}

void Facultate::Show_Secti(ListaSectii L){
    if(isEmptySect(L))
        std::cout << "Aceasta facultate nu are sectii adaugate!" << std::endl;
    else{
        int i = 0;
        Sectie* nod = L.first;
        std::cout << "ID\tNume" << std::endl;
        while (nod != nullptr){
            std::cout << i << "\t" << nod->nume << std::endl;
            nod = nod->next;
            i++;
        }
    }
}

int Facultate::ExistSec(ListaSectii L, int pozitie){
    if(isEmptySect(L))
        return 0;
    else{
        int i = 0;
        Sectie* nod = L.first;
        while (nod != nullptr && i < pozitie){
            nod = nod->next;
            i++;
        }
        if (i == pozitie && nod != nullptr)
            return 1;
        else{
            return 0;
        }
    }
}

ListaCursuri Facultate::PointerCurs(ListaSectii L, int pozitie){
    if(isEmptySect(L))
        std::cout <<  "Lista sectiilor este goala!";
    else{
        int i = 0;
        Sectie* nod = L.first;
        while (nod != nullptr && i < pozitie){
            nod = nod->next;
            i++;
        }
        if (i == pozitie && nod != nullptr)
            return nod->Cursuri;
        else{
            std::cout << "Nu s-a gasit pozitia data (" << pozitie << ")";
        }
    }
}

std::string Facultate::Nume_Sectie(ListaSectii L, int pozitie){
    if(isEmptySect(L))
        return "Lista sectiilor este goala!";
    else{
        int i = 0;
        Sectie* nod = L.first;
        while (nod != nullptr && i < pozitie){
            nod = nod->next;
            i++;
        }
        if (i == pozitie && nod != nullptr)
            return nod->nume;
        else{
            std::ostringstream text;
            text << "Nu s-a gasit pozitia data (" << pozitie << ")";
            return text.str();
        }
    }
}

std::string Facultate::Nume_Sectie(ListaSectii L, int pozitie, int PozCur){
    if(isEmptySect(L))
        return "Lista sectiilor este goala!";
    else{
        int i = 0;
        Sectie* nod = L.first;
        while (nod != nullptr && i < pozitie){
            nod = nod->next;
            i++;
        }
        if (i == pozitie && nod != nullptr)
            return Nume_Curs(nod->Cursuri, PozCur);
        else{
            std::ostringstream text;
            text << "Nu s-a gasit pozitia data (" << pozitie << ")";
            return text.str();
        }
    }
}


// Functii pentru cursuri
bool Facultate::isEmptyCurs(ListaCursuri C) const {
    return C.first == nullptr;
}

void Facultate::Add_cursuri_Secundar(ListaSectii L, int PozSec, int id, int an, int sem, std::string nume, std::string exam, int cred, std::string prof){
    if(isEmptySect(L))
        std::cout << "Lista sectiilor este goala!";
    else{
        int i = 0;
        Sectie* nod = L.first;
        while (nod != nullptr && i < PozSec){
            nod = nod->next;
            i++;
        }
        if (i == PozSec && nod != nullptr){
			if(isEmptyCurs(nod->Cursuri)){
				nod->Cursuri.first = new Curs;
				nod->Cursuri.first->id = nod->Cursuri.total_cursuri;
				nod->Cursuri.first->anul = an;
				nod->Cursuri.first->semestrul = sem;
				nod->Cursuri.first->credite = cred;
				nod->Cursuri.first->nume = nume;
				nod->Cursuri.first->examen = exam;
				nod->Cursuri.first->profesor = prof;
				nod->Cursuri.first->next = nullptr;
				nod->Cursuri.last = nod->Cursuri.first;
			}else{
				Curs* nod_aux = new Curs;
				nod_aux->id = nod->Cursuri.total_cursuri;
				nod_aux->nume = nume;
				nod_aux->anul = an;
				nod_aux->semestrul = sem;
				nod_aux->credite = cred;
				nod_aux->nume = nume;
				nod_aux->examen = exam;
				nod_aux->profesor = prof;
				nod_aux->next = nullptr;
				nod->Cursuri.last->next = nod_aux;
				nod->Cursuri.last = nod_aux;
			}
			nod->Cursuri.total_cursuri += 1;
        }else{
            std::cout << "Nu s-a gasit pozitia data (" << PozSec << ")";
        }
    }
}

void Facultate::Add_Cursuri(ListaCursuri& C, int an, int sem, std::string nume, std::string exam, int cred, std::string prof){
    if(isEmptyCurs(C)){
        C.first = new Curs;
        C.first->id = C.total_cursuri;
        C.first->anul = an;
        C.first->semestrul = sem;
        C.first->credite = cred;
        C.first->nume = nume;
        C.first->examen = exam;
        C.first->profesor = prof;
        C.first->next = nullptr;
        C.last = C.first;
    }else{
        Curs* nod = new Curs;
        nod->id = C.total_cursuri;
        nod->nume = nume;
        nod->anul = an;
        nod->semestrul = sem;
        nod->credite = cred;
        nod->nume = nume;
        nod->examen = exam;
        nod->profesor = prof;
        nod->next = nullptr;
        C.last->next = nod;
        C.last = nod;
    }
	C.total_cursuri += 1;
}

void Facultate::Add_Cursuri(int PozFac, int PozSec, int an, int sem, std::string nume, std::string exam, int cred, std::string prof){
    if(isEmptyFacultate())
        std::cout << "Lista este goala";
    else{
        int i = 0;
        Faculta* nod = Lista.first;
        while (nod != nullptr && i < PozFac){
            nod = nod->next;
            i++;
        }
        if (i == PozFac && nod != nullptr)
            Add_cursuri_Secundar(nod->Sectii, PozSec, nod->Sectii.first->Cursuri.total_cursuri, an, sem, nume, exam, cred, prof);
        else{
            std::cout << "Nu s-a gasit pozitia data (" << PozFac << ")";
        }
    }
}

void Facultate::Add_Cursuri(int PozFac, int PozSec, int id, int an, int sem, std::string nume, std::string exam, int cred, std::string prof){
    if(isEmptyFacultate())
        std::cout << "Lista este goala";
    else{
        int i = 0;
        Faculta* nod = Lista.first;
        while (nod != nullptr && i < PozFac){
            nod = nod->next;
            i++;
        }
        if (i == PozFac && nod != nullptr)
            Add_cursuri_Secundar(nod->Sectii, PozSec, id, an, sem, nume, exam, cred, prof);
        else{
            std::cout << "Nu s-a gasit pozitia data (" << PozFac << ")";
        }
    }
}

void Facultate::Show_Cursuri(ListaCursuri C){
    if(isEmptyCurs(C))
        std::cout << "Aceasta sectie nu are cursuri adaugate!" << std::endl;
    else{
        int i = 0;
        Curs* nod = C.first;
        std::cout << "ID\tAn.\tSem.\tNume\tExam.\tCred.\tProfesor" << std::endl;
        while (nod != nullptr){
            std::cout << i << "\t" << nod->anul << "\t" << nod->semestrul << "\t" << nod->nume << "\t" << nod->examen << "\t" << nod->credite << "\t" << nod->profesor << std::endl;
            nod = nod->next;
            i++;
        }
    }
}

std::string Facultate::Nume_Curs(ListaCursuri C, int pozitie){
    if(isEmptyCurs(C))
        return "Lista cursurilor este goala!";
    else{
        int i = 0;
        Curs* nod = C.first;
        while (nod != nullptr && i < pozitie){
            nod = nod->next;
            i++;
        }
        if (i == pozitie && nod != nullptr)
            return nod->nume;
        else{
            std::ostringstream text;
            text << "Nu s-a gasit pozitia data (" << pozitie << ")";
            return text.str();
        }
    }
}


