#include <SoftwareSerial.h>

#define pinRx 16  // Escolha um pino RX disponível
#define pinTx 17  // Escolha um pino TX disponível

HardwareSerial lora(2);  // Usa a UART2 do ESP32

unsigned long previousMillis = 0;
int combustivel;
float velocidade;
float temperatura_motor;
float temperatura_cvt;
float odometro;
int farol;
float bateria;

void setup() {
  Serial.begin(9600);  // Serial do USB
  lora.begin(9600, SERIAL_8N1, pinRx, pinTx);  // Inicia UART2 nos pinos escolhidos
}

void loop() {
  combustivel = random(0, 3);
  velocidade = random(0, 40) / 1.0;
  temperatura_motor = random(30, 80) / 1.0;
  temperatura_cvt = random(30, 80) / 1.0;
  odometro = random(0, 1000) / 1.0;
  farol = random(0, 2);  // Deve ser 0 ou 1, então use (0,2) no random()
  bateria = random(0, 5) / 1.0;

  String data = "CAPI, " + String(combustivel) + ", " + String(velocidade) + ", " +
                String(temperatura_motor) + ", " + String(temperatura_cvt) + ", " +
                String(odometro) + ", " + String(farol) + ", " + String(bateria);

  if (millis() - previousMillis >= 1100) {
    previousMillis = millis();
    lora.print(data);
  }
