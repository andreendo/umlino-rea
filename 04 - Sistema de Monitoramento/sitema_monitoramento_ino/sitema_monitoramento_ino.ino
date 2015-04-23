/*
 Desenvolvedores: Luis Fernando Galonetti
                  Murylo Peliçaro Lopes
 Orientador: André Takeshi Endo
 Criado em Dezembro de 2014
 UTFPR-CP
 Sistema de Monitoramento com sensor de temperatura e luminosidade + display LCD 16x2
*/

#include <LiquidCrystal.h> //inclusão da biblioteca do LCD
LiquidCrystal lcd(12,11,7,6,5,4);//pinos que estão ligados o LCD no arduino

const int sensorTemperatura = 1;//pino analógico em que está o sensor de temperatura
const int sensorLuminosidade = 0;//pino analógico em que está o sensor de luminosidade
static unsigned long last_interrupt_time01 = 0; //variável utilizada na interrupção
int valorTemp=0; //variável  usada para ler o valor da temperatura
int valorLum=0; //variável  usada para ler o valor da luminosidade
int pinoBotao = 0; //pino em que  botão está ligado no Arduino
boolean aux=true;

void setup()
{
    pinMode(pinoBotao, INPUT); 
    lcd.begin(16,2); //inicialização do LCD, os parametros 16x2 é o tamanho do visor (16 colunas x 2 linhas)
    Serial.begin(9600);
    attachInterrupt(pinoBotao, func, RISING);//define a interrupção na borda de subida do botão
}


void func()
{
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time01 > 400)
  {
      if(aux == true)
      {   
          valorTemp = analogRead(sensorTemperatura);
          lcd.clear(); //limpa LCD
          lcd.setCursor(1,0); //comando para colocar o cursor na posição desejada.
          lcd.println("Monitoramento:"); //comando que printa a mensagem na tela do LCD
          lcd.setCursor(3,1);
          lcd.print("Temp: ");
          lcd.print(valorTemp/20);
          lcd.write(B11011111); //Simbolo de graus celsius
          lcd.print("C");
          aux = false;
      }
      else
      {
          valorLum = analogRead(sensorLuminosidade);
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.println("Monitoramento:");
          lcd.setCursor(3,1);
          lcd.print("Luz: ");
          lcd.print(valorLum);
          aux = true;
      }
  }
  last_interrupt_time01 = interrupt_time;
}

void loop()
{
    lcd.setCursor(1,0);
    lcd.println("Monitoramento:");
    delay(1000);
    lcd.setCursor(0,1);
    lcd.print("Aperte o botao!");
    delay(3000);
}

