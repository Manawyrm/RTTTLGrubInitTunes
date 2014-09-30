#!/bin/bash

if [ $# -lt 3 ]; then
    ./$0 `gcc test.c && ./a.out`
    exit 1
fi

tempo=$1; shift

tmpdir=$(mktemp -d)

while [ -n "$*" ]; do
    freq=$1; shift
    dur=$1;  shift
    dur=$(echo "$dur*(60/$tempo)"|bc -l)
    sox -e mu-law -r 44100 -n -t raw - synth $dur square $freq >>$tmpdir/grubtune.ul
done

play -q -c1 -r 44100 $tmpdir/grubtune.ul

rm -r $tmpdir

