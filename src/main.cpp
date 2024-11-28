#include <Arduino.h>

const int debounceDelay = 50;
const int multiClickDuration = 500;
const int longClickDuration = 1000;

const int BTN1 = 2;
const int BTN2 = 3;

bool btn1_curState;
bool btn1_changed;
unsigned long btn1LastDebounceTime;
unsigned long lastClickTime;
int btn1NumClicks;

int i1=0;





// void btn1_falling_func() {
//   btn1_pressed = true;
//   // button1releasedtime = millis();
// }

// void btn1_rising_func() {
//   btn1_released = true;
//   // button1pressedtime = millis();
//   digitalWrite(LED_BUILTIN, LOW);
// }

void btn1_change_func() {
  btn1_changed = true;
  btn1LastDebounceTime = millis();
}

// void btn2_falling_func() {
//   btn2_pressed = true;
//   digitalWrite(LED_BUILTIN, HIGH);
// }

// void btn2_rising_func() {
//   btn2_released = true;
// }

void setup() {
  Serial.begin(115200);
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  // attachInterrupt(digitalPinToInterrupt(BTN1), btn1_falling_func, FALLING);
  // attachInterrupt(digitalPinToInterrupt(BTN1), btn1_rising_func, RISING);
  attachInterrupt(digitalPinToInterrupt(BTN1), btn1_change_func, CHANGE);
}

void loop() {
  if (btn1_changed && millis() - btn1LastDebounceTime > debounceDelay) {
    btn1_curState = digitalRead(BTN1);

    /**
     * when pressed, increment the btn click count if within the multiclick delay.
     */
    if (!btn1_curState) {
      Serial.print("btn1 pressed ");
      lastClickTime = millis();
      btn1NumClicks++;
      Serial.println(i1);
      i1++;
    }
    // else Serial.print("btn1 released ");
    btn1_changed = false;
  }

  if (btn1NumClicks) {
    if (millis() - lastClickTime > multiClickDuration) {
      if (digitalRead(BTN1)) {
        Serial.print("button clicked ");
        Serial.print(btn1NumClicks);
        Serial.println(" times.");
        btn1NumClicks = 0; 
      }
    }
    if (millis() - lastClickTime > longClickDuration) {
      if (!digitalRead(BTN1)) {
        Serial.print("button long clicked ");
        Serial.print(btn1NumClicks);
        Serial.println(" times.");
        btn1NumClicks = 0; 
      }
    }
  }

  // Serial.println(millis() - lastClickTime);
  

  // if (btn1NumClicks && )
  // if (btn1_released) {
  //   Serial.println("button released");
  //   // Serial.print("button1releasedtime = ");
  //   // Serial.print(button1releasedtime);
  //   // Serial.print(" button1pressedtime = ");
  //   // Serial.print(button1pressedtime);
  //   // Serial.print(" pressed time = ");
  //   // Serial.println(button1releasedtime - button1pressedtime);
  //   btn1_released = false;
  // }

  // if (btn1_pressed) {
  //   Serial.println("button pressed");
  //   btn1_pressed = false;
  // }

  // if (btn2_pressed) {
  //   Serial.println("f2");
  //   Serial.println(i2);
  //   i2++;
  //   btn2_pressed = false;
  // }
  
  
}
