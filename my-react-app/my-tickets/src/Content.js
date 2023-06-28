import './App.css';
import React, { useState } from 'react';
import LeftN from './NavLeft';
import RightN from './NavRight';
import Card from './Card';

export default function Content() {
    const [inputValue, setInputValue] = useState('');
    const [dataArray, setDataArray] = useState([]);
    const [totalIncome, setTotalIncome] = useState(0);

    const handleChange = (e) => {
        const value = e.target.value;
        setInputValue(value);
        if (e.key === 'Enter' || e.type === 'click') {
            setDataArray((prevArray) => [...prevArray, value]);
            setInputValue('');
        }
    };

    const updatePrice=(value, operation) =>{
        console.log("clicked", value, operation);
        if (operation == '+')
            setTotalIncome((prevIncome) => prevIncome + value);
        else if (operation == '-')
            setTotalIncome((prevIncome) => prevIncome - value);

    };

    const handleDelete = (index, price) => {
        setDataArray((prevArray) => prevArray.filter((_, i) => i !== index));
        updatePrice(price, '-');
    };

    const createDiv = (a, b) => {
        let tmp = 0;
        return (
          <div key={a} id="inputRow">
            <Card content={b} date="11.06" handleDelete={() => handleDelete(a, tmp)} updatePrice={updatePrice} index={a}/>
          </div>
        );
      };

    return (
        <>
            <div className='Content'>
                <div className='Wrapper'>
                    <LeftN />
                    <div id="inputText">
                        <input type="text" id="inputParam" placeholder="HR TITLE €" value={inputValue} onChange={handleChange} onKeyDown={handleChange} />
                    </div>
                    <RightN price={totalIncome}/>
                </div>
                <div>
                    {dataArray.map((item, index) => 
                    createDiv(index, item) )}
                </div>

            </div>
        </>
    );
}

//content needs to be sorted by date in ASC/DES