#pragma once
#include <limits>
#include <iostream>
#include <iomanip>
#include <vector>
#include "game_database.h"
using namespace std;
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
        void print_player_cards(vector<string> player_cards);

        // Hàm in bài của tất cả người chơi
        void print_all_player_cards(const vector<vector<string>>& player_cards, int number_player);

        // Hàm in thông tin người chơi
        void print_player_info(const Player& player);

        // Hàm in thông tin chế độ PvE
        void print_pve_info(const Player& player, bool check_bot);

        // Hàm in leaderboard (PvE) xếp hạng người chơi dựa trên tỷ lệ thắng
        void leaderboard_pve(const vector<Player>& players);

        //Hàm in leaderboard (PvE) cuối cùng xếp hạng người chơi dựa trên tỷ lệ thắng
        void final_leaderboard_pve(const vector<Player>& players);

        // Hàm in leaderboard xếp hạng người chơi
        void leaderboard(const vector<Player>& players);
        
        //Hàm in leaderboard cuối cùng xếp hạng người chơi
        void final_leaderboard(const vector<Player>& players);

        // Hàm in hướng dẫn chơi chế độ PvP
        void printPvPGuide();
        
        // Hàm in hướng dẫn chơi chế độ PvE
        void printPvEGuide();

        // In ASCII Art Poker
        void printASCIIPoker();

        // In hướng dẫn chơi chế độ Single Card Duel
        void printSingleCardDuelGuide();

        // In hướng dẫn chơi chế độ Three Card Poker
        void printThreeCardPokerGuide();

//====================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================


// Hàm nhập số người chơi
int input_number_of_players() 
{
    int number_player;
    cout << "Enter number of players(between 2 and 10): ";
    while (!(cin >> number_player) || number_player < 2 || number_player >= 10) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again: ";
    }
    return number_player;
}

// Hàm in bài của người chơi
void print_player_cards(vector<string> player_cards)
{
    for (const string& card : player_cards)
    {
        cout << card << endl; // In từng lá bài trên một dòng
    }
    cout << endl; 
    // Xuống dòng sau khi in xong lá bài của người chơi
}

// Hàm in bài của tất cả người chơi
void print_all_player_cards(const vector<vector<string>>& player_cards, int number_player) 
{
    // In ra từng lá bài của từng người chơi theo từng dòng
    for (int i = 0; i < number_player; i++) {
        cout << "Cards of player " << i + 1 << ":" << endl;

        for (const string& card : player_cards[i]) {
            cout << card << endl; // In từng lá bài trên một dòng
        }

        cout << endl; // Xuống dòng sau khi in xong lá bài của người chơi
    }
}

// Hàm in thông tin người chơi
void print_player_info(const Player& player) {
    // In thông tin cơ bản của người chơi
    cout << "Player " << player.number << ":\n";
    cout << "Total games played: " << player.total_games << "\n";
    cout << "Total wins: " << player.wins << "\n";
    
    // In tỷ lệ thắng, làm tròn đến 2 chữ số sau dấu phẩy
    cout << "Win rate: " << fixed << setprecision(2) << player.win_rate << "%\n";
    
    // In các tình huống thắng
    cout << "Winning situations:\n";
    if (player.win_situations.empty()) {
        cout << "No winning situations recorded.\n";
    } else {
        for (const auto& situation : player.win_situations) {
            cout << "- " << situation.first << ": " << situation.second << " wins\n";
        }
    }
    cout << endl;
}


