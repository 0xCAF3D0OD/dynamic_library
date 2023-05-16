#ifndef _TRI_A_BULL_H
#define _TRI_A_BULL_H

#include <unistd.h>
#include <stdio.h>

void test_case_tableau ( long * addr_tableau, int taille_tableau, int case_tableau, int prem_case_tableau );
void permut_cases ( long * addr_tableau, int case_1, int case_2 );
long * test_tableau ( long * addr_tableau, int prem_case_tableau, int taille_tableau );
int nb_cases_tableau ( long * addr_tableau );
//void	test_case_tableau(const long& *tableau, const int& taille_tableau, int case_tableau, int prem_case_tableau);
//void	permut_cases(long* addr_tableau, int case_1, int case_2);
//long	test_tableau(const long& *addr_tableau, int prem_case_tableau;, int taille_tableau);
//int		nb_cases_tableau(const long& *addr_tableau);

#endif
