#pragma once

const int MANO = 5, MAZO_VALOR =  5, MAZO_PALO = 4, BARAJA_FRANCESA = 20;
const string VALORES[MAZO_VALOR] = {"10", "J", "Q", "K", "A"};
const string PALOS[MAZO_PALO] = {"Corazón", "Diamante", "Pica", "Trébol"};

struct Carta
{
  string _valor;
  string _palo;
};

struct figura
{
  string _palo[MAZO_PALO];///EMBAUCADORA
};

struct Jugador
{
  string _nombre;
  Carta _mano[MANO];
  int _turno; ///turno para ver si es el jugador 1 o 2
};
