const fs = require('fs');
const Tour = require('./../models/tourModel');

// const tours = JSON.parse(
//   fs.readFileSync(`${__dirname}/../dev-data/data/tours-simple.json`)
// );

exports.getAllTours = async (req, res) => {

  try{
    const tours = await Tour.find();

    res.status(200).json({
      status: 'success',
      length: tours.length,
      data: {
        tours: tours
      }
    });
  }
  catch(err){
    res.status(400).json({
      status: 'fail',
      error: err
    })
  }
};

exports.getTour = async (req, res) => {
  try{
    const id = req.params.id;
    const tour = await Tour.findById(id);

    res.status(200).json({
      status: 'success',
      data:{
        tour: tour
      }
    });
  }
  catch(err){
    res.status(400).json({
      status: 'fail',
      error: err
    });
  }

  
};

exports.createTour = async (req, res) => {

  try {
    const newTour = await Tour.create(req.body);

    res.status(201).json({
     status: 'success',
     data: {
       tour: newTour
     }
    });
  }
  catch(err){
    res.status(400).json({
      status: 'failure',
      message: err
    });
  }
 
};

exports.updateTour = async (req, res) => {
  try{
    const tour = await Tour.findByIdAndUpdate(req.params.id, req.body, {
      new : true,
      runValidators: true
    });

    res.status(200).json({
      status: 'success',
      data: {
        tour: tour
      }
    });
  }catch(err){
    res.status(400).json({
      status: 'fail',
      error: err
    });
  }
};

exports.deleteTour = async (req, res) => {

  try{
    const id = req.params.id;
    await Tour.findByIdAndDelete(id);
    res.status(204).json({
      status: 'success'
    });
  }catch(err){
    res.status(400).json({
      status: 'fail',
      result: result
    })
  }
};
