#pragma once

#include"Persona.h"
#include<iostream>

class bkpPersona{
    private:
        Persona objPersona;
    public:
        void setPersona(Persona& p){objPersona = p;}
        Persona& getPersona(){return objPersona;}

//metodos

void MostrarBackup(const char* nombre="bkpPersona.dat");

void SetAbrirArchivoConRB(const char* nombre,FILE** p);

void SetAbrirArchivoConRBMAS(const char* nombre,FILE** p);

void SetAbrirArchivoConWB(const char* nombre,FILE **p);

void SetAbrirArchivoConAB(const char* nombre,FILE** p);

bool CrearBackup(const char* nombre1="Persona.dat",const char* nombre2="bkpPersona.dat");

bool RestaurarBackup(const char* nombre1="Persona.dat",const char* nombre2="bkpPersona.dat");

bool bajaFisica(int edad=7777,const char* nombre1="Persona.dat",const char* nombre2="bkpPersona.dat");

};