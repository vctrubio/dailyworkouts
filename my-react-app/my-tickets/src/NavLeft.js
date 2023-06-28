import './App.css';


//show date. click to change date if u want
export default function LeftN()
{
    const currentDate = new Date().toLocaleDateString();

    return (
        <>
        {currentDate} 
        </>
    )
};