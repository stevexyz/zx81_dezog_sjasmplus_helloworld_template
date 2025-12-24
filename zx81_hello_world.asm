 INCLUDE "includes/zx81_prologue.inc" ;|
;--------------------------------------/

; Note that in ZX81 programs there are certain restrictions:
; in SLOW MODE a', f', ix, iy, i and r registers cannot be used (not even read the af' pair).
; With NMI disabled (in the ZX81 this is possible due to external circuits) they can be all used
; if values are restored before enabling it again.
;
; Pay attention on what you put in the screen area: a line can be maximum 32 character and should
; always end with _NL (new line = $76 / halt instruction), and the whole screen itself should
; always start end end with _NLs. To avoid to define all the 24 lines after the last
; used _NL a "jp (hl)" can be used. Lastly note that for all bytes that are present in the screen
; area with bit 6 set, the corresponding Z80 instruction will be executed (there are many in depth
; explanations on ZX81 TV rendering); so just some of those values can be "safely" used, and since
; they are displayed as a "blank" probably just for specific purposes of keeping some sort of
; "display memory".  
;
; The area $4000-$403C ($407D if basic is used)  is dedicated to "system variables". Some of them
; are used by NMI to manage video generation (DFILE, MARGIN, FRAMES, CDFLAGS) or keyboard
; (LAST_K and DB_ST), so in general they cannot be used not even in assembler to store program values.

_main: ; starting address

  ld hl,display_area
  ld (D_FILE),hl ; set the display pointer to the prepared area containing hello world

end_program:
  jp end_program ; loop forever
                 ; note that the screen will take some time to appear since the "user code"
                 ; (this program) is executed during top and bottom borders in "slow mode"

display_area:
 INCLUDE "includes/zx81_charset.inc" ; ZX81 is not ascii based
  ; collapsed display for 1k (else all the lines should be complete)
  halt ; sync screen output
  db _cH,_cE,_cL,_cL,_cO, _NL ; *HELLO* (on 2 lines and with second word in inverted colors)
  db _iW,_iO,_iR,_iL,_iD, _NL ; *WORLD* (no exclamation point available on ZX81!)
  jp (hl) ; a "trick" to fill blank the the rest of the screen

;--------------------------------------\
 INCLUDE "includes/zx81_epilogue.inc" ;|

  assert $ < ($4000 + 9 + 940)
