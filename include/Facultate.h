#ifndef FACULTATE_H
#define FACULTATE_H

#include <string>

// Lista care contine cursurile
class Curs{
    public:
        int id;
        int anul;
        int semestrul;
        int credite;
        std::string nume;
        std::string examen;
        std::string profesor;
        Curs* next;
};
class ListaCursuri{
    public:
        Curs* first = nullptr;
        Curs* last = nullptr;
        int total_cursuri = 0;
};

// Lista care contine sectiile
class Sectie{
    public:
        int id;
        std::string nume;
        ListaCursuri Cursuri;
        Sectie* next;
};
class ListaSectii{
    public:
        Sectie* first = nullptr;
        Sectie* last = nullptr;
        int total_sectii = 0;
};

// Lista care contine facultatile
class Faculta{
    public:
        int id;
        std::string nume;
        ListaSectii Sectii;
        Faculta* next;
};
class ListaFacultati{
    public:
        Faculta* first;
        Faculta* last;
        int total_facultati = 0;
};

class Facultate{
    public:
        ListaFacultati Lista;

        Facultate();
        virtual ~Facultate();

        bool isEmptyFacultate() const;
        void Add_Facultate(std::string nume);
        void Add_Facultate(int id, std::string nume);
        void Add_Facultate(std::string nume, ListaSectii Sectiile);
        void Add_Facultate(int id, std::string nume, ListaSectii Sectiile);
        void Show_Facultate();
        int ExistFac(int pozitie);
        int ExistFac(std::string nume);
        std::string Nume_Facultate(int pozitie);
        ListaSectii Sectia_Facultate(int pozitie);
        void Show_Facultate_Secti(int pozitie);
        std::string Nume_Sectie_Fac(int PozFac, int PozSec);
        ListaCursuri ReturnCursuri(int PozFac, int PozSec);
        std::string Nume_Curs_Fac_Sec(int PozFac, int PozSec, int PozCur);
        ListaSectii ReturnSectii(int pozitie);

        bool isEmptySect(ListaSectii L) const;
        void Add_Secti(int fac, int id, std::string nume);
        void Add_Secti(int fac, std::string nume);
        void Add_Secti(ListaSectii& L, std::string nume, ListaCursuri C);
        void Show_Secti(ListaSectii L);
        int ExistSec(ListaSectii L, int pozitie);
        ListaCursuri PointerCurs(ListaSectii L, int pozitie);
        std::string Nume_Sectie(ListaSectii L, int pozitie);
        std::string Nume_Sectie(ListaSectii L, int pozitie, int PozCur);

        bool isEmptyCurs(ListaCursuri C) const;
        void Add_cursuri_Secundar(ListaSectii L, int PozSec, int id, int an, int sem, std::string nume, std::string exam, int cred, std::string prof);
        void Add_Cursuri(ListaCursuri& C, int an, int sem, std::string nume, std::string exam, int cred, std::string prof);
        void Add_Cursuri(int PozFac, int PozSec, int an, int sem, std::string nume, std::string exam, int cred, std::string prof);
        void Add_Cursuri(int PozFac, int PozSec, int id, int an, int sem, std::string nume, std::string exam, int cred, std::string prof);
        void Show_Cursuri(ListaCursuri C);
        std::string Nume_Curs(ListaCursuri C, int pozitie);

        std::string All_Info_Facultate();
        std::string All_Info_Sectia(ListaSectii L, int fac);
        std::string All_Info_FacultateSectii();
        std::string All_Info_Curs(ListaCursuri C, int fac, int sec);
        std::string All_Info_SectiaCurs(ListaSectii L, int fac);
        std::string All_Info_FacultateSectiiCursuri();


 };

#endif // FACULTATE_H
