#!/bin/sh 

CMD="ls > ~/test_at"
TMP_PATH="/tmp/.cmd_at"
DATE="8:42 12/21/18"

echo $CMD > $TMP_PATH
at $DATE < $TMP_PATH
rm $TMP_PATH
