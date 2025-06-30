; 确定具体硬件的连接方式
RSEQUP3.7
RWEQUP3.6
EEQUP3.5

; 初始化LCD
MOV P1, #00000001B    ; 清屏并光标复位
ACALL ENABLE          ; 调用写入命令子程序

MOV P1, #00111000B    ; 设置显示模式：8位2行5x7点阵
ACALL ENABLE

MOV P1, #00001111B    ; 显示器开、光标开、光标允许闪烁
ACALL ENABLE

MOV P1, #00000110B    ; 文字不动，光标自动右移
ACALL ENABLE

MOV P1, #0C0H         ; 写入显示起始地址（第二行第一个位置）
ACALL ENABLE

; 写入数据
MOV P1, #01000001B    ; 字母A的代码
SETB RS               ; RS=1
CLR RW                ; RW=0，准备写入数据
CLR E                 ; E=0，执行显示命令
ACALL DELAY           ; 半断液晶模块是否忙？
SETB E                ; E=1
AJMP $                ; 显示完成程序停车

;-------------------------------
; 子程序部分
;-------------------------------

ENABLE:               ; 写入控制命令的子程序
CLR RS
CLR RW
CLR E
ACALL DELAY
SETB E
RET

DELAY:                ; 判断液晶显示器是否忙的子程序
MOV P1, #0FFH
CLR RS
SETB RW
CLR E
NOP
SETB E
JB P1.7, DELAY        ; 如果P1.7为高电平表示忙就循环等待
RET

END

