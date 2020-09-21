#ifndef MTTEH_PROJECT_H_
#define MTTEH_PROJECT_H_

#include <MTTEH.hpp>

#define NO_SPEED     0
#define LOW_SPEED    10
#define MEDIUM_SPEED 50
#define HIGH_SPEED   100

#define RIGHT_FRONT_MOTOR_CR  2
#define RIGHT_FRONT_MOTOR_ACR 3
#define LEFT_FRONT_MOTOR_CR   4
#define LEFT_FRONT_MOTOR_ACR  5
#define RIGHT_BACK_MOTOR_CR   6
#define RIGHT_BACK_MOTOR_ACR  7
#define LEFT_BACK_MOTOR_CR    8
#define LEFT_BACK_MOTOR_ACR   9

#define TRIGGER_PIN   10
#define ECHO_PIN      11
#define SENSOR_PIN    12
#define INDICATOR_PIN 13

#define MIN_DISTANCE 20

void trigger();

#endif    // MTTEH_PROJECT_H_