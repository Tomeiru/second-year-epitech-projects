#!/bin/sh

typeset -i tests_run=0
function try { this="$1"; }
trap 'printf "$0: exit code $? on line $LINENO\nFAIL: $this\n"; exit 1' ERR
function assert {
        let tests_run+=1
        [ "$1" = "$2" ] && { echo -ne "$this : Success\n"; return; }
        printf "\nFAIL: $this\n'$1' != '$2'\n"; exit 1
}

try "Test Epi 1"

assert "`echo \"sa pb pb pb sa pa pa pa pa pa pa pa\" | ./pushswap_checker 2 1 3 6 5 8`" "OK"

try "Test Epi 2"

assert "`echo \"sa pb pb pb\" | ./pushswap_checker 2 1 3 6 5 8`" "KO:([6,5,8],[3,2,1])"

try "Test Empty Echo with Sorted List"

assert "`echo \"\" | ./pushswap_checker 1 2 3 4 5`" "OK"

try "Test Error Handling 1"

assert "`echo \"aaa\" | ./pushswap_checker 2 1 3 6 5 8 ; echo $?`" "84"

try "Test Error Handling 2"

assert "`echo \"sa pa pb\" | ./pushswap_checker a b c d e f ; echo $?`" "84"

try "Test Error Handling 3"

assert "`echo \"sa pa pb\" | ./pushswap_checker ; echo $?`" "84"

echo; echo "PASS: $tests_run tests"