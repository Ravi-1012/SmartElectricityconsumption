#ifndef GLOBAL_H
#define GLOBAL_H

#define AC_VOLTAGE_PIN 1       // 1 represent the analog first pin A0
#define AC_CURRENT_PIN A5

float power_per_second = 0;
float avg_power_per_hour = 0, consumed_power = 0;
int unit = 0;
char inchar = 'X';

#define power_limit_watts 1
#define realy_1 2
#define realy_2 3
#define realy_3 4
#define realy_4 5

void INIT()
{
  pinMode(realy_1,OUTPUT);
  pinMode(realy_2,OUTPUT);
  pinMode(realy_3,OUTPUT);
  pinMode(realy_4,OUTPUT);
  digitalWrite(realy_1,LOW);
  digitalWrite(realy_2,LOW);
  digitalWrite(realy_3,LOW);
  digitalWrite(realy_4,LOW);
}

#endif
