#include <Arduino.h>

#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#define FIRST_SPEED 100
#define SECOND_SPEED 100

#define MAvD1 2
#define MAvD2 3
#define MAvG1 4
#define MAvG2 5
#define MArD1 6
#define MArD2 7
#define MArG1 8
#define MArG2 9

void stop_moving();
void move_ahead();
void move_back();
void turn_right();
void turn_left();

#endif // MOVEMENT_H_