/*
   Q0422
   AUTOR:   BrincandoComIdeias
   LINK:    https://www.youtube.com/brincandocomideias ; https://cursodearduino.net/
   SKETCH:  Irrigação Inteligente
   DATA:    28/01/2019
*/

bool leituraSensor;
bool leituraAnterior;

void setup() {
  
  //Sensor
  pinMode(8, INPUT);

  //Atuador
  pinMode(12, OUTPUT);
  
  //LEDs
  pinMode(5, OUTPUT);  //vermelho
  pinMode(6, OUTPUT);  //amarelo
  pinMode(7, OUTPUT);  //verde
}

void loop() {

  leituraSensor = digitalRead(8);

  if (leituraSensor == HIGH) {
     //No estado seco
     digitalWrite(5, HIGH);  //vermelho
     digitalWrite(7, LOW);   //verde
  } else {
     //No estado úmido
     digitalWrite(5, LOW);   //vermelho
     digitalWrite(7, HIGH);  //verde
  }

  //Ao entrar no estado seco  
  if (leituraSensor && !leituraAnterior) {
     delay(5000);
     digitalWrite(5, LOW);   //vermelho
     digitalWrite(6, HIGH);  //amarelo

     while (digitalRead(8)) {
        digitalWrite(12, HIGH);   //rele / válvula / solenoide / bomba
        delay(500);
        digitalWrite(12, LOW);   //rele / válvula / solenoide / bomba

        delay(10000);          
     }
     digitalWrite(6, LOW);  //amarelo
  }
  
  leituraAnterior = leituraSensor;
}
