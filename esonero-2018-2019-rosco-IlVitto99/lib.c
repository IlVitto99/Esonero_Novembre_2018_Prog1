#include "lib.h"

void Warning(){ //Viene chiamata in caso di criticità nell'inserimento di valori;
  clr;
  printf("%sil valore inserito non e\' corretto", COL_RED);
  printf("\nsi prega di inserire un valore %sPOSITIVO!%s\n", COL_YELLOW, COL_GRAY);
  sleep(2);
  clr;
}

void PrintResult(int giornomin,int giornomax,int numeroazioni, int vector[]){ //Stampa i risultati svolgendo i calcoli
  clr;
  if(giornomax==0){
    printf("%snon e\' conveniente comprare nulla, visto l'andamento.\n", COL_GREEN);
    sleep(2);
  }
  else{
    printf("%se\' bene comprare il giorno %d\n", COL_GREEN, giornomin+1);
    sleep(1);
    printf("per poi vendere il giorno %d\n", giornomax);
    sleep(1);
    printf("%shai comprato il giorno %d %d azioni per un totale di %s%d%s\n",COL_YELLOW, giornomin+1, numeroazioni, COL_BLUE, numeroazioni*vector[giornomin], COL_YELLOW);
    sleep(1);
    printf("le hai vendute il giorno %d per un totale di %s%d%s\n", giornomax, COL_BLUE, numeroazioni*vector[giornomax], COL_YELLOW);
    sleep(1);
    printf("%sil guadagno complessivo e\' di %s%d%s\n", COL_WHITE, COL_BLUE, numeroazioni*vector[giornomax]-numeroazioni*vector[giornomin], COL_GRAY);
    sleep(2);
  }
}

int Inserisci(char string[]){ //Inserimento valori primo tipo
  int c=0, x;
  do{
    if(c==1) Warning();
    printf("%sInserisci %s -->%s ", COL_WHITE, string, COL_BLUE);
    c=0;
    scanf("%d", &x);
    c++;
  }while(x<=0);
  return x;
}

int Inserisci_giorno(char string[], int giorno){ //Inserimento valori secondo tipo
  int c=0, x;
  do{
    if(c==1) Warning();
    printf("%sInserisci %s %d -->%s ", COL_WHITE, string, giorno, COL_BLUE);
    c=0;
    scanf("%d", &x);
    c++;
  }while(x<=0);
  return x;
}

void Suggerisciarosco(int* inizio, int* fine, int n, int k){ //Funzione principale, stabilisce il giorno per comprare e per vendere
  int *valori,*diff, sum=0, max=0, zero=0;

  valori= (int *) calloc(n, sizeof(int));
  diff= (int*) calloc((n-1), sizeof(int));

  for(int i=0; i<n; i++){
      valori[i]=Inserisci_giorno("il valore delle azioni al giorno", i);
      if(i>0){
        diff[i-1]= valori[i]-valori[i-1];
        sum+=diff[i-1];
        if(sum > max){
          max=sum;
          *fine=i;
          *inizio=zero;
        }
        if(diff[i-2]+diff[i-1] < 0){
          diff[i-1] = 0;
          zero=i;
          sum=0;
        }
      }
    }
    PrintResult(*inizio, *fine, k, valori);
}
