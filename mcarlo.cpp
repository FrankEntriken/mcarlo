/*
Frank Entriken
2298368
entriken@chapman.edu
CPSC 380
Assignment 3: mcarlo.cpp
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

using namespace std;

// create global variables
void *sim(void *arg);
double random_double();
int num_in_circle;
int num_total;

int main(int argc, char** argv)
{
  // user input parameter for how many points they want to generate
  num_total = stoi(argv[1]);
  double pi;

  // two thread variables
  pthread_t a_thread;
  pthread_t b_thread;

  // create the threads
  pthread_create(&a_thread, NULL, sim, NULL);
  pthread_create(&b_thread, NULL, sim, NULL);

  // join threads
  pthread_join(a_thread, NULL);
  pthread_join(b_thread, NULL);

  // estimate pi
  pi = (4.0 * (num_in_circle)) / (num_total);
  cout << "pi = " << endl;
}

// generate random double
double random_double()
{
  return random() / ((double)RAND_MAX + 1);
}

// monte carlo simulation that checks if points are within circle
void *sim(void *arg)
{
  double x;
  double y;

  // check for points inside circle
  for (int i = 0; i < num_total; i++) {
    // generate random numbers between -1.0 and +1.0 (exclusive) */
    x = random_double() * 2.0 - 1.0;
    y = random_double() * 2.0 - 1.0;

    if (sqrt(x*x + y*y) < 1.0)
      ++num_in_circle;
  }
}
