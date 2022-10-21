const Joi = require('joi');
Joi.objectId = require('joi-objectid')(Joi);
const mongoose = require('mongoose');
const genres = require('./routes/genres');
const customers = require('./routes/customers');
const movies = require('./routes/movies');
const rentals = require('./routes/rentals');
require('dotenv').config();
const express = require('express');
const app = express();

const MONGO_URI=process.env.MONGO_URI;

app.get("/", (req,res)=>{
  res.send("Hello, Welcome to movie service by Saurav")
});
app.use(express.json());
app.use('/api/genres', genres);
app.use('/api/customers', customers);
app.use('/api/movies', movies);
app.use('/api/rentals', rentals);

const port = process.env.PORT || 3000;
mongoose.connect(MONGO_URI, {useUnifiedTopology: true, useNewUrlParser: true})
  .then(() => {   //first connect to DB
    console.log('Connected to MongoDB...');
    //then start to listen
    app.listen(port, ()=>console.log(`App is listening on port ${port}`));
  })
  .catch(err => console.log(err));