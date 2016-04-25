/* Projeto sugerido e elaborado pelos alunos em sala de aula
 * Desenvolvedor: Gianluca Maziero Machado
 *                Pedro Paulo Gonçalves Junior
 *                Marcele Hayane Aldins Bukvar
 *                Gustavo Jose Gomes Meilus
 * Orientador: André Takeshi Endo
 *
 * Criado em Junho de 2015
 * UTFPR-CP
 *
 * Controle da frequência de acendimento de LEDs através do potenciômetro.
*/
#include <LiquidCrystal.h>
#define T 5

//Define os parâmetros do display LCD
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int vetLED[] = {2,3,4,5,6}; 
int pinPotenciometro = 0;
int i, aux;

void setup() {
  //Inicia o display LCD
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Inicializando...");

  //Define os LEDs como porta de saída
  for(i = 0;i < T;i++)
    pinMode(vetLED[i],OUTPUT);

  piscaTeste(vetLED);

  lcd.setCursor(0,0);
  lcd.print("Projeto Final");
  lcd.setCursor(0,1);
  lcd.print("Grupo 3");
  delay(1000);
  
  Serial.begin(9600);
}

void loop() {
    
  for(i = 0;i < T;i++)
  {
    //Faz a leitura do valor do potenciômetro
    aux = analogRead(pinPotenciometro);
    
    if(aux < 1000){
      lcd.setCursor(0,1);
      lcd.print("Velocidade:     ");
    }
      
    lcd.setCursor(0,1);
    lcd.print("Velocidade: ");
    lcd.print((aux-1023)*(-1));

    //Se o potenciômetro está com valor zero, acende todos, senão pisca todos
    if(aux == 0)
      acendeTudo(vetLED);
    else{
      digitalWrite(vetLED[i],HIGH);
      delay(aux);
      digitalWrite(vetLED[i],LOW); 
    }   
  }
}

//Acende todos os LEDs
void acendeTudo(int vetLED[]){
  for(i = 0;i < T;i++)
    digitalWrite(vetLED[i],HIGH);
}

//Apaga todos os LEDs
void desligaTudo(int vetLED[]){
  for(i = 0;i < T;i++)
    digitalWrite(vetLED[i],LOW);
}

//Pisca todos os LEDs 4 vezes com delay de 500
void piscaTeste(int vetLED[]){
    int j;
    for(j = 0;j < 4;j++){
      acendeTudo(vetLED);
      delay(500);
      desligaTudo(vetLED);
      delay(500);
    }
}

