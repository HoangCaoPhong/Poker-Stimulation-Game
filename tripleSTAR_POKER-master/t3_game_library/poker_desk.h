#pragma once
#include <limits>
#include <iostream>
#include <iomanip>
#include <vector>
#include "game_database.h"
#include <windows.h>
//====================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================
//Mô tả: Thư viện này bao gồm các hàm liên quan đến giao diện game như việc nhập xuất và hiển thị thông tin 

//Hướng dẫn sử dụng: 
    //Để sử dụng các hàm trong thư viện này, bạn cần include thư viện này vào file của mình bằng cách thêm dòng lệnh sau:
    //#include "poker_desk.h"

//Thư viện này bao gồm các hàm:
//..................................................................................................................................
    //Các hàm nhập, kiểm tra thông tin

        // Hàm nhập số người chơi
        int input_number_of_players();

        // hỏi người dùng nhập Yes hoặc No 
        bool check_Yes_No_Input();

        //Hỏi người chơi có muốn chọn chế độ chơi lại không
        bool ask_to_choose_mode_again();

        // Hàm hỏi người chơi có muốn chơi tiếp hay không
        bool ask_to_continue();

        //Hàm chọn mức độ khó của trò chơi
        int selectGameLevel();
//..................................................................................................................................
    //Các hàm xuất thông tin

        // Hàm in bài của người chơi
        void print_player_cards(std::vector<std::string> player_cards);

        // Hàm in bài của tất cả người chơi
        void print_all_player_cards(const std::vector<std::vector<std::string>>& player_cards, int number_player);

        // Hàm in thông tin người chơi
        void print_player_info(const Player& player);

        // Hàm in thông tin chế độ PvE
        void print_pve_info(const Player& player, bool check_bot);

        // Hàm in leaderboard (PvE) xếp hạng người chơi dựa trên tỷ lệ thắng
        void leaderboard_pve(const std::vector<Player>& players);

        //Hàm in leaderboard (PvE) cuối cùng xếp hạng người chơi dựa trên tỷ lệ thắng
        void final_leaderboard_pve(const std::vector<Player>& players);

        // Hàm in leaderboard xếp hạng người chơi
        void leaderboard(const std::vector<Player>& players);
        
        //Hàm in leaderboard cuối cùng xếp hạng người chơi
        void final_leaderboard(const std::vector<Player>& players);

        // Hàm in hướng dẫn chơi chế độ PvP
        void printPvPGuide();
        
        // Hàm in hướng dẫn chơi chế độ PvE
        void printPvEGuide();

        // In ASCII Art Poker
        void printASCIIPoker();

        // In ASCII Art Poker
        void printASCIIArt();

        // In hướng dẫn chơi chế độ Single Card Duel
        void printSingleCardDuelGuide();

        // In hướng dẫn chơi chế độ Three Card Poker
        void printThreeCardPokerGuide();

        // Hàm chỉnh màu chữ
        void setTextColor(int color);

//====================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================


// Hàm nhập số người chơi
int input_number_of_players() 
{
    int number_player;
    std::cout << "Enter number of players(between 2 and 10): ";
    while (!(std::cin >> number_player) || number_player < 2 || number_player >= 10) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter again: ";
    }
    printASCIIArt();
    return number_player;
}

// Hàm in bài của người chơi
void print_player_cards(std::vector<std::string> player_cards)
{
    for (const std::string& card : player_cards)
    {
        std::cout << card << std::endl; // In từng lá bài trên một dòng
    }
    std::cout << std::endl; 
    // Xuống dòng sau khi in xong lá bài của người chơi
}

// Hàm in bài của tất cả người chơi
void print_all_player_cards(const std::vector<std::vector<std::string>>& player_cards, int number_player) 
{
    // In ra từng lá bài của từng người chơi theo từng dòng
    for (int i = 0; i < number_player; i++) {
        std::cout << "Cards of player " << i + 1 << ":" << std::endl;

        for (const std::string& card : player_cards[i]) {
            std::cout << card << std::endl; // In từng lá bài trên một dòng
        }

        std::cout << std::endl; // Xuống dòng sau khi in xong lá bài của người chơi
    }
}

