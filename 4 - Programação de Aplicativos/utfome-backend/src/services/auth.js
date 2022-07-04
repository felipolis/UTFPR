const bcrypt = require('bcrypt');

exports.createPasswordHash = async (password) => {
    const salt = await bcrypt.genSalt(10);
    const hash = await bcrypt.hash(password, salt);
    return hash;
}

exports.checkPassword = (user, password) => {
    try {
        return bcrypt.compare(password, user.senha);
    } catch (error) {
        return false;
    }
}