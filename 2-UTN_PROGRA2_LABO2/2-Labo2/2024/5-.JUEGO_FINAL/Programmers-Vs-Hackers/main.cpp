#include <SFML/Graphics.hpp>

int main()
{ 
  //Inicializacion de la ventana => con sfml es mas facil por que no debo crear 1er y 2do Buffwer
  sf::RenderWindow window(sf::VideoMode(800, 600), "Mi primer juego"); //800 px ancho


  while (window.isOpen())//game loop => es lo que hace que el juego siempre se ejecute
  {
    //1º ReadInput => actualiza los buffer con info de perifericos de entrada
    //2º Pull-events =>  win envia mensaje a la ventana para q sepa si se minimizo, si paso mouse por arriba etc
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();//cuando voy al boton "cerrar" => window.close() != window.isOpoen
    }

    window.clear();
    window.display();
  }

  //Liberar el juego => SFML lo hace por mi con window.close();

  return 0;
}