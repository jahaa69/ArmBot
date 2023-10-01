#include <Servo.h>

Servo servoMouv;  // Créez un objet Servo
Servo servoBase;
Servo servopince; 

int directionpoty = A5; // Connectez le potentiomètre à l'entrée analogique A5
int directionpotx = A2;

int pincepotx=A3;

int potValueMouv; // Variable pour stocker la valeur du potentiomètre
int potValuePince;
int potValueBase;

void setup() {
  servoBase.attach(6);
  servopince.attach(9);  // Attachez le servo au pin 9
  servoMouv.attach(8);
}

void loop() {
  potValueBase = analogRead(directionpotx);
  potValueMouv = analogRead(directionpoty);

  potValuePince = analogRead(pincepotx); // Lire la valeur du potentiomètre (0-1023)
  
  int hautBas = map(potValueMouv, 0, 1023, 0, 180); // Mappez la valeur à une plage d'angles (0-180 degrés)
  int base = map(potValueBase, 0, 1023, 0, 180);
  int pince = map(potValuePince, 0, 1023, 0, 180);

  servopince.write(pince); // Déplacez le servo à l'angle calculé
  servoBase.write(base);
  servoMouv.write(hautBas);
  delay(15);
}
