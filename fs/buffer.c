
#define _hashfn(dev,block) (((unsigned)(dev^block))%NR_HASH)
参数dev、block分别指设备号和逻辑块号，这里的NR_HASH=307。^为按位异或操作
在汇编指令中，异或操作符为XOR。，目前不明白该函数的功能。
