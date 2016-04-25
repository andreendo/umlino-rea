/* Projeto sugerido e elaborado pelos alunos em sala de aula
 * Desenvolvedores: Kauane Benitis
                    Victor Camargo
                    Flávio Rodrigues
                    Murilo Horácio Pereira da Cruz
 * Orientador: André Takeshi Endo
 * Criado em Junho de 2015
 * UTFPR-CP
 * Sistema simula efeito de chamas com LEDs
*/
//Define as portas dos LEDs
int ledPin1 = 9;
int ledPin2 = 10;
int ledPin3 = 11;
void setup() {
  //Define as portas como saída
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}
void loop() {
  //Seta o PWM das portas dos LEDs randomicamente, dando efeito de chamas
  analogWrite(ledPin1, random(120)+50);
  analogWrite(ledPin2, random(120)+50);
  analogWrite(ledPin3, random(120)+50);
  delay(random(100));
}
