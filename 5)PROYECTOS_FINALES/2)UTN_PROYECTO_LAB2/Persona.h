#pragma once
#include <string>

class Persona{
protected:
  char _nombre[26]; //validaciones tiene 25 por omision como max
  char _apellido[26];
  char _domicilio[26];
  char _dni[9];
  char _mail[26];
  char _telefono[26];

public:
  Persona();//mejor por que asi el constructor debe llenarse si o si
  Persona(std::string nom, std::string ape, std::string dom, std::string dni, std::string mail, std::string tel); 

  void setNombre(const std::string &nom); //const asi no se modifica dentro y por referencias para q no se hagan copias;
  void setApellido(const std::string &ape);
  void setDomicilio(const std::string &dom);
  void setDni(const std::string &dni);
  void setMail(const std::string &mail);
  void setTelefono(const std::string &tel);

  std::string getNombre() const; //siempre devuelve objeto temporal por pasar de char a string, por eso es mejor poner el const por valor, en suma, podria ser const por referencia de la copia
  std::string getApellido() const;
  std::string getDomicilio() const;
  std::string getDni() const ;
  std::string getMail() const;
  std::string getTelefono() const;

   // = 0 Método virtual puro(se debe sobre escribir) - ademas, si todos fueran virtuales puros seria INTERFACE
  ////virtual hace q el metodo no exista hasta q el hijo lo use(polimorfismo)
  virtual std::string toString() const = 0;//no va = 0 por que de lo contrario siempre habria q implementarlo, no es metodo virtual  puro
};