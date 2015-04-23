/*
 * Desenvolvedor:  Luis Fernando Galonetti
                   Murylo Peliçaro Lopes
 * Orientador: André Takeshi Endo
 * Criado em Novembro de 2014
 * UTFPR-CP
 * Código para controle do Robô
*/

#include <Servo.h> //inclusão da biblioteca do servo motor
#include <Ultrasonic.h>//inclusão da biblioteca do sensor ultrassônico
 
#define ENA 6 //enable A no pino 5 (tem de ser um pino PWM)
#define ENB 3 //enable B no pino 3 (tem de ser um pino PWM)
#define IN1 7 //IN1 no pino 2 controla 1 lado da ponte A
#define IN2 5 //IN2 no pino 4 controla o outro lado da ponte A
#define IN3 4 //IN3 no pino 6 controla 1 lado da ponte B
#define IN4 2 //IN4 no pino 7 controla o outro lado da ponte B
#define buzzerPin 10 //Pino 1 defino como o buzzer
#define echoPin 13 //Pino 13 recebe o pulso do echo
#define trigPin 12 //Pino 12 envia o pulso para gerar o echo
//#define minDistancia = 10;

int sensor1, sensor2, sensor3; //declaração de variáveis
int dif = 0; // essa função se limita a 0 = sem corrente e 1 = com corrente
Ultrasonic ultrasonic(12,13); // declara as portas onde se encontram
Servo myservo; //iniciação do servo
int pos = 0;
int cont = 0; //contagem inicial partindo do zero

//*INÍCIO DO CÓDIGO*

void setup()//inicialização (só se repete uma vez)
{
      //Definir quais serão as saídas (envia) e quais as entradas (recebe)
      pinMode(ENA, OUTPUT);
      pinMode(ENB, OUTPUT);
      pinMode(IN1, OUTPUT);
      pinMode(IN2, OUTPUT);
      pinMode(IN3, OUTPUT);
      pinMode(IN4, OUTPUT);
      pinMode(9, OUTPUT);
      pinMode(buzzerPin, OUTPUT);// define o o pino 1 como saída (envia)
      pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)
      pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)
      Serial.begin(9600); //inicia a porta serial
      myservo.attach(11); //função que mostra a porta onde se encontra o servo motor
      delay(3000); // tempo de espera para iniciação do laço de repetição
      
}

void movimentarRobo(){
      sensor1 = analogRead(0); //esquerda
      sensor2 = analogRead(1); //centro
      sensor3 = analogRead(2); //direita
  
      if((sensor1+sensor2+sensor3) > 500){ //taxa de leitura dos sensores infravermelhos maiores que 500 (dentro da linha)
          motorA(2, 30); //temos o Motor A no sentido anti-horário com 30% de velocidade
          motorB(1, 30); //temos o Motor B no sentido horário com 30% de velocidade
          delay(200); // delay muito pequeno, imperceptivel
          motorA(3, 0); //temos o Motor A no sentido anti-horário com 0% de velocidade
          motorB(3, 0); //temos o Motor B no sentido horário com 0% de velocidade
          cont++; //acrescentação na contagem
      }
       sensor1 = analogRead(0); //esquerda
       sensor3 = analogRead(2); //direita
       dif = abs(sensor1-sensor3); // tira-se a diferença para verificar se o robo continua na linha
       if(dif > 200){
           if(sensor1 < sensor3){ //condições uasadas para o alinhamento do robo
                motorA(1, 70);
                motorB(1, 70);
                delay(100);
                motorA(3, 0); //
                motorB(3, 0);
              }
              if(sensor3 < sensor1){//
                  motorA(2, 70);
                  motorB(2, 70);
                  delay(100);
                  motorA(3, 0); //
                  motorB(3, 0);
              }
        }
       if((sensor1+sensor2+sensor3) < 500){ //taxa de leitura dos sensores infravermelhos maiores que 500 (fora da linha)
          motorA(3, 0); // motores são parados
          motorB(3, 0);
          delay(200);
       }
}

void ativarAlarme(){
      tone(buzzerPin,1000);
      digitalWrite(9, HIGH);
      delay(1000);
      noTone(buzzerPin);
      digitalWrite(9, LOW);
      delay(1000);
}

