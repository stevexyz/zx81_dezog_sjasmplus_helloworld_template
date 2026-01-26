Note that in ZX81 programs there are certain restrictions:
in SLOW MODE a', f', ix, iy, i and r registers cannot be used (not even read the af' pair).
With NMI disabled (in the ZX81 this is possible due to external circuits) they can be all used
if values are restored before enabling NMI again.

Pay attention on what you put in the screen area: a line can be maximum 32 character and should
always end with _NL (new line = $76 / halt instruction), and the whole screen itself should
always start end end with _NLs. To avoid to define all the 24 lines after the last
used _NL a "jp (hl)" can be used. Lastly note that for all bytes that are present in the screen
area with bit 6 set, the corresponding Z80 instruction will be executed (there are many in depth
explanations on ZX81 TV rendering); so just some of those values can be "safely" used, and since
they are displayed as a "blank" probably used just for specific purposes of keeping some sort of
"display memory".  

The area $4000-$403C ($407D if basic is used) is dedicated to "system variables". Some of them
are used by NMI to manage video generation (DFILE, MARGIN, FRAMES, CDFLAGS) or keyboard
(LAST_K and DB_ST), so in general they cannot be used (not even in assembler) to store program values.

If in DeZog configuration ula is set to "highres" the screen will take some time to appear since
the "user code" (e.g. the program above) is executed in "slow mode" during top and bottom borders,
and after it the screen is displayed (simulating an "execution" of it)
