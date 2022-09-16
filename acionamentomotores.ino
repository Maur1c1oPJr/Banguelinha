/*
      Board pin | NodeMCU GPIO |    Arduino IDE
            A-                      1                         5 or D1
            A+                      3                         0 or D3
            B-                      2                         4 or D2
            B+                      4                         2 or D4
*/
const int pwmMotorA = D1;
const int pwmMotorB = D2;
const int dirMotorA = D3;
const int dirMotorB = D4;
char pwm;
int motorSpeed = 750;
void setup() {
  Serial.begin(115200);
  Serial.println();
  pinMode(pwmMotorA , OUTPUT);
  pinMode(pwmMotorB, OUTPUT);
  pinMode(dirMotorA, OUTPUT);
  pinMode(dirMotorB, OUTPUT);
  Serial.println("Motor SHield 12E Initialized");
  delay(5000);
}
void loop() {

  Serial.println("Activate A");   //  ANDA PARA FRENTE 
  digitalWrite(pwmMotorA, motorSpeed);
  digitalWrite(dirMotorA, LOW);
  Serial.println("Activate B");
  digitalWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, LOW);
  delay(3000);

  Serial.println("Reverse A");  //  ANDA PARA TRÁS
  digitalWrite(dirMotorA, HIGH);
  Serial.println("Reverse B");
  digitalWrite(dirMotorB, HIGH);
  delay(3000);

  Serial.println("Activate A");  //  CURVA PARA A ESQUERDA PARA FRENTE 
  digitalWrite(pwmMotorA, motorSpeed);
  digitalWrite(dirMotorA, LOW);
  delay(3000);

  Serial.println("Reverse A");  //  CURVA PARA A ESQUERDA PARA TRÁS
  digitalWrite(dirMotorA, HIGH);
  delay(3000);

  Serial.println("Activate B");  //  CURVA PARA A DIREITA PARA FRENTE
  digitalWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, LOW);
  delay(3000);

  Serial.println("Reverse B");  //  CURVA PARA A DIREITA PARA TRÁS
  digitalWrite(dirMotorB, HIGH);
  delay(3000);

  //-------------------------------------------------------------------
  
  pwm = Serial.read();
  if (pwm=='A'){  // CURVA PARA A ESQUERDA PARA FRENTE
  Serial.println("Activate A");
  digitalWrite(pwmMotorA, motorSpeed);
  digitalWrite(dirMotorA, LOW);
  delay(1500);
  }
  if (pwm=='B'){  // CURVA PARA A ESQUERDA PARA TRÁS
  Serial.println("Reverse A");
  digitalWrite(dirMotorA, HIGH);
  delay(1500);
  }
  if (pwm=='C'){  
  Serial.println("Stop A");
  digitalWrite(pwmMotorA, 0);
  digitalWrite(dirMotorA, LOW);
  delay(3000);
  }
  if (pwm=='D'){  // CURVA PARA A DIREITA PARA FRENTE
  Serial.println("Activate B");
  digitalWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, LOW);
  delay(1500);
  }
  if (pwm=='E'){  // CURVA PARA A DIREITA PARA TRÁS
  Serial.println("Reverse B");
  digitalWrite(dirMotorB, HIGH);
  delay(1500);
  }
  if (pwm=='F'){
  Serial.println("Stop B");
  digitalWrite(pwmMotorB, 0);
  digitalWrite(dirMotorB, LOW);
  delay(3000);
  }
  if (pwm=='G'){  // ANDA PARA FRENTE
  Serial.println("Activate A");
  digitalWrite(pwmMotorA, motorSpeed);
  digitalWrite(dirMotorA, LOW);
  Serial.println("Activate B");
  digitalWrite(pwmMotorB, motorSpeed);
  digitalWrite(dirMotorB, LOW);
  delay(1500);
  }
  if (pwm=='H'){  // ANDA PARA TRÁS
  Serial.println("Reverse A");
  digitalWrite(dirMotorA, HIGH);
  Serial.println("Reverse B");
  digitalWrite(dirMotorB, HIGH);
  delay(1500);
  }
}
