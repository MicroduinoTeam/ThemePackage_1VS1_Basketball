#define NUM 2          //设置数码管个数
#define LIGHT 50       //设置数码管亮度（50-255）

#define PIN_LINEA    A0      //灰度传感器A引脚.对应第一个数码管(右边)
#define PIN_LINEB    A2      //灰度传感器B引脚.对应第二个数码管(左边)
#define PIN_KEY      6       //碰撞开关引脚.
#define PIN_BUZZER   10      //蜂鸣器引脚.
#define DOCK_MAX     700     //灰度传感器的最小触发值。增大该值后，意味着你需要颜色更深的物体去触发灰度传感器

#define MAXSCORE 9  //设置赢的分数

#define LEFT  1   
#define RIGHT 0

#define SHOWG  0x5c
#define SHOWO  0x63

