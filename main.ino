

#include "global.h"
#include "lcd.h"
#include "accurrent.h"
#include "acvoltage.h"


bool flag = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //ss.begin(9600);
  lcd.begin(16, 2);
  ac_voltage_init();
  ac_current_init();
  INIT();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("AI BASED POWER");
  lcd.setCursor(0, 1);
  lcd.print("CONSUMPTION");
  delay(1000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  ac_voltage();
  ac_current();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("V:");
  lcd.setCursor(2, 0);
  lcd.print(supply_voltage);
  lcd.setCursor(10, 0);
  lcd.print("I:");
  lcd.setCursor(12, 0);
  lcd.print(supply_current);

  Serial.print("VOLTAGE:");
  Serial.println(supply_voltage);
  Serial.print("CURRENT:");
  Serial.println(supply_current);

  float Power = supply_voltage * supply_current;

  Serial.print("POWER:");
  Serial.println(Power, 4);

  Serial.println("P:" + String(Power));
  //  lcd.setCursor(0, 1);
  //  lcd.print("P:");
  //  lcd.setCursor(2, 1);
  //  lcd.print(Power);
  power_per_second = Power / 3600;
  Serial.println("POWER_PER_SEC:" + String(power_per_second, DEC));
  consumed_power += power_per_second;
  Serial.println(consumed_power, 3);
  lcd.setCursor(0, 1);
  lcd.print("CP:");
  lcd.setCursor(3, 1);
  lcd.print(consumed_power, 3);




  if (consumed_power >= 5)
  {
    digitalWrite(realy_1, HIGH);
    digitalWrite(realy_2, LOW);
    digitalWrite(realy_3, LOW);
    digitalWrite(realy_4, HIGH);
  }
  else
  {
    digitalWrite(realy_1, HIGH);
    digitalWrite(realy_2, HIGH);
    digitalWrite(realy_3, HIGH);
    digitalWrite(realy_4, HIGH);
  }

  //  delay(1000);
}
