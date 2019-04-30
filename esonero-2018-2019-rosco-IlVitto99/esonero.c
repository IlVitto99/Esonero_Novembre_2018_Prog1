  #include "lib.c"

int main(void) {
  int n,k,minday=0,maxday=0 ;

  clr;
  n=Inserisci("il numero di giorni da prevedere");
  k=Inserisci("la quantita\' di azioni da comprare");
  clr;

  Suggerisciarosco(&minday, &maxday, n, k);
}
