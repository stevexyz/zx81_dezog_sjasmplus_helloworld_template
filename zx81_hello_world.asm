 INCLUDE "includes/zx81_prologue.inc" ;|
;--------------------------------------/
; Note that in ZX81 programs there are certain restrictions:
; in SLOW MODE do not modify the a', f', ix, iy, i and r registers (not even read the af' pair),
; while with NMI disabled all is possible if registers are restored


_main: ; staring address

  ld hl,display_area
  ld (D_FILE),hl ; set the display pointer to the prepared area containing hello world

end_program:
  jp end_program ; loop forever

 INCLUDE "includes/zx81_charset.inc" ; ZX81 is not ascii based

display_area:
  ; collapsed display for 1k (else all the lines should be complete)
  halt ; sync screen output
  db _cH,_cE,_cL,_cL,_cO, _CR ; *HELLO* (on 2 lines and with second word in inverted colors)
  db _iW,_iO,_iR,_iL,_iD, _CR ; *WORLD* (no exclamation point available on ZX81!)
  jp (hl) ; a "trick" to fill blank the the rest of the screen


;--------------------------------------\
 INCLUDE "includes/zx81_epilogue.inc" ;|
