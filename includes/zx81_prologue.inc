
; leave a space before directives for sjasmplus (else it assumes they are labels)
 DEVICE NOSLOT64K ; DEVICE ZX81
 SLDOPT COMMENT WPMEM, LOGPOINT, ASSERTION ; for DeZog

 ORG $4000
MEMORYSTART:
MEMORY_END equ 0x4400 ; 1k

;--------------------------
; SYSVARS that aren't saved on file
; all this space is usable memory after asm program start if basic is not used
ERR_NR  equ $4000
FLAGS   equ $4001
ERR_SP  equ $4002
RAMTOP  equ $4004
MODE    equ $4006
PPC     equ $4007

;--------------------------
; SYSVARS that ARE SAVED on .p file
; the comments indicate if the space is usable in assembler programs (not basic)
; (immediately to store values directly on the file or later after program starts, or never)

 ORG $4009 ; .p org (start of saved content on cassette)
;VERSN   db $00       ; usable
;E_PPC   dw $0000     ; usable
;D_FILE  dw dfile     ; !! not usable
;DF_CC   dw $4097     ; usable if not using rst 10h or similar
;VARS    dw $4097     ; usable if not using basic vars
;DEST    dw $0000     ; usable
VERSN   equ $4009
E_PPC   equ $400A
D_FILE  equ $400C
DF_CC   equ $400E
VARS    equ $4010
DEST    equ $4012
;-- the above variables space is used for the "basic" startup below 
startup:
  nop : jp _main ; first fake BASIC "line number" (word, big endian) and "line lenght" (word, little endian)
                 ; and later reused as assembler instructions to jump to start of the program
  db $F9,$D4 ; BASIC tokens for "RAND" "USR" (here will be the DFILE, so not usable after start)
  ; the following 5 bytes (that represent $4009 in FP) are usable after program start 
  db $1C,$7E ; floating point number indicator
  db $8F   ; exp fixed for the 1k range = 2^+14 = 16384
  db 0     ; sign (bit7=0 means "+"), and mantisssa (2^0 is "implicit" 1)
  db $12   ; 2^-11 + 2^-14 (bits after decimals will not count for address)
           ; so 16384 * ( 1 + 1/2048 + 1/16384 ) = 16393 = $4009 (= startup label address)
E_LINE  dw eline     ; xx usable after asm start
CH_ADD  dw $0000     ; xx usable after asm start
X_PTR   dw $0000     ; xx usable after asm start
STKBOT  dw $0000     ; xx usable after asm start
STKEND  dw $0000     ; xx usable after asm start
BREG    db $00       ; xx usable if not floating point usage
MEM     dw $0000     ; xx usable after asm start
NOTUSED db $00       ; usable
DF_SZ   db $00       ; usable
S_TOP   dw $0000     ; usable
LAST_K  dw $FFFF     ; !! not usable (row/column of last char pressed)
DB_ST   db $FF       ; !! not usable (debounce)
MARGIN  db $37       ; !! not usable (display management)
NXTLIN  dw startup   ; xx usable after asm start
OLDPPC  dw $0000     ; usable
FLAGX   db $00       ; usable
STRLEN  dw $0000     ; usable
T_ADDR  dw $0000     ; xx usable after asm start
SEED    dw $0000     ; usable
FRAMES  dw $FFFF     ; !! not usable (value decrease after each frame output, 50 times per second)
COORDS  dw $0000     ; usable
PR_CC   db $00       ; usable
S_POSN  dw $0000     ; usable
CDFLAG  db %01000000 ; !! not usable (fast/slow flags)


 assert($==$403c) ; let's see if rom sysvars are ending correctly!

;---
;PRTBUF   db 33 dup (0)
;MEMBOT   db 30 dup (0)    
;NOTUSED2 dw 2
;=> 65 bytes fully usable
