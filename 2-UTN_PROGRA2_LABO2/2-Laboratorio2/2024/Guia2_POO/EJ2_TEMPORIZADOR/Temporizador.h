#ifndef TEMPORIZADOR_H_INCLUDED
#define TEMPORIZADOR_H_INCLUDED

class Temporizador{

   private:
   int _hora, _minuto, _segundo;
   void mostrarHora();
   void mostrarMinuto();
   void mostrarSegundo();

   public:
   Temporizador(int hora, int minuto, int segundo);
   int comparar(Temporizador aux);
   void mostrar();
   void tic();
   void tac();


};

#endif // TEMPORIZADOR_H_INCLUDED