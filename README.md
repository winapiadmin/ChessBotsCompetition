# ChessBotsCompetition

Framework used: https://github.com/Disservin/chess-library/

Game runner: [fastchess](https://github.com/Disservin/fastchess/)

Rules:
1. Required components can be provided to download in compile time, but not in runtime.
2. Banned things:
  - Compiler-specific headers
  - Threading APIs
  - std::cout/std::cin (comment them)
  - Writing or executing files/code in runtime
  - Interact with Internet in runtime
  - Dynamic amount of memory allocation
  - More than 1024MB of memory used
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
