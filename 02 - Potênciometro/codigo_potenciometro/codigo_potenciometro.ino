/*
 *
 * Desenvolvedor: Luis Fernando Galonetti
 * Orientador: André Takeshi Endo
 *
 * Criado em Novembro de 2014
 * UTFPR-CP
 *
 * Controle do acendimento do LED por meio do potênciometro
*/

int potPin = 0; //pino de entrada do potênciometro
int ledPin = 6; // pino de saída do led
int val = 0; // variável para armazenar o valor de leitura do potênciometro

void setup() {
  pinMode(ledPin, OUTPUT);  // declara o pino do LED como saída
}

void loop() {
  val = analogRead(potPin);    // lê o valor do sensor
  digitalWrite(ledPin, HIGH);  // liga o LED
  delay(val);
  digitalWrite(ledPin, LOW);   // desliga o LED
  delay(val);
}
