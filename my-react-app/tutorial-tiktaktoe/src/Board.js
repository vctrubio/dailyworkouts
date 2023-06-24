import './App.css';

function Square({ arg }) {
    function handleClick() {
        console.log('clicked ', arg);
    }

    return (
        <button 
            className='square'
            onClick={handleClick}
        >
            {arg}
        </button>

    );
}

export default function Board() {
    return (
        <>
            <div>
                <Square arg={1} />
                <Square arg={2} />
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
