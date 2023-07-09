import './App.css';
import NavBar from './NavBar';
import Page1 from './Page1';
import Page2 from './Page2';
import ScreenTime from './ScreenTime';

export default function App() {
  return (
    <div className="App">
      <NavBar/>
      {/* <Page1/> */}
      {/* <Page2/> */}
      <ScreenTime></ScreenTime>
    </div>
  );
}