// Hàm in thông tin người chơi
void print_player_info(const Player& player) {
    // In thông tin cơ bản của người chơi
    std::cout << "Player " << player.number << ":\n";
    std::cout << "Total games played: " << player.total_games << "\n";
    std::cout << "Total wins: " << player.wins << "\n";
    
    // In tỷ lệ thắng, làm tròn đến 2 chữ số sau dấu phẩy
    std::cout << "Win rate: " << std::fixed << std::setprecision(2) << player.win_rate << "%\n";
    
    // In các tình huống thắng
    std::cout << "Winning situations:\n";
    if (player.win_situations.empty()) {
        std::cout << "No winning situations recorded.\n";
    } else {
        for (const auto& situation : player.win_situations) {
            std::cout << "- " << situation.first << ": " << situation.second << " wins\n";
        }
    }
    std::cout << std::endl;
}


// Hàm in thông tin chế độ PvE
void print_pve_info(const Player& player, bool check_bot) {
    if (check_bot) 
    {
    // In thông tin cơ bản của người chơi
    std::cout << "Bot(super AI version):\n";
    std::cout << "Total games played: " << player.total_games << "\n";
    std::cout << "Total wins: " << player.wins << "\n";
    
    // In tỷ lệ thắng, làm tròn đến 2 chữ số sau dấu phẩy
    std::cout << "Win rate: " << std::fixed << std::setprecision(2) << player.win_rate << "%\n";
    
    // In các tình huống thắng
    std::cout << "Winning situations:\n";
    if (player.win_situations.empty()) {
        std::cout << "No winning situations recorded.\n";
    } else {
        for (const auto& situation : player.win_situations) {
            std::cout << "- " << situation.first << ": " << situation.second << " wins\n";
        }
    }
    std::cout << std::endl;
    }
    else
    {
        // In thông tin cơ bản của người chơi
        std::cout << "Player:\n";
        std::cout << "Total games played: " << player.total_games << "\n";
        std::cout << "Total wins: " << player.wins << "\n";
        
        // In tỷ lệ thắng, làm tròn đến 2 chữ số sau dấu phẩy
        std::cout << "Win rate: " << std::fixed << std::setprecision(2) << player.win_rate << "%\n";
        
        // In các tình huống thắng
        std::cout << "Winning situations:\n";
        if (player.win_situations.empty()) {
            std::cout << "No winning situations recorded.\n";
        } else {
            for (const auto& situation : player.win_situations) {
                std::cout << "- " << situation.first << ": " << situation.second << " wins\n";
            }
        }
        std::cout << std::endl;
    }

}

int selectGameLevel() {
    int level;
    bool isValid = false;

    // Loop until the user enters a valid level
    while (!isValid) {
        std::cout << "Select the game difficulty level:\n";
        std::cout << "1. Lv1 - Normal\n";
        std::cout << "2. Lv2 - Challenge\n";
        std::cout << "3. Lv3 - Legendary\n";
        std::cout << "Enter your choice (1-3): ";

        // Kiểm tra nếu người dùng nhập sai kiểu dữ liệu
        if (std::cin >> level) {
            // Validate the user's input
            if (level >= 1 && level <= 3) {
                isValid = true; // Exit the loop if valid input is provided
                switch (level) {
                    case 1:
                        std::cout << "You have selected Lv1 - Normal.\n";
                        break;
                    case 2:
                        std::cout << "You have selected Lv2 - Challenge.\n";
                        break;
                    case 3:
                        std::cout << "You have selected Lv3 - Legendary.\n";
                        break;
                }
            } else {
                // Thông báo lỗi khi người dùng chọn sai mức độ
                std::cout << "Invalid choice! Please select a number between 1 and 3.\n\n";
            }
        } else {
            // Xử lý khi người dùng nhập không phải số
            std::cout << "Invalid input! Please enter a valid number between 1 and 3.\n";
            std::cin.clear();  // Xóa trạng thái lỗi của cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Loại bỏ các ký tự còn lại trong input buffer
        }
    }
    printASCIIArt();
    return level;
}