// Hàm in thông tin chế độ PvE
void print_pve_info(const Player& player, bool check_bot) {
    if (check_bot) 
    {
    // In thông tin cơ bản của người chơi
    cout << "Bot(super AI version):\n";
    cout << "Total games played: " << player.total_games << "\n";
    cout << "Total wins: " << player.wins << "\n";
    
    // In tỷ lệ thắng, làm tròn đến 2 chữ số sau dấu phẩy
    cout << "Win rate: " << fixed << setprecision(2) << player.win_rate << "%\n";
    
    // In các tình huống thắng
    cout << "Winning situations:\n";
    if (player.win_situations.empty()) {
        cout << "No winning situations recorded.\n";
    } else {
        for (const auto& situation : player.win_situations) {
            cout << "- " << situation.first << ": " << situation.second << " wins\n";
        }
    }
    cout << endl;
    }
    else
    {
        // In thông tin cơ bản của người chơi
        cout << "Player:\n";
        cout << "Total games played: " << player.total_games << "\n";
        cout << "Total wins: " << player.wins << "\n";
        
        // In tỷ lệ thắng, làm tròn đến 2 chữ số sau dấu phẩy
        cout << "Win rate: " << fixed << setprecision(2) << player.win_rate << "%\n";
        
        // In các tình huống thắng
        cout << "Winning situations:\n";
        if (player.win_situations.empty()) {
            cout << "No winning situations recorded.\n";
        } else {
            for (const auto& situation : player.win_situations) {
                cout << "- " << situation.first << ": " << situation.second << " wins\n";
            }
        }
        cout << endl;
    }

}

int selectGameLevel() {
    int level;
    bool isValid = false;

    // Loop until the user enters a valid level
    while (!isValid) {
        cout << "Select the game difficulty level:\n";
        cout << "1. Lv1 - Normal\n";
        cout << "2. Lv2 - Challenge\n";
        cout << "3. Lv3 - Legendary\n";
        cout << "Enter your choice (1-3): ";

        // Kiểm tra nếu người dùng nhập sai kiểu dữ liệu
        if (cin >> level) {
            // Validate the user's input
            if (level >= 1 && level <= 3) {
                isValid = true; // Exit the loop if valid input is provided
                switch (level) {
                    case 1:
                        cout << "You have selected Lv1 - Normal.\n";
                        break;
                    case 2:
                        cout << "You have selected Lv2 - Challenge.\n";
                        break;
                    case 3:
                        cout << "You have selected Lv3 - Legendary.\n";
                        break;
                }
            } else {
                // Thông báo lỗi khi người dùng chọn sai mức độ
                cout << "Invalid choice! Please select a number between 1 and 3.\n\n";
            }
        } else {
            // Xử lý khi người dùng nhập không phải số
            cout << "Invalid input! Please enter a valid number between 1 and 3.\n";
            cin.clear();  // Xóa trạng thái lỗi của cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Loại bỏ các ký tự còn lại trong input buffer
        }
    }
    return level;
}

// hỏi người dùng nhập Yes hoặc No 
bool check_Yes_No_Input() {
    char input;
    while (true) {
        cout << "Please enter Y (Yes) or N (No): ";
        cin >> input;

        if (input == 'y' || input == 'Y') {
            return true; // Người dùng nhập Y
        } else if (input == 'n'|| input == 'N') {
            return false; // Người dùng nhập N
        } else {
            cout << "Invalid input. "; // Thông báo nếu đầu vào không hợp lệ
        }
    }
}


// Hàm in leaderboard xếp hạng người chơi dựa trên tỷ lệ thắng
void leaderboard_pve(const vector<Player>& players) 
{
    // Tạo bản sao danh sách người chơi để sắp xếp
    vector<Player> sorted_players = players;

    // Sắp xếp theo tỷ lệ thắng giảm dần
    sort(sorted_players.begin(), sorted_players.end(), [](const Player& a, const Player& b) {
        return a.win_rate > b.win_rate;
    });

    // In bảng xếp hạng
    cout << "\n======================= LEADERBOARD PVE ========================\n";
    cout << left << setw(10) << "Rank" 
         << setw(15) << "Participant" 
         << setw(15) << "Games Played" 
         << setw(10) << "Wins" 
         << setw(12) << "Win Rate (%)" << endl;

    for (size_t i = 0; i < sorted_players.size(); ++i) {
        const Player& player = sorted_players[i];
        cout << left << setw(10) << (i + 1) 
             << setw(15) << (player.number == 2 ? "Bot" : "Player")
             << setw(15) << player.total_games 
             << setw(10) << player.wins 
             << setw(12) << fixed << setprecision(2) << player.win_rate << endl;
    }
     cout << "================================================================\n";
}