void procuraObstaculo(){
      digitalWrite(trigPin, LOW);//seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
      delayMicroseconds(2); // delay de 2 microssegundos
      digitalWrite(trigPin, HIGH);//seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
      delayMicroseconds(10);//delay de 10 microssegundos
      digitalWrite(trigPin, LOW);//seta o pino 12 com pulso baixo novamente
      int distancia = (ultrasonic.Ranging(CM)); //mede-se a distancia calculada pelo Ultrassonico
      if(distancia < 20){
         ativarAlarme();
      }
}

void varreduraSensor(){
      //Na Frente
      procuraObstaculo();
      //Laterais
      for(pos = 90; pos <= 180; pos++){ // uso do servo motor, fazendo o ultrassonico girar
          myservo.write(pos);
          delay(10);
      }
      procuraObstaculo();
      for(pos = 180; pos >= 90; pos--){ //retorno ao centro
          myservo.write(pos);
          delay(10);
      }
      delay(1000);
      for(pos = 90; pos >= 0; pos--){ //varredura da outra lateral
          myservo.write(pos);
          delay(10);
      }
      procuraObstaculo();
      for(pos = 0; pos <= 90; pos++){ //movimenta sensor para a posição inicial
          myservo.write(pos);
          delay(10);
      }
      delay(2000);
      cont=0;

}
 
void loop() { // laço de repetição (repetição, até segunda ordem)
    controleRemoto();
    if(cont < 50){ // quando atingir a contagem, o robo irá fazer a varredura
        movimentarRobo();
    }else{ // inicio da varredura
        varreduraSensor();
    }
     
}   

//*FIM DO CÓDIGO*

//FUNÇÕES DO MOTOR 
//****************** Controlo do Motor A - ESQUERDO*******************
void motorA(int mode, int percent)
{
 
//muda a percentagem de 0 até 100 no PWM
int duty = map(percent, 0, 100, 0, 255);
 
        switch(mode){          
          case 0: //desativa o motor
          digitalWrite(ENA, LOW); //define o enable a LOW para desativar o A
          break;
          case 1: //define o sentido horario
          digitalWrite(IN1, HIGH); //define IN1 a HIGH
          digitalWrite(IN2, LOW); //define IN2 a LOW
          analogWrite(ENA, duty); //usa o PWM para controlar a velocidade do motor através do pin do enable
          break;
          case 2: //define o sentido anti horario
          digitalWrite(IN1, LOW); //define IN1 a LOW
          digitalWrite(IN2, HIGH); //define IN2 a HIGH
          analogWrite(ENA, duty); //usa o PWM para controlar a velocidade do motor através do pin do enable
          break;
          case 3: //Travar o motor
          digitalWrite(IN1, LOW); //define IN1 a LOW
          digitalWrite(IN2, LOW); //define IN2 a LOW
          analogWrite(ENA, duty); //usa o PWM para travar o motor através do pin do enable
          break;
        }
}
 
//****************** Controlo Motor B - DIREITO *******************
void motorB(int mode, int percent){
        //muda a percentagem de 0 até 100 no PWM
        int duty = map(percent, 0, 100, 0, 255);
        switch(mode){
          case 0: //desativa o motor
          digitalWrite(ENB, LOW); //define INB a LOW
          break;
          case 1: //define o sentido horario
          digitalWrite(IN3, HIGH); //define IN3 a HIGH
          digitalWrite(IN4, LOW); //define IN4 a LOW
          analogWrite(ENB, duty); //usa o PWM para controlar a velocidade do motor através do pin do enable
          break;
          case 2: //define o sentido anti horario
          digitalWrite(IN3, LOW); //define IN3 a LOW
          digitalWrite(IN4, HIGH); //define IN4 a HIGH
          analogWrite(ENB, duty); //usa o PWM para controlar a velocidade do motor através do pin do enable
          break;
          case 3: //trava o motor B
          digitalWrite(IN3, LOW); //define IN3 a LOW
          digitalWrite(IN4, LOW); //define IN4 a LOW
          analogWrite(ENB, duty); //usa o PWM para travar o motor através do pin do enable
          break;
        }
}

