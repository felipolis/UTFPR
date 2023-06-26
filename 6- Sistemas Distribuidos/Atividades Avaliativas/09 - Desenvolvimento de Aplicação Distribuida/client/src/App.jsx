import { BrowserRouter, Route, Routes } from "react-router-dom";
import './App.css';
import HomePage from "./pages/HomePage";
import ChatPage from "./pages/ChatPage";

function App() {


  return (
    <div className="App">
        <Routes>
          <Route path="/" element={<HomePage />}/>
          <Route path="/chats" element={<ChatPage />}/>
        </Routes>
    </div>
  );
}

export default App;
