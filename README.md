# ChessBotsCompetition

Framework used: https://github.com/Disservin/chess-library/

Game runner: [fastchess](https://github.com/Disservin/fastchess/)

Rules:
1. Required components can be provided to download in compile time, but not in runtime.
2. Disqualification requirements:
  - Using strong engines as the code
  - Compiler-specific headers
  - Using threading APIs
  - Writing or executing files/code in runtime
  - Interact with Internet in runtime
  - Dynamic amount of memory allocation
  - More than 1024MB of memory used
  - Timeout/illegal move(s)
3. Example of a valid bot: 
```
#include "chess.hpp"
#include "timer.hpp"
chess::Move Think(chess::Board& board, Timer time){
    chess::Movelist moves;
    chess::movegen::legalmoves(moves, board);
    return moves[0];
}
```
