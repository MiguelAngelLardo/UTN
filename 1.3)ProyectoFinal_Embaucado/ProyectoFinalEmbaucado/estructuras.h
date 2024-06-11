#pragma once

const int CARTAS_POR_MANO = 5, TAM_BARAJA_FRANCESA = 20;
const int TAM_VALOR =  5, TAM_PALO = 4;
const string VALORES[TAM_VALOR] = {"10", "J", "Q", "K", "A"};
const string PALOS[TAM_PALO] = {"Corazón", "Diamante", "Pica", "Trébol"};

struct Carta
{
  string _valor;
  string _palo;
};

struct figura
{
  string _palo[TAM_PALO];///EMBAUCADORA
};

struct Jugador
{
  string _nombre;
  Carta _mano[CARTAS_POR_MANO];
  int _turno; ///turno para ver si es el jugador 1 o 2
  int _puntaje;
};
