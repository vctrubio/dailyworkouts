import './App.css';
import { useState } from 'react';

function Square({ arg }) {
    const [value, setValue] = useState(null);

    function handleBitch() {
        console.log('clicked ', arg);
        setValue(value === 'X' ? '': 'X');
    }

    return (
        <button className='square'onClick={handleBitch}>
            {value}
        </button>

    );
}

export default function Board() {
    return (
        <>
            <div>
                <Square arg={1} />
                <Square  />
                <Square arg={3} />
            </div>
            <div>
                <Square arg={4} />
                <Square arg={5} />
                <Square arg={6} />
            </div>
            <div>
                <Square arg={7} />
                <Square arg={8} />
                <Square arg={9} />
            </div>
        </>
    )
}
