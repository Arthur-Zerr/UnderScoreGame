#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd "/Users/arthurzerr/Documents/PKZ Projects/UnderScoreGame"
  make -f /Users/arthurzerr/Documents/PKZ\ Projects/UnderScoreGame/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd "/Users/arthurzerr/Documents/PKZ Projects/UnderScoreGame"
  make -f /Users/arthurzerr/Documents/PKZ\ Projects/UnderScoreGame/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd "/Users/arthurzerr/Documents/PKZ Projects/UnderScoreGame"
  make -f /Users/arthurzerr/Documents/PKZ\ Projects/UnderScoreGame/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd "/Users/arthurzerr/Documents/PKZ Projects/UnderScoreGame"
  make -f /Users/arthurzerr/Documents/PKZ\ Projects/UnderScoreGame/CMakeScripts/ReRunCMake.make
fi

