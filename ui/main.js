console.log('Loaded!');
var img=document.getElementById('hey');
function moveRight(){
    var marginLeft=0;
    marginLeft=marginLeft+10;
    img.style.marginLeft=marginLeft+'px';
};
img.onclick=function(){
    var interval=setInterval(moveRight,100)
   // img.style.marginLeft='500px';
};