// hỏi người dùng nhập Yes hoặc No 
bool check_Yes_No_Input() {
    char input;
    while (true) {
        std::cout << "Please enter Y (Yes) or N (No): ";
        std::cin >> input;

        if (input == 'y' || input == 'Y') {
            return true; // Người dùng nhập Y
        } else if (input == 'n'|| input == 'N') {
            return false; // Người dùng nhập N
        } else {
            std::cout << "Invalid input. "; // Thông báo nếu đầu vào không hợp lệ
        }
    }
}


// Hàm in leaderboard xếp hạng người chơi dựa trên tỷ lệ thắng
void leaderboard_pve(const std::vector<Player>& players) 
{
    // Tạo bản sao danh sách người chơi để sắp xếp
    std::vector<Player> sorted_players = players;

    // Sắp xếp theo tỷ lệ thắng giảm dần
    std::sort(sorted_players.begin(), sorted_players.end(), [](const Player& a, const Player& b) {
        return a.win_rate > b.win_rate;
    });

    // In bảng xếp hạng
    std::cout << "\n======================= LEADERBOARD PVE ========================\n";
    std::cout << std::left << std::setw(10) << "Rank" 
         << std::setw(15) << "Participant" 
         << std::setw(15) << "Games Played" 
         << std::setw(10) << "Wins" 
         << std::setw(12) << "Win Rate (%)" << std::endl;

    for (size_t i = 0; i < sorted_players.size(); ++i) {
        const Player& player = sorted_players[i];
        std::cout << std::left << std::setw(10) << (i + 1) 
             << std::setw(15) << (player.number == 2 ? "Bot" : "Player")
             << std::setw(15) << player.total_games 
             << std::setw(10) << player.wins 
             << std::setw(12) << std::fixed << std::setprecision(2) << player.win_rate << std::endl;
    }
     std::cout << "================================================================\n";
}

//Hàm in leaderboard cuối cùng xếp hạng người chơi dựa trên tỷ lệ thắng
void final_leaderboard_pve(const std::vector<Player>& players) 
{
    // Tạo bản sao danh sách người chơi để sắp xếp
    std::vector<Player> sorted_players = players;

    // Sắp xếp theo tỷ lệ thắng giảm dần
    std::sort(sorted_players.begin(), sorted_players.end(), [](const Player& a, const Player& b) {
        return a.win_rate > b.win_rate;
    });

    // In bảng xếp hạng
    std::cout << "\n======================= FINAL LEADERBOARD PVE ========================\n";
    std::cout << std::left << std::setw(10) << "Rank" 
         << std::setw(15) << "Participant" 
         << std::setw(15) << "Games Played" 
         << std::setw(10) << "Wins" 
         << std::setw(12) << "Win Rate (%)" << std::endl;

    for (size_t i = 0; i < sorted_players.size(); ++i) {
        const Player& player = sorted_players[i];
        std::cout << std::left << std::setw(10) << (i + 1) 
             << std::setw(15) << (player.number == 2 ? "Bot" : "Player ")
             << std::setw(15) << player.total_games 
             << std::setw(10) << player.wins 
             << std::setw(12) << std::fixed << std::setprecision(2) << player.win_rate << std::endl;
    }
    std::cout << "=======================================================================\n";
}


// Hàm in leaderboard xếp hạng người chơi dựa trên tỷ lệ thắng
void leaderboard(const std::vector<Player>& players) 
{
    // Tạo bản sao danh sách người chơi để sắp xếp
    std::vector<Player> sorted_players = players;

    // Sắp xếp theo tỷ lệ thắng giảm dần
    std::sort(sorted_players.begin(), sorted_players.end(), [](const Player& a, const Player& b) {
        return a.win_rate > b.win_rate;
    });

    // In bảng xếp hạng
     std::cout << "\n=========================== LEADERBOARD ==============================\n";
    std::cout << std::left << std::setw(10) << "Rank" 
         << std::setw(15) << "Player No." 
         << std::setw(15) << "Games Played" 
         << std::setw(10) << "Wins" 
         << std::setw(12) << "Win Rate (%)" << std::endl;

    for (size_t i = 0; i < sorted_players.size(); ++i) {
        const Player& player = sorted_players[i];
        std::cout << std::left << std::setw(10) << (i + 1) 
             << std::setw(15) << player.number 
             << std::setw(15) << player.total_games 
             << std::setw(10) << player.wins 
             << std::setw(12) << std::fixed << std::setprecision(2) << player.win_rate << std::endl;
    }
    std::cout << "=======================================================================\n";
}

