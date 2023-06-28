import './App.css';
import React, { useEffect } from 'react';

export default function Card(props) {
    const {index, content, date, handleDelete, updatePrice} = props;
    
    const regex = /(\d+)\s*(.*?)\s*(\d+)$/; // Regular expression pattern
    const match = content.match(regex); // Use match() to extract values
    // if (!content || !date || !match) {
    //     return null;
    // }

    const [_, hour, title, price] = match;
    const total = hour * price;

    useEffect(() => {
        updatePrice(total, '+'); // Call updatePrice when the Card component is created
        return () => {
          updatePrice(total, '-'); // Call updatePrice when the Card component is destroyed
        };
      }, [total, updatePrice]);


    return (
        <>
            <div className='Card'>
                <div className='leftCard'>
                    <div className='topCard' style={{ background: '', height: '50%' }}>
                        {title}
                    </div>
                    <div className='bottomCard' style={{ background: '', height: '50%' }}>
                        {date} {hour}hr * {price}€
                    </div>
                </div>
                <button className='rightCard' style={{ background: 'green' }}  onClick={() => handleDelete(index, price)}>
                    {total}
                </button>
            </div>
        </>
    )
}