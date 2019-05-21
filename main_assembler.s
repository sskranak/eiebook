;##############################################################################
;# File: main_assembler.s
;##############################################################################

;------------------------------------------------------------------------------
; Description
; This is a demonstration program to show basic code structures in assembly
; A test comment
; Includes
#define  __ASSEMBLY__           1  ; Need this so the correct values in AT91SAM3U4.h are selected
#include "AT91SAM3U4.h"	           ; Include file for all special function registers
						                       ; and corresponding bit names
; A "MODULE" in an assembly file becomes and object file after it is assembled.
 		MODULE  main_assembler
    SECTION .text : CODE : NOROOT(2)
    THUMB

; "PUBLIC" declarations make labels from this file visible to others
		PUBLIC  main
				

main

move_eg   MOV   r0, #0    ;r0 = 0
    MOV   r1, #0    ;r1 = 0
    MOV   r2, r1    ;r2 = r1

    MOVS    r3, #0    ;r3 = 0, update APSR
    
    ADD  r0, r0, #256    ;r0 = r0 + 256
    ADD  r1, r1, r0, LSL #2  ;r1 = r1 +(4*r0)
    MOV  r2, r0, LSR #6  ; r2 = r0/64
    
    SUBS  r3, r1, r0  ; r3 = r1 - r0

    IT  EQ  ;Get ready for a conditional
    MOVEQ   r3, #1024  ;if {Z}, r3 =1024

    RSBS  r3, r1, r0, LSL #4  ; r3 = (16*r0) - r1

    IT  NE  ; Get ready for a conditional
    MULNE  r3, r2, r0  ; if {!Z}, r3 = r2*r0
    
    CMP  r3, r1  ; Set flags if r1 == r3
    
    IT  EQ
    ORREQS  r3, r0, r1, LSR #10  ; r3 = r0 |(r1/1024)


    MOV  r1, #0x20000000  ; r1 is the target address, this is a valid immediate
    MOV  r0, #5000    ; r0 = 5000
    LDR  r0, =5000    ; r0 = 5000
    STR  r0, [r1]  ; *r1 = r0

    LSL  r0, r0, #2  ;Multiply r0 by 4
    ADD  r1, r1, #4  ; r1 += 4 (new RAM address)
    STR  r0, [r1]  ; *r1 = r0

    LDR  r3, [r1]  ;r3 = *r1
    B  main  ; Repeat Infinitely
    
    
	END