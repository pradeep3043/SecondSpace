var express = require('express');
var Pusher  = require("pusher");
var router = express.Router();

var pusher = new Pusher({
  appId : '111251',
  key   : '9e9e520ff97ec106c3be',
  secret: 'ab2a95d7b4368254f8a8'
});


/* GET users listing. */
router.get('/', function(req, res) {
  res.render('handler');
});
router.post("/",function(req,res){
   var body =req.body;
   console.log(body);
   pusher.trigger("nid","pradeep",body);
   res.json({message:"changed activity."});
});

module.exports = router;
