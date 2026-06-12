//Sensor
const int ESQ = 7;
const int CENTRO = 6;
const int DIR = 5;

// Motor esquerdo
int esqf = 8;
int esqt = 9;

// Motor direito
int dirf = 10;
int dirt = 11;

void setup() {
  pinMode(esqf, OUTPUT);
  pinMode(esqt, OUTPUT);

  pinMode(dirf, OUTPUT);
  pinMode(dirt, OUTPUT); 

  pinMode(ESQ, INPUT);
  pinMode(CENTRO, INPUT);
  pinMode(DIR, INPUT); 

  Serial.begin(9600);
}

void frente() {
  digitalWrite(esqf, HIGH);
  digitalWrite(esqt, LOW);

  digitalWrite(dirf, HIGH);
  digitalWrite(dirt, LOW);
  delay(100);
}

void direita() {
  digitalWrite(esqf, HIGH);
  digitalWrite(esqt, LOW);

  digitalWrite(dirf, LOW);
  digitalWrite(dirt, HIGH);
  delay(100);
}

void esquerda() {
  digitalWrite(esqf, LOW);
  digitalWrite(esqt, HIGH);

  digitalWrite(dirf, HIGH);
  digitalWrite(dirt, LOW);
  delay(100);
}

void parar() {
  digitalWrite(esqf, LOW);
  digitalWrite(esqt, LOW);

  digitalWrite(dirf, LOW);
  digitalWrite(dirt, LOW);
  delay(100);  
}

void tras() {
  digitalWrite(esqf, LOW);
  digitalWrite(esqt, HIGH);

  digitalWrite(dirf, LOW);
  digitalWrite(dirt, HIGH);
  delay(100);
}

void loop() {

  // frente
  if(digitalRead(ESQ) == LOW &&
     digitalRead(CENTRO) == HIGH &&
     digitalRead(DIR) == LOW) {

    frente();
  }

  // esquerda
  else if(digitalRead(ESQ) == LOW &&
          digitalRead(CENTRO) == HIGH &&
          digitalRead(DIR) == HIGH) {

    esquerda();
  }

  // direita
  else if(digitalRead(ESQ) == HIGH &&
          digitalRead(CENTRO) == HIGH &&
          digitalRead(DIR) == LOW) {

    direita();
  }

  else if(digitalRead(ESQ) == HIGH &&
          digitalRead(CENTRO) == HIGH &&
          digitalRead(DIR) == HIGH) {

    parar();
  }


Serial.print(ESQ);
Serial.print(" ");
Serial.print(CENTRO);
Serial.print(" ");
Serial.println(DIR);
}
