#include "t3_game_library/t3_library.h"

int main() 
{
    // Khởi tạo seed cho hàm random
    std::srand(std::time(0));  
    
    // In ASCII Art Poker
    printASCIIPoker();

    std::cout << std::endl;

    // Khởi tạo danh sách người chơi
    std::vector<Player> players;

    bool continue_game = true;
    bool first_game = true;

    // Tiến hành các vòng chơi cho đến khi người chơi muốn dừng
    while (continue_game) {

        // kiểm tra có phải lần đầu chơi không
        if (first_game) {
            select_game_mode(players);
            first_game = false;
        } 
        
        else {
            // Hỏi người chơi có muốn tiếp tục chơi không
            if (ask_to_choose_mode_again()) {
                select_game_mode(players);
            } else {
                // Nếu không, hỏi người chơi có muốn chơi tiếp không
                continue_game = ask_to_continue();
            }
        }
    }

    std::cout << "Thanks for playing! See you next time." << std::endl;

    return 0;
}
