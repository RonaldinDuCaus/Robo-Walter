#include <Servo.h>

// JOYSTICK 1
int x1Pin = A0;  // Horizontal J1 (esq/dir → Servo 8)
int y1Pin = A1;  // Vertical J1 (cima/baixo → Servo 9)
int sw1Pin = 2;

// JOYSTICK 2
int x2Pin = A2;  // Horizontal J2 (esq/dir → Servo 10)
int y2Pin = A3;  // Vertical J2 (cima/baixo → Servo 11)
int sw2Pin = 3;

// SERVOS
Servo servo8;  // J1 Horizontal (esq=180°, dir=0°)
Servo servo9;  // J1 Vertical (cima=180°, baixo=0°)
Servo servo10; // J2 Horizontal
Servo servo11; // J2 Vertical

// Posições neutras (90°)
int pos8 = 90, pos9 = 90, pos10 = 90, pos11 = 90;

void setup() {
  Serial.begin(9600);

  // Configurar botões
  pinMode(sw1Pin, INPUT_PULLUP);
  pinMode(sw2Pin, INPUT_PULLUP);

  // Anexar servos
  servo8.attach(8);
  servo9.attach(9);
  servo10.attach(10);
  servo11.attach(11);

  // Posição inicial (neutro)
  servo8.write(90);
  servo9.write(90);
  servo10.write(90);
  servo11.write(90);

  Serial.println("=== CONTROLE DE SERVOS COM 2 JOYSTICKS ===");
  Serial.println("J1: Servo8(Horz), Servo9(Vert)");
  Serial.println("J2: Servo10(Horz), Servo11(Vert)");
  delay(1000);
}

void loop() {
  // Ler JOYSTICKS (0-1023)
  int x1 = analogRead(x1Pin);
  int y1 = analogRead(y1Pin);
  int x2 = analogRead(x2Pin);
  int y2 = analogRead(y2Pin);

  //  JOYSTICK 1 - SERVO 8 (Horizontal: Esq=180°, Dir=0°) 
  if (x1 < 300) {        // Esquerda
    pos8 = 180;
  } else if (x1 > 700) { // Direita
    pos8 = 0;
  } else {               // Centro
    pos8 = 90;
  }
  servo8.write(pos8);

  //  JOYSTICK 1 - SERVO 9 (Vertical: Cima=180°, Baixo=0°) 
  if (y1 < 300) {        // Baixo
    pos9 = 0;
  } else if (y1 > 700) { // Cima
    pos9 = 180;
  } else {               // Centro
    pos9 = 90;
  }
  servo9.write(pos9);
//  JOYSTICK 2 - SERVO 10 (Horizontal: Esq=180°, Dir=0°) 
  if (x2 < 300) {
    pos10 = 180;
  } else if (x2 > 700) {
    pos10 = 0;
  } else {
    pos10 = 90;
  }
  servo10.write(pos10);

  //  JOYSTICK 2 - SERVO 11 (Vertical: Cima=180°, Baixo=0°) 
  if (y2 < 300) {
    pos11 = 0;
  } else if (y2 > 700) {
    pos11 = 180;
  } else {
    pos11 = 90;
  }
  servo11.write(pos11);

  // Debug no Serial
  Serial.print("J1[X:");
  Serial.print(x1); Serial.print(",Y:"); Serial.print(y1);
  Serial.print("] S8:"); Serial.print(pos8);
  Serial.print(" S9:"); Serial.print(pos9);

  Serial.print(" | J2[X:");
  Serial.print(x2); Serial.print(",Y:"); Serial.print(y2);
  Serial.print("] S10:"); Serial.print(pos10);
  Serial.print(" S11:"); Serial.println(pos11);

  delay(50); // Suavidade
}