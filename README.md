# tic_tac_toe [![Build Status](https://travis-ci.org/Br0ce/tic_tac_toe.svg?branch=master)](https://travis-ci.org/Br0ce/tic_tac_toe)

tic_tac_toe lets you play the classic Tic-tac-toe game.
It consists of two parts.

#### ttt_frontend
Simple gui-frontend for the game.
  
#### ttt_backend
The command-line game-engine.

 * Min Max Algorithm: -mm Flag
 * Alpha Betha Algorithm: -ab Flag

Displays number of evaluated moves and elapsed time to compute them.

The front- and backend communicate via TCP/IP. So they can easily be substituted.
