import './App.css';

// import Board from './Board';
import Box from './Box';


export default function App() {
  return (
    <div className="App">
      <header className="App-header">
        <div className='inline'>
          <p>
            Hello tikitaktoe
          </p>
          <Box />
        </div>
      </header>
    </div>
  );
}

