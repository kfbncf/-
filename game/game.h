#define row 3
#define col 3

void Initboard(char board[row][col],int row1,int col1);
void DisplayBpard(char board[row][col], int row1, int col1);
void PlayerMove(char board[row][col], int row1, int col1);
void PCMove(char board[row][col], int row1, int col1);
char Iswin(char board[row][col], int row1, int col1);
int IsFull(char board[row][col], int row1, int col1);