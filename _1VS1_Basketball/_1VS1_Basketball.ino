#include <Microduino_Key.h>
#include "Microduino_Number.h"
#include "userDef.h"
#include "music.h"

SoftwareSerial mySerial(4, 5);  // 数码管接口
Number LED(NUM, &mySerial);  //使用软串口（2，3）
//Number LED(NUM, &Serial); //使用硬串口（2，3）

AnalogKey  keyLineA(PIN_LINEA);
AnalogKey  keyLineB(PIN_LINEB);
DigitalKey keyButton(PIN_KEY);

/*移动动画*/
byte move_data[7] = {0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f};

uint32_t long timer;
uint8_t change;

uint8_t scoreA, scoreB;
boolean playsta;

/*游戏未开始动画*/
void Animation()
{
  if (millis() - timer > 300)
  {
    change++;
    if (change > 2)
      change = 0;
    timer = millis();
  }
  switch (change)
  {
    case 0:
      LED.setSeg(LEFT, SHOWG, LIGHT);
      LED.turnOff(RIGHT);
      break;
    case 1:
      LED.setSeg(LEFT, SHOWO, LIGHT);
      LED.setSeg(RIGHT, SHOWG , LIGHT);
      break;
    case 2:
      LED.turnOff(LEFT);
      LED.setSeg(RIGHT, SHOWO , LIGHT);
      break;
  }
  LED.show();
}

/*游戏准备开始动画*/
void playInit()
{
  for (uint8_t i = 0; i < 7; i++)
  {
    tone(PIN_BUZZER, (i + 1) * 150, 80);
    LED.setSeg(LEFT, move_data[i], LIGHT);
    LED.setSeg(RIGHT, move_data[i], LIGHT);
    LED.show();
    delay(100);
  }
}

void setup() {
  LED.begin();
  LED.direction(NEGATIVE);

  keyLineA.begin(INPUT);
  keyLineB.begin(INPUT);
  keyButton.begin(INPUT);
}

void loop() {
  /*游戏未开始检测按钮按下开始游戏*/
  if (keyButton.readEvent() == SHORT_PRESS && !playsta)
  {
    scoreA = 0;
    scoreB = 0;
    playsta = true;
    playInit();   //准备开始动画
  }

  if (playsta)  //游戏开始
  {
    if (keyLineA.readEvent(0, DOCK_MAX) == SHORT_PRESS) //右边得分
    {
      scoreA++;
      tone(PIN_BUZZER, 600, 100);
    }
    else if (keyLineB.readEvent(0, DOCK_MAX) == SHORT_PRESS) //左边得分
    {
      scoreB++;
      tone(PIN_BUZZER, 600, 100);
    }

    /*显示左右分数*/
    LED.setNumber(RIGHT, scoreA, LIGHT);
    LED.setNumber(LEFT, scoreB, LIGHT);
    LED.show();

    /*到达最高分，结束游戏*/
    if (scoreA == MAXSCORE || scoreB == MAXSCORE)
    {
      PlayMusic();     //播放音乐
      playsta = false;
    }
  }
  else
    Animation();  //未进入游戏动画

  delay(15);
}
