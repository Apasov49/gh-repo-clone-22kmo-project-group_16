const mysql = require('mysql');
const dotenv = require('dotenv');
dotenv.config();
const connection = mysql.createPool({
    host: '127.0.0.1',
    user: 'root',
    password: 'root',
    database: 'group_16'
  });
module.exports = connection;