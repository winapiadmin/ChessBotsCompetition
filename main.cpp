// a minimal UCI-compliant chess wrapper
#include "chess.hpp"
#include "timer.hpp"
#include <iostream>
extern chess::Move Think(chess::Board&, Timer);
chess::Board board;
void handle_position(std::istringstream &iss)
{
    std::string token;
    iss >> token;

    if (token == "startpos")
    {
        board.setFen(chess::constants::STARTPOS);
        iss >> token;
    }
    else if (token == "fen")
    {
        std::vector<std::string> fen_parts;
        while (iss >> token && token != "moves")
        {
            fen_parts.push_back(token);
        }

        // Assign default values if necessary
        while (fen_parts.size() < 6)
        {
            switch (fen_parts.size())
            {
            case 1:
                fen_parts.push_back("w");
                break; // Active color
            case 2:
                fen_parts.push_back("-");
                break; // Castling availability
            case 3:
                fen_parts.push_back("-");
                break; // En passant target square
            case 4:
                fen_parts.push_back("0");
                break; // Halfmove clock
            case 5:
                fen_parts.push_back("1");
                break; // Fullmove number
            }
        }

        // Reconstruct the FEN string
        std::string fen = fen_parts[0];
        for (size_t i = 1; i < 6; ++i)
        {
            fen += " " + fen_parts[i];
        }

        board.setFen(fen);
    }

    if (token == "moves")
    {
        while (iss >> token)
        {
            chess::Move mv = chess::uci::uciToMove(board, token);
            board.makeMove(mv);
        }
    }
}
void handle_go(std::istringstream &iss)
{
    Timer tc;
    std::string sub;
    while (iss >> sub)
    {
        if (sub == "wtime")
            iss >> tc.wtime;
        else if (sub == "btime")
            iss >> tc.btime;
        else if (sub == "winc")
            iss >> tc.winc;
        else if (sub == "binc")
            iss >> tc.binc;
    }
    chess::Move mv = Think(board, tc);
    std::cout<<chess::uci::moveToUci(mv)<<std::endl;
}
int main(){
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::istringstream iss(line);
        std::string token;
        iss >> token;
        if (token == "uci")
            std::cout<<"uciok"<<std::endl;
        else if (token == "isready")
            std::cout<<"readyok"<<std::endl;
        else if (token == "quit")
            break;
        else if (token == "position")
            handle_position(iss);
        else if (token == "go")
            handle_go(iss);
    }
    return 0;
}
