# Easier_Arduino
一个整合了常见操作的Arduino库，让忍受不了坑爹的大小写敏感函数的你稍微放松点。
## 安装指南
下载zip，将里面的文件夹放进：文档/Arduino/libraries
## 调用
- 请注意前面用byte的千万不能用int
### pmin - 批量定义输入
- pmin(byte a[],int length)
- a: 输入串口数组
- length: 数组长度【我懒】
### pmout - 批量定义输出
- pmout(byte a[],int length)
- 与pmin相似
### otiwd - 输出输入
- otiwd(byte a=9,byte b=A0,int delaytime=50,double times=1.0)
- a: 输入端口
- b: 输出端口
- delaytime: 防抖延时（如为0则不防抖）
- times: a的输入\*times = b的输出
### servoinit - Setup 2 servos
- servoinit(bool nineenabled=false,bool tenenabled=false,bool mechanicinit=false,int mechanicdelay=1000)
- 这个函数写的比较死，只接受9,10两个口输出
- nineenabled: attach D9 端口为舵机
- tenenabled: attach D10 端口为舵机
- mechanicinit: 开则强行修正舵机位置问题
- mechanicdelay: 强行修正问题的内部延时
- 会产生nine 和 ten 两个 Servo（实际上是强行在最开始定义的）
### servow - 设置舵机角度
- servow(int nineang = 90,int tenang = 90)
- nineang: Port 9 舵机设定位置
- tenang: Port 10 舵机设定位置
- 如果直接调用不加参数则直接归中
### keypress (不确定能否工作，且可能报错。) - 按键
- keypress(byte a[],int count=1,int holdtime=50,bool takeover=true)
- a: 要按的键数组
- count: 按键数目（我懒）
- holdtime: 按住时间
- takeover: 在最初开启控制并最后终结控制
