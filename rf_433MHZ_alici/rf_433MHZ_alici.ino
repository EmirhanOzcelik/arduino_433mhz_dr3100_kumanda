/*
Emirhan Özçelik tarafından hazırlanmıştır.

  dr3100 bağlantıları
    vcc -- 5v
    gnd -- gnd
    DATA -- 12

  gelen veri paketi içeriği
    paket[0] = joy-x
    paket[1] = joy-y
    paket[2] = but_1
    paket[3] = but_2
    paket[4] = but_3
    paket[5] = but_4

herhangi sorunuz olursa emirhanozcelik339@gmail.com adresinden ulaşabilirsiniz.İyi çalışmalar :)
*/

#include <VirtualWire.h>

void setup()
{
    Serial.begin(9600);	
    Serial.println("setup");
    vw_set_ptt_inverted(true); 
    vw_setup(2000);	
    vw_rx_start();    
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    

    if (vw_get_message(buf, &buflen)) 
    {
      for(int i = 0; i<buflen;i++)
      {
       Serial.println(buf[i],DEC);
       delay(1);
      }
      Serial.println("__________________");
    }
}