//Hàm in leaderboard cuối cùng xếp hạng người chơi dựa trên tỷ lệ thắng
void final_leaderboard(const std::vector<Player>& players) 
{
    // Tạo bản sao danh sách người chơi để sắp xếp
    std::vector<Player> sorted_players = players;

    // Sắp xếp theo tỷ lệ thắng giảm dần
    std::sort(sorted_players.begin(), sorted_players.end(), [](const Player& a, const Player& b) {
        return a.win_rate > b.win_rate;
    });

    // In bảng xếp hạng
    std::cout << "\n======================== FINAL LEADERBOARD ========================\n";
    std::cout << std::left << std::setw(10) << "Rank" 
         << std::setw(15) << "Player No." 
         << std::setw(15) << "Games Played" 
         << std::setw(10) << "Wins" 
         << std::setw(12) << "Win Rate (%)" << std::endl;

    for (size_t i = 0; i < sorted_players.size(); ++i) {
        const Player& player = sorted_players[i];
        std::cout << std::left << std::setw(10) << (i + 1) 
             << std::setw(15) << player.number 
             << std::setw(15) << player.total_games 
             << std::setw(10) << player.wins 
             << std::setw(12) << std::fixed << std::setprecision(2) << player.win_rate << std::endl;
    }
    std::cout << "===================================================================\n";
}

//Hỏi người chơi có muốn chọn chế độ chơi lại không
bool ask_to_choose_mode_again() {
    std::string user_input;
    std::cout << "Do you want to choose the game mode again (yes/no): ";
    std::cin >> user_input;

    // Kiểm tra xem người chơi nhập "yes" hoặc "no"
    if (user_input == "yes" || user_input == "y" || user_input == "Y") {
        return true;  // Người chơi muốn chọn lại chế độ
    } else if (user_input == "no" || user_input == "n" || user_input == "N") {
        return false;  // Người chơi không muốn chọn lại chế độ
    } else {
        std::cout << "Invalid input! Please enter 'yes' or 'no'.\n";
        return ask_to_choose_mode_again();  // Nếu nhập sai, yêu cầu nhập lại
    }
}


// Hàm hỏi người chơi có muốn chơi tiếp hay không
bool ask_to_continue() {
    char choice;
    std::cout << "Do you want to continue playing? (Y/N): ";
    std::cin >> choice;
    return (choice == 'Y' || choice == 'y');
}

// Hàm in hướng dẫn chơi chế độ PvP
void printPvPGuide() {
    std::cout << "=== PvP Mode (Player vs. Player) Guide ===\n";
    std::cout << "Description:\n";
    std::cout << "  + PvP mode allows two players to compete directly against each other.\n";
    std::cout << "    Each player takes turns to play their move.\n\n";

    std::cout << "Instructions:\n";
    std::cout << "  + When entering PvP mode, enter the number of players (from 2 to 10).\n";
    std::cout << "  + The computer will randomly distribute cards to each player.\n";
    std::cout << "  + The computer will automatically calculate and find the strongest hand for each player.\n";
    std::cout << "  + The computer will automatically determine the winner.\n";
    std::cout << "  + Players with the strongest hand will win and receive 1 point.\n";
    std::cout << "  + The computer will automatically update the players' information.\n";
    std::cout << "  + The computer will display the current round's Leaderboard sorted by win rate.\n";
    std::cout << "  + The game has no limit on the number of rounds.\n";
    std::cout << "  + The game ends when players decide to stop playing.\n";
    std::cout << "  + The computer will display the final Leaderboard.\n\n";
}

