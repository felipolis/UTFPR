import {
    BrowserRouter as Router,
    Route,
    Routes,
    Navigate,
} from 'react-router-dom';

import React, { useContext } from 'react';

import Footer from './componentes/layout/footer/Footer';
import Header from './componentes/layout/header/Header';
import About from './componentes/pages/about/About';
import Review from './componentes/pages/review/Review';
import Home from './componentes/pages/home/Home';
import Contact from './componentes/pages/contact/Contact';
import Produto from './componentes/components/produto/Produto';
import Login from './componentes/pages/login/Login';
import Announce from './componentes/pages/announce/Announce';
import Profile from './componentes/pages/profile/Profile';

import { AuthProvider, AuthContext } from './contexts/auth';
import Register from './componentes/pages/register/Register';

const AppRoutes = () => {
    const Private = ({ children }) => {
        const { authenticated, loading } = useContext(AuthContext);

        if (loading) {
            return <div>Carregando...</div>
        }

        if (!authenticated) {
            return (
                <Navigate to="/login" />
            );
        }

        return children;
    }

    const PrivateForNoAuth = ({ children }) => {
        const { authenticated, loading } = useContext(AuthContext);

        if (loading) {
            return <div>Carregando...</div>
        }

        if (authenticated) {
            return (
                <Navigate to="/perfil" />
            );
        }

        return children;
    }

    return(
        <Router>
            <AuthProvider>
                <Routes>

                    {/* ##### APENAS USUARIOS AUTENTICADOS PODEM ACESSAR #####*/}
                    <Route exact path="/anunciar" element={
                        <Private>
                            <Announce />
                        </Private>
                    } />

                    <Route exact path="/perfil" element={
                        <Private>
                            <Profile />
                        </Private>
                    } />




                    {/* ##### APENAS USUARIOS NAO AUTENTICADOS PODEM ACESSAR #####*/}
                    <Route exact path="/login" element={
                        <PrivateForNoAuth>
                            <Login />
                        </PrivateForNoAuth>
                
                    } />

                    <Route exact path="/register" element={
                        <PrivateForNoAuth>
                            <Register />
                        </PrivateForNoAuth>
                    } />




                    {/* ############### ROTAS GERAIS ###############*/}
                    <Route exact path="/contato" element={<Contact />} />
                    <Route exact path="/review" element={<Review />} />
                    <Route exact path="/sobre" element={<About />} />
                    <Route exact path="/" element={<Home />} />
                    {/* <Route exact path="/main" element={<Main />} /> */}


                </Routes>
            </AuthProvider>
        </Router>
    )
}




export default AppRoutes;