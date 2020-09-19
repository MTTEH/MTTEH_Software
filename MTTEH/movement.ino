#include "movement.h"

void stop_moving()
{
  analogWrite(MAvD1, 0);
  analogWrite(MArD1, 0);
  analogWrite(MAvD2, 0);
  analogWrite(MArD2, 0);
  analogWrite(MAvG1, 0);
  analogWrite(MArG1, 0);
  analogWrite(MAvD2, 0);
  analogWrite(MArD2, 0);

  delay(20);
}

void move_ahead()
{
  stop_moving();

  analogWrite(MAvD1, FIRST_SPEED);
  analogWrite(MArD1, FIRST_SPEED);
  analogWrite(MAvG1, SECOND_SPEED);
  analogWrite(MArG1, SECOND_SPEED);
}

void move_back()
{
  stop_moving();

  analogWrite(MAvD2, FIRST_SPEED);
  analogWrite(MArD2, FIRST_SPEED);
  analogWrite(MAvD2, SECOND_SPEED);
  analogWrite(MArD2, SECOND_SPEED);
}

void turn_right()
{
  stop_moving();

  analogWrite(MAvD2, FIRST_SPEED);
  analogWrite(MArD2, FIRST_SPEED);
  analogWrite(MAvG1, SECOND_SPEED);
  analogWrite(MArG1, SECOND_SPEED);
}

void turn_left()
{
  stop_moving();

  analogWrite(MAvD1, FIRST_SPEED);
  analogWrite(MArD1, FIRST_SPEED);
  analogWrite(MAvD2, SECOND_SPEED);
  analogWrite(MArD2, SECOND_SPEED);
}