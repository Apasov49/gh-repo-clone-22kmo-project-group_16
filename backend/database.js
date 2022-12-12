const mysql = require('mysql');
const dotenv = require('dotenv');
dotenv.config();
const connection = mysql.createPool({
    host: '127.0.0.1',
    user: 'root',
    password: 'Bias@1706',
    database: 'group_16'
  });
module.exports = connection;