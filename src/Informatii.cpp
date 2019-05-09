#include "Informatii.h"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>

Informatii::Informatii(Facultate& F){

    // Lista completa a facultatilor
    std::ifstream fa("facultati.txt");
    std::string nume, temp, tempLine;
    int id;
    while ( getline(fa, tempLine, '\n') ) {
        std::vector <std::string> tempstr;
        std::stringstream ss(tempLine);
        while (getline(ss, temp, '\t')) {
            tempstr.push_back(temp);
        }
        id = std::atoi(tempstr[0].c_str());
        nume = tempstr[1];
        F.Add_Facultate(id, nume);
    }

    //Lista completa a sectiilor
    std::ifstream fs("sectii.txt");
    std::string s_nume, s_temp, s_tempLine;
    int s_id, s_fac;
    while ( getline(fs, s_tempLine, '\n') ) {
        std::vector <std::string> s_tempstr;
        std::stringstream ss(s_tempLine);
        while (getline(ss, s_temp, '\t')) {
            s_tempstr.push_back(s_temp);
        }
        s_fac = std::atoi(s_tempstr[0].c_str());
        s_id = std::atoi(s_tempstr[1].c_str());
        s_nume = s_tempstr[2];
        F.Add_Secti(s_fac, s_id, s_nume);
    }

    // Lista completa a cursurilor
    std::ifstream fc("cursuri.txt");
    std::string c_nume, c_exam, c_prof, c_temp, c_tempLine;
    int c_fac, c_sec, c_id, c_an, c_sem, c_cred;
    while ( getline(fc, c_tempLine, '\n') ) {
        std::vector <std::string> c_tempstr;
        std::stringstream ss(c_tempLine);
        while (getline(ss, c_temp, '\t')) {
            c_tempstr.push_back(c_temp);
        }
        c_fac = std::atoi(c_tempstr[0].c_str());
        c_sec = std::atoi(c_tempstr[1].c_str());
        c_id = std::atoi(c_tempstr[2].c_str());
        c_an = std::atoi(c_tempstr[3].c_str());
        c_sem = std::atoi(c_tempstr[4].c_str());
        c_nume = c_tempstr[5];
        c_exam = c_tempstr[6];
        c_cred = std::atoi(c_tempstr[7].c_str());
        c_prof = c_tempstr[8];
        F.Add_Cursuri(c_fac, c_sec, c_id, c_an, c_sem, c_nume, c_exam, c_cred, c_prof);
    }
}

Informatii::Informatii(Student& S){
    // Lista a studentilor
    std::ifstream fa("studenti.txt");
    std::string temp, tempLine;
    std::string nume, prenume;
    int facultate, sectia, anul, semestrul;
    while ( getline(fa, tempLine, '\n') ) {
        std::vector <std::string> tempstr;
        std::stringstream ss(tempLine);
        while (getline(ss, temp, '\t')) {
            tempstr.push_back(temp);
        }
        facultate = std::atoi(tempstr[1].c_str());
        sectia = std::atoi(tempstr[2].c_str());
        anul = std::atoi(tempstr[3].c_str());
        semestrul = std::atoi(tempstr[4].c_str());
        nume = tempstr[5];
        prenume = tempstr[6];
        S.Addaugare(nume, prenume, facultate, sectia, anul, semestrul);
    }
 }


