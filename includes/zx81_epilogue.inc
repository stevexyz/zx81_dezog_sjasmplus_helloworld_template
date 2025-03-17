

;================================================================

  ; this basic instruction are re-usable after program start (e.g. putting stack here or other asm variables)! 
  ; avoiding using BASIC functions (e.g. VAL) will use less stack to start (and anyway will never return!)

  ; db $00,$53 ; line number (big endian)
  ; dw line1end-$-2 ; line length (little endian)
  ; commenting line numbers above take line number (quite ok) and lenght(attention!) from previous bytes
    
line1a4: ; AUTORUN here - 4 (line number and length are fictitious, "almost" every value will fit)
  db $F9,$D4 ; RAND USR
  ; then "minimal" FP notation to indicate starting point
  db $1c,$7e ; NR + FP indicator
  db $8f ; exp fixed for the 1k range
  LUA ALLPASS
    STARTING_ADDRESS = _c("main_program") 
    MANTISSA1 = (STARTING_ADDRESS-16384)//128
    sj.add_byte(MANTISSA1)
    sj.add_byte((STARTING_ADDRESS-16384)*2-MANTISSA1*256)
  ENDLUA
  ; explanations: http://www.users.waitrose.com/~thunor/mmcoyzx81/chapter17.html
  ;               https://gzuliani.bitbucket.io/sinclair/scacchi-1k.html
line1end:

vars2:
    db $80 ; end of vars flag
end_vars:

eline: ; edit line temporary area
endoftape: ;-- End of ".o" or ".p" -----------------

total_lenght equ $ - MEMORYSTART
; assert total_lenght <= 958 ; 958-9 = 949 .p payload MAX (all included) that seems allowed by _standard_ BASIC loader!