//Hàm in leaderboard cuối cùng xếp hạng người chơi dựa trên tỷ lệ thắng
void final_leaderboard_pve(const vector<Player>& players) 
{
    // Tạo bản sao danh sách người chơi để sắp xếp
    vector<Player> sorted_players = players;

    // Sắp xếp theo tỷ lệ thắng giảm dần
    sort(sorted_players.begin(), sorted_players.end(), [](const Player& a, const Player& b) {
        return a.win_rate > b.win_rate;
    });

    // In bảng xếp hạng
    cout << "\n======================= FINAL LEADERBOARD PVE ========================\n";
    cout << left << setw(10) << "Rank" 
         << setw(15) << "Participant" 
         << setw(15) << "Games Played" 
         << setw(10) << "Wins" 
         << setw(12) << "Win Rate (%)" << endl;

    for (size_t i = 0; i < sorted_players.size(); ++i) {
        const Player& player = sorted_players[i];
        cout << left << setw(10) << (i + 1) 
             << setw(15) << (player.number == 2 ? "Bot" : "Player ")
             << setw(15) << player.total_games 
             << setw(10) << player.wins 
             << setw(12) << fixed << setprecision(2) << player.win_rate << endl;
    }
    cout << "=======================================================================\n";
}


// Hàm in leaderboard xếp hạng người chơi dựa trên tỷ lệ thắng
void leaderboard(const vector<Player>& players) 
{
    // Tạo bản sao danh sách người chơi để sắp xếp
    vector<Player> sorted_players = players;

    // Sắp xếp theo tỷ lệ thắng giảm dần
    sort(sorted_players.begin(), sorted_players.end(), [](const Player& a, const Player& b) {
        return a.win_rate > b.win_rate;
    });

    // In bảng xếp hạng
     cout << "\n=========================== LEADERBOARD ==============================\n";
    cout << left << setw(10) << "Rank" 
         << setw(15) << "Player No." 
         << setw(15) << "Games Played" 
         << setw(10) << "Wins" 
         << setw(12) << "Win Rate (%)" << endl;

    for (size_t i = 0; i < sorted_players.size(); ++i) {
        const Player& player = sorted_players[i];
        cout << left << setw(10) << (i + 1) 
             << setw(15) << player.number 
             << setw(15) << player.total_games 
             << setw(10) << player.wins 
             << setw(12) << fixed << setprecision(2) << player.win_rate << endl;
    }
    cout << "=======================================================================\n";
}

//Hàm in leaderboard cuối cùng xếp hạng người chơi dựa trên tỷ lệ thắng
void final_leaderboard(const vector<Player>& players) 
{
    // Tạo bản sao danh sách người chơi để sắp xếp
    vector<Player> sorted_players = players;

    // Sắp xếp theo tỷ lệ thắng giảm dần
    sort(sorted_players.begin(), sorted_players.end(), [](const Player& a, const Player& b) {
        return a.win_rate > b.win_rate;
    });

    // In bảng xếp hạng
    cout << "\n======================== FINAL LEADERBOARD ========================\n";
    cout << left << setw(10) << "Rank" 
         << setw(15) << "Player No." 
         << setw(15) << "Games Played" 
         << setw(10) << "Wins" 
         << setw(12) << "Win Rate (%)" << endl;

    for (size_t i = 0; i < sorted_players.size(); ++i) {
        const Player& player = sorted_players[i];
        cout << left << setw(10) << (i + 1) 
             << setw(15) << player.number 
             << setw(15) << player.total_games 
             << setw(10) << player.wins 
             << setw(12) << fixed << setprecision(2) << player.win_rate << endl;
    }
    cout << "===================================================================\n";
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
    cout << "=== PvP Mode (Player vs. Player) Guide ===\n";
    cout << "Description:\n";
    cout << "  + PvP mode allows two players to compete directly against each other.\n";
    cout << "    Each player takes turns to play their move.\n\n";

    cout << "Instructions:\n";
    cout << "  + When entering PvP mode, enter the number of players (from 2 to 10).\n";
    cout << "  + The computer will randomly distribute cards to each player.\n";
    cout << "  + The computer will automatically calculate and find the strongest hand for each player.\n";
    cout << "  + The computer will automatically determine the winner.\n";
    cout << "  + Players with the strongest hand will win and receive 1 point.\n";
    cout << "  + The computer will automatically update the players' information.\n";
    cout << "  + The computer will display the current round's Leaderboard sorted by win rate.\n";
    cout << "  + The game has no limit on the number of rounds.\n";
    cout << "  + The game ends when players decide to stop playing.\n";
    cout << "  + The computer will display the final Leaderboard.\n\n";
}

