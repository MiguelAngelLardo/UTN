#include "Persona.h"
#include <cstring>//string.h

using namespace std;

Persona::Persona(){ 
  _nombre[0] = '\0';
  _apellido[0] = '\0';
  _domicilio[0] = '\0';
  _dni[0] = '\0';
  _mail[0] = '\0';
  _telefono[0] = '\0';
}
//si es por omision como entra en set no puedo darle por omision
//ademas asi tengo q enviar todo si o si, si fuera por omision puedo pasarle el nombre solo con lo q no me sirve
//hay q pasarle todo
//de aca hago el objeto anonimo
Persona::Persona(string nom, string ape, string dom, string dni, string mail, string tel){
  setNombre(nom);
  setApellido(ape);
  setDomicilio(dom);
  setDni(dni);
  setMail(mail);
  setTelefono(tel);
}

void Persona::setNombre(const string &nom){
  if(nom.size() <= 25) {
    strcpy(_nombre,nom.c_str());
  }else{
    _nombre[0] = '\0';
  }
}

void Persona::setApellido(const string &ape){
  if(ape.size() <= 25){
    strcpy(_apellido, ape.c_str());
  }else{
    _apellido[0] = '\0';
  }
}


void Persona::setDomicilio(const string &dom){
  if(dom.size() <= 25) {
    strcpy(_domicilio,dom.c_str());
  } else {
    _domicilio[0] = '\0';
  }
}

void Persona::setDni(const string &dni){
  if(dni.size() <= 8) {
    strcpy(_dni,dni.c_str());
  } else {
    _dni[0] = '\0';
  }
}

void Persona::setMail(const string &mail){
  if(mail.size() <= 25) {
    strcpy(_mail,mail.c_str());
  } else {
    _mail[0] = '\0';
  }
}

void Persona::setTelefono(const string &tel){
  if(tel.size() <= 25) {
    strcpy(_telefono,tel.c_str());
  } else {
    _telefono[0] = '\0';
  }   
}

 string Persona::getNombre() const{
  return string(_nombre);
}

string Persona::getApellido() const{
  return string(_apellido);
}

string Persona::getDomicilio() const {
  return string(_domicilio);
}

string Persona::getDni() const {
  return string(_dni);
}

string Persona::getMail() const {
  return string(_mail);
}

string Persona::getTelefono() const {
  return string(_telefono);
}


string Persona::toString() const {
  string str = "\t";
  str += string(_nombre) + ", \n\t";
  str += string(_apellido) + ", \n\t";
  str += string(_domicilio) + ", \n\t";
  str += string(_dni) + ", \n\t";
  str += string(_mail) + ", \n\t";
  str += string(_telefono) + ", \n\t";
  return str;
}