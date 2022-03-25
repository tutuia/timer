
#include <TimerOne.h>

#define sinal_entrada 3
#define saida 7

#define tempo 40; // tempo em segundos
int contador;

void setup() {
  
  pinMode(saida, OUTPUT);
  digitalWrite(saida, LOW);
  attachInterrupt(digitalPinToInterrupt(sinal_entrada), reinicia_timer, RISING);

  contador = tempo;
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(conta_tempo);
}

void loop() {
 
}

void conta_tempo(){
  
  contador--;  
  
  if(contador < 0){
    contador = tempo;
    digitalWrite(saida, HIGH);  
    delay(10000);
    digitalWrite(saida, LOW);
    reinicia_timer();
  }
  
}

void reinicia_timer(){
  contador = tempo;
  Timer1.start();
  Timer1.attachInterrupt(conta_tempo); 
  digitalWrite(saida, LOW);
}