// Hàm in hướng dẫn chơi chế độ PvE
void printPvEGuide() {
    std::cout << "=== PvE Mode (Player vs. Environment) Guide ===\n";
    std::cout << "Description:\n";
    std::cout << "  + PvE mode allows a player to compete against the computer (AI/Bot) designed by the Triple_Star team.\n";
    std::cout << "    This is a great way to practice or have fun without a human opponent.\n\n";

    std::cout << "Instructions:\n";
    std::cout << "  + When entering PvE mode, the player will be asked to select the bot difficulty level:\n";
    std::cout << "      Lv1 - Normal: Basic difficulty, the bot plays like a regular player.\n";
    std::cout << "                    (Bot win rate: ~60%)\n";
    std::cout << "      Lv2 - Challenge: Challenging difficulty, the bot plays at an expert level.\n";
    std::cout << "                    (Bot win rate: ~70%)\n";
    std::cout << "      Lv3 - Legendary: Extremely high difficulty, the bot plays like a Poker champion.\n";
    std::cout << "                    (Bot win rate: ~80%)\n";
    std::cout << "  + The computer will randomly distribute cards.\n";
    std::cout << "  + The computer will automatically calculate and find the strongest hands for both the bot and the player, then display them.\n";
    std::cout << "  + The computer will automatically determine the winner.\n";
    std::cout << "  + Whoever has the strongest hand wins and receives 1 point.\n";
    std::cout << "  + The computer will automatically update the player's information.\n";
    std::cout << "  + The computer will display the current round's Leaderboard sorted by win rate.\n";
    std::cout << "  + The game has no limit on the number of rounds.\n";
    std::cout << "  + The game ends when the player decides to stop playing.\n";
    std::cout << "  + The computer will display the final Leaderboard.\n\n";
}

// In ASCII Art Poker
    void printASCIIPoker() {
    std::cout << "  _____      _             \n";
    std::cout << " |  __ \\    | |            \n";
    std::cout << " | |__) |__ | | _____ _ __ \n";
    std::cout << " |  ___/ _ \\| |/ / _ \\ '__|\n";
    std::cout << " | |  | (_) |   <  __/ |   \n";
    std::cout << " |_|   \\___/|_|\\_\\___|_|   \n";
    std::cout << "                           \n";
    std::cout << "                           \n";
}

