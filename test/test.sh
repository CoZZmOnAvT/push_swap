#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                                              #
#    test.sh                                                                   #
#                                                                              #
#    By: phrytsenko                                                            #
#                                                                              #
#    Created: 2019/01/05 14:53:53 by phrytsenko                                #
#    Updated: 2019/01/08 16:16:10 by phrytsenko                                #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP_BINARY_PATH=$(find . -name "push_swap" -type f -print -quit);
CHECKER_BINARY_PATH=$(find . -name "checker" -type f -print -quit);

# Color List
NC="\033[0m";
BLACK="\033[0;30m";         DARK_GRAY="\033[1;30m";
RED="\033[0;31m";           LIGHT_RED="\033[1;31m";
GREEN="\033[0;32m";         LIGHT_GREEN="\033[1;32m";
ORANGE="\033[0;33m";        YELLOW="\033[1;33m";
BLUE="\033[0;34m";          LIGHT_BLUE="\033[1;34m";
PURPLE="\033[0;35m";        LIGHT_PURPLE="\033[1;35m";
CYAN="\033[0;36m";          LIGHT_CYAN="\033[1;36m";
LIGHT_GRAY="\033[1;37m";    WHITE="\033[0;37m";

PRINT_ERROR() {
    printf "${RED}------------ [ERROR] ------------${NC}\n"
    printf "${PURPLE}STACK${NC}: `echo $1`\n";
    printf "${PURPLE}${PUSH_SWAP_BINARY_PATH}${NC}: `echo $2`\n";
    printf "${PURPLE}${CHECKER_BINARY_PATH}${NC}: ${RED}%s${NC}\n" $3;
    printf "${RED}---------------------------------${NC}\n\n"
}

PRINT_WARNING() {
    printf "${ORANGE}----------- [WARNING] -----------${NC}\n"
    printf "${BLUE}STACK${NC}: `echo $1`\n";
    printf "${BLUE}INSTRUCTIONS${NC}: `echo $2`\n";
    printf "${BLUE}COUNT${NC}: ${RED}%ld${NC}\n" $3;
    printf "${ORANGE}---------------------------------${NC}\n\n"
}

RUN_COUNT_TEST() {
    local MAX_COUNT=0
    for i in {0..100};
    do
        local ARG=$(shuf -i 0-$(echo $1 ' * 2' | bc) -n $1 | xargs);
        local RESULT=$($PUSH_SWAP_BINARY_PATH $ARG)
        local TMP_COUNT=$(echo "$RESULT" | wc -l);

        if [ $TMP_COUNT -gt $MAX_COUNT ]; then
            MAX_COUNT=$TMP_COUNT;
        fi
        if [ $1 -le 5 ] && [ $TMP_COUNT -gt 12 ]; then
            PRINT_WARNING "$ARG" "$RESULT" "$TMP_COUNT"
            PRINT_WARNING "$ARG" "$RESULT" "$TMP_COUNT" >> test.log
        elif [ $1 -le 100  ] && [ $TMP_COUNT -gt 700 ]; then
            PRINT_WARNING "$ARG" "$RESULT" "$TMP_COUNT"
            PRINT_WARNING "$ARG" "$RESULT" "$TMP_COUNT" >> test.log
        elif [ $1 -le 500  ] && [ $TMP_COUNT -gt 5500 ]; then
            PRINT_WARNING "$ARG" "$RESULT" "$TMP_COUNT"
            PRINT_WARNING "$ARG" "$RESULT" "$TMP_COUNT" >> test.log
        fi

        local CHECK_RESULT=$(echo "$RESULT" | $CHECKER_BINARY_PATH $ARG)
        if [ "$CHECK_RESULT" != "OK" ]; then
            PRINT_ERROR "$ARG" "$RESULT" "$CHECK_RESULT"
            PRINT_ERROR "$ARG" "$RESULT" "$CHECK_RESULT" >> test.log
        fi
    done
    printf "${CYAN}STACK_SIZE:${NC} %ld, ${CYAN}MAX_INSTRUCTIONS:${NC} %ld\n" $1 $MAX_COUNT;
}

RUN_COUNT_TEST 5;
# RUN_COUNT_TEST 100;
# RUN_COUNT_TEST 500;
