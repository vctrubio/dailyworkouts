import './App.css';
import { useState } from 'react';

export default function NavBar() {
    const [isHovered, setIsHovered] = useState(false);

    const handleMouseEnter = () => {
        setIsHovered(true);
    };

    const handleMouseLeave = () => {
        setIsHovered(false);
    };

    const handleDivClick = () => {
        window.open('tel:+34692610111');
    };

    return (
        <div className={`Nav ${isHovered ? 'hovered' : ''}`}
            onMouseEnter={handleMouseEnter}
            onMouseLeave={handleMouseLeave}
            onClick={handleDivClick}
        >
            {!isHovered && <p className='Title'>Promeco</p>}
            {isHovered && <p>629 610 111</p>}
        </div>
    );
}