// In ASCII Art Poker
void printASCIIArt() {
    std::cout << "                                              %######%\n";
    std::cout << "                                           %*+=+++++++==+#%%%%%%*+*%\n";
    std::cout << "                                         %*-=**=---==++**++++++==#==%\n";
    std::cout << "                                       %%+-#*::=**+===-::-++*++#%#%:*%\n";
    std::cout << "                                     %#+==#*:*%%+=+*++=++==::-*#-*#:#%\n";
    std::cout << "                                    %+-+*+%*#%%*#%#*+*****####*+#%-+%\n";
    std::cout << "                                   %+:#+.-#%%%##%#*%%###%%%##%%%%+:%\n";
    std::cout << "                                   %-+#.*##%%%#%%%@%#%@%%#%%%%%=-%-+%\n";
    std::cout << "                                   %-+#*#%%*===::=++++-:.  :#%#*=%-=%\n";
    std::cout << "                                   %==%+#%#--=.              #%++%:*%\n";
    std::cout << "                                   %*:#*%%*---               #@*#*:#%\n";
    std::cout << "                                    %:=%%%+-==.         ...  =@%%-=%\n";
    std::cout << "                                   %+-+%%#-*#####+   .*###**- %%#+-*%\n";
    std::cout << "                                  %+:%+:*#=++*%%*+.  .:+%#=.: %=:**:#%\n";
    std::cout << "                                  %==%=#%#--:=@%:      =@%-  .%#*+%:*%\n";
    std::cout << "                                  %*:%*=#%=:  ..        .    :%*=#*:#%\n";
    std::cout << "                                   %=-%*+%=: .    .       .  -%+##:*%\n";
    std::cout << "                                    %+-+*%+=#- :*%%##%#+..+* +%*=-*%\n";
    std::cout << "                                      %*:*#=%##@@@@@@@@@%#%+ %=-*%\n";
    std::cout << "                                       %+-%*=*#*#*+--+*#**: *#:*%\n";
    std::cout << "                                     %%#*-+@#=:   :--.    .*%--#%%\n";
    std::cout << "                                  %##*+--#*%#%*-.       .=#%%#*-=+*##%\n";
    std::cout << "                             %%#*+===+*#%--%.+@%#+-:::-*%@--%:+%*++===+*#\n";
    std::cout << "                          %#*+=-+**+=--%::*%. *@@@@%%%@@%+ -%+.+%-=+***=-=+*#%\n";
    std::cout << "                         #==+**#@::--*#-.+*%-:.-*%%%%%#+:  -%++.*#*:=.=@***===#\n";
    std::cout << "                        #=-*#+:..%-=%*@+.+++%#***+-=**--=++*#%++=.#%*@-=# .-*#+-=#\n";
    std::cout << "                      #-=%+.    #**##%.=+++%-:--=#*++##=--:+%+++:=%*%+#*    .+%=-#\n";
    std::cout << "                     #-=%-      *#*%#%##*+*%-==+#%--:+%#+=-=%*+*##%*%*%=      -%=-#\n";
    std::cout << "                    #-=%:       +%*%*%%#=-*%+-=**%*++#%**=-*%+-+%#%*%*%-       :%==#\n";
    std::cout << "                   #==%-       :+%*%#%--=++#%++*#%####%#*++%#++-:+%#%*%=:       -%-+#\n";
    std::cout << "                  #+-%=      .::+%*%#%*+++++*%#*+-::::=+*%%*+++++#%*%#%=:::      +%-+#\n";
    std::cout << "                 #+-#+      ::::+%*%*%%*+++++%+..  *=  .:##+++++#%%*%#%=::::      ##-*#\n";
    std::cout << "                #*-*#      :::::=%*%#%#%*++++#*   #+  .%*++++#%%%*%#%-:::::     .%+-#\n";
    std::cout << "                #-+%.     ::::-:=%#%###%%*++++*%+  ..  ##++++#%#%*%*%##=*-::::::     -%==#\n";
    std::cout << "               #==%-     .::::-*+%#%###%%%*+++*%+  ..  ##++++#%#%*%*%##=*-:::::     +%-+#\n";
    std::cout << "             #==*=.:-------:-**-#%%######%#%%*++*%*:-#%+++#%%#%*%*%*%%%%-=#=::----=-:.=#-+#\n";
    std::cout << "            #+-%*=++=-.:-==-=*%*%%%######%#%%%#*++%###++*%%##*%*%*%#%%%**%+=##*++++=-:-+%+-*#\n";
    std::cout << "           #+-*#=--==+++++*#+=%**%%######%###%%%#*+%#**%%%%##*%*%*%#%%%**%+=##*++++=-:-+%+-*#\n";
    std::cout << "          %*:#+:=*+-...-=++*%%%-=%%%#%###%###%#%%%%%%%%%%#%#%*%*%#%#%%%=-%%%#++=-..:-+*-:#+-#\n";
    std::cout << "          %*-%*#-     :--===+*%=-%%%%%#%#%###%%%%%%%%%%%%#%#%#%#%%%%%%%+%%*+===--.  . .+##*-%\n";
    std::cout << "          %+-%*..:. .=*#+===+*%%+%%%%%%%#%#%%#+==+++++++=#%%%#%#%%%%%%%+%%*+===+**-..:. :#*-#\n";
    std::cout << "          %-*%::=-.-#%+.      .-+##%%%%%%%%%====-:-=====. -#%%%%%%%@%#*=:.       +%*:.+=:=%-+%\n";
    std::cout << "          %+=%+*#-:##=-.          =%+-*##%#%*-.:=+=-:::-:   -#%##+-+#:          .-=%*:+#=*#-#%\n";
    std::cout << "           %+=*%%--%+-==-:.      +*.-+-++: **+#+:..-++=:..    :++-*::#-      .--==-#%:=%#+=*%\n";
    std::cout << "            *=-+%*-##+=--===--:.=# -*:#-    .-***##*#%+%*::     =*:#::%-::--===--=+%+-##--+*\n";
    std::cout << "           +****%%%#%%%#*+======%+:%-*+    .::-=-:#+.+*=%+:::    *==#:##----==+*#%%%#%%##*+\n";
}


