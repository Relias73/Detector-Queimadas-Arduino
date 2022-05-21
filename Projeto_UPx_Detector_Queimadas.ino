//Programa: Sensor de Chama - UPX Grupo 81 - ADS - 1º SEM

//Incluindo Bibliotecas
#include <LiquidCrystal.h> //Biblioteca para trabalhar com o display LCD

//Declarando Pinos
LiquidCrystal lcd(22,24,26,48,46,44,42,40,38,36,34); //Pinos LCD

int pino_D0_s1 = 6; //Pino digital (D0) do sensor de chama 1 (s1)
int pino_D0_s2 = 7; //Pino digital (D0) do sensor de chama 2 (s2)

// Declarando Variaveis
int valor_d_s1, valor_d_s2; //Valor digital de s1 e s2

//Configuração Inicial
void setup() {
  lcd.begin(16, 2); //Iniciando o LCD(16x2)
  pinMode(5, OUTPUT); //Definindo o pino 5 como saída
  analogWrite(5,0); //Definindo o valor do pino 5 como 0 (maior contraste do LCD)

  pinMode(pino_D0_s1, INPUT); //Definindo o pino do sensor 1 como entrada
  pinMode(pino_D0_s2, INPUT); //Definindo o pino do sensor 2 como entrada

  Serial.begin(9600); //Iniciando a serial
}

//Loop de Execução
void loop() {
  valor_d_s1 = digitalRead(pino_D0_s1); //Lê o valor digital do sensor 1
  valor_d_s2 = digitalRead(pino_D0_s2); //Lê o valor digital do sensor 2

  lcd.clear(); //Limpa o LCD
  lcd.setCursor(0,0); //Aponta o cursor do LCD para primeira coluna e linha

  //Verifica o valor digital do sensor 1. Caso seja diferente de 1, fogo detectado
  if (valor_d_s1 != 1) {
    Serial.println("S1: Fogo detectado!"); //Envia mensagem pela serial
    lcd.print("S1: Fogo detectado!"); //Exibe mensagem no LCD
  }
  else {
    Serial.println("S1: Monitorando...");
    lcd.print("S1: Monitorando...");
  }

  lcd.setCursor(0,1); //Aponta o cursor do LCD para primeira coluna da segunda linha

  //Verifica o valor digital do sensor 2. Caso seja diferente de 1, fogo detectado
  if (valor_d_s2 != 1) {
    Serial.println("S2: Fogo detectado!");
    lcd.print("S2: Fogo detectado!");
  }
  else {
    Serial.println("S2: Monitorando...");
    lcd.print("S2: Monitorando...");
  }
  delay(500);
}  
