; leave a space before directives for sjasmplus (else it assumes they are labels)
 DEVICE NOSLOT64K ; DEVICE zx81
 SLDOPT COMMENT WPMEM, LOGPOINT, ASSERTION ; SLDOPT for DeZog

 ORG $4000
MEMORYSTART:
MEMORY_END equ 0x4400 ; 1k
;--------------------------
; SYSVARS which aren't saved on file
ERR_NR  equ $4000       ; usable memory after asm program start
FLAGS   equ $4001       ;    /
ERR_SP  equ $4002       ;   /
RAMTOP  equ $4004       ;  /
MODE    equ $4006       ; /
PPC     equ $4007       ;/

 ORG $4009 ; .p org (start of saved content on cassette)
;--------------------------
; SYSVARS which are saved on .p file
; the comments indicate if the space is usable in assembler programs

;VERSN    db $00         ; usable
;E_PPC    dw $0000       ; usable
;D_FILE   dw dfile       ; !! not usable
;DF_CC    dw $4097       ; usable if not using rst 10h or similar
;VARS     dw $4097       ; usable if not using basic vars
;DEST     dw $0000       ; usable
;-- the above variables space is used for basic startup 
startup:
    nop : jp _main ; basic dw "line number" (big endian) and dw lenght (little endian)
D_FILE equ $400C ; just keep address
    db $F9,$D4 ; RAND USR
    db $1C,$7E ; floating point number  indicator
    db $8F ; exp fixed for the 1k range
    db 0,$12 ; mantisssa for $4009

E_LINE   dw eline       ; xx usable after asm start
CH_ADD   dw eline       ; xx usable after asm start
X_PTR    dw $0000       ; xx usable after asm start
STKBOT   dw $409A       ; xx usable after asm start
STKEND   dw $409A       ; xx usable after asm start
BERG     db $FF         ; xx usable if not floating point usage
MEM      dw $0000       ; xx usable after asm start
NOTUSED  db $01         ; one byte free
DF_SZ    db $02         ; usable
S_TOP    dw $0000       ; usable
LAST_K   dw $FFFF       ; !! not usable (row/column of last char pressed)
DB_ST    db $FF         ; !! not usable (debounce))
MARGIN   db $37         ; !! not usable (display management))
NXTLIN   dw startup     ; xx usable after asm start
OLDPPC   dw $0000       ; usable
FLAGX    db $00         ; usable
STRLEN   dw $0000       ; usable
T_ADDR   dw $0000       ; xx usable after asm start
SEED     dw $0000       ; usable
FRAMES   dw $FFFF       ; !! not usable
COORDS   dw $0000       ; usable
PR_CC    db $00         ; usable
S_POSN   dw $0021       ; usable
CDFLAG   db 01000000b   ; !! not usable

; assert $ eq $403c ; let's see if rom sysvars are ending correctly!

;---
;PRTBUF   db 33 dup (0)
;MEMBOT   db 30 dup (0)    
;NOTUSED2 dw 2
;=> 65 bytes fully usable
