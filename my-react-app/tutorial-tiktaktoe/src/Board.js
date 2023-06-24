import './App.css';
import { useState } from 'react';


function Square({ value, onSquareClick }) {

    return (
        <button className='square' onClick={onSquareClick}>
            {value}
        </button>

    );
}

function calculateWinner(squares) {
    const possibilities = [
        [0, 1, 2],
        [3, 4, 5],
        [6, 7, 8],
        [0, 3, 6],
        [1, 4, 7],
        [2, 5, 8],
        [0, 4, 8],
        [2, 4, 6]
    ];

    for (let i = 0; i < possibilities.length; i++) {
        const [a, b, c] = possibilities[i];
        if (squares[a] && squares[a] === squares[b] && squares[a] === squares[c])
            return (squares[a]);
    }
    return null;
}


export default function Board() {
    const [xisNext, setXIsNext] = useState(true);
    const [squares, setSquares] = useState(Array(9).fill(null));
    

    const winner = calculateWinner(squares);
    let status;
    if (winner)
        status = "Winner Weener: " + winner;
    else
        status = "Next P: " + (xisNext ? "X" : "O");

    function handleClick(i) {
        if (calculateWinner(squares)) {
            console.log("end");
            return;
        }
        const nextSquare = squares.slice();
        if (nextSquare[i] == null) {
            if (xisNext)
                nextSquare[i] = 'X';
            else
                nextSquare[i] = 'O';
            setXIsNext(!xisNext);
        }
        console.log("clocked", nextSquare);
        setSquares(nextSquare);
    }

    return (
        <>
            <div className='statusHeader'>{status}</div>
            <div>
                <Square value={squares[0]} onSquareClick={() => handleClick(0)} />
                <Square value={squares[1]} onSquareClick={() => handleClick(1)} />
                <Square value={squares[2]} onSquareClick={() => handleClick(2)} />
            </div>
            <div>
                <Square value={squares[3]} onSquareClick={() => handleClick(3)} />
                <Square value={squares[4]} onSquareClick={() => handleClick(4)} />
                <Square value={squares[5]} onSquareClick={() => handleClick(5)} />
            </div>
            <div>
                <Square value={squares[6]} onSquareClick={() => handleClick(6)} />
                <Square value={squares[7]} onSquareClick={() => handleClick(7)} />
                <Square value={squares[8]} onSquareClick={() => handleClick(8)} />
            </div>
        </>
    )
}
