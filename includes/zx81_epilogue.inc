
vars:
  db $80 ; end of vars flag
end_vars:

eline: ; edit line temporary area
endoftape: ;-- End of ".p" --

total_lenght EQU $ - MEMORYSTART
; assert total_lenght <= 958 ; 958-9 = 949 .p payload MAX (all included) that seems allowed by _standard_ BASIC loader!
