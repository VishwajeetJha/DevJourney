class TicTacToe:
    def __init__(self):
        self.board = [' ' for _ in range(9)]  # A list to hold the board state
        self.current_player = 'X'  # Starting player

    def print_board(self):
        # Print the current state of the board
        print(f"{self.board[0]} | {self.board[1]} | {self.board[2]}  | 0 | 1 | 2")
        print("---------")
        print(f"{self.board[3]} | {self.board[4]} | {self.board[5]}  | 3 | 4 | 5")
        print("---------")
        print(f"{self.board[6]} | {self.board[7]} | {self.board[8]}  | 6 | 7 | 8")
        print()  # Add an empty line for better readability

    def check_winner(self):
        # Winning combinations
        winning_combinations = [
            (0, 1, 2), (3, 4, 5), (6, 7, 8),  # Rows
            (0, 3, 6), (1, 4, 7), (2, 5, 8),  # Columns
            (0, 4, 8), (2, 4, 6)              # Diagonals
        ]

        for combo in winning_combinations:
            if self.board[combo[0]] == self.board[combo[1]] == self.board[combo[2]] != ' ':
                return self.board[combo[0]]

        return None

    def is_draw(self):
        return ' ' not in self.board

    def make_move(self, position):
        if self.board[position] == ' ':
            self.board[position] = self.current_player
            winner = self.check_winner()
            if winner:
                self.print_board()
                print(f"Player {winner} wins!")
                return True
            if self.is_draw():
                self.print_board()
                print("It's a draw!")
                return True
            self.current_player = 'O' if self.current_player == 'X' else 'X'
        else:
            print("Invalid move. Try again.")
        return False

    def play(self):
        while True:
            self.print_board()
            try:
                position = int(input(f"Player {self.current_player}, enter your move (0-8): "))
                if position < 0 or position > 8:
                    print("Invalid position. Enter a number between 0 and 8.")
                    continue
            except ValueError:
                print("Invalid input. Please enter a number.")
                continue

            if self.make_move(position):
                break


if __name__ == "__main__":
    game = TicTacToe()
    game.play()
