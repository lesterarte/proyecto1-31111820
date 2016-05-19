#include <ncurses.h>
#include <stdlib.h>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

using std::stringstream;
using std::string;

void mapainicial();
void createDeck(int**,const int, const int);
void deleteDeck(int**,const int);
void createFiveCards(int **,const int, const int);
void deleteFiveCards(int **,const int);
void randomFiveCards(int **,int**);
void flipMap();
void showFiveCards(int **, const int, const int);
void fullDeck(int **, const int, const int);
void initFiveCards(int**,const int, const int);
void otherFlipCards(int** ,int**,const int,char);
bool pair(int**,const int);
bool twhoPairs(int**,const int);
bool trio(int**,const int);
bool flush(int**,const int);
bool color(int**,const int);
bool fullHouse(int**,const int);
bool poker(int**,const int);
bool colorFlush(int**,const int);
bool royalFlush(int**,const int);
void showOneCard(int);
void showTwoCards(int,int);
int selectRandomCardMachine(int);
void hidecards();
bool validateDoble(int**,int,int);


int main(int argc,char* argv[])
{

	const int PALOS = 4;
	const int CARTAS = 13;
	const int FLIP_CARDS = 5;
	const int ATRIBUTES_CARDS = 2;
	char cartaDeDoble; 
	int contadorParaDoble=0;
	int cartaAleatoria;
	//almacena las 5 cartas con sus respectivos atributos
	int** arrayFlipCards = new int*[FLIP_CARDS];
	int ** arrayDeck = new int*[PALOS];
	int contarCartasMover = 0;
	int contarNumeros1 =0;
	int contarNumeros2 = 0;
	int contarNumeros3 = 0;
	int contarNumeros4 = 0;
	int contarNumeros5 = 0;
	char op_ingresoapuesta;
	char op_holdcards;
	char op_changeCards;
	char continueGame;
	char capchCards[5] = {' ',' ',' ',' ',' '};
	int creditos=0;
	int cuantasCartasCambiar=0;
	int apuestaCero=0;
	int apuestaToInt=0;
	int resultadosApuesta =0;
	string apuesta_valor;
	char doblarApuesta; 

	srand(time(NULL));
	createFiveCards(arrayFlipCards,FLIP_CARDS, ATRIBUTES_CARDS);
	createDeck(arrayDeck,PALOS,CARTAS);
	fullDeck(arrayDeck,PALOS,CARTAS);
	initFiveCards(arrayFlipCards,FLIP_CARDS, ATRIBUTES_CARDS);
	randomFiveCards(arrayDeck,arrayFlipCards);


	initscr();
	start_color();
	attron(A_BOLD);
	scrollok(curscr,TRUE);
	init_pair(1, COLOR_RED,     COLOR_BLACK);
    init_pair(2, COLOR_GREEN,   COLOR_BLACK);
    init_pair(3, COLOR_CYAN,    COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_WHITE,   COLOR_BLACK);
    init_pair(7,COLOR_WHITE, COLOR_BLACK);
    bkgd(COLOR_PAIR(7) | A_BOLD);
    mapainicial();
	noecho();

	while(continueGame != 'n' && continueGame != 'N')
	{

		mvprintw(28,13,"              ");
		mvprintw(28,13,"%d",creditos);
		move(36,84);

		while(op_ingresoapuesta != '\n')
		{
			op_ingresoapuesta = getch();
			if(op_ingresoapuesta > 47 && op_ingresoapuesta < 58)
			{
				addch(op_ingresoapuesta);
				apuestaCero++;
				apuesta_valor.push_back(op_ingresoapuesta);
			}
			if(apuestaCero == 0)
			{
				op_ingresoapuesta = ' ';
			}
		}
		apuestaToInt = atoi(apuesta_valor.c_str());

		if(creditos != 0)
		{
			while((creditos - apuestaToInt) < 0 && (creditos - apuestaToInt) != 0 )
			{

				mvprintw(33,48,"                                   ");
				mvprintw(33,45,"APUESTA INCORRECTA");
				mvprintw(36,84, "               ");
				move(36,84);

				op_ingresoapuesta = ' ';
				apuesta_valor.clear();
				while(op_ingresoapuesta != '\n')
				{
					op_ingresoapuesta = getch();
					if(op_ingresoapuesta > 47 && op_ingresoapuesta < 58)
					{
						addch(op_ingresoapuesta);
						apuesta_valor.push_back(op_ingresoapuesta);
					}
				}
				apuestaToInt = atoi(apuesta_valor.c_str());
			}
		}


		if(apuestaToInt <= creditos)
			creditos-=apuestaToInt;
		attron(COLOR_PAIR(3));
		mvprintw(34,14,"%d",apuestaToInt);
		attroff(COLOR_PAIR(3));
		mvprintw(28,13,"               ");
		attron(COLOR_PAIR(3));
		mvprintw(28,13,"%d",creditos);
		attroff(COLOR_PAIR(3));
		flipMap();
		showFiveCards(arrayFlipCards,FLIP_CARDS,ATRIBUTES_CARDS);
		mvprintw(32,44,"                                                             ");
		mvprintw(33,44,"                                                           ");
		mvprintw(36,44,"                                                         ");
		noecho();
		mvprintw(33,48,"Desea Cambiar alguna Carta?     ( si s/S ,  No  n/N )" );
		move(36,54);

		while(op_changeCards != 'n' && op_changeCards != 'N' && op_changeCards != 's'
			&& op_changeCards != 'S')
		{
			op_changeCards = getch();
			if(op_changeCards == 's' || op_changeCards == 'S')
			{

				mvprintw(33,48,"                                                      ");
				mvprintw(33,48,"Que cartas desea Cambiar (si no desea cambiar cartas puede precionar ENTER");
				mvprintw(34,48,"Ejemplo:  CARTAS: 23 -> Carta 2 y carta 3 ");
				mvprintw(36,42,"|                       CARTAS:   ");

				while(op_holdcards != '\n')
				{
					op_holdcards = getch();
					if(op_holdcards > 48 && op_holdcards < 54 && contarCartasMover <= 4)
					{

						if(contarNumeros1 == 0 && op_holdcards == '1')
						{
							addch(op_holdcards);
							contarCartasMover++;
							contarNumeros1++;
							cuantasCartasCambiar++;

							for(int i=0; i<5;i++)
							{
								if(capchCards[i] == ' ')
								{
									capchCards[i] = op_holdcards;
									break;
								}
							}
						}

						if(contarNumeros2 == 0 && op_holdcards == '2')
						{
							addch(op_holdcards);
							contarCartasMover++;
							contarNumeros2++;
							cuantasCartasCambiar++;

							for(int i=0; i<5;i++)
							{
								if(capchCards[i] == ' ')
								{
									capchCards[i] = op_holdcards;
									break;
								}
							}
						}

						if(contarNumeros3 == 0 && op_holdcards == '3')
						{
							addch(op_holdcards);
							contarCartasMover++;
							contarNumeros3++;
							cuantasCartasCambiar++;

							for(int i=0; i<5;i++)
							{
								if(capchCards[i] == ' ')
								{
									capchCards[i] = op_holdcards;
									break;
								}
							}
						}

						if(contarNumeros4 == 0 && op_holdcards == '4')
						{
							addch(op_holdcards);
							contarCartasMover++;
							contarNumeros4++;
							cuantasCartasCambiar++;

							for(int i=0; i<5;i++)
							{
								if(capchCards[i] == ' ')
								{
									capchCards[i] = op_holdcards;
									break;
								}
							}
						}

						if(contarNumeros5 == 0 && op_holdcards == '5')
						{
							addch(op_holdcards);
							contarCartasMover++;
							contarNumeros5++;
							cuantasCartasCambiar++;

							for(int i=0; i<5;i++)
							{
								if(capchCards[i] == ' ')
								{
									capchCards[i] = op_holdcards;
									break;
								}
							}
						}
					}
				}

				

				if(cuantasCartasCambiar==1)
				{
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[0]);
				}
				if(cuantasCartasCambiar==2)
				{
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[0]);
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[1]);
				}

				if(cuantasCartasCambiar==3)
				{
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[0]);
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[1]);
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[2]);
				}

				if(cuantasCartasCambiar==4)
				{
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[0]);
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[1]);
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[2]);
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[3]);
				}

				if(cuantasCartasCambiar==5)
				{
					randomFiveCards(arrayDeck,arrayFlipCards);
				}

				flipMap();
				showFiveCards(arrayFlipCards,FLIP_CARDS,ATRIBUTES_CARDS);
			}
		}
		
		if(twhoPairs(arrayFlipCards,FLIP_CARDS))
		{
			attron(COLOR_PAIR(3));
			mvprintw(28,70, ".-*-.-*-.-*TWO PAIRS-*-.-*-.-*");
			resultadosApuesta = apuestaToInt*2;
			attroff(COLOR_PAIR(3));
		}
		
		else if(pair(arrayFlipCards,FLIP_CARDS))
		{
			attron(COLOR_PAIR(3));
			mvprintw(28,70, ".-*-.-*-.-*PAIR-*-.-*-.-*");
			resultadosApuesta = apuestaToInt;
			attroff(COLOR_PAIR(3));
		}

		
		else if(trio(arrayFlipCards,FLIP_CARDS))
		{
			attron(COLOR_PAIR(3));
			mvprintw(28,65, ".-*-.-*-.-*THREE OF A KIND-*-.-*-.-*");
			resultadosApuesta = apuestaToInt*3;
			attroff(COLOR_PAIR(3));
		}
		
		else if(flush(arrayFlipCards,FLIP_CARDS))
		{
			attron(COLOR_PAIR(3));
			mvprintw(28,70, "-*-.-*-.-*FLUSH-*-.-*-.-*");
			resultadosApuesta =apuestaToInt*4;
			attroff(COLOR_PAIR(3));
		}

		
		else if(fullHouse(arrayFlipCards,FLIP_CARDS))
		{
			attron(COLOR_PAIR(3));
			mvprintw(28,65, "-*-.-*-.-*FULL HOUSE-*-.-*-.-*");
			resultadosApuesta =apuestaToInt*9;
			attroff(COLOR_PAIR(3));
		}

		else if(poker(arrayFlipCards,FLIP_CARDS))
		{
			attron(COLOR_PAIR(3));
			mvprintw(28,70, "-*-.-*-.-*POKER-*-.-*-.-*");
			resultadosApuesta =apuestaToInt*25;
			attroff(COLOR_PAIR(3));
		}

	
		else if(colorFlush(arrayFlipCards,FLIP_CARDS))
		{
			attron(COLOR_PAIR(3));
			mvprintw(28,65, "-*-.-*-.-*COLOR FLUSH-*-.-*-.-*");
			resultadosApuesta =apuestaToInt*50;
			attroff(COLOR_PAIR(3));
		}
		
		else if(royalFlush(arrayFlipCards,FLIP_CARDS))
		{
			attron(COLOR_PAIR(3));
			mvprintw(28,65, "-*-.-*-.-*ROYAL FLUSH-*-.-*-.-*");
			resultadosApuesta =apuestaToInt*250;
			attroff(COLOR_PAIR(3));
		}
		
		else if(color(arrayFlipCards,FLIP_CARDS))
		{
			attron(COLOR_PAIR(3));
			mvprintw(28,70, "-*-.-*-.-*COLOR-*-.-*-.-*");
			resultadosApuesta = apuestaToInt*5;
			attroff(COLOR_PAIR(3));
		}

		else
		{	
			attron(COLOR_PAIR(3));
			mvprintw(28,56, "-*-.-*-.-*INTENTA OTRA VEZ-*-.-*-.-*");
			attroff(COLOR_PAIR(3));
		}

		//codigo para doblar apuesta

		mvprintw(33,49,"                                                                             ");
		mvprintw(33,48,"Doblar Apuesta??    ( si s/S ,  No  n/N ) " );
		mvprintw(34,48,"                                            ");
		mvprintw(36,43,"                                          ");
		move(36,55);

		if(pair(arrayFlipCards,FLIP_CARDS) || twhoPairs(arrayFlipCards,FLIP_CARDS) 
		|| trio(arrayFlipCards,FLIP_CARDS) || flush(arrayFlipCards,FLIP_CARDS) 
		|| fullHouse(arrayFlipCards,FLIP_CARDS) || poker(arrayFlipCards,FLIP_CARDS)
		|| colorFlush(arrayFlipCards,FLIP_CARDS) || royalFlush(arrayFlipCards,FLIP_CARDS) 
		|| royalFlush(arrayFlipCards,FLIP_CARDS) || color(arrayFlipCards,FLIP_CARDS))
		{
			doblarApuesta = getch();
			while(doblarApuesta != 'N' && doblarApuesta != 'n')
			{
				if(doblarApuesta == 's' || doblarApuesta == 'S')
				{
					deleteFiveCards(arrayFlipCards,FLIP_CARDS);
					deleteDeck(arrayDeck,PALOS);
					createFiveCards(arrayFlipCards,FLIP_CARDS, ATRIBUTES_CARDS);
					createDeck(arrayDeck,PALOS,CARTAS);
					fullDeck(arrayDeck,PALOS,CARTAS);
					initFiveCards(arrayFlipCards,FLIP_CARDS, ATRIBUTES_CARDS);
					randomFiveCards(arrayDeck,arrayFlipCards);
					hidecards();

					mvprintw(28,56, "                                                           ");
					mvprintw(33,49,"                                                                             ");
					mvprintw(33,48,"Elija Una carta: " );
					mvprintw(34,48,"                                            ");
					mvprintw(36,43,"                                          ");
					move(36,55);

					while(contadorParaDoble == 0)
					{
						cartaDeDoble = getch();
						if(cartaDeDoble > 48 && cartaDeDoble < 54)
							contadorParaDoble++;						
					}
					contadorParaDoble = 0;
				
					flipMap();
					showFiveCards(arrayFlipCards,FLIP_CARDS,ATRIBUTES_CARDS);
					showOneCard(cartaDeDoble-'0');
					mvprintw(33,48,"                           " );
					mvprintw(33,48,"CARTA ALEATORIA..... cualquier tecla para continuar" );
					move(36,55);
					getch();
					flipMap();
					showFiveCards(arrayFlipCards,FLIP_CARDS,ATRIBUTES_CARDS);
					 cartaAleatoria = selectRandomCardMachine(cartaDeDoble-'0');
					showTwoCards(cartaDeDoble-'0', cartaAleatoria);

					if(validateDoble(arrayFlipCards,cartaDeDoble-'0',cartaAleatoria))
					{
						attron(COLOR_PAIR(3));
						mvprintw(28,65, "-*-.-*-.-*PERDISTE-*-.-*-.-*");
						attroff(COLOR_PAIR(3));
						resultadosApuesta=0;
						doblarApuesta = 'N';
					}
					else
					{
						attron(COLOR_PAIR(3));
						mvprintw(28,65, "-*-.-*-.-*GANASTE-*-.-*-.-*");
						attroff(COLOR_PAIR(3));
						resultadosApuesta *= 2;
						mvprintw(39,14,"                      ");
						attron(COLOR_PAIR(3));
						mvprintw(39,14,"%d",resultadosApuesta);
						attroff(COLOR_PAIR(3));
						mvprintw(8,35,"                                                                                        ");
						mvprintw(33,49,"                                                                             ");
						mvprintw(33,48,"Doblar Apuesta??    ( si s/S ,  No  n/N ) " );
						mvprintw(34,48,"                                            ");
						mvprintw(36,43,"                                          ");
						move(36,55);
						doblarApuesta = getch();
					}
				}
			}		
		}

		//Mostrar Ganancias
  		if(resultadosApuesta != 0)
  			creditos += resultadosApuesta;

		mvprintw(28,13,"               ");
		attron(COLOR_PAIR(3));
		mvprintw(28,13,"%d",creditos);
		attroff(COLOR_PAIR(3));
		mvprintw(33,49,"                                                                             ");
		mvprintw(33,48,"Desea Seguir Jugando?     ( si s/S ,  No  n/N )" );
		mvprintw(34,48,"                                            ");
		mvprintw(36,43,"                                          ");
		move(36,55);

		while(continueGame != 'n' && continueGame != 'N')
		{
			continueGame = getch();
			if(continueGame == 's' || continueGame == 'S')
			{

				deleteFiveCards(arrayFlipCards,FLIP_CARDS);
				deleteDeck(arrayDeck,PALOS);
				createFiveCards(arrayFlipCards,FLIP_CARDS, ATRIBUTES_CARDS);
				createDeck(arrayDeck,PALOS,CARTAS);
				fullDeck(arrayDeck,PALOS,CARTAS);
				initFiveCards(arrayFlipCards,FLIP_CARDS, ATRIBUTES_CARDS);
				randomFiveCards(arrayDeck,arrayFlipCards);
				op_ingresoapuesta = ' ';
				op_holdcards = ' ';
				contarNumeros1 = 0;
				contarNumeros2 = 0;
				contarNumeros3 = 0;
				contarNumeros4 = 0;
				contarNumeros5 = 0;
				contarCartasMover=0;
				cuantasCartasCambiar=0;
				op_changeCards = ' ';
				apuestaCero=0;
				apuesta_valor.clear();
				apuestaToInt=0;
				resultadosApuesta=0;

				for(int i=0;i<5;i++)
				{
					capchCards[i] = ' ';
				}

				clear();
				mapainicial();
				move(36,84);
				noecho();
				break;
			}
		}
	}//final del juego

	refresh();
	endwin();
	deleteFiveCards(arrayFlipCards,FLIP_CARDS);
	deleteDeck(arrayDeck,PALOS);
	return 0;
}


