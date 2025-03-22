#!/bin/bash

./clean.sh

set -e

sjasmplus/sjasmplus \
    --nologo \
    --msg=war \
    --fullpath \
    --outprefix=. \
    --sld=zx81_hello_world.sld \
    --lst=zx81_hello_world.lst \
    --lstlab \
    --sym=zx81_hello_world.sym \
    --raw=zx81_hello_world.p \
    zx81_hello_world.asm 

set +e

