import json
import time
from itertools import product
from stockfish import Stockfish


def get_board_plays(path):
    with open(path) as f:
        plays = json.loads(f.read())
    return plays


def get_moves_list(plays):
    moves = []
    for play in plays[1:]:
        original_state = play['JogadaAtualAntigaPosicao']
        future_state = play['JogadaAtualNovaPosicao']
        moves.append(
            encode_position(original_state, BOARD) +
            encode_position(future_state, BOARD)
        )
    return moves


def available_moves(plays):
    moves = list()
    last_play = plays[-1]
    for piece in last_play['DetalhesPecas']:
        current_position = encode_position(piece['PosicaoAtual'], BOARD)
        for action in piece['CaminhosPossiveis']:
            moves.append(current_position + encode_position(action, BOARD))
    return moves


def define_board_notation():
    board = list()
    columns = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
    rows = ['1', '2', '3', '4', '5', '6', '7', '8']
    board_arr = list(product(columns, rows))
    board_arr = sorted(board_arr, key=lambda x: x[1], reverse=True)
    for position in board_arr:
        board.append(position[0] + position[1])
    return board


def encode_position(position, ref: list):
    position = int(position)
    return ref[position - 1]


def decode_position(position: str, ref: list):
    return ref.index(position) + 1


def get_top_moves(n):
    top_moves = []
    engine_top_moves = STOCKFISH.get_top_moves(n)
    for move in engine_top_moves:
        top_moves.append(move['Move'])
    return top_moves


if __name__ == '__main__':
    
    print(0000)
    eval = {}
    BOARD = define_board_notation()
    plays = get_board_plays('C:\\Users\\User\\Desktop\\Galaxian\\Chess\\Unreal\\ZooChess\\InfoPartida.json')[:-1]
    moves = get_moves_list(plays)
    avai_moves = available_moves(plays)
    
    print(111)

    STOCKFISH = Stockfish('stockfish.exe')
    STOCKFISH.set_position(moves)
    top_moves = get_top_moves(10)
    
    print(333)
    
    #for count in range(3):
        #print(time.ctime())
        # Prints the current time with a five second difference
        #time.sleep(2.5)

    if len(top_moves) < 1:
        eval['next_move'] = ''
    else:
        next_move = top_moves[0]
        current_postition = decode_position(next_move[0:2], BOARD)
        next_postition = decode_position(next_move[2:4], BOARD)
        eval['next_move'] = {'current_position': current_postition,
                             'next_position': next_postition}

    eval = json.dumps(eval)
    with open('C:\\Users\\User\\Desktop\\Galaxian\\Chess\\Unreal\\ZooChess\\next_move.json', 'w') as f:
        json.dump(eval, f)

    # input("Press enter to exit ;)")
