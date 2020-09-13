#pragma once

#ifndef UTILITY_H
#define UTILITY_H

//isleap
#define isleap(y)  ((y)%4 == 0 && ((y)%100 != 0 || (y)%400 ==0))

int isprime(int);
int ndigit(int);
void dline(void);
void sleep(double);
int day_of_week(int, int, int);

#endif
