#include <ncurses.h>
#include <stdlib.h>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <string>


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
int cardsTochange(int);

int main(int argc,char* argv[])
{
	const int PALOS = 4;
	const int CARTAS = 13;
	const int FLIP_CARDS= 5;
	const int ATRIBUTES_CARDS = 2; 
	//almacena las 5 cartas con sus respectivos atributos
	int** arrayFlipCards = new int*[FLIP_CARDS];
	int ** arrayDeck = new int*[PALOS]; 
	double apuestainicial = 0.0;
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
	double gananciaAcumulada = 0.0; 
	int cuantasCartasCambiar=0;


	srand(time(NULL));
	createFiveCards(arrayFlipCards,FLIP_CARDS, ATRIBUTES_CARDS);
	createDeck(arrayDeck,PALOS,CARTAS);
	fullDeck(arrayDeck,PALOS,CARTAS);
	initFiveCards(arrayFlipCards,FLIP_CARDS, ATRIBUTES_CARDS);
	randomFiveCards(arrayDeck,arrayFlipCards);


	initscr();
	mapainicial();
	move(33,84);
	noecho();

	while(continueGame != 'n' && continueGame != 'N')
	{
		

		while(op_ingresoapuesta != '\n')
		{
			op_ingresoapuesta = getch();		
			if(op_ingresoapuesta > 47 && op_ingresoapuesta < 58)
			{
				addch(op_ingresoapuesta);
				//apuesta_valor.push_back(op_ingresoapuesta);
				//mvprintw(34,14,apuesta_valor.c_str());
			}			
		}
		op_ingresoapuesta=' ';

		flipMap();
		showFiveCards(arrayFlipCards,FLIP_CARDS,ATRIBUTES_CARDS);
		mvprintw(29,44,"                                                             ");
		mvprintw(30,44,"                                                           ");
		mvprintw(33,44,"                                                         ");
		noecho();
		mvprintw(30,48,"Desea Cambiar alguna Carta?     ( si s/S ,  No  n/N )" );
		move(33,54);

		while(op_changeCards != 'n' && op_changeCards != 'N' && op_changeCards != 's'
			&& op_changeCards != 'S')
		{
			op_changeCards = getch();
			if(op_changeCards == 's' || op_changeCards == 'S')
			{
				mvprintw(30,48,"                                                      ");
				mvprintw(30,48,"Que cartas desea Cambiar: ");
				mvprintw(31,48,"Ejemplo:  CARTAS: 23 -> Carta 2 y carta 3 ");
				mvprintw(33,42,"|                       CARTAS:   ");

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
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[0]);
				if(cuantasCartasCambiar==2)
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[0]);
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[1]);
				if(cuantasCartasCambiar==3)
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[0]);
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[1]);
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[2]);
				if(cuantasCartasCambiar==4)
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[0]);
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[1]);
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[2]);
					otherFlipCards(arrayDeck,arrayFlipCards,FLIP_CARDS,capchCards[3]);
				if(cuantasCartasCambiar==5)
					randomFiveCards(arrayDeck,arrayFlipCards);
				flipMap();
				showFiveCards(arrayFlipCards,FLIP_CARDS,ATRIBUTES_CARDS);
			}
		}
		mvprintw(30,48,"                                                      ");
		mvprintw(30,48,"Desea Seguir Jugando?     ( si s/S ,  No  n/N )" );
		mvprintw(31,48,"                                            ");
		mvprintw(33,42,"                                          ");
		move(33,54);

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
				contarCartasMover=0;
				cuantasCartasCambiar=0;
				op_changeCards = ' ';	

				for(int i=0;i<5;i++)
				{
					capchCards[i] = ' ';
				}

				clear();
				mapainicial();
				move(33,84);
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


void createFiveCards(int** fiveCards, const int cartas_mostradas, const int atributos_cartas_mostradas)
{
	for(int i=0;i<cartas_mostradas;i++)
	{
		fiveCards[i]= new int[atributos_cartas_mostradas]; 
	}
}

