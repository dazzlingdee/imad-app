var express = require('express');
var morgan = require('morgan');
var path = require('path');

var app = express();
app.use(morgan('combined'));

var artone={
    title: 'article1',
    heading: 'article one',
    content:`  
             <p>
                 You are reading article one and I am Deeksha,sitting here and typing my html file happily.you can take a look at my profile.I am really trying hard to make my best.Writing html code is always cool task.I enjoy the coding.
             </p>
             <p>
                 You are reading article one and I am Deeksha,sitting here and typing my html file happily.
             </p>
             <p>
                 You are reading article one and I am Deeksha,sitting here and typing my html file happily.
             </p>`
}
function createTemplate(data){
    var title=data.title;
    var heading=data.heading;
    var content=data.content;
    var htmlTemplate={
        ` <html>
        <head>
            <title>$title</title>
            <meta name="viewport" content="width-device-width,initial-scale-1" />
            <link href="/ui/style.css" rel="stylesheet" />
           <div class="center">
           <img src="https://warroom.securestate.com/wp-content/uploads/2016/10/coding.jpg" class="img-medium"/>
           </div>
         
        </head>
         <body>
            <div class="container">
             
             <div>
                 <a href="/">Home</a>
    
             </div>
                          <a href="http://deekshabd1.imad.hasura-app.io/article-three">article three</a>
             <hr/>
                 <h2>$heading</h2>
                 <div>
                 $content
                 </div>
         </div>
     </body>
     return htmlTemplate;
    </html>`
}

app.get('/', function (req, res) {
  res.sendFile(path.join(__dirname, 'ui', 'index.html'));
});

var counter=0;
app.get('/counter',function(req,res){
    counter=counter+1;
    res.send(counter.toString());
});

app.get('/article-one',function(req,res){
   res.sendFile(path.join(__dirname, 'ui', 'article-one.html'));
  //res.send('article one');
});

app.get('/article-two',function(req,res){
    res.sendFile(path.join(__dirname, 'ui', 'article-two.html'));
});

app.get('/article-three',function(req,res){
   res.sendFile(path.join(__dirname, 'ui', 'article-three.html'));
});
app.get('/ui/style.css', function (req, res) {
  res.sendFile(path.join(__dirname, 'ui', 'style.css'));
});

app.get('/ui/madi.png', function (req, res) {
  res.sendFile(path.join(__dirname, 'ui', 'madi.png'));
});


// Do not change port, otherwise your app won't run on IMAD servers
// Use 8080 only for local development if you already have apache running on 80

var port = 80;
app.listen(port, function () {
  console.log(`IMAD course app listening on port ${port}!`);
});
