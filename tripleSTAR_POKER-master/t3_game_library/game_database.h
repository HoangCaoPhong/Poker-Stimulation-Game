#pragma once
#include <map>
#include <string>
     
//====================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================
//Mô tả: Thư viện này bao gồm các hàm liên quan đến việc xây dựng Database cho trò chơi

//Hướng dẫn sử dụng: 
    //Để sử dụng các hàm trong thư viện này, bạn cần include thư viện này vào file của mình bằng cách thêm dòng lệnh sau:
    //#include "game_database.h"

//Thư viện này bao gồm:

    //Phân loại các mức bài
    enum Hand_Rank {
        HIGH_CARD = 0,
        PAIR,
        TWO_PAIR,
        THREE_OF_A_KIND,
        STRAIGHT,
        FLUSH,
        FULL_HOUSE,
        FOUR_OF_A_KIND,
        STRAIGHT_FLUSH
    };

    //Cấu trúc dữ liệu người chơi
    struct Player {
        int number;  // Player's number (1-based index)
        int total_games = 0;  // Total games played
        int wins = 0;  // Total wins
        float win_rate = 0.0;  // Win rate in percentage
        std::map<std::string, int> win_situations; // Track win types (card value & suit)
    };

    // Hàm khởi tạo người chơi
    Player create_player(int player_number) {
        Player p;
        p.number = player_number;
        p.total_games = 0;
        p.wins = 0;
        p.win_rate = 0.0;
        // Khởi tạo thêm các giá trị khác nếu cần
        return p;
    }

    // Enums for suits
    enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

    // Struct for representing a card
    struct Card 
    {
        int value;  // 2-14 (where 11 = J, 12 = Q, 13 = K, 14 = A)
        Suit suit;  // Suit enumeration
    };

    
//====================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================