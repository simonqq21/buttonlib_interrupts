#include <Arduino.h>
#include "buttonlib2.h"

const int btn1pin = 2;
const int btn2pin = 3;
InterruptButton btn1(btn1pin);
InterruptButton btn2(btn2pin);

void btn1_change_func() {
  btn1.changeInterruptFunc();
}

void btn2_change_func() {
  btn2.changeInterruptFunc();
}

void btn1_1shortclick() {
  Serial.println("btn1 clicked 1 time");
}

void btn1_2shortclick() {
  Serial.println("btn1 clicked 2 times");
}

void btn1_3shortclick() {
  Serial.println("btn1 clicked 3 times");
}

void btn1_1longclick() {
  Serial.println("btn1 long pressed 1 time");
}

void btn1_2longclick() {
  Serial.println("btn1 long pressed 2 times");
}

void btn1_3longclick() {
  Serial.println("btn1 long pressed 3 times");
}


void btn2_1shortclick() {
  Serial.println("btn2 clicked 1 time");
}

void btn2_2shortclick() {
  Serial.println("btn2 clicked 2 times");
}

void btn2_3shortclick() {
  Serial.println("btn2 clicked 3 times");
}

void btn2_1longclick() {
  Serial.println("btn2 long pressed 1 time");
}

void btn2_2longclick() {
  Serial.println("btn2 long pressed 2 times");
}

void btn2_3longclick() {
  Serial.println("btn2 long pressed 3 times");
}

void setup() {
  Serial.begin(115200);
  btn1.begin(btn1_change_func);
  btn2.begin(btn2_change_func);
  pinMode(LED_BUILTIN, OUTPUT);

  btn1.set1ShortPressFunc(btn1_1shortclick);
  btn1.set2ShortPressFunc(btn1_2shortclick);
  btn1.set3ShortPressFunc(btn1_3shortclick);
  btn1.set1LongPressFunc(btn1_1longclick);
  btn1.set2LongPressFunc(btn1_2longclick);
  btn1.set3LongPressFunc(btn1_3longclick);

  btn2.set1ShortPressFunc(btn2_1shortclick);
  btn2.set2ShortPressFunc(btn2_2shortclick);
  btn2.set3ShortPressFunc(btn2_3shortclick);
  btn2.set1LongPressFunc(btn2_1longclick);
  btn2.set2LongPressFunc(btn2_2longclick);
  btn2.set3LongPressFunc(btn2_3longclick);
}

void loop() {
  btn1.loop();
  btn2.loop();
}
