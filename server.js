var express = require('express');
var morgan = require('morgan');
var path = require('path');
var Pool=require('pg').Pool;

var config={
    user: 'deekshabd1',
    database: 'deekshabd1',
    host: 'db.imad.hasura-app.io',
    port: '5432',
    password:process.env.DB_PASSWORD
};
var app = express();
app.use(morgan('combined'));

var names=[];
app.get('/submit-name',function(req,res){
    var name=req.query.name;
    names.push(name);
    res.send(JSON.stringify(names));
});


var articles={
    'article-one':{
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
    },
     'article-two':{
    title: 'article2',
    heading: 'article two',
    content:`  
         <p>
             hey there...you are reading my article....
         </p>
         <div class="ab">
         <p>
             It is all about uniqueness...
         </p>
         </div>
         <p>
             Just be yourself...People may not like you...and you dont need to care..:)
         </p>`
    },
     'article-three':{
    title: 'article3',
    heading: 'article three',
    content:`          <p>
             Myself Deeksha......
         </p>
         <div class="happy">
         <p>
             I love singing...and I love nature...
         </p>
         </div>
         <p>
             Always enjoy learning new stuffs...
         </p>`
        }
};
function createTemplate(data){
    var title=data.title;
    var heading=data.heading;
    var content=data.content;
    var htmlTemplate=
        ` <html>
        <head>
            <title>
                ${title}
            </title>
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
                 <h2>
                    ${heading}
                 </h2>
                 <div>
                     ${content}
                 </div>
         </div>
     </body>
     </html>
     `;
        return htmlTemplate;
        
    }
    



var pool = new Pool(config);
app.get('/test',function(req,res){
    pool.query('SELECT * FROM test',function(err,res){
        if(err){
            res.status(500).send(err.toString());
        }else{
            res.send(JSON.stringify(result.rows));
        }
    });
});

app.get('/', function (req, res) {
  res.sendFile(path.join(__dirname, 'ui', 'index.html'));
});

var counter=0;
app.get('/counter',function(req,res){
    counter=counter+1;
    res.send(counter.toString());
});

var names=[];
app.get('/submit-name',function(req,res){
    var name=req.query.name;
    names.push(name);
    res.send(JSON.stringify(names));
});

app.get('/articles/:articlename',function(req,res){
     
     pool.query("SELECT * FROM article WHERE title='+request.params.articleName'",function(err,res){
         if(err){
             res.status(500).send(err.toString());
            } else{
                if(res.rows.length == 0){
                    res.status(404).send('Article not found');
                }else{
                    var articleData=result.rows(0);
                     res.send(createTemplate(articles[articlename]));
                }
            }
 });
 });
    
    


//app.get('/article-one',function(req,res){
   //res.send(createTemplate(artone));
//});

app.get('/ui/style.css', function (req, res) {
  res.sendFile(path.join(__dirname, 'ui', 'style.css'));
});

app.get('/ui/main.js', function (req, res) {
  res.sendFile(path.join(__dirname, 'ui', 'main.js'));
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
