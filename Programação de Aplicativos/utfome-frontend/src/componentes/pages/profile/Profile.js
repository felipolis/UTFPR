
import Footer from '../../layout/footer/Footer';
import Header from '../../layout/header/Header';
import './Profile.css';

import React, { useContext } from 'react';
import { AuthContext } from '../../../contexts/auth';

function Profile(){

    const { authenticated, logout } = useContext(AuthContext);


    const handleLogout = () => {
        logout();
    }

    
    return (
        <>
            <p>{String(authenticated)}</p>
            <button onClick={handleLogout}>LOOOOOOOGOUT</button>
            <h1>PERFIL</h1>
            <h1>PERFIL</h1>
            <h1>PERFIL</h1>
            <h1>PERFIL</h1>
            <h1>PERFIL</h1>
            <h1>PERFIL</h1>
            <h1>PERFIL</h1>
            
        </>
    )
}

export default Profile;