// In hướng dẫn chơi chế độ Single Card Duel
#include <iostream>
using namespace std;

void printSingleCardDuelGuide()
{
    std::cout << "\nSingle Card Duel:\n\n";

    std::cout << "    Description:\n";
    std::cout << "        + Single Card Duel mode allows two players to compete directly.\n";
    std::cout << "        + Each player will receive 1 card.\n";
    std::cout << "        + The player(s) with the strongest card will win the round.\n\n";

    std::cout << "    Gameplay Instructions:\n";
    std::cout << "        + Enter the number of players:\n";
    std::cout << "            At the start of PvP mode, players enter the number of participants (from 2 to 10).\n";
    std::cout << "        + Random card distribution:\n";
    std::cout << "            The system will randomly deal a card to each player.\n";
    std::cout << "        + After the cards are dealt:\n";
    std::cout << "            The system will determine the strongest card and display the result.\n";
    std::cout << "        + Players with the strongest card will win the round and receive 1 point.\n";
    std::cout << "        + If multiple players have the strongest card, they will all receive 1 point.\n";
    std::cout << "        + The system will automatically update player scores after each round.\n";
    std::cout << "        + A temporary Leaderboard will be displayed, sorted by win rate, to track progress.\n";
    std::cout << "        + Unlimited rounds:\n";
    std::cout << "            The game continues until players decide to stop.\n";
    std::cout << "        + At the end of the game:\n";
    std::cout << "            The system will display the final Leaderboard with overall results.\n\n";

    std::cout << "    Card Comparison Rules:\n";
    std::cout << "        + Standard 52-card deck.\n";
    std::cout << "        + Higher card ranks follow the order: 2 < 3 < ... < 10 < J < Q < K < A.\n";
    std::cout << "        + If two cards have the same rank:\n";
    std::cout << "            Suit comparison applies: Spades (♠) > Hearts (♥) > Diamonds (♦) > Clubs (♣).\n";
}

// In hướng dẫn chơi chế độ Three Card Poker
void printThreeCardPokerGuide() {
    std::cout << "Three Card Poker Guide\n";
    std::cout << "========================\n\n";

    std::cout << "Description:\n";
    std::cout << "+ The Three_Card_Poker mode allows multiple players to compete directly.\n";
    std::cout << "+ Each player will receive 3 cards.\n";
    std::cout << "+ Use the deck from A (Ace) to K for calculation.\n";
    std::cout << "+ Whoever has the strongest hand will win.\n\n";

    std::cout << "Instructions for Playing:\n";
    std::cout << "+ Enter the number of players (2 to 10).\n";
    std::cout << "+ When starting the mode, input the number of participants.\n";
    std::cout << "+ Randomly deal cards: The computer will randomly deal 3 cards to each player.\n";
    std::cout << "+ After the cards are dealt, the computer will calculate the score for each player and display the results.\n";
    std::cout << "+ The player with the highest score will win the round and receive 1 point.\n";
    std::cout << "+ If multiple players have the same highest score, all will receive 1 point.\n";
    std::cout << "+ The computer automatically updates the player's score after each round.\n";
    std::cout << "+ Display the temporary leaderboard, sorted by win rate, to track progress.\n";
    std::cout << "+ The game has no round limit.\n";
    std::cout << "+ When the game ends, the final leaderboard will be printed, showing the results of all matches.\n\n";

    std::cout << "Comparison Rules:\n";
    std::cout << "+ Standard deck (52 cards).\n";
    std::cout << "+ Card values:\n";
    std::cout << "  - A (Ace) = 1 point.\n";
    std::cout << "  - Cards from 2 to 9 keep their numeric value.\n";
    std::cout << "  - 10, J, Q, K = 10 points.\n";
    std::cout << "+ Sum the points of 3 cards.\n";
    std::cout << "+ Only take the unit digit (e.g., total 18 -> actual score 8).\n";
    std::cout << "+ Maximum score: 9 points.\n";
}

// Hàm chỉnh màu chữ
void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
