import React from 'react';
import './Login.css';
import logo from '../../../assets/images/Logo_grande.png';
import { useState, useContext } from 'react';
import { AuthContext } from '../../../contexts/auth';

const Login = () => {
    const { authenticated, login } = useContext(AuthContext);

    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');

    const handleSubmit = (e) => {
        e.preventDefault();
        console.log("Submitted", { email, password });
        login(email, password);
    }

    return (
        <div className='container'>
            <div className='container-login'>
                <div className='wrap-login'>
                    <form 
                    className='login-form' 
                    onSubmit={handleSubmit}>
                        {/* <p>{String(authenticated)}</p> */}
                        <span className='login-form-title'>
                            <img src={logo}></img>
                        </span>

                        <div className='wrap-input'>
                            <input 
                            className={email !== '' ? 'has-val input' : 'input'}
                            type="email"
                            value={email}
                            onChange={e => setEmail(e.target.value)} />
                            <span className='focus-input' data-placeholder="Email"></span>
                        </div>

                        <div className='wrap-input'>
                            <input 
                            className={password !== '' ? 'has-val input' : 'input'} 
                            type="password"
                            value={password}
                            onChange={e => setPassword(e.target.value)} />
                            <span className='focus-input' data-placeholder="Password"></span>
                        </div>

                        <div className='container-login-form-btn'>
                            <button className='login-form-btn'>
                                Login
                            </button>
                        </div>

                        <div className='text-center'>
                            <span className='txt1'>
                                Nao possui conta?
                            </span>

                            <a href='#' className='txt2'>
                                Criar conta
                            </a>
                        </div>
                    </form>
                </div>
            </div>
        </div>
    )
}

export default Login;