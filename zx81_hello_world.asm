INCLUDE "includes/zx81_prologue.inc" ;|
;-------------------------------------/


; A very simple helo world program :)

_main: ; starting address

  ld hl,display_area
  ld (D_FILE),hl ; set the display pointer to the prepared area containing hello world

end_program:
  jp end_program ; loop forever

display_area:
 INCLUDE "includes/zx81_charset.inc" ; ZX81 is not ascii based
  ; collapsed display for 1k
  halt ; sync screen output
  db _cH,_cE,_cL,_cL,_cO, _NL ; *HELLO* (on 2 lines and with second word in inverted colors)
  db _iW,_iO,_iR,_iL,_iD, _NL ; *WORLD* (no exclamation point available on ZX81!)
  jp (hl) ; a "trick" to fill blank the the rest of the screen


;--------------------------------------\
 INCLUDE "includes/zx81_epilogue.inc" ;|
  assert $ < ($4000 + 9 + 940)        ;|
