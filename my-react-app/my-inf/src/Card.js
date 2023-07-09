import './App.css';

export default function Card(props)
{
    function handleClick(event) {
        const card = event.target;
        card.classList.toggle('active');
      }
      
    return <div className='Carding' onClick={handleClick}>
        <div className='headerCard'>
        </div> {props.title}
        <div>Body</div>
    </div>
}