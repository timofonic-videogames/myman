#!/bin/bash --
# turboc.sh - compile MyMan for DOS using Turbo C
#
# This calls turbo.bat inside DOSBox to do the dirty work.

# override $TURBOC to point to the root of your Turbo C installation,
# i.e. the directory containing a "tc" subdirectory
TURBOC="${TURBOC:-~/tc201}"

prefix="TCC$$"
srcdir="$(dirname "$0")"/..
TMPDIR="${TMPDIR:-/tmp}"
errfile="${prefix}.ERR"
retfile="${prefix}.RET"

cd "$srcdir" &&
rm -f "${TMPDIR}/${errfile}" &&
touch "${TMPDIR}/${errfile}" &&
rm -f "${TMPDIR}/${retfile}" &&
echo 0 > "${TMPDIR}/${retfile}" &&
(
    tail -f "${TMPDIR}/${errfile}" | sed 's/$//;s/^\([^:]*\)\\/\1\//;s/^\([^ ]*\) \([^:]*\) \([0-9]\+\): /\2:\3: \1: /;s/\(.*\) (warning)$/warning: \1/;s/ (error)$//'
) & tail=${!}
sleep 1
(echo '[dosbox]'; echo 'memsize=64'; echo '[cpu]'; echo 'cycles=max') | dosbox -conf /dev/fd/0 -noautoexec -c cls -c 'mount c '"${TURBOC}" -c 'mount t '"${TMPDIR:-/tmp}" -c 'mount d .' -c 'd:' -c 'path c:\tc;%path%' -c '%comspec% /c call utl\turboc > t:'"${errfile}"'' -c 'if errorlevel 1 echo 1 > t:'"${retfile}"'' -c 'exit' >/dev/null || echo $? > "${TMPDIR}/${retfile}"
sleep 1
disown "$tail"
kill "$tail"
ret="$( ( echo 1; cat "${TMPDIR}/${retfile}" ) | tr -d '' | grep . | tail -1)"
rm -f "${TMPDIR}/${retfile}" "${TMPDIR}/${errfile}"
exit "$ret"
