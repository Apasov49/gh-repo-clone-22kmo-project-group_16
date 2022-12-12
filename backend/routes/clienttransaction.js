const express = require('express');
const router = express.Router();
const transaction = require('../models/transaction_model');

//This will look for the first 10 transactions
router.get('/:id', function(request,response){
    const id=request.params.id;
    transaction.getTransactions(id,function(err,dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult);
        }
    })

});

module.exports=router;