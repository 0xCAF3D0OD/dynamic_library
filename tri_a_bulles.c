#include "tri_a_bulles.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void test_case_tableau ( long * addr_tableau, int taille_tableau, int case_tableau, int prem_case_tableau ) {
  if ( case_tableau > prem_case_tableau )
    if (addr_tableau[case_tableau] < addr_tableau[case_tableau-1]) {
      permut_cases ( addr_tableau, case_tableau, case_tableau-1 );
      test_case_tableau ( addr_tableau, taille_tableau, case_tableau-1, prem_case_tableau );
    }
}

void permut_cases ( long * addr_tableau, int case_1, int case_2 ) {
  long tempo;

  tempo = addr_tableau[case_1];
  addr_tableau[case_1] = addr_tableau[case_2];
  addr_tableau[case_2] = tempo;
}

long * test_tableau ( long * addr_tableau, int prem_case_tableau, int taille_tableau )
{
  int i;

  for (i=prem_case_tableau; i<taille_tableau; i++)
    test_case_tableau (addr_tableau, taille_tableau, i, prem_case_tableau);

  return addr_tableau;
}

int nb_cases_tableau ( long * addr_tableau ) {
  int nb_cases;

  nb_cases=0;
  while (addr_tableau[nb_cases])
    nb_cases++;
  return (nb_cases);
}

int main (void)
{
  long * tab; int i;

  /* créée un tableau de 10 longs */
  tab = (long *)malloc( 10 * sizeof (long) );

  /* Initialise le générateur de nombre aléatoires avec ... * L'heure de lancement ... * voir man random ou man rand pour le pourquoi de la chose !!! * voir man time pour le comment !!! */
  srandom((int)time((time_t *)NULL));

  /* remplit le tableau avec une suite de nombres pseudo-aléatoires * et affiche le contenu. */
  for (i=0; i<10; i++)
  {
    tab[i] = random();
    printf("tableau[%d] = %ld\n", i, tab[i]);
  }

  /* Affiche le nombre de cases su tableau retourné par la librairie */
  printf ("\nTaille du tableau: %d\n", nb_cases_tableau (tab));

  /* Permute 2 cases et affiche le tableau résultant */
  permut_cases (tab, 2, 8);
  printf ("\nTableau après permutation des cases 2 et 8.\n");
  for (i=0; i<10; i++)
    printf ("tableau[%d] = %ld\n", i, tab[i]);

  /* Trie le tableau et affiche le résultat */
  printf ("\nTableau trié par la fonction de la librairie\n");
  test_tableau ( tab, 0, nb_cases_tableau (tab) );
  for (i=0; i<10; i++)
    printf ("tableau[%d] = %ld\n", i, tab[i]);

  return 0;
}
