/*该函数功能为清楚指定地址所在的缓冲内存块的内容，指令stosl功能是将eax寄存器的值写入es:edi中。在该函数里，即将addr指向的内容清零。*/
  #define clear_block(addr)\
    __asm__ __volatile__("cld\n\t"\
                         "rep\n\t"\
                         "stosl\n\t"\
                         ::"a"(0),"c"(BLOCK_SIZE/4),"D"((long)(addr))\
                         :"cx","di")
  
/*该函数对addr的第nr位进行置位（1），并且将nr位原来的值存在res中，返回res*/
//btsl指令全称 bit test and set，作用是取addr的第nr位于cf中，并将第nr位置1。
//setb根据cf设置al寄存器内容，若cf为0则al内容为0，若cf为1则al内容为1。
  #define set_bit(nr,addr)({\
  register int res;\
   __asm__ __volatile__("btsl %2,%3\n\t"\
                        "setb %al\n\t"\
                        :"=a"(res)
                        :"0"(0),"r"(nr),"m"((*)(addr)));
                        res;})
  /*复位addr的第nr位，返回该位的反码*/
  #define clear_bit(n,addr)({\
  register int res;\
  __asm__ __volatile__("btrl %2,%3\n\t"\
                       "setb %%al\n\t"\
                       :"=a"(res)
                       :"0"(0),"r"(nr),"m"((*)(addr))
  )
  res;})                    
  
  
