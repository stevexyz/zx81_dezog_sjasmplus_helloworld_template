; leave a space before directives to work!
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
VERSN    db $01         ; usable
E_PPC    dw $01         ; usable
D_FILE   dw dfile       ; !! not usable
DF_CC    dw $0101       ; usable if not using rst 10h or similar
VARS     dw $0101       ; usable if not using basic vars
DEST     dw $0101       ; usable
E_LINE   dw eline       ; xx usable after asm start?
CH_ADD   dw line1a4     ; xx usable after asm start?
X_PTR    dw eline       ; xx usable after asm start?
STKBOT   dw eline       ; xx usable after asm start?
STKEND   dw eline       ; xx usable after asm start?
BERG     db 0           ; xx usable if not floating point usage?
MEM      dw line1a4     ; xx usable after asm start?
NOTUSED  db $01         ; one byte free
DF_SZ    db $01 ;2      ; usable
S_TOP    dw $0101       ; usable
LAST_K   dw $FFFF       ; !! not usable (row/column of last char pressed)
DB_ST    db $FF         ; !! not usable (debounce))
MARGIN   db 55          ; !! not usable (display management))
NXTLIN   dw line1a4 - 4 ; xx autorun (=dfile for no autorun), usable after asm start
OLDPPC   dw $0101       ; usable
FLAGX    db $01         ; usable
STRLEN   dw $0101       ; usable
T_ADDR   dw $0101       ; xx usable after asm start
SEED     dw $0101       ; usable
FRAMES   db $FF,$FF     ; !! not usable
COORDS   db $01,$01     ; usable
PR_CC    db $01         ; usable
S_POSN   db $01,$01     ; usable
CDFLAG   db 01000000B   ; !! not usable

; assert $ eq $403c ; let's see if rom sysvars are ending correctly!

;---
;PRTBUF   db 33 dup (0)
;MEMBOT   db 30 dup (0)    
;NOTUSED2 dw 2
;=> 65 bytes fully usable

