%include "io64.inc"

section .text
global main
main:
    ;write your code here
    PRINT_STRING msg
    
    ; 메모를 남길 수 있는 기능 = 주석
    
    ; 10진수(0 1 2 3 4 5 6 7 8 9)
    ; 10 11 12 13 .... 19 20 
    
    ; 2진수(0 1)
    ; 0 1 10
    ; 0b0 0b1 0b10 0b11 0b100
    
    ; 16진수(0 1 2 3 4 5 6 7 8 9 A B C D E F)
    ; 0 1 2 3 4 5 6 7 8 9 A B C D E F 10
    ; 0x00
    
    ; 0b 1001 0101 = 0x95
    
    
    xor rax, rax
    ret
    
section .data
    msg db '강승훈 바보', 0x00