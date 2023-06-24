import './App.css';

import {useEffect} from 'react';


/*
Create a board,
let the box move inside the board,
create two pins and a ball
*/


export default function Box(){
    function handleKeyDown(event){
        console.log('key down', event);
    }

    useEffect(() =>{
        document.addEventListener("keydown",handleKeyDown)

        //for mem leaks.
        return () => {
            document.removeEventListener('keydown', handleKeyDown);
          };
    }, []);
    return (
        <div className="box flexy">
        </div>
    )
}