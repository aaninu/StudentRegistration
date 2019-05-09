#include "Student.h"

#include <iostream>
#include <sstream>

Student::Student(){
    head = nullptr;
    tail = nullptr;
}

Student::~Student(){
    Nod *it = head, *temp;
    while(it != nullptr){
        temp = it;
        it = it->next;
        delete temp;
    }
    head = tail = nullptr;
}

bool Student::isEmpty() const {
    return head == nullptr;
}

void Student::Addaugare(std::string nume, std::string prenume, int fac, int sec, int an, int sem){
    if(isEmpty()){
        head = new Nod;
        head->id = total_studenti;
        head->nume = nume;
        head->prenume = prenume;
        head->facultate = fac;
        head->sectia = sec;
        head->anul = an;
        head->semestrul = sem;
        head->next = nullptr;
        tail = head;
    }else{
        Nod* nod = new Nod;
        nod->id = total_studenti;
        nod->nume = nume;
        nod->prenume = prenume;
        nod->facultate = fac;
        nod->sectia = sec;
        nod->anul = an;
        nod->semestrul = sem;
        nod->next = nullptr;
        tail->next = nod;
        tail = nod;
    }
    total_studenti += 1;
}

void Student::Afisare(){
    if(isEmpty())
        std::cout << "Lista studentilor este goala" << std::endl;
    else{
        Nod* nod = head;
        std::cout << "ID\tFac.\tSec.\tAn.\tSem.\tNume si prenume" << std::endl;
        while (nod != nullptr){
            std::cout << nod->id << "\t" << nod->facultate << "\t" << nod->sectia << "\t";
            std::cout << nod->anul << "\t" << nod->semestrul << "\t";
            std::cout << nod->nume << "\t" << nod->prenume << "\t" << std::endl;
            nod = nod->next;
        }
    }
}

std::string Student::AllInfo(){
    std::ostringstream text;
    text << "";
    if(isEmpty())
        return text.str();
    else{
        Nod* nod = head;
        while (nod != nullptr){
            text << nod->id << "\t" << nod->facultate << "\t" << nod->sectia << "\t";
            text << nod->anul << "\t" << nod->semestrul << "\t";
            text << nod->nume << "\t" << nod->prenume << "\n";
            nod = nod->next;
        }
        return text.str();
    }
}




