#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define COL(x) "\033[" #x ";1m" //Colori per il terminale UNIX
#define COL_RED COL(31)
#define COL_GREEN COL(32)
#define COL_YELLOW COL(33)
#define COL_BLUE COL(34)
#define COL_WHITE COL(37)
#define COL_GRAY "\033[0m"

#define clr system("clear");

void Warning();

void PrintResult(int giornomin,int giornomax,int valoreazioni, int vector[]);

int Inserisci(char string[]);

int Inserisci_giorno(char string[], int giorno);

void Suggerisciarosco(int* inizio, int* fine, int n, int k);
