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
  delay(10);
}

void direita() {
  digitalWrite(esqf, HIGH);
  digitalWrite(esqt, LOW);

  digitalWrite(dirf, LOW);
  digitalWrite(dirt, HIGH);
  delay(10);
}

void esquerda() {
  digitalWrite(esqf, LOW);
  digitalWrite(esqt, HIGH);

  digitalWrite(dirf, HIGH);
  digitalWrite(dirt, LOW);
  delay(10);
}

void parar() {
  digitalWrite(esqf, LOW);
  digitalWrite(esqt, LOW);

  digitalWrite(dirf, LOW);
  digitalWrite(dirt, LOW);
  delay(10);  
}

void tras() {
  digitalWrite(esqf, LOW);
  digitalWrite(esqt, HIGH);

  digitalWrite(dirf, LOW);
  digitalWrite(dirt, HIGH);
  delay(10);
}

void loop() {

  // frente
  if(digitalRead(ESQ) == 0 &&
     digitalRead(CENTRO) == 1 &&
     digitalRead(DIR) == 0) {
      Serial.println("FRENTE");

    frente();
  }

  // esquerda
  else if(digitalRead(ESQ) == 0 &&
          digitalRead(CENTRO) == 1 &&
          digitalRead(DIR) == 1) {
            Serial.println("ESQUERDA");

    esquerda();
  }

   // esquerda
  else if(digitalRead(ESQ) == 0 &&
          digitalRead(CENTRO) == 0 &&
          digitalRead(DIR) == 1) {
            Serial.println("ESQUERDA");

    esquerda();
  }

  // direita
  else if(digitalRead(ESQ) == 1 &&
          digitalRead(CENTRO) == 1 &&
          digitalRead(DIR) == 0) {
            Serial.println("DIREITA");

    direita();
  }
  // direita
  else if(digitalRead(ESQ) == 1 &&
          digitalRead(CENTRO) == 0 &&
          digitalRead(DIR) == 0) {
            Serial.println("DIREITA");

    direita();
  }

  else if(digitalRead(ESQ) == 1 &&
          digitalRead(CENTRO) == 1 &&
          digitalRead(DIR) == 1) {
            Serial.println("PARAR");

    parar();
  } else{
    Serial.println("PARAR");
     parar();
  }


Serial.print(digitalRead(ESQ));
Serial.print(" ");
Serial.print(digitalRead(CENTRO));
Serial.print(" ");
Serial.println(digitalRead(DIR));
Serial.println("**************");
}
