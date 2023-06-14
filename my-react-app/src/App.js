import './App.css';
import React, { useState } from 'react';

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
		<a>
			<h1>Name: Johno</h1>
			<h2>Age: 35</h2>
		</a>

	)

}

export default function App() {
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
		</div>
	);

}

