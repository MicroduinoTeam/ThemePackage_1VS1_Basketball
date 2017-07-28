//Musical Notes---LOW    1,   2,   3,   4,   5,   6,   7
//                                                MIDDLE    1,   2,   3,   4,   5,   6,   7
//                                                                                      HIGH     1,    2,    3,    4,    5,    6,    7
//Note number in songs:  0    1    2    3    4    5    6    7    8    9    10   11   12   13    14    15    16    17    18    19    20
uint16_t toneList[] = { 262, 294, 330, 349, 392, 440, 494, 523, 587, 659, 698, 784, 880, 988, 1046, 1175, 1318, 1397, 1568, 1760, 1967 };

/*一闪一闪亮晶晶*/
uint8_t music[14] = {1, 1, 5, 5, 6, 6, 5, 4, 4, 3, 3, 2, 2, 1};
uint8_t rhythm[14] = {2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 4};

/*游戏结束音乐*/
void PlayMusic()
{
  for (uint8_t i = 0; i < 14; i++)
  {
    tone(PIN_BUZZER, toneList[ music[i] + 6]);
    delay(rhythm[i] * 80);
    noTone(PIN_BUZZER);
    delay(40);
  }
}
