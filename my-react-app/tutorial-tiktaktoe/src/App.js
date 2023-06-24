import './App.css';

import Board from './Board';

/*
function Square(value, onSquareClick)
function Board(xisNext, square, onPlay)
function CalculateWinner()
export function Game()
*/

export default function App() {
  return (
    <div className="App">
      <header className="App-header">
        <p>
          Hello tikitaktoe
        </p>
        <Board/>
      </header>
    </div>
  );
}

