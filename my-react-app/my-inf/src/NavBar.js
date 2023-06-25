import './App.css';

export default function NavBar() {
    const scrollToPage = (pageId) => {
        const pageElement = document.getElementById(pageId);
        pageElement.scrollIntoView({ behavior: 'smooth' });
    };


    return (
        <nav className="NavBar">
            <button onClick={() => scrollToPage('page1')}>Page1</button>
            <button onClick={() => scrollToPage('page2')}>Page2</button>
        </nav>
    );
}