"use strict";

const express = require("express"),
      multer = require('multer'),
      Tesseract = require('tesseract.js'),
      fs = require('fs')

const port = process.env.PORT || 4000,
      responseTime = require('response-time'),
      field = 'userPhoto',
      folder = './uploads',
      storage = multer.diskStorage({
        destination: (req, file, callback)  => {
            callback(null, folder);
        },
        filename: (req, file, callback) => {
            callback(null, file.fieldname + '-' + Date.now());
        }
      }),

      upload = multer({ storage : storage}).single(field);

let app = express();

app.use(responseTime())
app.use(express.static('front.save/'));


app.post('/api/photo',(req,res) => {
    upload(req,res, (err) => {
        if(err)
          return res.json("Error uploading file.");

        let file = `${folder}/${req.file.filename}`;
        Tesseract.recognize(file)
        .then((result) => {
          fs.unlink(file, (err) => {
            if (err)
                return res.status(500).json({err: err});

            return res.status(200).json({
              upload: 'ok',
              result: result.text
            });
          });
        });
    });
});

app.listen(port,function(){
    console.log(`Working on port ${port}`);
});
