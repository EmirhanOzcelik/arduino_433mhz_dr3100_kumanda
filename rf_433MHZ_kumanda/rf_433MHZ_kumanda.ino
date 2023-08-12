/*
Emirhan Özçelik tarafından hazırlanmıştır.

  dr3100 bağlantıları
    vcc -- 5v
    gnd -- gnd
    DATA -- 12

  joyistik bağlantıları
    joy-x -- A0
    JOY-y --A1
  
  buton bağlantıları
    but_1 -- 2
    but_2 -- 4
    but_3 -- 7
    but_4 -- 8

  giden veri paketinin içeriği
    paket[0] = joy-x
    paket[1] = joy-y
    paket[2] = but_1
    paket[3] = but_2
    paket[4] = but_3
    paket[5] = but_4

herhangi sorunuz olursa emirhanozcelik339@gmail.com adresinden ulaşabilirsiniz.İyi çalışmalar :)
*/


#include <VirtualWire.h>


const int max = 6;
byte paket[max];
unsigned long gecen_zaman = 0;
const unsigned long aralik = 50;
byte sayac = 0;

void setup()
{
    Serial.begin(9600);
    Serial.println("setup");
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec
    pinMode(2,INPUT_PULLUP);
      pinMode(4,INPUT_PULLUP);
        pinMode(7,INPUT_PULLUP);
          pinMode(8,INPUT_PULLUP);
}

void loop()
{
    kontrol1();
    if(millis() - aralik >= gecen_zaman)
    {
      gecen_zaman = millis();
      vw_send((uint8_t *)paket, max);
      vw_wait_tx(); 
      memset(paket,0,sizeof(paket)); // bu satırı silerseniz siz makineye başka veri yollamadıkça son gönderdiğiniz değeri alır
    }
}
void kontrol1()
{
  paket[0] = map(analogRead(A0),0,1023,0,255);
  paket[1] = map(analogRead(A1),0,1023,0,255);
  paket[2] = digitalRead(2);
  paket[3] = digitalRead(4);
  paket[4] = digitalRead(7);
  paket[5] = digitalRead(8);
}