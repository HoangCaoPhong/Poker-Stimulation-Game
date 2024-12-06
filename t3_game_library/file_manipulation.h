#pragma once

//====================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================
//Mô tả: Thư viện này bao gồm các hàm liên quan đến việc nhập xuất file

//Hướng dẫn sử dụng: 
    //Để sử dụng các hàm trong thư viện này, bạn cần include thư viện này vào file của mình bằng cách thêm dòng lệnh sau:
    //#include "file_manipulation.h"

//Thư viện này bao gồm:

    // Hàm xóa nội dung file
    void clear_file();
    
    // Hàm lưu dữ liệu trò chơi vào file
    void save_game_data_to_file(const std::string& mode, const std::vector<Player>& players);
    

//====================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================

//Hàm xóa nội dung file
void clear_file() {
    std::ofstream file("Data_Game.txt", std::ios::trunc); // Mở file ở chế độ trunc
    if (file.is_open()) {
        file.close();
    } else {
        std::cout << "Unable to open file for clearing." << std::endl;
    }
}

// Hàm lưu dữ liệu trò chơi vào file và hiển thị bảng xếp hạng
void save_game_data_to_file(const std::string& mode, const std::vector<Player>& players) {
    // Tạo một file game_data.txt để lưu dữ liệu
    std::ofstream outfile("Data_Game.txt", std::ios::app); // Mở file ở chế độ thêm (append)

    if (outfile.is_open()) {
        // Lưu tên chế độ chơi
        outfile << "Game Mode: " << mode << std::endl;

        // Lưu thông tin người chơi
        outfile << "Players: " << std::endl;
        for (const auto& player : players) {
            outfile << "Player #" << player.number << std::endl;
            outfile << "Total Games: " << player.total_games << std::endl;
            outfile << "Wins: " << player.wins << std::endl;
            outfile << "Win Rate: " << player.win_rate << "%" << std::endl;
            
            // Lưu các tình huống thắng (card value & suit)
            outfile << "Win Situations: " << std::endl;
            for (const auto& situation : player.win_situations) {
                outfile << "  " << situation.first << ": " << situation.second << " times" << std::endl;
            }
            outfile << "-------------------------" << std::endl;
        }

        // Tạo bản sao danh sách người chơi để sắp xếp
        std::vector<Player> sorted_players = players;

        // Sắp xếp theo tỷ lệ thắng giảm dần
        std::sort(sorted_players.begin(), sorted_players.end(), [](const Player& a, const Player& b) {
            return a.win_rate > b.win_rate;
        });

        // Lưu bảng xếp hạng vào file
        outfile << "\n======================== FINAL LEADERBOARD ========================\n";
        outfile << std::left << std::setw(10) << "Rank" 
                << std::setw(15) << "Player No." 
                << std::setw(15) << "Games Played" 
                << std::setw(10) << "Wins" 
                << std::setw(12) << "Win Rate (%)" << std::endl;

        for (size_t i = 0; i < sorted_players.size(); ++i) {
            const Player& player = sorted_players[i];
            outfile << std::left << std::setw(10) << (i + 1) 
                    << std::setw(15) << player.number 
                    << std::setw(15) << player.total_games 
                    << std::setw(10) << player.wins 
                    << std::setw(12) << std::fixed << std::setprecision(2) << player.win_rate << std::endl;
        }
        outfile << "===================================================================\n\n\n";

        outfile.close();
    
    } else {
        std::cout << "Unable to open file for saving game data." << std::endl;
    }
}