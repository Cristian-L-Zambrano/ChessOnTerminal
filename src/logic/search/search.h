#ifndef SEARCH_H
#define SEARCH_H
#include "movement.h"
#include "move.h"
#include "board.h"

class Search {
  public:
    explicit Search(Board* board);
    virtual ~Search();
    Move search_best_move();
    int evaluate_board();

  private:
    bool time_out();
    void pick_next_move(int index, MoveList*);
    void clear_for_seach();
    void generate_moves(MoveList*);
    void generate_all_cap_moves(MoveList*);
    int negamax(int deapth, int alpha, int beta);
    int quiescence_search(int alpha, int beta);
    int is_repeated_move(const int& depth, int* alpha, int* beta);
    Move root_negamax(int cur_depth);
    TTEntry::Flag get_flag(int alpha, int orig_alpha, int beta);

    Movement* movement = nullptr;
    Board* p_board = nullptr;
    bool has_black_pieces = false;
    bool m_stop = false;
    int total_nodes = 0;
    std::chrono::time_point<std::chrono::steady_clock> m_start;
    // int m_time_allocated = 4000;
    int m_time_allocated = 1500;
    int m_elapsed = 0;
};

#endif /* SEARCH_H */
