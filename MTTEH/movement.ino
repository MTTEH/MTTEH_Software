#include "movement.hpp"

void Move::stop()
{
    analogWrite(RIGHT_FRONT_MOTOR_CR, NO_SPEED);
    analogWrite(RIGHT_BACK_MOTOR_CR, NO_SPEED);
    analogWrite(RIGHT_FRONT_MOTOR_ACR, NO_SPEED);
    analogWrite(RIGHT_BACK_MOTOR_ACR, NO_SPEED);
    analogWrite(LEFT_FRONT_MOTOR_CR, NO_SPEED);
    analogWrite(LEFT_BACK_MOTOR_CR, NO_SPEED);
    analogWrite(RIGHT_FRONT_MOTOR_ACR, NO_SPEED);
    analogWrite(RIGHT_BACK_MOTOR_ACR, NO_SPEED);

    delay(MOVE_STOP_SAFE_DELAY_MS);
}

void Move::forward()
{
    stop();

    analogWrite(RIGHT_FRONT_MOTOR_CR, HIGH_SPEED);
    analogWrite(RIGHT_BACK_MOTOR_CR, HIGH_SPEED);
    analogWrite(LEFT_FRONT_MOTOR_CR, HIGH_SPEED);
    analogWrite(LEFT_BACK_MOTOR_CR, HIGH_SPEED);
}

void Move::backward()
{
    stop();

    analogWrite(RIGHT_FRONT_MOTOR_ACR, HIGH_SPEED);
    analogWrite(RIGHT_BACK_MOTOR_ACR, HIGH_SPEED);
    analogWrite(RIGHT_FRONT_MOTOR_ACR, HIGH_SPEED);
    analogWrite(RIGHT_BACK_MOTOR_ACR, HIGH_SPEED);
}

void Move::right()
{
    stop();

    analogWrite(RIGHT_FRONT_MOTOR_ACR, HIGH_SPEED);
    analogWrite(RIGHT_BACK_MOTOR_ACR, HIGH_SPEED);
    analogWrite(LEFT_FRONT_MOTOR_CR, HIGH_SPEED);
    analogWrite(LEFT_BACK_MOTOR_CR, HIGH_SPEED);
}

void Move::left()
{
    stop();

    analogWrite(RIGHT_FRONT_MOTOR_CR, HIGH_SPEED);
    analogWrite(RIGHT_BACK_MOTOR_CR, HIGH_SPEED);
    analogWrite(RIGHT_FRONT_MOTOR_ACR, HIGH_SPEED);
    analogWrite(RIGHT_BACK_MOTOR_ACR, HIGH_SPEED);
}

void Move::short_test()
{
    forward();
    delay(500);
    backward();
    delay(500);
    right();
    delay(500);
    left();
    delay(500);
    stop();
}
