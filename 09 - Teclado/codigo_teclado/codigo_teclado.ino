/* Projeto sugerido e elaborado pelos alunos em sala de aula
 * Desenvolvedor: Lucas Messias
 * Orientador: André Takeshi Endo
 * Criado em Outubro de 2015
 * UTFPR-CP
 * Simula um teclado que emite sons em frequências de acordo com o botão pressionado.
*/


//Define as NOTAS  que serão utilizadas nas teclas 
#define DO 261 
#define RE 294 
#define MI 329 
#define FA 349 
#define SOL 392 
#define LA 440 
#define SI 493 

int notas[7] = {DO,RE,MI,FA,SOL,LA,SI}; 

void setup() {  
  for (int i=2; i<9; i++)
    pinMode(i, INPUT);
} 

void loop() {    
  //for que identifica se cada uma das teclas esta pressionada
  for (int i=2; i<9; i++){     
    while (digitalRead(i)){      
      tone (12, notas [i-2]);//Ativa o buzzer de acordo com o botão pressionado
    }    
    noTone (12);//Desativa o buzzer
  }
}