int cardsTochange(int cuantasCambiar)
{
	if(cuantasCambiar == 1)
		return 1;


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

void flipMap()
{
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
}

void showFiveCards(int ** fiveCards, const int cartas_mostradas, const int atributos_cartas_mostradas)
{
	for(int i=0; i<cartas_mostradas; i++)
	{
		if(fiveCards[i][0] == 1)
		{		
			mvprintw(13,36 +(21*i),"   ****  ****"); 
			mvprintw(14,36 +(21*i),"  ************"); 
			mvprintw(15,36 +(21*i),"   **********"); 
			mvprintw(16,36 +(21*i),"     ******"); 
			mvprintw(17,36 +(21*i),"       **"); 
		}
		
		if(fiveCards[i][0] == 2)
		{		
			mvprintw(13,36 +(21*i),"       *"); 
			mvprintw(14,36 +(21*i),"      ***"); 
			mvprintw(15,36 +(21*i),"    *******"); 
			mvprintw(16,36 +(21*i),"      ***"); 
			mvprintw(17,36 +(21*i),"       *"); 
		}

		if(fiveCards[i][0] == 3)
		{
			mvprintw(13,36 +(21*i),"       *"); 
			mvprintw(14,36 +(21*i),"    *******"); 
			mvprintw(15,36 +(21*i),"  ***********"); 
			mvprintw(16,36 +(21*i),"  **** * ****");
			mvprintw(17,36 +(21*i),"   *  ***  *");
			mvprintw(18,36 +(21*i),"     ***** ");
		}

		if(fiveCards[i][0]==4)
		{
			mvprintw(13,36 +(21*i),"      ***"); 
			mvprintw(14,36 +(21*i),"     *****"); 
			mvprintw(15,36 +(21*i),"  *** *** ***"); 
			mvprintw(16,36 +(21*i),"  **** * ****");
			mvprintw(17,36 +(21*i),"      ***  ");
			mvprintw(18,36 +(21*i),"     ***** ");
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
	mvprintw(1,29," *       *  *  * *    *****   ****          * *     ****   *   *  *****  * *"); 
	mvprintw(2,29,"  *     *   *  *   *  *      *    *         *   *  *    *  *  *   *      *   *");
	mvprintw(3,29,"   *   *    *  *    * ***    *    *         * *    *    *  **     ***    * *"); 
	mvprintw(4,29,"    * *     *  *   *  *      *    *         *      *    *  *  *   *      *   *"); 
	mvprintw(5,29,"     *      *  * *    *****   ****          *       ****   *   *  *****  *    *");  

	mvprintw(9,1,"+---------------------------+ ");
	mvprintw(10,1,"|     Ganancia x Mano       | ");
	mvprintw(11,1,"+---------------------------+ ");
	mvprintw(12,1,"|  par jack o mejor = X 1   | ");
	mvprintw(13,1,"|  Dos Pares        = X 2   | ");
	mvprintw(14,1,"|  Trio             = X 3   | ");
	mvprintw(15,1,"|  Escalera         = X 4   | ");
	mvprintw(16,1,"|  Mismo Manjar     = X 5   | ");
	mvprintw(17,1,"|  Full House       = X 9   | ");
	mvprintw(18,1,"|  Cuatro Iguales   = X 25  | ");
	mvprintw(19,1,"|  Escalera M/Palo  = X 50  | ");
	mvprintw(20,1,"|  Escalera Real    = X 250 | ");
	mvprintw(21,1,"|                           |");
	mvprintw(22,1,"+---------------------------+ ");

	mvprintw(25,1,"+---------------------------+ ");
	mvprintw(26,1,"|         ACUMULADO         |");
	mvprintw(27,1,"+---------------------------+ ");
	mvprintw(28,1,"|    $       0              |");
	mvprintw(29,1,"+---------------------------+ ");
	mvprintw(31,1,"+---------------------------+ ");
	mvprintw(32,1,"|         EN JUEGO          |");
	mvprintw(33,1,"+---------------------------+ ");
	mvprintw(34,1,"|    $       0              |");
	mvprintw(35,1,"+---------------------------+ ");

	mvprintw(28,42,"+-------------------------------------------------------------------------------------+ ");
	mvprintw(29,42,"|                                  BIENVENIDO !!!!!                                   | ");
	mvprintw(30,42,"|  Ingrese Su Apuesta:        Ejemplo ->   0012 = $ 12                                | ");
	mvprintw(31,42,"|                                                                                     | ");
	mvprintw(32,42,"|                                                                                     | ");
	mvprintw(33,42,"|                       APUESTA:      $                                               | ");
    mvprintw(34,42,"|                                                                                     | ");
    mvprintw(35,42,"|                                                                                     | ");
	mvprintw(36,42,"+-------------------------------------------------------------------------------------+ ");

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
	mvprintw(23,35," +--------------+     +--------------+     +--------------+     +--------------+     +--------------+  "); 
	mvprintw(24,35," |       1      |     |       2      |     |       3      |     |       4      |     |       5      |"); 
	mvprintw(25,35," +--------------+     +--------------+     +--------------+     +--------------+     +--------------+  "); 			 
}