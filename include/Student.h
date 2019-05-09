#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Nod{
    int id;
    std::string nume;
    std::string prenume;
    int facultate;
    int sectia;
    int anul;
    int semestrul;
    Nod* next;
};

class Student
{
    public:
        Student();
        virtual ~Student();

        bool isEmpty() const;
        void Addaugare(std::string nume, std::string prenume, int fac, int sec, int an, int sem);
        void Afisare();
        std::string AllInfo();

    private:
        int total_studenti = 0;
        Nod* head;
        Nod* tail;

};

#endif // STUDENT_H
