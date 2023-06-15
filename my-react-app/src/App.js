import './App.css';
import './AppClone.css';
import MovieCard from './MovieCard';
import { useEffect, useState } from 'react';

const API_URL = 'http://www.omdbapi.com?apikey=fca8be50';

// const tmpMovie = {
// 	"Title": "Superman, Spiderman or Batman",
// 	"Year": "2011",
// 	"imdbID": "tt2084949",
// 	"Type": "movie",
// 	"Poster": "https://m.media-amazon.com/images/M/MV5BMjQ4MzcxNDU3N15BMl5BanBnXkFtZTgwOTE1MzMxNzE@._V1_SX300.jpg"
// }

export default function App() {

	const [movies, setMovies] = useState([]);
	const [searchTerm, setSearchTerm] = useState(["henanash"]);

	const searchMovies = async (title) => {
		try {
			const response = await fetch(`${API_URL}&s=${title}`);
			if (!response.ok)
				throw new Error("Error RESPONSE");
			const data = await response.json();
			setMovies(data.Search);
		}
		catch (error) {
			console.error('ERROR101. ', error.message);
		}
	};

	useEffect(() => {
		searchMovies('hernan');
	}, []);

	const searchEnterKey = (e) => {
        if (e.key === 'Enter') {
            searchMovies(searchTerm)
        }
    }
	return (
		<>
			<div className="app">
				<h1>MovieLand</h1>
				<div className="search">
					<input
						placeholder="Search for movies"
						value={searchTerm}
						onChange={(e) => setSearchTerm(e.target.value)}
						onKeyDown={searchEnterKey}
					>
					</input>
				</div>
				{
					movies?.length > 0 ?
						(
							<div className="container">
								{movies.map((movie) => <MovieCard movie={movie} />)}
							</div>
						) :
						(
							<div className='empty'>
								<h2>No movies found</h2>
							</div>
						)
				}


			</div>
		</>
	);
}