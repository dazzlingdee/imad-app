
var button=document.getElementById('counter');
var counter=0;
button.onclick=function(){
    var request=XMLHttpRequest();
    request.onreadystatechange=function(){
        if(request.readyState==200){
            var counter=request.responseText;
            var span=document.getElementById('count');
            span.innerHTML=counter.toString();
        }
    }
};
request.open('GET','http://deekshabd1.imad.hasura-app.io/counter',true);
request.send(null);
}