// Hàm in hướng dẫn chơi chế độ PvE
void printPvEGuide() {
    cout << "=== PvE Mode (Player vs. Environment) Guide ===\n";
    cout << "Description:\n";
    cout << "  + PvE mode allows a player to compete against the computer (AI/Bot) designed by the Triple_Star team.\n";
    cout << "    This is a great way to practice or have fun without a human opponent.\n\n";

    cout << "Instructions:\n";
    cout << "  + When entering PvE mode, the player will be asked to select the bot difficulty level:\n";
    cout << "      Lv1 - Normal: Basic difficulty, the bot plays like a regular player.\n";
    cout << "                    (Bot win rate: ~60%)\n";
    cout << "      Lv2 - Challenge: Challenging difficulty, the bot plays at an expert level.\n";
    cout << "                    (Bot win rate: ~70%)\n";
    cout << "      Lv3 - Legendary: Extremely high difficulty, the bot plays like a Poker champion.\n";
    cout << "                    (Bot win rate: ~80%)\n";
    cout << "  + The computer will randomly distribute cards.\n";
    cout << "  + The computer will automatically calculate and find the strongest hands for both the bot and the player, then display them.\n";
    cout << "  + The computer will automatically determine the winner.\n";
    cout << "  + Whoever has the strongest hand wins and receives 1 point.\n";
    cout << "  + The computer will automatically update the player's information.\n";
    cout << "  + The computer will display the current round's Leaderboard sorted by win rate.\n";
    cout << "  + The game has no limit on the number of rounds.\n";
    cout << "  + The game ends when the player decides to stop playing.\n";
    cout << "  + The computer will display the final Leaderboard.\n\n";
}

// In ASCII Art Poker
    void printASCIIPoker() {
    cout << "  _____      _             \n";
    cout << " |  __ \\    | |            \n";
    cout << " | |__) |__ | | _____ _ __ \n";
    cout << " |  ___/ _ \\| |/ / _ \\ '__|\n";
    cout << " | |  | (_) |   <  __/ |   \n";
    cout << " |_|   \\___/|_|\\_\\___|_|   \n";
    cout << "                           \n";
    cout << "                           \n";
}


// In hướng dẫn chơi chế độ Single Card Duel
#include <iostream>
using namespace std;

void printSingleCardDuelGuide()
{
    cout << "\nSingle Card Duel:\n\n";

    cout << "    Description:\n";
    cout << "        + Single Card Duel mode allows two players to compete directly.\n";
    cout << "        + Each player will receive 1 card.\n";
    cout << "        + The player(s) with the strongest card will win the round.\n\n";

    cout << "    Gameplay Instructions:\n";
    cout << "        + Enter the number of players:\n";
    cout << "            At the start of PvP mode, players enter the number of participants (from 2 to 10).\n";
    cout << "        + Random card distribution:\n";
    cout << "            The system will randomly deal a card to each player.\n";
    cout << "        + After the cards are dealt:\n";
    cout << "            The system will determine the strongest card and display the result.\n";
    cout << "        + Players with the strongest card will win the round and receive 1 point.\n";
    cout << "        + If multiple players have the strongest card, they will all receive 1 point.\n";
    cout << "        + The system will automatically update player scores after each round.\n";
    cout << "        + A temporary Leaderboard will be displayed, sorted by win rate, to track progress.\n";
    cout << "        + Unlimited rounds:\n";
    cout << "            The game continues until players decide to stop.\n";
    cout << "        + At the end of the game:\n";
    cout << "            The system will display the final Leaderboard with overall results.\n\n";

    cout << "    Card Comparison Rules:\n";
    cout << "        + Standard 52-card deck.\n";
    cout << "        + Higher card ranks follow the order: 2 < 3 < ... < 10 < J < Q < K < A.\n";
    cout << "        + If two cards have the same rank:\n";
    cout << "            Suit comparison applies: Spades (♠) > Hearts (♥) > Diamonds (♦) > Clubs (♣).\n";
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