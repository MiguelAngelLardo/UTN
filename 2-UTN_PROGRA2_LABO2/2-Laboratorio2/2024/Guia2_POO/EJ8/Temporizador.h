#pragma once

class Temporizador{

   private:
   int _hora, _minuto, _segundo;
   void mostrarHora();
   void mostrarMinuto();
   void mostrarSegundo();

   public:
   Temporizador(int hora = 0, int minuto = 0, int segundo = 0);
   int comparar(Temporizador aux);
   void cargar();
   void mostrar();
   void tic();
   void tac();
};

