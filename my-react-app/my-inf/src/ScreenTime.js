import './App.css';
import Card from './Card';

export default function ScreenTime()
{
    const cards= [];

    for (let i = 1; i <= 6; i++)
        cards.push(<Card title={`${i}`} />)
    return <div className='ScrenTime'>
        {cards}
    </div>
}