#include <Arduino.h>

#ifndef MOVEMENT_H_
    #define MOVEMENT_H_

    #define NO_SPEED     0
    #define LOW_SPEED    10
    #define MEDIUM_SPEED 50
    #define HIGH_SPEED   100

    #define MOVE_STOP_SAFE_DELAY_MS 20    // Delay >= 20ms recommended

    #define RIGHT_FRONT_MOTOR_CR  2
    #define RIGHT_FRONT_MOTOR_ACR 3
    #define LEFT_FRONT_MOTOR_CR   4
    #define LEFT_FRONT_MOTOR_ACR  5
    #define RIGHT_BACK_MOTOR_CR   6
    #define RIGHT_BACK_MOTOR_ACR  7
    #define LEFT_BACK_MOTOR_CR    8
    #define LEFT_BACK_MOTOR_ACR   9

class Move
{
  public:
    void stop();
    void forward();
    void backward();
    void right();
    void left();
    void short_test();
};

#endif    // MOVEMENT_H_