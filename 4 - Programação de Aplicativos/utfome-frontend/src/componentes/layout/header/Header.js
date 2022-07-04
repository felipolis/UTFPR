import './Header.css';
import logo from '../../../assets/images/Logo_grande.png';

import { FaBars } from 'react-icons/fa';
import { useContext } from 'react';
import { AuthContext } from '../../../contexts/auth';

function Header(){

    const { authenticated } = useContext(AuthContext);

    function openMenu(){
        let navbar = document.querySelector('.navbar');
        navbar.classList.toggle('active');
    }
    
    window.onscroll = () =>{
        let navbar = document.querySelector('.navbar');
        navbar.classList.remove('active');
    }

    return (
            <header className='header'>

                <a href='#' className='logo'>
                    <img src={logo}></img>
                </a>

                <nav className='navbar'>
                    <a href='#home'>home</a>
                    <a href='#produtos'>produtos</a>
                    <a href='#anunciar'>anunciar</a>
                    <a href='#sobre'>sobre</a>
                    <a href='#contato'>contato</a>
                    <a href='#conta'>perfil</a>
                </nav>

                <div className='icons'>
                    <div id='menu-btn' onClick={openMenu}>
                        <FaBars />
                    </div>
                </div>

            </header>
    );
}

export default Header;