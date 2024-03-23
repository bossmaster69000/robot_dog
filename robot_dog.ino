#include <ESP32Servo.h>

#define NUM_SERVOS 12

// Constants for servo pins
const int RotationLF_PIN = 12;
const int UpperLF_PIN = 14;
const int LowerLF_PIN = 27;

const int RotationLB_PIN = 15;
const int UpperLB_PIN = 2;
const int LowerLB_PIN = 4;

const int RotationRF_PIN = 33;
const int UpperRF_PIN = 25;
const int LowerRF_PIN = 26;

const int RotationRB_PIN = 18;
const int UpperRB_PIN = 5;
const int LowerRB_PIN = 17;


// Constants for servo pos
 int RotationLF_POS = 90;
 int UpperLF_POS = 90;
 int LowerLF_POS = 90;

 int RotationLB_POS = 90;
 int UpperLB_POS = 90;
 int LowerLB_POS = 90;

 int RotationRF_POS = 90;
 int UpperRF_POS = 90;
 int LowerRF_POS = 90;

 int RotationRB_POS = 90;
 int UpperRB_POS = 90;
 int LowerRB_POS = 90;




Servo servos[NUM_SERVOS];

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(getPin(i));
  }
}

void loop() {
  // Example usage:
  writeFB(1,150,1);
  
}
void writeALL(int angle){
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].write(angle);
  }

}

void writeINDEX(int index, int angle){
  for (int i = 0; i < NUM_SERVOS; i++) {
    if((i%3) == index){
      servos[i].write(angle);
    }
  }
}

void writeFB(int index, int angle, int dir ){
  for (int i = 0; i < NUM_SERVOS; i++) {
    if((i%6) - (3* dir) == index){
      setPos(angle,i);
      servos[i].write(getPos(i));
      delay(2000);
      Serial.println(i);
      Serial.println(getPos(i));
      Serial.println(" ");
    }
  }
}

void writeRL(int index, int angle){
  for (int i = 0; i < NUM_SERVOS; i++) {
    if((i%3) == index){
      servos[i].write(angle);
    }
  }
}
void CLBpos() {
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].write(90);
  }
}

void sit() {
  // Define sit positions for all servos
}

void stand() {
  // Define stand positions for all servos
}

int getPin(int index) {
  switch (index) {
    case 0: return RotationLF_PIN;
    case 1: return UpperLF_PIN;
    case 2: return LowerLF_PIN;
    case 3: return RotationLB_PIN;
    case 4: return UpperLB_PIN;
    case 5: return LowerLB_PIN;
    case 6: return RotationRF_PIN;
    case 7: return UpperRF_PIN;
    case 8: return LowerRF_PIN;
    case 9: return RotationRB_PIN;
    case 10: return UpperRB_PIN;
    case 11: return LowerRB_PIN;
    default: return -1; // Error: Invalid index
  }
}

int getPos(int index) {
  switch (index) {
    case 0: return RotationLF_POS;
    case 1: return UpperLF_POS;
    case 2: return LowerLF_POS;
    case 3: return RotationLB_POS;
    case 4: return UpperLB_POS;
    case 5: return LowerLB_POS;
    case 6: return RotationRF_POS;
    case 7: return UpperRF_POS;
    case 8: return LowerRF_POS;
    case 9: return RotationRB_POS;
    case 10: return UpperRB_POS;
    case 11: return LowerRB_POS;
    default: return -1; // Error: Invalid index
  }

}
  int setPos(int angle, int index) {
  switch (index) {
    case 0:  RotationLF_POS = angle;
    case 1:  UpperLF_POS= angle;
    case 2:  LowerLF_POS= angle;
    case 3:  RotationLB_POS= angle;
    case 4:  UpperLB_POS= angle;
    case 5:  LowerLB_POS= angle;
    case 6:  RotationRF_POS= angle;
    case 7:  UpperRF_POS= angle;
    case 8:  LowerRF_POS= angle;
    case 9:  RotationRB_POS= angle;
    case 10:  UpperRB_POS= angle;
    case 11:  LowerRB_POS= angle;
    default: return -1; // Error: Invalid index
  }
}
