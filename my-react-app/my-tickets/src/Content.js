import './App.css';
import React, { useState, useMemo } from 'react';
import RightN from './NavRight';
import Card from './Card';

export default function Content() {
    const [inputValue, setInputValue] = useState('');
    const [dataArray, setDataArray] = useState([]);
    const [totalIncome, setTotalIncome] = useState(0);
    const [currentDate, setCurrentDate] = useState(new Date());

    const parser = useMemo(() => {
        return currentDate.toLocaleDateString('es-ES', { year: 'numeric', day: '2-digit', month: '2-digit' }).slice(0, -5);
      }, [currentDate]);
    

    const handleDate = (i) => {
        const newDate = new Date(currentDate);
        if (i === '-')
            newDate.setDate(newDate.getDate() - 1);
        else if (i === '+')
            newDate.setDate(newDate.getDate() + 1);
        setCurrentDate(newDate);
    };

    const handleChange = (e) => {
        const value = e.target.value;
        setInputValue(value);
        if (e.key === 'Enter' || e.type === 'click') {
            setDataArray((prevArray) => [...prevArray, value]);
            setInputValue('');
        }
    };

    const updatePrice = (value, operation) => {
        if (operation === '+')
            setTotalIncome((prevIncome) => prevIncome + value);
        else if (operation === '-')
            setTotalIncome((prevIncome) => prevIncome - value);
    };

    const handleDelete = (index, price) => {
        setDataArray((prevArray) => prevArray.filter((_, i) => i !== index));
        updatePrice(price, '-');
    };

    const createDiv = (a, b, date) => {
        console.log(date);
        return (
            <div key={a} id="inputRow">
                <Card content={b} date={date} handleDelete={() => handleDelete(a, 0)} updatePrice={updatePrice} index={a} />
            </div>
        );
    };

    return (
        <>
            <div className='Content'>
                <div className='Wrapper'>
                    <div className='Time'>
                        <button onClick={() => handleDate('-')}>-</button>
                        {parser}
                        <button onClick={() => handleDate('+')}>+</button>
                    </div>
                    <div id="inputText">
                        <input type="text" id="inputParam" placeholder="HR TITLE €" value={inputValue} onChange={handleChange} onKeyDown={handleChange} />
                    </div>
                    <RightN price={totalIncome} />
                </div>
                <div>
                    {dataArray.map((item, index) =>
                        createDiv(index, item, parser))}
                        </div>

            </div>
        </>
    );
}