bool validateDoble(int** fiveCards, int CartaEleccionJugador,int cartaSeleccionMaquina)
{
	if(fiveCards[cartaSeleccionMaquina-1][1]== 1)
		return true;
	else if(fiveCards[CartaEleccionJugador-1][1] == 1)
		return false;
	else if(fiveCards[cartaSeleccionMaquina-1][1] > fiveCards[CartaEleccionJugador-1][1])
		return true; 
	else 
		return false;
}

void hidecards()
{
	attron(COLOR_PAIR(2));
	mvprintw(9,35," ****************     ****************     ****************     ****************     ****************");
	mvprintw(10,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(11,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(12,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(13,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(14,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(15,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(16,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(17,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(18,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(19,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(20,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(21,35," ****************     ****************     ****************     ****************     ****************  ");
	attroff(COLOR_PAIR(2));
}

void showOneCard(int cartaNoMostrar)
{
	for(int i=0; i<5; i++)
	{
		if((i+1) != cartaNoMostrar)
		{
			attron(COLOR_PAIR(2));
			mvprintw(9,35 + (21*i)," ****************");
			mvprintw(10,35 + (21*i),"******************");
			mvprintw(11,35 + (21*i),"******************");
			mvprintw(12,35 + (21*i),"******************");
			mvprintw(13,35 + (21*i),"******************");
			mvprintw(14,35 + (21*i),"******************");
			mvprintw(15,35 + (21*i),"******************");
			mvprintw(16,35 + (21*i),"******************");
			mvprintw(17,35 + (21*i),"******************");
			mvprintw(18,35 + (21*i),"******************");
			mvprintw(19,35 + (21*i),"******************");
			mvprintw(20,35 + (21*i),"******************");
			mvprintw(21,35 + (21*i)," ****************");
			attroff(COLOR_PAIR(2));
		}
		else
		{
			mvprintw(8,35 + (21*i), "    SU CARTA");
		}	
	}
}

void showTwoCards(int cartaNoMostrarJugador, int cartaNoMostrarMachine)
{
	for(int i=0; i<5; i++)
	{
		if((i+1) != cartaNoMostrarJugador && (i+1) != cartaNoMostrarMachine)
		{
			attron(COLOR_PAIR(2));
			mvprintw(9,35 + (21*i)," ****************");
			mvprintw(10,35 + (21*i),"******************");
			mvprintw(11,35 + (21*i),"******************");
			mvprintw(12,35 + (21*i),"******************");
			mvprintw(13,35 + (21*i),"******************");
			mvprintw(14,35 + (21*i),"******************");
			mvprintw(15,35 + (21*i),"******************");
			mvprintw(16,35 + (21*i),"******************");
			mvprintw(17,35 + (21*i),"******************");
			mvprintw(18,35 + (21*i),"******************");
			mvprintw(19,35 + (21*i),"******************");
			mvprintw(20,35 + (21*i),"******************");
			mvprintw(21,35 + (21*i)," ****************");
			attroff(COLOR_PAIR(2));
		}
	}
}

int selectRandomCardMachine(int CartaEleccionJugador)
{
	int cartaSeleccionMaquina;
	bool salirwhile = false;
	while(salirwhile != true)
	{
		cartaSeleccionMaquina = rand()%5 + 1;
		if(cartaSeleccionMaquina != CartaEleccionJugador)
			salirwhile = true; 
	}
	return cartaSeleccionMaquina;
}

void createFiveCards(int** fiveCards, const int cartas_mostradas, const int atributos_cartas_mostradas)
{
	for(int i=0;i<cartas_mostradas;i++)
	{
		fiveCards[i]= new int[atributos_cartas_mostradas];
	}
}

void createDeck(int** deck, const int palos, const int cartas)
{
	for(int i=0;i<palos;i++)
	{
		deck[i]= new int[cartas];
	}
}

void deleteFiveCards(int** fiveCards, const int cartas_mostradas)
{
	for(int i=0; i<cartas_mostradas; i++)
	{
		delete[] fiveCards[i];
	}
	delete[] fiveCards;
}// liberar memoria

void deleteDeck(int** deck, const int palos)
{
	for(int i=0; i<palos; i++)
	{
		delete[] deck[i];
	}
	delete[] deck;
}// liberar memoria

void fullDeck(int ** deck, const int palos, const int cartas)
{
	for(int i =0; i<palos; i++)
	{
		for(int j=0; j<cartas; j++)
		{
			deck[i][j] = j+1;
		}
	}
}

void randomFiveCards(int ** deck,int** fiveCards)
{
	int palo,carta;
	int cont=0;
	int i=0;
	int j=0;

	while(cont != 5)
	{
		palo = rand() % 4;
		carta = rand() % 13;
		if(deck[palo][carta]  != 0)
		{
			fiveCards[i][j] = palo+1;
			fiveCards[i][j+1] = deck[palo][carta];
			deck[palo][carta] = 0;
			i++;
			cont++;
		}
	}
}

void otherFlipCards(int** deck,int** fiveCards,const int palos,char estaCarta)
{
	int cambiarEstaCarta = (estaCarta-'0')-1;
	int palo,carta;
	int j=0;

	for(int i=0; i<palos;i++)
	{
		if( i == cambiarEstaCarta)
		{
			palo = rand() % 4;
			carta = rand() % 13;

			while(i<5)
			{
				if(deck[palo][carta]  != 0)
				{
					fiveCards[i][j] = palo+1;
					fiveCards[i][j+1] = deck[palo][carta];
					deck[palo][carta] = 0;
					break;
				}
				palo = rand() %4;
				carta = rand() %13;
			}
			break;
		}
	}
}

void initFiveCards(int** fiveCards,const int palo, const int carta)
{
	for(int i=0; i<palo; i++)
	{
		for(int j=0; j<carta; j++)
		{
			fiveCards[i][j] = 0;
		}
	}
}

bool twhoPairs(int** fiveCards,const int cantidadCartas)
{
	int cont1 = 0;
	int cont2 = 0;
	int cont3 = 0;
	int muestra = fiveCards[0][1];
	int muestra2 = 0; 
	int muestra3 =0;	
	
	for (int i = 1; i < cantidadCartas; i++)
	{
		if(fiveCards[i][1] != muestra)
		{
			muestra2 = fiveCards[i][1];
			break;
		}
	}

	for (int i = 1; i < cantidadCartas; i++)
	{
		if(fiveCards[i][1] != muestra && fiveCards[i][1] != muestra2)
		{
			muestra3 = fiveCards[i][1];
			break;
		}
	}

	for (int i = 0; i < cantidadCartas; i++)
	{
		if(fiveCards[i][1] ==muestra)
			cont1++;
		if(fiveCards[i][1] ==muestra2)
			cont2++;
		if(fiveCards[i][1] == muestra3)
			cont3++;
	}

	if((cont1==1 && cont2 == 2 && cont3 == 2) 
		|| (cont1==2 && cont2 == 1 && cont3 == 2) 
		|| (cont1==2 && cont2 == 2 && cont3 == 1))
		return true; 
	else
		return false;
}

bool pair(int** fiveCards,const int cantidadCartas)
{
	int cont = 0;

	for(int i=0; i<cantidadCartas; i++)
	{
		for(int j=i+1;j<cantidadCartas;j++)
		{
			if(fiveCards[i][1] == fiveCards[j][1] && (fiveCards[i][1]== 1
			|| fiveCards[i][1] == 11 || fiveCards[i][1] == 12 || fiveCards[i][1] == 13))
			{
				cont++;
			}
		}
	}
	if(cont == 1)
		return true;
	else
		return false;
}

bool trio(int** fiveCards,const int cantidadCartas)
{
	int cont1=0;
	int cont2=0;
	int cont3=0;
	int muestra1 = fiveCards[0][1];
	int muestra2 = 0;
	int muestra3 = 0;

	for(int i=1; i<cantidadCartas;i++)
	{
		if(muestra1 != fiveCards[i][1])
		{
			muestra2 = fiveCards[i][1];
			break;
		}
	}

	for(int i=1; i<cantidadCartas;i++)
	{
		if((muestra1 != fiveCards[i][1]) && muestra2 != fiveCards[i][1])
		{
			muestra3 = fiveCards[i][1];
			break;
		}
	}

	for(int i=1; i<cantidadCartas;i++)
	{
		if(muestra1 == fiveCards[i][1])
		{
			cont1++;
		}
	}

	for(int i=1; i<cantidadCartas;i++)
	{
		if(muestra2 == fiveCards[i][1])
		{
			cont2++;
		}
	}

	for(int i=1; i<cantidadCartas;i++)
	{
		if(muestra3 == fiveCards[i][1])
		{
			cont3++;
		}
	}

	if((cont1 == 2 && cont2 == 1 && cont3 == 1)||
	 (cont1 == 0 && cont2 == 3 && cont3 == 1) ||
	 (cont1 == 0 && cont2 == 1 && cont3 == 3))
		return true;
	else
		return false;

}

bool flush(int** fiveCards,const int cantidadCartas)
{
	int numeroMenor = fiveCards[0][1];
	int nextnumber=0;
	int contarPalos = 0;

	for(int i=1; i<cantidadCartas; i++)
	{
		if(fiveCards[i][0]  == fiveCards[0][0])
			contarPalos++;
	}

	for(int i=1; i<cantidadCartas; i++)
	{
		if(fiveCards[i][1] < numeroMenor)
			numeroMenor = fiveCards[i][1];
	}

	for(int i=0; i<cantidadCartas; i++)
	{
		if(fiveCards[i][1] == numeroMenor+1)
		{
			nextnumber++;
			numeroMenor++;
			i=-1;
		}
	}

	if(nextnumber == 4 && contarPalos != 4)
		return true;
	else
		return false;
}

bool color(int** fiveCards,const int cantidadCartas)
{
	int contpalos = 0;
	int contcartas =0;
	int valorpalo =fiveCards[0][0];

	for(int i=1; i<cantidadCartas; i++)
	{
		if(fiveCards[i][0] == valorpalo)
			contpalos++;
	}

	for(int i=0; i<cantidadCartas; i++)
	{
		for(int j=i+1;j<cantidadCartas;j++)
		{
			if(fiveCards[i][1] == fiveCards[j][1])
			{
				contcartas++;
			}
		}
	}

	if(contpalos == 4 && contcartas == 0)
		return true;
	else
		return false;
}

bool fullHouse(int** fiveCards,const int palos)
{
	int cont1=0;
	int cont2=0;
	int muestra1=fiveCards[0][1];
	int muestra2=0;

	for(int i=1; i<palos;i++)
	{
		if(muestra1 != fiveCards[i][1])
		{
			muestra2 = fiveCards[i][1];
			break;
		}
	}

	for(int i=1; i<palos;i++)
	{
		if(muestra1 == fiveCards[i][1])
		{
			cont1++;
		}
	}

	for(int i=1; i<palos;i++)
	{
		if(muestra2 == fiveCards[i][1])
		{
			cont2++;
		}
	}


	if((cont1 == 2 && cont2 == 2) ||(cont1 == 1 && cont2 == 3))
		return true;
	else
		return false;
}

bool poker(int** fiveCards,const int palos)
{
	int cont1=0;
	int cont2=0;
	int muestra1=fiveCards[0][1];
	int muestra2=0;

	for(int i=1; i<palos;i++)
	{
		if(muestra1 != fiveCards[i][1])
		{
			muestra2 = fiveCards[i][1];
			break;
		}
	}

	for(int i=1; i<palos;i++)
	{
		if(muestra1 == fiveCards[i][1])
		{
			cont1++;
		}
	}

	for(int i=1; i<palos;i++)
	{
		if(muestra2 == fiveCards[i][1])
		{
			cont2++;
		}
	}


	if((cont1 == 0 && cont2 == 4) || (cont1 == 3 && cont2 == 1))
		return true;
	else
		return false;
}

bool colorFlush(int** fiveCards,const int palos)
{
	int contpalos = 0;
	int numeroMenor = fiveCards[0][1];
	int nextnumber=0;
	int valorpalo = fiveCards[0][0];

	for(int i=1; i<palos; i++)
	{
		if(fiveCards[i][0] == valorpalo)
			contpalos++;
	}

	if(contpalos == 4)
	{
		for(int i=1; i<palos; i++)
		{
			if(fiveCards[i][1] < numeroMenor)
				numeroMenor = fiveCards[i][1];
		}

		for(int i=0; i<palos; i++)
		{
			if(fiveCards[i][1] == numeroMenor+1)
			{
				nextnumber++;
				numeroMenor++;
				i=-1;
			}
		}

		if(nextnumber == 4)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool royalFlush(int** fiveCards,const int palos)
{
	int contpalos = 0;
	int contcartas=0;
	int valorpalo =fiveCards[0][0];

	for(int i=1; i<palos; i++)
	{
		if(fiveCards[i][0] == valorpalo)
			contpalos++;
	}

	if(contpalos == 4)
	{
		for(int i=0; i<palos;i++)
		{
			if(fiveCards[i][1] == 1)
			{
				contcartas++;
				break;
			}
		}

		for(int i=0; i<palos;i++)
		{
			if(fiveCards[i][1] == 10)
			{
				contcartas++;
				break;
			}
		}

		for(int i=0; i<palos;i++)
		{
			if(fiveCards[i][1] == 11)
			{
				contcartas++;
				break;
			}
		}

		for(int i=0; i<palos;i++)
		{
			if(fiveCards[i][1] == 12)
			{
				contcartas++;
				break;
			}
		}

		for(int i=0; i<palos;i++)
		{
			if(fiveCards[i][1] == 13)
			{
				contcartas++;
				break;
			}
		}

		if(contcartas == 5)
			return true;
		else
			return false;
	}
	else
		return false;
}

void flipMap()
{
	attron(COLOR_PAIR(2));
	mvprintw(9,35," ****************     ****************     ****************     ****************     ****************");
	mvprintw(10,35,"*                *   *                *   *                *   *                *   *                * ");
	mvprintw(11,35,"*                *   *                *   *                *   *                *   *                * ");
	mvprintw(12,35,"*                *   *                *   *                *   *                *   *                * ");
	mvprintw(13,35,"*                *   *                *   *                *   *                *   *                * ");
	mvprintw(14,35,"*                *   *                *   *                *   *                *   *                * ");
	mvprintw(15,35,"*                *   *                *   *                *   *                *   *                * ");
	mvprintw(16,35,"*                *   *                *   *                *   *                *   *                * ");
	mvprintw(17,35,"*                *   *                *   *                *   *                *   *                * ");
	mvprintw(18,35,"*                *   *                *   *                *   *                *   *                * ");
	mvprintw(19,35,"*                *   *                *   *                *   *                *   *                * ");
	mvprintw(20,35,"*                *   *                *   *                *   *                *   *                * ");
	mvprintw(21,35," ****************     ****************     ****************     ****************     ****************  ");
	attroff(COLOR_PAIR(2));
}

void showFiveCards(int ** fiveCards, const int cartas_mostradas, const int atributos_cartas_mostradas)
{
	attron(A_BOLD);
	for(int i=0; i<cartas_mostradas; i++)
	{
		if(fiveCards[i][0] == 1)
		{	attron(COLOR_PAIR(1));
			mvprintw(13,36 +(21*i),"   ****  ****");
			mvprintw(14,36 +(21*i),"  ************");
			mvprintw(15,36 +(21*i),"   **********");
			mvprintw(16,36 +(21*i),"     ******");
			mvprintw(17,36 +(21*i),"       **");
			attroff(COLOR_PAIR(1));
		}

		if(fiveCards[i][0] == 2)
		{	attron(COLOR_PAIR(1));
			mvprintw(13,36 +(21*i),"       *");
			mvprintw(14,36 +(21*i),"      ***");
			mvprintw(15,36 +(21*i),"    *******");
			mvprintw(16,36 +(21*i),"      ***");
			mvprintw(17,36 +(21*i),"       *");
			attroff(COLOR_PAIR(1));
		}

		if(fiveCards[i][0] == 3)
		{
			attron(COLOR_PAIR(6));
			mvprintw(13,36 +(21*i),"       *");
			mvprintw(14,36 +(21*i),"    *******");
			mvprintw(15,36 +(21*i),"  ***********");
			mvprintw(16,36 +(21*i),"  **** * ****");
			mvprintw(17,36 +(21*i),"   *  ***  *");
			mvprintw(18,36 +(21*i),"     ***** ");
			attroff(COLOR_PAIR(6));
		}

		if(fiveCards[i][0]==4)
		{
			attron(COLOR_PAIR(6));
			mvprintw(13,36 +(21*i),"      ***");
			mvprintw(14,36 +(21*i),"     *****");
			mvprintw(15,36 +(21*i),"  *** *** ***");
			mvprintw(16,36 +(21*i),"  **** * ****");
			mvprintw(17,36 +(21*i),"      ***  ");
			mvprintw(18,36 +(21*i),"     ***** ");
			attroff(COLOR_PAIR(6));
		}
	}

	for(int i=0; i<cartas_mostradas; i++)
	{
		if(fiveCards[i][1] == 1)
		{
			mvprintw(10,37 + (21*i),"A");
			mvprintw(20,49 + (21*i),"A");
		}

		if(fiveCards[i][1] == 2)
		{
			mvprintw(10,37 + (21*i),"2");
			mvprintw(20,49 + (21*i),"2");
		}

		if(fiveCards[i][1] == 3)
		{
			mvprintw(10,37 + (21*i),"3");
			mvprintw(20,49 + (21*i),"3");
		}

		if(fiveCards[i][1] == 4)
		{
			mvprintw(10,37 + (21*i),"4");
			mvprintw(20,49 + (21*i),"4");
		}

		if(fiveCards[i][1] == 5)
		{
			mvprintw(10,37 + (21*i),"5");
			mvprintw(20,49 + (21*i),"5");
		}

		if(fiveCards[i][1] == 6)
		{
			mvprintw(10,37 + (21*i),"6");
			mvprintw(20,49 + (21*i),"6");
		}

		if(fiveCards[i][1] == 7)
		{
			mvprintw(10,37 + (21*i),"7");
			mvprintw(20,49 + (21*i),"7");
		}

		if(fiveCards[i][1] == 8)
		{
			mvprintw(10,37 + (21*i),"8");
			mvprintw(20,49 + (21*i),"8");
		}

		if(fiveCards[i][1] == 9)
		{
			mvprintw(10,37 + (21*i),"9");
			mvprintw(20,49 + (21*i),"9");
		}

		if(fiveCards[i][1] == 10)
		{
			mvprintw(10,37 + (21*i),"10");
			mvprintw(20,49 + (21*i),"10");
		}

		if(fiveCards[i][1] == 11)
		{
			mvprintw(10,37 + (21*i),"J");
			mvprintw(20,49 + (21*i),"J");
		}

		if(fiveCards[i][1] == 12)
		{
			mvprintw(10,37 + (21*i),"Q");
			mvprintw(20,49 + (21*i),"Q");
		}

		if(fiveCards[i][1] == 13)
		{
			mvprintw(10,37 + (21*i),"K");
			mvprintw(20,49 + (21*i),"K");
		}
	}
}

void mapainicial()
{
	attron(COLOR_PAIR(3));
	mvprintw(1,26," **       **  **  ** **    ******   ****          ****     ****     **   **  ******  ** **");
	mvprintw(2,26,"  **     **   **  **   **  **      **   **        **  **  **   **   ** **    **      **   **");
	mvprintw(3,26,"   **   **    **  **   **  ****    **    **       *****   **    **  ** *     ****    ****");
	mvprintw(4,26,"    ** **     **  **  **   **      ***  **        **      ***  **   **  **   **      **   **");
	mvprintw(5,26,"     **       **  ** **    ******   ****          **       ****     **   **  ******  **   **");
	attroff(COLOR_PAIR(3));

	mvprintw(9,1,"+---------------------------+ ");
	mvprintw(10,1,"|     Ganancia x Mano       | ");
	mvprintw(11,1,"+---------------------------+ ");
	mvprintw(12,1,"|  PAIR             = X 1   |");
	mvprintw(13,1,"|  TWO PAIRS        = X 2   | ");
	mvprintw(14,1,"|  THREE OF A KIND  = X 3   | ");
	mvprintw(15,1,"|  FLUSH            = X 4   | ");
	mvprintw(16,1,"|  COLOR            = X 5   | ");
	mvprintw(17,1,"|  FULL HOUSE       = X 9   | ");
	mvprintw(18,1,"|  POKER            = X 25  | ");
	mvprintw(19,1,"|  COLOR FLUSH      = X 50  | ");
	mvprintw(20,1,"|  ROYAL FLUSH      = X 250 | ");
	mvprintw(21,1,"|                           |");
	mvprintw(22,1,"+---------------------------+ ");

	mvprintw(25,1,"+---------------------------+ ");
	mvprintw(26,1,"|          CREDITS          |");
	mvprintw(27,1,"+---------------------------+ ");
	mvprintw(28,1,"|    $       0              |");
	mvprintw(29,1,"+---------------------------+ ");
	mvprintw(31,1,"+---------------------------+ ");
	mvprintw(32,1,"|             BET           |");
	mvprintw(33,1,"+---------------------------+ ");
	mvprintw(34,1,"|    $       0              |");
	mvprintw(35,1,"+---------------------------+ ");
	mvprintw(36,1,"+---------------------------+ ");
	mvprintw(37,1,"|        DOBLAR APUESTA     |");
	mvprintw(38,1,"+---------------------------+ ");
	mvprintw(39,1,"|    $       0              |");
	mvprintw(40,1,"+---------------------------+ ");

	mvprintw(31,42,"+-------------------------------------------------------------------------------------+ ");
	mvprintw(32,42,"|                                  BIENVENIDO !!!!!                                   | ");
	mvprintw(33,42,"|  Ingrese Su Apuesta:                                                                | ");
	mvprintw(34,42,"|                                                                                     | ");
	mvprintw(35,42,"|                                                                                     | ");
	mvprintw(36,42,"|                       APUESTA:      $                                               | ");
    mvprintw(37,42,"|                                                                                     | ");
    mvprintw(38,42,"|                                                                                     | ");
	mvprintw(39,42,"+-------------------------------------------------------------------------------------+ ");
	attron(COLOR_PAIR(2));
	mvprintw(9,35," ****************     ****************     ****************     ****************     ****************");
	mvprintw(10,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(11,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(12,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(13,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(14,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(15,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(16,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(17,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(18,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(19,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(20,35,"******************   ******************   ******************   ******************   ****************** ");
	mvprintw(21,35," ****************     ****************     ****************     ****************     ****************  ");
	attroff(COLOR_PAIR(2));
	mvprintw(23,35," +--------------+     +--------------+     +--------------+     +--------------+     +--------------+  ");
	mvprintw(24,35," |       1      |     |       2      |     |       3      |     |       4      |     |       5      |");
	mvprintw(25,35," +--------------+     +--------------+     +--------------+     +--------------+     +--------------+  ");
	attroff(COLOR_PAIR(2));

}
