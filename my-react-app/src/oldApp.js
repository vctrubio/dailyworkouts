import logo from './logo.svg';
import './App.css';

function App2() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Edit <code>src/App.js</code> and save to reload.
        </p>
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
      </header>
    </div>
  );
}


/*
function App() {
  return (
	<div className="App">
	  <body className="App-header">
		<p>
		 Hello Tano
		</p>
	  </body>
	</div>
  );
}
*/

function Person() {
	return (
		<>
			<h1>Name: Johno</h1>
			<h2>Age: 35</h2>
		</>

	)
}

export default function App3() {
	let count = 0;

	const [counter, setCounter] = useState(24);

	return (
		<div className="App">
			<h1>
				Hello {counter} !
			</h1>
			<br></br>
			<button onClick={() => setCounter((i) => --i)}>
				-
			</button>
			<button onClick={() => setCounter((i) => ++i)}>
			+</button>

			<br></br>
			<br></br>
			<br></br>
			<br></br>
			<br></br>
			<Person/>
		</div>
	);

}

